#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HightCreditAccount.h"

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
    }else
    {
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

void AccountHandler::DepositMoney()
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