#include <iostream>

using namespace std;

class SoSimple
{
    private :
        int num;
    public : 
        SoSimple(int n):num(n)
        {

        }
        SoSimple& AddNum(int n)
        {
            num += n;
            return *this;
        }
        void ShowData() const
        {
            cout<<"num : "<<num<<endl;
        }
};

int main(int argc, char **argv)
{
    const SoSimple obj(7);
    //obj.AddNum(20);  //const 함수가 아니라 에러 발생 한다.
    obj.ShowData();
    return 0;
}