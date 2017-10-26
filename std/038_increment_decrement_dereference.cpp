#include<iostream>

using namespace std;

class Int
{
	friend ostream& operator<<(ostream& os, const Int& i);
	public:
		Int(int i) : m_i(i) {}

		//prefix
		Int& operator++() {
			++(this->m_i);
			return *this;
		}

		//postfix
		Int& operator++(int) {
			Int temp = *this;
			++(*this);
			return temp;
		}

		Int& operator--() {
			--(this->m_i);
			return *this;
		}

		const Int operator--(int) {
			
		}
}
