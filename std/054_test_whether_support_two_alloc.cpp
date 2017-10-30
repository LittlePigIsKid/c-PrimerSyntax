#include<iostream>


int
main(int argc, char* argv[])
{
	#ifdef __USE_MALLOC
	std::cout << "---2---" << std::endl;
	#else
	std::cout << "---1---" << std::endl;
	#endif
	return 0;
}
