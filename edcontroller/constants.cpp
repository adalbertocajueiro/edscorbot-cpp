#include "JointInfo.cpp"
#include <string>
using namespace std;

//controller name
const string CONTROLLER_NAME = "EDScorbot";

// metainfo constants
const int ARM_GET_METAINFO = 1;
const int ARM_METAINFO = 2;

// commands constants
const int ARM_CHECK_STATUS = 3;
const int ARM_STATUS = 4;
const int ARM_CONNECT = 5;
const int ARM_CONNECTED = 6;
const int ARM_MOVE_TO_POINT = 7;
const int ARM_APPLY_TRAJECTORY = 8;
const int ARM_CANCEL_TRAJECTORY = 9;
const int ARM_CANCELED_TRAJECTORY = 10;
const int ARM_DISCONNECT = 11;
const int ARM_DISCONNECTED = 12;
const int ARM_HOME_SEARCHED = 13;

// subtopics for each robot
const string META_INFO = "metainfo";
const string COMMANDS = "commands";
const string MOVED = "moved";


const JointInfo metainfo[] = 
{
    JointInfo(-450, 500),
    JointInfo(-950, 800),
    JointInfo(-350, 350),
    JointInfo(-1500, 1600),
    JointInfo(-360, 360),
    JointInfo(0, 100)
};
