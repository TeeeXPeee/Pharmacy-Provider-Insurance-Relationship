#pragma once

#define DEFAULT_BUFLEN 512

class Socket
{
private:
    int m_port;
    SOCKET m_openSocket;
    SOCKET m_targetSocket;
    struct addrinfo *m_result, *m_ptr, m_hints;


public:
    Socket(char* port);
    char* recieveMessage();
    int sendMessage(char* message);

};