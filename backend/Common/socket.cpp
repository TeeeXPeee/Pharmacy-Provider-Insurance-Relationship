#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include "socket.h"

#pragma comment(lib, "Ws2_32.lib")

Socket::Socket(char* port)
{

    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);


    ZeroMemory(&this->m_hints, sizeof (this->m_hints));

    this->m_hints.ai_family = AF_INET;
    this->m_hints.ai_socktype = SOCK_STREAM;
    this->m_hints.ai_protocol = IPPROTO_TCP;
    this->m_hints.ai_flags = AI_PASSIVE;

    // Resolve the local address and port to be used by the server
    iResult = getaddrinfo(NULL, port, &this->m_hints, &this->m_result);

    this->m_openSocket = socket(this->m_result->ai_family, this->m_result->ai_socktype, this->m_result->ai_protocol);

    // Setup the TCP listening socket
    iResult = bind( this->m_openSocket, this->m_result->ai_addr, (int)this->m_result->ai_addrlen);

    freeaddrinfo(this->m_result);
}

char* Socket::recieveMessage()
{
    int bytesRecieved = 0;

    char recvbuf[DEFAULT_BUFLEN];
    int iResult;

    listen( this->m_openSocket, SOMAXCONN );
    this->m_targetSocket = accept(this->m_openSocket, NULL, NULL);

    bytesRecieved = recv(this->m_targetSocket, recvbuf, DEFAULT_BUFLEN, 0);
    printf("Bytes Sent: %ld\n", bytesRecieved);

    return recvbuf;
}

int Socket::sendMessage(char* message)
{
    int bytesSent = 0;
    //TODO set up ptr address location
    connect( this->m_openSocket, this->m_ptr->ai_addr, (int)this->m_ptr->ai_addrlen);
    bytesSent = send(this->m_openSocket, message, (int) strlen(message), 0);
    shutdown(this->m_openSocket, SD_SEND);

    printf("Bytes Sent: %ld\n", bytesSent);

    return bytesSent;
}
