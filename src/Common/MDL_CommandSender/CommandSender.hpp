#ifndef COMMAND_SENDER_CLASS_H
#define COMMAND_SENDER_CLASS_H

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

#include "../CommonDefines.hpp"
#include "../MDL_CommandQueue/CommandQueue.hpp"

class CommandSender
{
    public:
        CommandSender(uint16_t port);
        ~CommandSender();
        int startCommandSend(CommandQueue& cmdQueue);

    protected:
        void commandSendThread(CommandQueue& cmdQueue);
        int initSocketFD();
        int connectToServer();
        int sendCommandToServer(CommandQueue& cmdQueue);

        std::thread m_cmdSendThread;
        uint16_t m_port;
        int m_socketFD;
        struct sockaddr_in m_serverAddress;
        char cmdToSend[2];
};

#endif