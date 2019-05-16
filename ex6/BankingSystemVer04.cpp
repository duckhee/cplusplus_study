#include <iostream>
#include <cstring> 
using namespace std;


enum
{
    MAKE=1, 
    DEPOSIT,
    WITHDRAW, 
    INQUIRE,
    EXIT
};

const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);


class Account
{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char *name):accID(ID), balance(money)
        {
            cusName = new char[strlen(name)+1];
            strcpy(cusName, name);
        }
        Account(const Account &ref):accID(ref.accID), balance(ref.balance)
        {
            cusName = new char[strlen(ref.cusName)+1];
            strcpy(cusName, ref.cusName);
        }
        int GetAccID() const {
            return accID;
        }
        void Deposit(int money)
        {
            balance += money;
        }
        int Withdraw(int money)
        {
            if(balance < money)
            {
                return 0;
            }
            balance -= money;
            return money;
        }
        void ShowAccInfo() const
        {
            cout<<" acc id : "<<accID<<endl;
            cout<<"name : "<<cusName<<endl;
            cout<<"result money : "<<balance<<endl;
        }
        ~Account()
        {
            delete [] cusName;
        }
};


Account *accArr[100];
int accNum = 0;

int main()
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"select : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case MAKE:
                MakeAccount();
            break;
            case DEPOSIT:
                DepositMoney();
            break;
            case WITHDRAW:
                WithdrawMoney();
            break;
            case INQUIRE:
                ShowAllAccInfo();
            break;
            case EXIT:
                for(int i = 0; i < accNum; i++)
                {
                    delete accArr[i];
                }
                return 0;
            default:
                cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}

void ShowMenu()
{
    cout<<"-----menu-----"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입금"<<endl;
    cout<<"3. 출금"<<endl;
    cout<<"4. 계좌 정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌 개설]"<<endl;
    cout<<"계좌 아이디 : ";
    cin>>id;
    cout<<"이름 : ";
    cin>>name;
    cout<<"입금액 : ";
    cin>>balance;
    cout<<endl;

    accArr[accNum++] = new Account(id, balance, name);

}

void DepositMoney()
{
    int money;
    int id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌 아이디 : ";
    cin>>id;
    cout<<"입금액 : ";
    cin>>money;

    for(int i = 0; i < accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }

}

void WithdrawMoney()
{
    int money;
    int id;
    cout<<"[출 금]"<<endl;
    cout<<"계좌 아이디 : ";
    cin>>id;
    cout<<"출금액 : ";
    cin>>money;

    for(int i = 0; i < accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->Withdraw(money) == 0)
            {
                cout<<"잔액 부족"<<endl<<endl;
                return ;
            }
            cout<<"출금 완료"<<endl<<endl;
            return ;
        }
    }
    cout<<"유효하지 않는 아이디 입니다."<<endl<<endl;
}

void ShowAllAccInfo()
{
    for(int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}