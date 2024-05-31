#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string ProduceSavingsTable(double startAmount, double apr, int numYears) {
   // Column widths
   const int YEAR_COL_WIDTH = 5;
   const int BALANCE_COL_WIDTH = 10;

   ostringstream outSS;
   double interest;
   double balance = startAmount;
   int month;
   int totalMonths = numYears * 12;

   // Convert APR to monthly percentage rate and decimal number
   double mpr = apr / 12 * 0.01;

   // Display 2 decimal places
   outSS << fixed << setprecision(2);

   // Table heading
   outSS << setw(YEAR_COL_WIDTH) << "Year"
      << setw(BALANCE_COL_WIDTH) << "Balance" << endl;

   // Calculate interest and ending balance for each month
   for (month = 1; month <= totalMonths; ++month) {
      interest = balance * mpr;
      balance += interest;

      // Only output year number and balance at the end of the year
      if (month % 12 == 0) {
         outSS << setw(YEAR_COL_WIDTH) << month / 12
             << setw(BALANCE_COL_WIDTH) << balance << endl;
      }
   }

   // Return the table as a string
   return outSS.str();
}

int main() {
   string table;
   double startAmount;
   double apr;
   int years;

   // Get input values
   cout << "Starting amount?" << endl;
   cin >> startAmount;
   cout << "Annual Percentage Rate?" << endl;
   cin >> apr;
   cout << "Number of years?" << endl;
   cin >> years;

   cout << endl << "Savings over time:" << endl;
   table = ProduceSavingsTable(startAmount, apr, years);
   cout << table << endl;

   return 0;
}
