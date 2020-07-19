#include "CommandGenerator.hpp"

CommandGenerator::CommandGenerator(std::string filePath)
{
    std::ifstream configFile(filePath);
    if (configFile.is_open()) {
        std::string line;
        std::getline(configFile, line);
        m_commandFrequency = std::stod(line);
        configFile.close();
    }
    else {
        std::cout << "[ERR] CommandGenerator: Failed to open " << filePath << std::endl;
    }
}

CommandGenerator::~CommandGenerator()
{
    m_cmdGenThread.join();
}

int CommandGenerator::startCommandGeneration(CommandQueue& cmdQueue)
{
    m_cmdGenThread = std::thread(&CommandGenerator::commandGenerationThread, this, std::ref(cmdQueue));
    return (m_cmdGenThread.joinable() ? 0: 1);
}

void CommandGenerator::commandGenerationThread(CommandQueue& cmdQueue)
{
    std::srand(std::time(nullptr));

    std::chrono::duration<double, std::chrono::seconds::period> cmdGenPeriod(1.0/m_commandFrequency);
    while (cmdQueue.size() < (unsigned int) MAX_COMMAND_COUNT) {
        // Push new command to queue (0: UP, 1: DOWN, 2: LEFT, 3: RIGHT)
        cmdQueue.push_back(std::rand() % 4);
        std::this_thread::sleep_for(cmdGenPeriod);
    }
}
