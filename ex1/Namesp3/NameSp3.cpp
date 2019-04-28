/**
 * namespace Parent
 * {
 * int num = 2;
 * namespace SubOne
 * {
 * int num = 3;
 * }
 * namespace SubTwo
 * {
 * int num = 4;
 * }
 * }
 * 
 * Parent::num
 * Parent::SubOne::num
 * Parent::SubTwo::num
 */


#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{

    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    std::cout<<"BestCom define function"<<std::endl;
    PrettyFunc();
    ProgComImpl::SimpleFunc();

}

void BestComImpl::PrettyFunc(void)
{
    std::cout<<"So Pretty !"<<std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
    std::cout<<"ProCom define function"<<std::endl;
}