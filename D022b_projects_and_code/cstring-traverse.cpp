#include <iostream>
using namespace std;

#include <string.h>

int main() {
   char userStr[20] = "1234567890123456789"; // Input string 0 '\0'
   char str1[] = "abcde";  // null char is automatically inserted at the end
   int i;

   cout << "str1 = " << str1 << "\t length of str1 = " << strlen(str1) << endl;

   // Prompt user for string input
   cout << "Enter string (<20 chars): ";
   cin >> userStr;

   // Print string
   cout << endl << userStr << endl;

   // Look for '@'
   for (i = 0; userStr[i] != '\0'; ++i) {
      if (userStr[i] == '@') {
         cout << "Found '@'." << endl;
      }
   }
   cout << endl;


   // The following is an ERROR.
   // May print chars it shouldn't.
   // Problem: doesn't stop at null char.
   cout << "\""; // Print opening "
   for (i = 0; i < 20; ++i) { // Print each char
      cout << userStr[i];
   }
   cout << "\"" << endl;      // Print closing "


   // The following is an even WORSE ERROR.
   // Accesses beyond valid index range.
   // Program may crash.
   cout << "\""; // Print opening "
   for (i = 0; i < 30; ++i) {
      cout << userStr[i];
   }
   cout << "\"" << endl; // Print closing "

   cout << "str1 = " << str1 << "\t length of str1 = " << strlen(str1) << endl;

   return 0;
}
