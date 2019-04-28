#include <iostream>

int main(void)
{
	char name[100];
	char lang[200];

	std::cout<<"what is your name? ::";
	std::cin>>name;

	std::cout<<"what is tour favarite program language ? ::";
	std::cin>>lang;

	std::cout<<"my name is "<<name<<std::endl;
	std::cout<<"my favarite program "<<lang<<std::endl;

	return 0;

}


