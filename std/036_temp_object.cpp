#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
class print
{
	public:
		void operator() (const T& element) {
			cout << element << ' ';
		}
};

int
main(int argc, char* argv[])
{
	int ia[6] = {0, 1, 2, 3, 4, 5};
	vector<int> iv(ia, ia+6);

	for_each(iv.begin(), iv.end(), print<int>());
	print<int> p;
	cout << endl;
	p(5);
	cout << endl;
	print<int>* p1 = new print<int>;
	(*p1)(10);
	cout << endl;
	::operator delete(p1);
}
