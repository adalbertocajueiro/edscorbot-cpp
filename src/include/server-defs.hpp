#include <string>
#include <list>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

//controller name and channels/topics
const std::string CONTROLLER_NAME = "EDScorbot";
const std::string META_INFO = "metainfo";
const std::string COMMANDS = "EDScorbot/commands";
const std::string MOVED = "EDScorbot/moved";

enum MetaInfoSignal {
    ARM_GET_METAINFO = 1,
    ARM_METAINFO = 2
}; 

enum CommandsSignal {
    ARM_CHECK_STATUS = 3,
    ARM_STATUS = 4,
    ARM_CONNECT = 5,
    ARM_CONNECTED = 6,
    ARM_MOVE_TO_POINT = 7,
    ARM_APPLY_TRAJECTORY = 8,
    ARM_CANCEL_TRAJECTORY = 9,
    ARM_CANCELED_TRAJECTORY = 10,
    ARM_DISCONNECT = 11,
    ARM_DISCONNECTED = 12,
    ARM_HOME_SEARCHED = 13
};

class JointInfo {
    public:
        double minimum;
        double maximum;

        JointInfo() { 
            this->minimum = 0.0;
            this->maximum = 0.0;
        }

        JointInfo(double min, double max) { 
            minimum = min;
            maximum = max;
        }

        json to_json(){
            json result = json();

            result["minimum"] = this->minimum;
            result["maximum"] = this->maximum;

            return result;
        }

        static JointInfo from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static JointInfo from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);

            JointInfo result = JointInfo();
            result.maximum = json_obj["maximum"];
            result.minimum = json_obj["minimum"];

            return result;
        }
};

class MetaInfoObject {
    public:
        MetaInfoSignal signal; 
        std::string name;
        std::list<JointInfo> joints;

        MetaInfoObject()
        {
            this->signal = ARM_METAINFO;
            this->name = CONTROLLER_NAME;
            this->joints = std::list<JointInfo>();
        }

        MetaInfoObject(MetaInfoSignal sig, std::string n, std::list<JointInfo> jts)
        {
            signal = sig;
            name = n;
            joints = std::list<JointInfo>(jts);
        }
        json to_json(){
            json result = json();

            result["signal"] = this->signal;
            result["name"] = this->name;
            json js = json::array();

            for (JointInfo j : joints)
            {
                js.push_back(j.to_json());
            }
            result["joints"] = js;

            return result;
        }

        static MetaInfoObject from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static MetaInfoObject from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);


            MetaInfoObject result = MetaInfoObject();
            result.signal = json_obj["signal"];
            result.name = json_obj["name"];

            std::list<JointInfo> joints = std::list<JointInfo>();
            json list = json_obj["joints"];
           
            for (json::iterator it = list.begin(); it != list.end(); ++it) {
                JointInfo ji = JointInfo::from_json(it.value());
                result.joints.push_back(ji);
            }

            return result;
        }
};

class Client {
    public:
        std::string id;

        Client(std::string ident) {
            this->id = ident;
        }

        Client(){
            this->id = "";
        }

        bool is_valid(){
            return strcmp(this->id.c_str(),"") == 0;
        }

        json to_json(){
            json result = json();

            result["id"] = this->id;

            return result;
        }

        static Client from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static Client from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);

            Client result = Client();
            result.id = json_obj["id"];
        }

};

class CommandContent{
    public:
        virtual bool is_point();
        virtual bool is_trajectory();
        virtual json to_json();
};


class Point : public CommandContent{
    public:
        std::list<double> coordinates;
        Point() {
            coordinates = std::list<double>();
        }
        Point(std::list<double> coords){
            coordinates = std::list<double>(coords);
        }

        bool is_empty(){
            return this->coordinates.size() == 0;
        }
        bool is_point(){
            return true;
        }
        bool is_trajectory(){
            return false;
        }
        json to_json(){
            json result = json();
            json coords = json::array();
            
            for (double coord:coordinates) {
                coords.push_back(coord);
            }
            result["coordinates"] = coords;

            return result;
        }

        static Point from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static Point from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);


            Point result = Point();
            
            json coords = json_obj["coordinates"];
           
            for (json::iterator it = coords.begin(); it != coords.end(); ++it) {
                double c = it.value();
                result.coordinates.push_back(c);
            }

            return result;
        }
};

class Trajectory : public CommandContent{
    public:
        std::list<Point> points;
        Trajectory(){
            points = std::list<Point>();
        }
        Trajectory(std::list<Point> pts){
            points = std::list<Point>(pts);
        };
        bool is_point(){
            return false;
        }
        bool is_trajectory(){
            return true;
        }

        json to_json(){
            json result = json();
            json pts = json::array();
            
            for (Point point:points) {
                json p = point.to_json();
                pts.push_back(p);
            }
            result["points"] = pts;

            return result;
        }

        static Trajectory from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static Trajectory from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);


            Trajectory result = Trajectory();
            
            json points = json_obj["points"];
           
            for (json::iterator it = points.begin(); it != points.end(); ++it) {
                Point p = Point::from_json(it.value());
                result.points.push_back(p);
            }

            return result;
        }
};


class CommandObject {
    public:
        CommandsSignal signal;
        Client client;
        bool error;
        CommandContent content;

        CommandObject(){
            client = Client();
            content = Point();
        }

        json to_json(){
            json result = json();
            result["signal"] = signal;
            result["client"] = client.to_json();
            result["error"] = error_state;
            result["content"] = content.to_json();

            return result;
        }

        static Trajectory from_json(json json_obj){
            return from_json_string(json_obj.dump());
        }

        static Trajectory from_json_string(std::string json_string){
            json json_obj = json::parse(json_string);


            Trajectory result = Trajectory();
            
            json points = json_obj["points"];
           
            for (json::iterator it = points.begin(); it != points.end(); ++it) {
                Point p = Point::from_json(it.value());
                result.points.push_back(p);
            }

            return result;
        }
};


// joints informed in static way
const std::list<JointInfo> METAINFOS = 
{
    JointInfo(-450, 500),
    JointInfo(-950, 800),
    JointInfo(-350, 350),
    JointInfo(-1500, 1600),
    JointInfo(-360, 360),
    JointInfo(0, 100)
};

//global flag representing error state of the robot
static bool error_state = false;

//represents the initial owner of the arm. it contains an empty id
static Client owner = Client();

//signatures of useful functions
void handle_response(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);

void *publish(const char *topic, const char *buf);

int extract_signal(std::string message);

MetaInfoObject initial_metainfoobj();