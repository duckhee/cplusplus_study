#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void)
	{
		std::cout<<"Best Com define function"<<std::endl;
	}
}

namespace ProComImpl
{
	void SimpleFunc(void)
	{
		std::cout<<"Pro Com define function"<<std::endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProComImpl::SimpleFunc();

	return 0;

}


