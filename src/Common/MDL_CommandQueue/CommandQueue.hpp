#ifndef COMMAND_QUEUE_CLASS_H
#define COMMAND_QUEUE_CLASS_H

#include <condition_variable>
#include <mutex>
#include <deque>

class CommandQueue
{
    public:
        CommandQueue();
        ~CommandQueue();
        bool isEmpty();
        unsigned int size();
        void push_back(int command);
        int pop_front();

    private:
        std::deque<int> m_queue;
        std::mutex m_mutex;
        std::condition_variable m_condVar;
};

#endif
