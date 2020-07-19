#ifndef COMMAND_GENERATOR_CLASS_H
#define COMMAND_GENERATOR_CLASS_H

#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include "../CommanderConstants.hpp"
#include "../../Common/CommonConstants.hpp"
#include "../../Common/MDL_CommandQueue/CommandQueue.hpp"

class CommandGenerator
{
    public:
        CommandGenerator(std::string filePath);
        ~CommandGenerator();
        int startCommandGeneration(CommandQueue& cmdQueue);

    private:
        void commandGenerationThread(CommandQueue& cmdQueue);

        double m_commandFrequency; // Hz
        std::thread m_cmdGenThread;
};

#endif