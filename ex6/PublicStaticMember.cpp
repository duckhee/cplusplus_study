#include <iostream>

using namespace std;


class SoSimple
{
    public:
        static int simObjCnt;
    public:
        SoSimple()
        {
            simObjCnt++;
        }
};

int SoSimple::simObjCnt = 0;

int main()
{
    cout<<SoSimple::simObjCnt<<"번째 SoSimple object"<<endl;
    SoSimple sim1;
    SoSimple sim2;

    cout<<SoSimple::simObjCnt<<"번째 SoSimple object"<<endl;
    cout<<sim1.simObjCnt<<"번째 SoSimple object"<<endl;
    cout<<sim2.simObjCnt<<"번째 SoSimple object"<<endl;

    return 0;
}