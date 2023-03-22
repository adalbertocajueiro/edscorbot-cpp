#include <stdio.h>
#include <signal.h>
//#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "mosquitto.h"
#include "MetaInfoObject.cpp"
#include "json/json.h"
#include "CommandObject.cpp"

//#define mqtt_host "192.168.1.104"
#define mqtt_host "localhost"
#define mqtt_port 1883

static int run = 1;
struct mosquitto *mosq;

typedef struct
{
	int type;
	char mode;
	char *payload;
	int last;
} progress_info;

progress_info progress;

bool errorState = false;
Client *owner = NULL;
bool executingTrajectory = false;

void parse_command(char *command, int *t, char *m, char *url, int *n,int* sleep);
void ftp_trajectory(char *url);
void handle_signal(int s)
{
	run = 0;
}

void connect_callback(struct mosquitto *mosq, void *obj, int result)
{
	printf("connect callback, rc=%d\n", result);
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
	bool match = 0;
	// printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char*) message->payload, message->topic);

	mosquitto_topic_matches_sub("/EDScorbot/commands", message->topic, &match);
	if (match)
	{
#ifdef EDS_VERBOSE
		printf("got message for /EDScorbot/commands topic\n");
#endif

		int type, n, sleep;
		char mode;
		char url[100];
		parse_command((char *)message->payload, &type, &mode, url, &n,&sleep);
		progress.type = type;
		progress.mode = mode;
		progress.payload = url;
		progress.last = 1;
		char *cmd, *out_fname;
		//[1,S,/home/root/puntos.json]
		//type = 1
		// mode = S
		//url = /home/root/puntos.json
		
		switch (progress.type)
		{
		case 1:
			// Trajectory
			if (progress.mode == 'S')
			{
				cmd = reinterpret_cast<char *>(malloc(512));
				out_fname = reinterpret_cast<char *>(malloc(100));
				int l = strlen(progress.payload);
				
				
				for (int i = 0; i < l; i++)
				{
					out_fname[i] = progress.payload[i];
					if (l - i < 7)
					{
						char aux[15] = "_out_cont.json";
						strcat(out_fname,aux);
						break;
					}
				}

				snprintf(cmd, 512, "/home/root/trajectory -c /home/root/initial_config.json -n %d -p 100 -cont %s -s %d %s > log.txt &", n,out_fname,sleep*1000,progress.payload);
				printf("%s",cmd);
				system(cmd);
			}
			break;
		case 2:
			// Move joints
			cmd = reinterpret_cast<char *>(malloc(300));
			// Not really progress nor n, don't know how to solve this right now :P
			snprintf(cmd, 300, "/home/root/sendRef %d %d", progress.mode, n);
			system(cmd);
			break;
		case 3:
			// Reset spid (ConfigureInit)
			cmd = reinterpret_cast<char *>(malloc(20));
			snprintf(cmd, 20, "/home/root/reset");
			system(cmd);
			break;
		case 4:
			// Home
			cmd = reinterpret_cast<char *>(malloc(20));
			snprintf(cmd, 20, "/home/root/home");
			system(cmd);
			break;

		default:
			// free(cmd);
			break;
		}
		free(cmd);
	}
}

void parse_command(char *command, int *t, char *m, char *url, int *n,int *sleep)
{

	char *pch;

	pch = strtok(command, "[],");
	int type = atoi(pch);
	*t = type;
	pch = strtok(NULL, "[],");
	char mode = pch[0];
	*m = mode;
	pch = strtok(NULL, "[],");
	// char buf[100];
	strcpy(url, pch);
	pch = strtok(NULL, "[],");
	*n = atoi(pch);
	pch = strtok(NULL, "[],");
	*sleep = atoi(pch);
// url = buf;
#ifdef EDS_VERBOSE

	printf("type: %d\n", type);
	printf("mode: %c\n", mode);
	printf("url: %s\n", url);
	printf("n: %d\n", *n);

#endif
}

// esto va en el archivo trajectory.cpp
void *pub_progress(void *buf)
{
	char *payload = (char *)buf;
	int rc = mosquitto_publish(mosq, NULL, "/EDScorbot/trajectory", strlen(payload), payload, 1, false);
	int *p = &rc;
	void *v = (void *)p;
	return v;
}

void ftp_trajectory(char *url)
{

	// descargar trayectoria y ejecutarla
	// system("execute_trajectory ....");
	// pthread_t pub_thread;
}

void subscribe_all_topics()
{
    
    // mosquitto_subscribe(mosq, NULL, META_INFO, 0);
    printf("Subscribing on topic metainfo\n");
    mosquitto_subscribe(mosq, NULL, "metainfo", 0);
    printf("Subscribing on topic EDScorbot/commands\n");
    mosquitto_subscribe(mosq, NULL, "EDScorbot/commands", 0);
}

void *publish(const char *topic, const char *buf)
{
    char *payload = (char *)buf;
	int rc = mosquitto_publish(mosq, NULL, topic, strlen(payload), payload, 1, false);
	int *p = &rc;
	void *v = (void *)p;
	return v;
}

Json::Value str_to_json(string message){

	const std::string rawJson = message;
  	const auto rawJsonLength = static_cast<int>(rawJson.length());
  	
  	JSONCPP_STRING err;
  	Json::Value root;

  	Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, 
				&root, &err)) {
		//some error occurred when parsing the message
	} 
	return root;
}

int extract_signal(string message){
	int result;
	Json::Value root = str_to_json(message);
	
	if(root.isMember("signal")){
		int sig = root["signal"].asInt();
		result = sig;
	}

	return result;
}



string meta_info_obj_to_str(int signal,string robot_name, const JointInfo *infos)
{
	Json::Value metainfoobj;
  	Json::Value joints (Json::arrayValue);

	metainfoobj["signal"] = signal;
  	metainfoobj["name"] = robot_name;

	for( int i = 0; i < sizeof(infos)/sizeof(infos[0]); i++)
	{
		JointInfo j = infos[i];
		Json::Value joint;
		joint["minimum"] = j.minimum;
		joint["maximum"] = j.maximum;
		joints.append(joint);
	}

	metainfoobj["joints"] = joints;
  	
	Json::StreamWriterBuilder builder;
	string json_metainfo = Json::writeString(builder, metainfoobj);
	
	return json_metainfo;
}

string build_initial_meta_info_obj()
{
	return meta_info_obj_to_str(ARM_METAINFO,CONTROLLER_NAME,(JointInfo *) metainfo);
}

void handle_meta_info(char *payload)
{
	string info = meta_info_obj_to_str(ARM_METAINFO,CONTROLLER_NAME,(JointInfo *) metainfo);

	publish("metainfo",info.c_str());
}


string command_obj_to_str(int signal, CommandObject obj){
	Json::Value metainfoobj;
	Json::Value client;

	metainfoobj["signal"] = signal;
	metainfoobj["error"] = errorState;

	if( obj.client == NULL){
		
	} else {
		string id = obj.client->id;
		client["id"] = id;
		metainfoobj["client"] = client;
	}
  	if( !(obj.content == NULL) ){
		//build the internal object and adds it to the content field of the message
	}

	Json::StreamWriterBuilder builder;
	string json_commandobj = Json::writeString(builder, metainfoobj);
	
	return json_commandobj;
}

void send_status(){
	string topic = "EDScorbot/commands";
	CommandObject content;
	content.signal = ARM_STATUS;
	if(owner == NULL){

	} else {
		content.client = owner;
	}
	
	string content_str = command_obj_to_str(ARM_STATUS, content);
	publish((char *) topic.c_str(),(char *) content_str.c_str());
	
}
void handle_response(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
{
	char *t = message->topic;

    bool match = 0;
	mosquitto_topic_matches_sub(META_INFO.c_str(), message->topic, &match);
    if(match)
    { 	//topic metainfo
        printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char*) message->payload, message->topic);
		//get the signal
		int sig = extract_signal((char*) message->payload);
		if(sig == ARM_GET_METAINFO){
			handle_meta_info((char*) message->payload);
		}
	}
	//char *topic = strcat(strcat((char*) CONTROLLER_NAME.c_str(),"/"),COMMANDS.c_str());
	//int equal = strcmp(t,topic);
	bool match2 = 0;
	mosquitto_topic_matches_sub("EDScorbot/commands", message->topic, &match2);
	if(match2)
    {
        printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char*) message->payload, message->topic);
		int sig = extract_signal((char*) message->payload);
		switch(sig)
		{
			case ARM_CHECK_STATUS:
				printf("check status received. sending status back \n");
				//send_status();
				break;
			case ARM_CONNECT:
				printf("connect received\n");
				break;
			case ARM_DISCONNECT:
				printf("disconnect received\n");
				break;
			case ARM_MOVE_TO_POINT:
				printf("move to point received\n");
				break;
			case ARM_APPLY_TRAJECTORY:
				printf("apply trajectory received\n");
				break;
			case ARM_CANCEL_TRAJECTORY:
				printf("cancel trajectory received\n");
				break;
			default:
				printf("signal not processed %d \n", sig);
		}
	}
}






MetaInfoObject str_to_meta_info(string message)
{
	MetaInfoObject result;
	result.signal = ARM_METAINFO;
	
  	Json::Value root = str_to_json(message);

	if(root.isMember("signal")){
		int sig = root["signal"].asInt();
		result.signal = sig;
	}
	return result;
	
}



int main(int argc, char *argv[])
{

	uint8_t reconnect = true;
	char clientid[24];
	int rc = 0;

	signal(SIGINT, handle_signal);
	signal(SIGTERM, handle_signal);

	mosquitto_lib_init();

	memset(clientid, 0, 24);
	snprintf(clientid, 23, "mqtt_server_%d", getpid());
	mosq = mosquitto_new(clientid, true, NULL);
	progress.last = 0;
	if (mosq)
	{
		// mosquitto_connect_callback_set(mosq, connect_callback);
		//mosquitto_message_callback_set(mosq, message_callback);
        mosquitto_message_callback_set(mosq, handle_response);

		rc = mosquitto_connect(mosq, mqtt_host, mqtt_port, 60);

        subscribe_all_topics();
		//mosquitto_subscribe(mosq, NULL, "/EDScorbot/commands", 0);

		bool equal = owner != NULL;

		string initial_info = meta_info_obj_to_str(ARM_METAINFO,CONTROLLER_NAME, (JointInfo *) metainfo);

		publish("metainfo",(char *) initial_info.c_str());

		while (run)
		{
			rc = mosquitto_loop(mosq, -1, 1);
			if (run && rc)
			{
				printf("connection error!\n");
				sleep(2);
				mosquitto_reconnect(mosq);
			}
            else
            {
                printf("server conected to mosquitto broker!\n");
            }
		}
		mosquitto_loop_stop(mosq,true);
		mosquitto_destroy(mosq);
	}

	mosquitto_lib_cleanup();

	return rc;
}
