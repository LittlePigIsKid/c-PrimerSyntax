using namespace std;

#include"045_JJ_allocator.h"

#include<vector>
#include<iostream>

int
main(int argc, char* argv[])
{
	int ia[5] = {1, 2, 3, 4, 5};
	unsigned int i;

	vector<int, JJ::allocator<int> > iv(ia, ia+5);
	for (i = 0; i < iv.size(); i++) {
		cout << iv[i] << ' ';
	}
	cout << endl; 
}
