#include "CommandReceiver.hpp"

CommandReceiver::CommandReceiver(uint16_t port) : m_port(port)
{
}

CommandReceiver::~CommandReceiver()
{
    m_cmdReceiveThread.join();
}

int CommandReceiver::startCommandReceive(CommandQueue& cmdQueue)
{
    m_cmdReceiveThread = std::thread(&CommandReceiver::commandReceiveThread, this, std::ref(cmdQueue));
    return (m_cmdReceiveThread.joinable() ? 0 : -1);
}

void CommandReceiver::commandReceiveThread(CommandQueue& cmdQueue)
{
    while (true) {
        if (initSocketFD() == -1) {
            continue;
        }
        if (bindSocketFD() == -1) {
            close(m_socketFD);
            continue;
        }
        if (listenForConnections() == -1) {
            close(m_socketFD);
            continue;
        }
        if (receiveNetworkData(cmdQueue) == -1) {
            close(m_socketFD);
            continue;
        }
    }
}

int CommandReceiver::initSocketFD()
{
    int retVal = -1;

    m_socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFD < 0) {
        retVal = -1;
    }
    else {
        retVal = 0;
    }

    return retVal;
}

int CommandReceiver::bindSocketFD()
{
    int retVal = -1;

    m_socketAddress.sin_family = AF_INET;
    m_socketAddress.sin_port = htons(m_port);
    m_socketAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(m_socketFD, (struct sockaddr *) &m_socketAddress, sizeof(m_socketAddress)) < 0) {
        retVal = -1;
    }
    else {
        retVal = 0;
    }

    return retVal;
}

int CommandReceiver::listenForConnections()
{
    int retVal = -1;

    if (listen(m_socketFD, 5) < 0 ) {
        retVal = -1;
    }
    else {
        retVal = 0;
    }

    return retVal;
}

int CommandReceiver::receiveNetworkData(CommandQueue& cmdQueue)
{
    int retVal = -1;
    int acceptSocket;
    socklen_t addressLen = sizeof(m_socketAddress);
    int receiverState = 0;
    char cmd[2] = {0};

    while(true) {
        // Waiting for client connection
        if (receiverState == 0) {
            acceptSocket = accept(m_socketFD, (struct sockaddr *)&m_socketAddress, &addressLen);
            if (acceptSocket < 0) {
                retVal = -1;
                break;
            }
            receiverState = 1;
        }
        // Accepting data from client
        else if (receiverState == 1) {
            memset(cmd, 0, sizeof(cmd));
            if (recv(acceptSocket, cmd, 1, 0) <= 0) {
                close(acceptSocket);
                receiverState = 0;
                break;
            }
            std::string cmdStr("");
            cmdStr.push_back(cmd[0]);
            cmdQueue.push_back(std::stoi(cmdStr));
        }
    }

    close(m_socketFD);
    close(acceptSocket);
    return retVal;
}
