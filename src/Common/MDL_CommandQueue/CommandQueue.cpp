#include "CommandQueue.hpp"

CommandQueue::CommandQueue()
{
}

CommandQueue::~CommandQueue()
{
}

bool CommandQueue::isEmpty()
{
    return m_queue.empty();
}

unsigned int CommandQueue::size()
{
    return m_queue.size();
}

void CommandQueue::push_back(int command)
{
    std::unique_lock<std::mutex> mlock(m_mutex);
    m_queue.push_back(command);
    mlock.unlock();
    m_condVar.notify_one();
}

int CommandQueue::pop_front()
{
    std::unique_lock<std::mutex> mlock(m_mutex);
    while (m_queue.empty())
    {
        m_condVar.wait(mlock);
    }
    int firstElement = m_queue.front();
    m_queue.pop_front();
    m_queue.shrink_to_fit();
    return firstElement;
}
