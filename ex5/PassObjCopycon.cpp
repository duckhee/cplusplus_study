#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
    private:
        int num;
    public:
        SoSimple(int n):num(n)
        {

        }
        SoSimple(const SoSimple &copy):num(copy.num)
        {
            cout<<"Called SoSimple(const SoSimple &copy) "<<endl;
        }
        void ShowData()
        {
            cout<<"num :: "<<num<<endl;
        }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main()
{
    SoSimple obj(7);
    cout<<"function call before"<<endl;
    SimpleFuncObj(obj);
    cout<<"function call after"<<endl;
    return 0;
}
