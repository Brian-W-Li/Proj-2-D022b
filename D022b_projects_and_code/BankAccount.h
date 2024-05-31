#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

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

#endif
