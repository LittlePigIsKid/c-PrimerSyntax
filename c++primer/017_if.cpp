#include<iostream>

int
main()
{
	int pre = 0, before = 0;
	int val = 0;
	if (std::cin >> pre) {
		before = pre;
		val++;
		while(std::cin >> pre) {
			if(pre == before) {
				val++;
			} else {
				std::cout<<"the value "<<" "<<before<<" shows "<<val<<" times"<<std::endl;
				before = pre;
				val = 1;
			}
		}
		if (pre == before) {
			std::cout<<"the value "<<before<<" shows "<<val<<" times"<<std::endl;
		} else {
			std::cout<<"the value "<<pre<<" shows "<<val<<" times"<<std::endl;
		}
	}
	return 0;
}
