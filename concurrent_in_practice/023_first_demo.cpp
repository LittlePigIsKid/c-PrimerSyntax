#include<iostream>
#include<thread>

void
hello(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));

	std::cout << "Hello World" << std::endl;
}

int
main()
{
	std::thread t(hello, 5);
	t.join();
	return 1;
}
