#include<iostream>
#include<vector>

using namespace std;

int
main(int argc, char* argv[])
{
	#ifdef __sgi
	cout << "__sgi" << endl;
	#endif

	#ifdef __GNUC__
	cout << "__GNUC__" << endl;
	cout << __GNUC__ << ' ' << __GNUC_MINOR__ << endl;
	#endif

	#ifdef __STL_NO_DRAND48
	cout << "__STL_NO_DRAND48 defined" << endl;
	#else
	cout << "_STL_NODRAND48 undefined" << endl;
	#endif
}
