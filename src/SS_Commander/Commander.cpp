#include "Commander.hpp"

Commander::Commander()
{
    std::cout << "== COMMANDER STARTED ==" << std::endl;
}

Commander::~Commander()
{
}

int Commander::startCommandGenerateThread()
{
    m_dirCmdGen = new CommandGenerator(CONFIG_INI_FILE);
    return m_dirCmdGen->startCommandGeneration(m_dirCmdQueue);
}

int Commander::startCommandSendThread()
{
    m_dirCmdSnd = new CommandSender(ENVIRONMENT_PORT);
    return m_dirCmdSnd->startCommandSend(m_dirCmdQueue);
}
