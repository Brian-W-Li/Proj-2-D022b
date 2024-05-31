
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <cstdlib>

struct Student {
   int age;
   string name;
   double gpa;
};

void outputTableHeading();
void outputStudent(int, Student);
Student inputStudent();

int main(){
   Student jack;
   jack.age = 18;
   jack.name = "Jack Smith";
   jack.gpa = 2.89;

   Student jill;
   jill.age = 18;
   jill.name = "Jill Smith";
   jill.gpa = jack.gpa + 1.0;

   Student classmate;
   cout << "Enter the name of Jack and Jill's classmate: ";
   getline(cin, classmate.name);

   string buf;
   cout << "And what's " << classmate.name << "'s age?";
   cin >> buf;
   classmate.age = stoi(buf);

}


