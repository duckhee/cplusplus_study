#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

enum{
    MAKE = 1,
    DEPOSIT, 
    WITHDRAW, 
    INQUIRE, 
    EXIT
};

enum{
    LEVEL_A = 7,
    LEVEL_B = 4,
    LEVEL_C = 2
};

enum
{
    NORMAL = 1,
    CREDIT = 2
};

class Account
{
    private:
        int accID;
        int balance;
        char *cusName;
    public:
        Account(int ID, int money, char *name);
        Account(const Account &ref);
        int GetAccID() const;
        virtual void Deposit(int money);
        int Withdraw(int money);
        void ShowAccInfo() const;
        ~Account();
};

Account::Account(int ID, int money, char *name):accID(ID), balance(money)
{
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref):accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName)+1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const{
    return accID;
}

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if(balance < money)
    {
        return 0;
    }
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"account id : "<<accID<<endl;
    cout<<"name : "<<cusName<<endl;
    cout<<"balance : "<<balance<<endl;
}

Account::~Account()
{
    delete []cusName;
}

class NormalAccount: public Account
{
    private:
        int interRate;
    public:
        NormalAccount(int ID, int money, char *name, int rate) : Account(ID, money, name), interRate(rate)
        {
            
        }
        virtual void Deposit(int money)
        {
            Account::Deposit(money);
            Account::Deposit(money*(interRate/100.0));
        }
        ~NormalAccount()
        {
            cout<<"NormalAccount() delete"<<endl;
        }
};

class HighCreditAccount:public NormalAccount
{
    private:
        int specialRate;
    public:
        HighCreditAccount(int id, int money, char *name, int rate, int special):NormalAccount(id, money, name, rate), specialRate(special)
        {

        }
        virtual void Deposit(int money)
        {
            NormalAccount::Deposit(money);
            Account::Deposit(money*(specialRate/100.0));
        }
        ~HighCreditAccount()
        {
            cout<<"HighCreditAccount() delete"<<endl;
        }
};

class AccountHandler
{
    private:
        Account *accArr[100];
        int accNum;
    public:
        AccountHandler();
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccInfo(void) const;
        ~AccountHandler();
    protected:
        void MakeNormalAccount(void);
        void MakeCreditAccount(void);
};

void AccountHandler::ShowMenu() const
{
    cout<<"-----menu-----"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입금"<<endl;
    cout<<"3. 출금"<<endl;
    cout<<"4. 계좌 정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::MakeAccount()
{
    int sel;
    cout<<"계좌 종류 선택"<<endl;
    cout<<"1. 보통 예금 계좌"<<endl;
    cout<<"2. 신용 신뢰 계좌"<<endl;
    cout<<"select : ";
    cin>>sel;

    if(sel == NORMAL)
    {
        MakeNormalAccount();
    }
    else{
        MakeCreditAccount();
    }
}

void AccountHandler::MakeNormalAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout<<"보통 예금 계좌 개설"<<endl;
    cout<<"account ID : ";
    cin>>id;
    cout<<"name : ";
    cin>>name;
    cout<<"입금액 : ";
    cin>>balance;
    cout<<"이자율 : ";
    cin>>interRate;
    cout<<endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout<<"신용 신뢰 계좌 개설"<<endl;
    cout<<"account ID : ";
    cin>>id;
    cout<<"name : ";
    cin>>name;
    cout<<"입금액 : ";
    cin>>balance;
    cout<<"이자율 : ";
    cin>>interRate;
    cout<<"신용 등금 (1toA, 2toB, 3toC) : ";
    cin>>creditLevel;
    cout<<endl;

    switch(creditLevel)
    {
        case 1:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
        case 2:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
        case 3:
            accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
        break;
    }
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout<<"입 금"<<endl;
    cout<<"account ID : ";
    cin>>id;
    cout<<"입 금 액 : ";
    cin>>money;

    for(int i = 0; i < accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout<<"입금 완료"<<endl<<endl;
            return ;
        }
    }
    cout<<"유효 하지 않는 ID 입니다."<<endl<<endl;
}

void AccountHandler::WithdrawMoney()
{
    int money;
    int id;
    cout<<"출금"<<endl;
    cout<<"account ID : ";
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
                return;
            }
            cout<<"출금 완료 "<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않는 ID 입니다."<<endl<<endl;
}

AccountHandler::AccountHandler():accNum(0)
{

}

void AccountHandler::ShowAllAccInfo() const
{
    for(int i = 0 ; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < accNum; i++)
    {
        delete accArr[i];
    }
}

int main()
{
    AccountHandler manager;
    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout<<"select : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case MAKE:
                manager.MakeAccount();
            break;
            case DEPOSIT:
                manager.DepositMoney();
            break;
            case WITHDRAW:
                manager.WithdrawMoney();
            break;
            case INQUIRE:
                manager.ShowAllAccInfo();
            break;
            case EXIT:
                return 0;
            default:
                cout<<"Illegal section ..."<<endl;
        }
    }
    return 0;
}