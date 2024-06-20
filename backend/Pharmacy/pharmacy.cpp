
#include "socket.h"
#include <iostream>

int main(int argc, char *argv[])
{
    //Initalize socket with port 27015
    Socket socket = Socket("27015");
    char* recievedData; 

    while(true)
    {
        recievedData = socket.awaitInput();

        std::cout << recievedData;
    }


};