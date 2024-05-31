#include <iostream>
#include <string>
using namespace std;

#include <iomanip>   //for setprecision
#include <sstream>   // string format control


void printFindingResult(string myStr);
void changeString(string &item);
void nochangeString(string item);

int main()
{
   string email1 = "name@dvc.edu" ;
   string email2 = "dvc.edu" ;
   printFindingResult(email1);
   printFindingResult(email2);


   string desc = "";
   changeString(desc);
   cout << "in main, desc: " << desc << endl;

   string desc2 = "old string";
   nochangeString(desc2);

   cout << "in main, desc2: " << desc2 << endl;

   return 0;
}

void changeString(string &item)
{
   string desc = "Book";
   stringstream cost_ss;  // output string
   float cost = 5.6894;

   cost_ss.clear();   // clear out stringstream
   // cout << fixed << setprecision(2) << cost;
   cost_ss << fixed << setprecision(2) << cost;  //2 decimal places
   cout << "cost_ss.str = " << cost_ss.str() << endl;
   item = "ITEM(" + desc + ")\tCOST($" + cost_ss.str() + ")\n";

   cout << "in changeString, item: " << item << endl;
}

void nochangeString(string item)
{
   string desc = "Book";
   stringstream cost_ss;
   float cost = 5.6894;
   cost_ss.clear();   // clear out stringstream
   cost_ss << fixed << setprecision(2) << cost;  //2 decimal places
   item = "ITEM(" + desc + ")\tCOST($" + cost_ss.str() + ")\n";

   cout << "in nochangeString, item: " << item;
}

void printFindingResult(string s)
{
   cout << "string length = " << s.length() << endl;

   // Test for match              -1
   if (s.find('@') != string::npos)
      cout << s << " has the @ character" << endl;
   else
      cout << s << " does not have the @ character" << endl ;
}
