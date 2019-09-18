/*
Daily Coding Problem: Problem #120 [Medium]

This problem was asked by Microsoft.

Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. And in every even call of getInstance(), return the first instance and in every odd call of getInstance(), return the second instance.
*/

#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>

static std::mutex g_mutex;

class AutoLock
{
    std::mutex &m_mutex;

public:
    AutoLock(std::mutex &m)
        : m_mutex(m)
    {
        m_mutex.lock();
    }

    ~AutoLock()
    {
        m_mutex.unlock();
    }
};

class DoubleSingleton
{
public:

    static DoubleSingleton &Get()
    {
        static unsigned int count = 0;
        static DoubleSingleton instance0;
        static DoubleSingleton instance1;

        AutoLock lock(g_mutex);

        if(count++ % 2 == 0)
        {
            std::cout << "Returning instance:0\n";
            return instance0;
        }
        else
        {
            std::cout << "Returning instance:1\n";
            return instance1;
        }
    }
};

void ThreadProc()
{
    for(unsigned int i=0; i<10; i++)
        DoubleSingleton s = DoubleSingleton::Get();
}

void DoDoubleSingleton()
{
    std::thread t0(ThreadProc);
    std::thread t1(ThreadProc);

    t0.join();
    t1.join();
}