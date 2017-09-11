#ifndef __O39_TASK_H
#define __O39_TASK_H

#include<iostream>

class Task {
	public:
		void operator()() const {
			std::cout << "call the function in Task" << std::endl;
		}
};

#endif
