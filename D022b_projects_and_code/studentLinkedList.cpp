#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <iomanip>

#include <algorithm>
using std::swap;

#include <string>
using std::string;

/* Student data */
struct Student
{
  string  name;
  int     idNumber;
  float   gpa;
  Student *next; // addr of next node
};

void sortList(Student *);
void printStudents(Student *);

int main()
{
  Student* firstStudentPtr = nullptr; // an empty linked list, C++11: nullptr

  // three nodes -- their "next pointers" initialized to zero
  Student a = {"Cortana", 123, 3.56f}; // VS gives warning if 'f' is not specified
  Student b = {"Siri", 432, 3.6f};
  Student c = {"Alexa", 852, 3.2f};

  // add node "a" to the beginning of the empty list
  a.next = firstStudentPtr;
  firstStudentPtr = &a;

  // add node "b" to the beginning of the list, in front of "a"
  b.next = firstStudentPtr;
  firstStudentPtr = &b;

  // add node "c" to the beginning of the list, in front of "b"
  c.next = firstStudentPtr;
  firstStudentPtr = &c;

   // Print student list.  Note: list size is not required
  printStudents(firstStudentPtr);

  // For array, you can find/access a node at an index by:
  //   studentArray[i]
  // For linked list, you need to step thru the link using
  // a for loop.
  // Find node at index
  /*int index = 1,
      i;   // index counter
  Student *nodePtr; // traversal pointer
  // Step thru until hitting target node
  for (nodePtr = firstStudentPtr, i = 0; nodePtr && i != index;
        nodePtr = nodePtr->next, i++);
    // Where is the loop body?

  // Is it part of the loop?
  {
    // Make sure pointer is not null and index is not negative
    if (nodePtr != 0 && index >= 0)
      cout << "\n Found " << nodePtr->name << " at index "<< index
             << endl;
	else
	  cout << "Index " << index << " is out of range.\n";
  }

  // Updating student GPA
  string studentName;
  cout << "Enter a student name to update GPA: ";
  cin >> studentName;
  for (nodePtr = firstStudentPtr; nodePtr; nodePtr = nodePtr->next)
    if (nodePtr->name == studentName)
      break;

  // if found (that is, nodePtr did not run off the end of the list)
  if (nodePtr)
  {
    string buf;
    cout << "Enter a new GPA for " << nodePtr->name << " [ currently " << nodePtr->gpa << "]: ";
    cin >> buf; nodePtr->gpa = stof(buf);
  }
  else
    cout << "Student not found\n";

  cout << "\n ---- After update ----\n";
  printStudents(firstStudentPtr);


  // Print student list.  Note: list size is not required
  cout << "\n ---- Unsorted list: ----\n";
  printStudents(firstStudentPtr);
  */

  // Sort the list
  sortList(firstStudentPtr);

  cout << "\n ---- Sorted list: ----\n";
  printStudents(firstStudentPtr);


  return 0;
}

/*************************************************************************
* Purpose:  Sort the list in alphabetical order
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void sortList(Student *firstStudentPtr)
{
  for (Student *p = firstStudentPtr; p; p = p->next)
    for (Student* q = p->next; q; q = q->next)
      if (q->name < p->name)
	  {
        // swap entire content
		swap(*p, *q);

        // swap ptr to original value
		swap(p->next, q->next);
	  }
}

/*************************************************************************
* Purpose:  Print student info in the linked list
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void printStudents(Student *firstStudentPtr)
{
  int index = 1;
  cout << "Seq.  Name             ID    GPA  " << endl;      // non-zero: true
  // 0 : false;  non-zero: true                              // 0/nullptr: false
  for (Student *nodePtr = firstStudentPtr; nodePtr;
       nodePtr = nodePtr->next, index++)
  {
   cout.width(5);
   cout << std::left << index;
   cout.width(18);
   cout << nodePtr->name;
   cout.width(6);
   cout << nodePtr->idNumber;
   cout.setf(ios::fixed); cout.precision(2);
   cout << nodePtr->gpa << endl;
  }
}


