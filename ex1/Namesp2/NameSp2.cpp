#include <iostream>

namespace BestComImpl
{
	void SimpleFunc(void);
}

namespace ProgComImpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	std::cout<<"Best Com define Function"<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout<<"Pro com define Function"<<std::endl;
}



