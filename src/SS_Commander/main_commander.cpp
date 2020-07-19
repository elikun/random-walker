#include "Commander.hpp"

int main(void)
{
    Commander *commander = new Commander();

    commander->startCommandGenerateThread();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    commander->startCommandSendThread();

    while (true);
    return 0;
}