#include <iostream>

using namespace std;

int CalSalary(int sales)
{
    return (int)(50+sales*0.12);
}

int main(void)
{
    int sales;

    while(1)
    {
        cout<<"판매 금액을 만원 단위로 입력 (-1 to end) : ";
        cin>>sales;
        if(sales == -1)
        {
            break;
        }

        cout<<"이번 달 금액 : ";
        cout<<CalSalary(sales)<<"만원"<<endl;
    }
    cout<<"program end "<<endl;

    return 0;
    
}