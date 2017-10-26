#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
#include<iostream>

using namespace std;
namespace user_first {
	
	class UsedForTest {
		public:
			//UsedForTest() = default;
			UsedForTest() {
				std::cout << "into UsedForTest class default constructor" << endl;
			}
			UsedForTest(int value): _value(value){
				std::cout << "into UsedForTest class constructor" << endl;
			}
			~UsedForTest(){
				std::cout << "into UsedForTest class destructor" << endl;
			}
			void print() {
				std::cout << "_value =" << this->_value << endl;
			}
			void *operator new(size_t size) {
				std::cout << "into user_first's operator new" << endl;
				return malloc(size);	
			}
		private:
			int _value = 1;
	};
}

void *operator new(size_t size) {
	std::cout << "into global_second's operator new" << endl;
	return malloc(size);	
}

// this one is used to test the support of c syntax
static void function_test_static() {
	cout << "function test static" << endl;
}
int
main(int argc, char* argv[])
{
	function_test_static();

	void* ptr1 = user_first::UsedForTest
					::operator new(sizeof(user_first::UsedForTest));

	void* ptr2 = ::operator new (sizeof(user_first::UsedForTest));

	//placement new using in c++ primer page 729 
	new((user_first::UsedForTest*)ptr1) user_first::UsedForTest[1];
	((user_first::UsedForTest *)ptr1) -> print();

	user_first::UsedForTest ptr3(3);
	new ((user_first::UsedForTest*)ptr2) user_first::UsedForTest[1];
	((user_first::UsedForTest *)ptr2) -> print();
}
