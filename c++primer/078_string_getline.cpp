#include<iostream>

using namespace std;

int
main()
{
	string line;

	//the getline could read the '\n', but the string could not save it, so we add endl to cout to begin a new line.
	while(getline(cin, line)) {
		cout << line << endl;
	}
}
