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

struct Student
{
  string  name;
  int     idNumber;
  float   gpa;
  Student *next;
};

void sortList(Student *);
void printStudents(Student *);

int main()
{
  Student *firstStudentPtr = NULL; // an empty linked list, C++11: nullptr

  // add a node to the beginning of the list
  Student *temp = new Student{"Cortana", 542, 3.24f}; // C++11 syntax
  temp->next = firstStudentPtr;
  firstStudentPtr = temp;

  // add a node to the beginning of the list
  temp = new Student{"Siri", 432, 3.55f}; // C++11 syntax
  temp->next = firstStudentPtr;
  firstStudentPtr = temp;

  // add a node to the beginning of the list
  temp = new Student{"Alexa", 895, 3.72f}; // C++11 syntax
  temp->next = firstStudentPtr;
  firstStudentPtr = temp;

  // Print student list.  Note: list size is not required
  printStudents(firstStudentPtr);

  // Remove a single node
  Student *prev, *nodePtr;
  string studentName;
  cout << "Enter a student name to remove: ";
  cin >> studentName;
  for (nodePtr = firstStudentPtr, prev = 0; nodePtr;
       prev = nodePtr, nodePtr = nodePtr->next)
    if (nodePtr->name == studentName)
      break;

  // if found
  if (nodePtr)
  {
    if (prev)
      prev->next = nodePtr->next; // skips over the node at p
    else
	  firstStudentPtr = nodePtr->next; // there's a new head, possibly zero
    delete nodePtr; // we're done with this node
  }
  else
    cout << "Student not found\n";

  // Print student list.  Note: list size is not required
  printStudents(firstStudentPtr);

  // Deallocate all nodes
  while (firstStudentPtr) // keep going as long as the list is not empty
  {
    Student* p = firstStudentPtr; // hold onto head node
    firstStudentPtr = firstStudentPtr->next; // because we're linking over it to its next
    delete p; // now deallocate the old head
  }


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
  cout << "\nSeq.  Name             ID    GPA  " << endl;
  for (Student *nodePtr = firstStudentPtr; nodePtr;
       nodePtr = nodePtr->next, index++)
  {
   cout.width(5);
   cout << std::left << index;
   cout.width(18);
   cout << nodePtr->name; // (*nodePtr).name
   cout.width(6);
   cout << nodePtr->idNumber;
   cout.setf(ios::fixed); cout.precision(2);

   cout << nodePtr->gpa << endl;
  }
}


void sortedInsert(Student *&firstStudentPtr, Student *new_student)
{
    Student *current;
    /* Special case for the head end */
    if (!firstStudentPtr || firstStudentPtr->name >= new_student->name)
    {
        new_student->next = firstStudentPtr;
        firstStudentPtr = new_student;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = firstStudentPtr;
        while (current->next != NULL &&
               current->next->name < new_student->name)
        {
            current = current->next;
        }
        new_student->next = current->next;
        current->next = new_student;
    }
}


