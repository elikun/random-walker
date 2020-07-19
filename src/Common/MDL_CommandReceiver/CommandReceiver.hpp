#ifndef COMMAND_RECEIVER_CLASS_H
#define COMMAND_RECEIVER_CLASS_H

#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

#include "../MDL_CommandQueue/CommandQueue.hpp"

class CommandReceiver
{
    public:
        CommandReceiver(uint16_t port);
        ~CommandReceiver();
        int startCommandReceive(CommandQueue& cmdQueue);

    protected:
        void commandReceiveThread(CommandQueue& cmdQueue);
        int initSocketFD();
        int bindSocketFD();
        int listenForConnections();
        virtual int receiveNetworkData(CommandQueue& cmdQueue);

        std::thread m_cmdReceiveThread;
        uint16_t m_port;
        int m_socketFD;
        struct sockaddr_in m_socketAddress;
};

#endif