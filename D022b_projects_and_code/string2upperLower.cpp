#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <cctype> // for toupper and tolower

string toLowerCase(string); // these don't actually change the case of the parameter...
string toUpperCase(string); //...they return a changed version of the parameter.

void searchCaseInsensitive(string, string);

int main( )
{
  string a = "123 !@#$ Hello";
  string b = "World";
  cout << toLowerCase(a) << endl; // shows as "hello"
  cout << toUpperCase(b) << endl; // shows as "WORLD"

  // Is 'a' still the same?
  cout << "orignal 'a' = " << a << endl;

  a = toLowerCase(a); // now "a" is replaced by "hello"
  b = toUpperCase(b); // now "b" is replaced by "WORLD"

  cout << "new a = " << a << endl;
  cout << "new b = " << b << endl;

  // Compare string case-insensitive
  if (toLowerCase(a) == toLowerCase(b))
    cout << "They are the same\n";
  else if (toLowerCase(a) < toLowerCase(b))
    cout << "a comes before b\n";
  else // toLowerCase(a) > toLowerCase(b)
    cout << "a comes after b\n";

  string prog = "Programming C++ is fun.";
  searchCaseInsensitive(prog, "Java");

  return 0;
}

string toLowerCase(string aCppString)
{
  int n = aCppString.length();  // 10
  for (int i = 0; i < n; i++)
    aCppString[i] = tolower(aCppString[i]);  // 'A'  'a'  '='
  return aCppString;
}

string toUpperCase(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; i++)
    aCppString[i] = toupper(aCppString[i]);
  return aCppString;
}

// You can change return type to boolean to make it
// more useful for your project.
void searchCaseInsensitive(string s, string target)
{
   int index;
   string upper_s = toUpperCase(s);
   string upper_target = toUpperCase(target);

   index = upper_s.find(upper_target);
   cout << "index = " << index << endl;

   // Test for match
   if (index != string::npos) // it's really -1
      cout << target << " found" << endl;
   else
      cout << target << " not found" << endl;
}
