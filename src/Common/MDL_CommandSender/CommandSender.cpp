#include "CommandSender.hpp"

CommandSender::CommandSender(uint16_t port) : m_port(port)
{
}

CommandSender::~CommandSender()
{
    m_cmdSendThread.join();
}

int CommandSender::startCommandSend(CommandQueue& cmdQueue)
{
    m_cmdSendThread = std::thread(&CommandSender::commandSendThread, this, std::ref(cmdQueue));
    return (m_cmdSendThread.joinable() ? 0 : -1);
}

void CommandSender::commandSendThread(CommandQueue& cmdQueue)
{
    while (true) {
        if (initSocketFD() == -1) {
            continue;
        }
        if (connectToServer() == -1) {
            close(m_socketFD);
            continue;
        }
        else {
            if (m_port == ENVIRONMENT_PORT) {
                std::cout << "[INFO] CommandSender: successful connection of Commander to Environment" <<  std::endl;
            }
        }
        if (sendCommandToServer(cmdQueue) == -1) {
            close(m_socketFD);
            continue;
        }
    }
}

int CommandSender::initSocketFD()
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

int CommandSender::connectToServer()
{
    int retVal = -1;

    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_port = htons(m_port);
    m_serverAddress.sin_addr.s_addr = inet_addr(LOOPBACK_IPV4_ADDRESS);

    if (connect(m_socketFD, (struct sockaddr *) &m_serverAddress, sizeof(m_serverAddress)) == -1) {
        close(m_socketFD);
        retVal = -1;
    }
    else {
        retVal = 0;
    }

    return retVal;
}

int CommandSender::sendCommandToServer(CommandQueue& cmdQueue)
{
    int retVal = -1;
    static bool isFirstTransmission = true;

    if (isFirstTransmission) {
        sprintf(cmdToSend, "%d", cmdQueue.pop_front());
        isFirstTransmission = false;
    }

    char tempbuf[2] = "\0";
    while (true) {
        if (recv(m_socketFD, tempbuf, 1, MSG_DONTWAIT) != 0) {
            if (send(m_socketFD, cmdToSend, strlen(cmdToSend), MSG_NOSIGNAL) != -1) {
                sprintf(cmdToSend, "%d", cmdQueue.pop_front());
                retVal = 0;
            }
            else {
                retVal = -1;
                break;
            }
        }
        else {
            retVal = -1;
            break;
        }
    }

    return retVal;
}