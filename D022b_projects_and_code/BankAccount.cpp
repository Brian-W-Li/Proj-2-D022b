#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount()
{
   m_balance = 0;
}

BankAccount::BankAccount(double initialBalance)
{
    m_balance = initialBalance ;
}

bool      BankAccount::deposit(double amount)
{
    m_balance += amount ;
    return true ;
}

bool     BankAccount::withdraw(double amount)
{
    m_balance  -= amount ;
    return true ;
}

double   BankAccount::balance() const
{
    return ( m_balance ) ;
}

void     BankAccount::print() const
{
    cout << "Balance: " << m_balance << endl;
}
