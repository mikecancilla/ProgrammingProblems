#include <iostream>
#include <chrono>
#include <thread>

void cb()
{
	std::cout << "Callback called!" << std::endl;
}

void ScheduleJob(void(*callback)(), const unsigned int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));

	callback();
}

void DoJobScheduler()
{
	ScheduleJob(cb, 3000);

	ScheduleJob([](){std::cout << "Callback called from Lambda!" << std::endl; }, 3000);
}