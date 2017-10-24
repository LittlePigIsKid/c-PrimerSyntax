#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main()
{
	string str = "hello world";
	auto b = str.begin();
	auto e = str.end();
	for( ; b != e; b++) {
		*b = toupper(*b);
	}
	cout << str << endl;
	return 0;
}
