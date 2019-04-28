#include <iostream>

int main(void)
{
    int num = 0;
    int input;

    using namespace std;

    for(int i = 0; i < 5; i++)
    {
        cout<<i+1<<"번째 정수 입력 : ";
        cin>>input;
        num += input;
    }
    cout<<"sum : "<<num<<endl;
    return 0;
}