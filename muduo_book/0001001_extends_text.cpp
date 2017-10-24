#include<stdio.h>

class Par final {
	protected:
		Par(){};
};

class Chi : public Par {
	public:
		Chi() = default; 
		Chi(int v) : value_(1) {}; 
		void print_value() {
			printf("the value_ = %d\n", value_);
		}
	private:
		int value_ = 0;
};

int 
main(int argc, char *argv[]) 
{
	//Par par = Chi();
	Chi chi = Chi(5);
	chi.print_value();
	printf("the mian is finished\n");
}
