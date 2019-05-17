#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
    private:
        int bullet;
    public:
        Gun(int bnum):bullet(bnum)
        {

        }
        void Shot()
        {
            cout<<"BBANG!"<<endl;
            bullet--;
        }
};

class Police
{
    private:
        int handcuffs;
        Gun *pistol;
    public:
        Police(int bnum, int bcuff):handcuffs(bcuff)
        {
            if(bnum>0)
            {
                pistol = new Gun(bnum);
            }else{
                pistol = NULL;
            }
        }
        void PutHandcuff()
        {
            cout<<"SNAMP!"<<endl;
            handcuffs--;
        }
        void Shot()
        {
            if(pistol == NULL)
            {
                cout<<"Hut BBANG !"<<endl;
            }else
            {
                pistol->Shot();
            }
            
        }
        ~Police()
        {
            if(pistol != NULL)
            {
                delete pistol;
            }
        }
};

int main(){
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandcuff();

    Police pman1(0, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    return 0;
}