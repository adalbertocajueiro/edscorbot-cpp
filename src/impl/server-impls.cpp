#include <string>
#include "../include/server-defs.hpp"

int extract_signal(std::string message){
    int result;
	json json_obj = json::parse(message);
    result = json_obj["signal"];
	
	return result;
}

MetaInfoObject initial_metainfoobj(){
    MetaInfoObject result = MetaInfoObject();
    result.joints = std::list<JointInfo>(METAINFOS);
}