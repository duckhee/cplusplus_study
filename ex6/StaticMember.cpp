#include <iostream>

using namespace std;

class SoSimple
{
    private :
        static int simObject;
    public :
        SoSimple()
        {
            simObject++;
            cout<<simObject<<"번째 SoSimple 객체"<<endl;
        }
};

int SoSimple::simObject = 0;

class SoComplex
{
    private :
        static int cmxObject;
    public :
        SoComplex()
        {
            cmxObject++;
            cout<<cmxObject<<"번째 SoComplex 객체"<<endl;
        }
        SoComplex(SoComplex &copy)
        {
            cmxObject++;
            cout<<cmxObject<<"번째 SoComplex 객체"<<endl;
        }
};

int SoComplex::cmxObject = 0;

int main()
{
    SoSimple sm1;
    SoSimple sm2;

    SoComplex cmx1;
    SoComplex cmx2 = cmx1;
    SoComplex();

    return 0;
}