#include <iostream>
using std::cout;
using std::endl;

void changeMyAge1(int );
void changeMyAge2(int &);

int main()
{
  int age = 10; // stored somewhere in computer memory
  cout << "1. Here's \"age\" now! " << age << endl;

  changeMyAge1(age);
  cout << "2. Here's \"age\" now! (pass-by-value) " << age << endl;

  age = 15;
  changeMyAge2(age);
  cout << "3. Here's \"age\" now! (pass-by-reference) " << age << endl;
}

// passed by value
void changeMyAge1(int x)
{
  x = 50;
  cout << "\t\tIn changeMyAge1, x (age) = " << x << endl;
}

// passed by reference
void changeMyAge2(int &x)
{
  x = 22;
  cout << "\t\tIn changeMyAge2, x (age) = " << x << endl;
}
