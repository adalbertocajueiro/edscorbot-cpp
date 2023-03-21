#include "Client.cpp"

class CommandObject {
    public:
        int signal;
        Client *client;
        bool error;
        void *content;

        CommandObject(){
            content = NULL;
        }
};