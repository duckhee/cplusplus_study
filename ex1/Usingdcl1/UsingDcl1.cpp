#include <iostream>

namespace Hybrid
{
    void HybFunc(void)

    {
        std::cout<<"So Simple function!"<<std::endl;
        std::cout<<"In namespace Hybrid!"<<std::endl;
    }
}

int main(void)
{
    using Hybrid::HybFunc;

    HybFunc();

    return 0;
    
}