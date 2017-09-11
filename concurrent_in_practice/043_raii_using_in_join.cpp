#include<iostream>
#include<thread>

class Thread_guard {
	std:: thread &t;
	public:
		explicit Thread_guard(std::thread &t_): t(t_) {}
		~Thread_guard() {
			if (t.joinable()) {
				t.join();
			}
		}
		Thread_guard(Thread_guard const&) = delete;
		Thread_guard& operator = (Thread_guard const&) = delete;
};

struct Func {
	int& i;
	Func(int& i_):i(i_) {}
	void operator() () {
		for (unsigned j = 0; j < 100000; j++) {
			std::cout << j << std::endl;
		}
	}
};

int
main()
{
	int some_local_state = 0;
	Func my_func(some_local_state);
	std::thread t(my_func);
	// this object is destruct before thread for the reason the local variables
	// are destructed in the reverse order of they are pushed in the stack;
	Thread_guard guard(t); 
}
