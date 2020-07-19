#ifndef COMMANDER_CLASS_H
#define COMMANDER_CLASS_H

#include "../Common/CommonConstants.hpp"
#include "../Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../Common/MDL_CommandSender/CommandSender.hpp"
#include "MDL_CommandGenerator/CommandGenerator.hpp"

class Commander
{
    public:
        Commander();
        ~Commander();
        int startCommandGenerateThread();
        int startCommandSendThread();

    private:
        CommandQueue m_dirCmdQueue;
        CommandGenerator *m_dirCmdGen;
        CommandSender *m_dirCmdSnd;
};

#endif