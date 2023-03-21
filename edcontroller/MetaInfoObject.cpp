#include <string>
#include "constants.cpp"

using namespace std;

class MetaInfoObject {
    public:
        int signal; 
        string name;
        JointInfo *joints;

        MetaInfoObject()
        {

        }

        MetaInfoObject(int sig, string n, JointInfo *jts)
        {
            signal = sig;
            name = n;

            for (int i = 0; i < sizeof(jts)/sizeof(jts); i++)
            {
                joints[i] = jts[i];
            }
        }
};