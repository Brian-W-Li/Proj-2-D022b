#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream outFS; // Output file stream

   // Open file
   outFS.open("numtext1.txt");

   if (!outFS.is_open()) {
      cout << "Could not open file numtext1.txt." << endl;
      return 1;
   }

   // Write to file
   outFS << "Hello" << endl;
   outFS << "1 2 3 4" << endl;

   // Done with file, so close
   outFS.close();

   return 0;
}