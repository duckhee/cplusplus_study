#include <iostream>

int Addr(int num1=1, int num2=2)
{
	return num1+num2;
}


int main(void)
{
	std::cout<<Addr()<<std::endl;
	std::cout<<Addr(5)<<std::endl;
	std::cout<<Addr(3, 5)<<std::endl;

	return 0;

}
