#include<iostream>
#include<thread>
#include"039_task.h"

int
main()
{
	Task task;
	std::thread my_thread(task);
	my_thread.join();
}
