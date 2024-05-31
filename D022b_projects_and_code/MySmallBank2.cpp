#include <iostream>
using namespace std;
//#include "BankAccount.h"

// Declaration from BankAccount.h
class BankAccount
{
     private:
         int         m_id ;
         double      m_balance ;

     public:
	    BankAccount(); // default constructor
		BankAccount(double initialBalance);
        bool     deposit(double amount);
        bool     withdraw(double amount);
        double   balance() const;
		void     print() const;
};


// Implementation from BankAccount.cpp
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


/********************************************************************
* Compile on command line:
* C:\ g++ -std=c++11 -o mybank MySmallBank.cpp BankAccount.cpp
*
*********************************************************************/

int main()
{

        cout << "Welcome to my small bank." << endl;
		BankAccount  acct;
		acct.deposit(100);
		// cout << acct.m_balance << endl;    // error
		cout << "from blance: " << acct.balance() << endl;
		acct.print();

		acct.withdraw(20);
		cout << "acct: ";
		acct.print() ;

		BankAccount yourAcct(200);
		yourAcct.deposit(50);
		cout << "yourAcct: ";
		yourAcct.print() ;

		BankAccount accts[10]; // array of BankAccount
        accts[0].deposit(500);
		cout << "accts[0]: ";
		accts[0].print();

		cout << "Thank you for using my bank." << endl;

        return 0 ;
}

