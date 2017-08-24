#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::string;
using std::endl;

int
main()
{
	vector<string> vect1(10, "hi");
	cout << "size_of_vector:" << vect1.size() << endl;
	for (int i = 0; i < vect1.size(); i++) {
		string *ptr = &vect1[i];
		*ptr += "H";
	}
	for (int i = 0; i < vect1.size(); i++) {
		string str = vect1[i];
		str = "I" + str;
	}
	for (int i = 0; i < vect1.size(); i++) {
		string str;
		str = vect1[i];
		cout << str << endl;
	}
	return 0;
}
