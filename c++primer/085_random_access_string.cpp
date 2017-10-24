#include<iostream>

using namespace std;

int
main()
{
	const string const_str("123456789");
	string::size_type n;
	string str;
	while (cin >> n) {
		str += const_str[n - 1];	
	}
	cout << str << endl;
	return 0;
}
