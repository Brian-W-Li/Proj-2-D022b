#ifndef MOVIESLINKEDLIST_H
#define MOVIESLINKEDLIST_H

/*********************************************************************
* Name: Brian Li
* Project 1
* Editor(s) used: VScode
* Compiler(s) used: VScode
* Description:
*     This program is a interactive program that uses a linked list to implement a movie list. The user is able to add movies, 
update movies, remove movies, list all movies, and arrange the movies in various ways.
Implemented in this file is a custom to_upper function to convert strings to upper case by value, and the classes for Node and 
Linked List.
**********************************************************************/

#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

/*********************************************************************
* Function: This function simply takes a string passed by value s, and returns the same string with each character converted to 
upper case.
*
* Parameters:
*   string s: the string that we want to upper case of
* Return: string s but turned into upper case.
This function is used in the sorting functions.
**********************************************************************/
std::string to_upper(std::string s) {
  for (char &c : s)
  {
      c = toupper(c);
  }
  return s;
}

// Node Class skeleton was taken from zybooks and examples posted to canvas. Modified for my purposes.
class Node {
public:
   std::string name;
   int year;
   int rating;
   Node* next;

   Node(std::string name, int year, int rating) {
      this->name = name;
      this->year = year;
      this->rating = rating;
      next = nullptr;
   }
};

//Linked List skeleton was taken from zybooks and examples posted to canvas. Modified for my purposes.
class LinkedList {
private:
   Node* head;
   Node* tail;
   int numElems;

public:
   //Constructor for the linked list class. Sets head and tail to null and numElems to 0.
   LinkedList() {
      head = nullptr;
      tail = nullptr;
      numElems = 0;
   }

   //Destructor for the linked list class. Loops through linked list freeing all the nodes.
   virtual ~LinkedList() {
      Node* curr = head;
      while (curr) {
         Node* toBeDeleted = curr;
         curr = curr->next;
         delete toBeDeleted;
      }
   }

   /*********************************************************************
* Function: This function takes in a node that should be placed at the start of the linked list and places it there.
*
* Parameters:
*   Node* newNode: the node we want to add to the linked list
* Return: void
**********************************************************************/
   void Prepend(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head = newNode;
      }
      numElems++;
   }

   //A printing function meant to print out output to the user. Supports movie title length of at least 40 characters.
   void PrintList() {
    int index = 1;
    std::cout << "\nSeq. Name                                    year    rating" << std::endl;
    for (Node *nodePtr = head; nodePtr; nodePtr = nodePtr->next, index++){
        std::cout << std::setw(5) << std::left << index;
        std::cout << std::setw(40) << nodePtr->name;
        std::cout << std::setw(8) << nodePtr->year;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(11) << nodePtr->rating;
        std::cout << std::endl;
        
    }
   }
   
   //quick function to access the numElems member of the Linked List class that keeps track of how many elements are in the
   //linked list.
   int NumElems(){
      return numElems;
   }

   //assuming list has 2 or more elements.
   /*********************************************************************
* Function: This program assumes the list has 2 or more elements, and returns the node before an index for the use of the
Remove Node function. 
*
* Parameters:
*   int index: the index of the linked list node that we consider
* Return: the node right before the linked list marked by the index above.
**********************************************************************/
   Node* NodeBefore(int index){
      int count = 2;
      Node* nodePtr = nullptr;
      for (nodePtr = head; nodePtr && count != index; nodePtr = nodePtr->next, count++);
      return nodePtr;

   }

/*********************************************************************
* Function: This program takes in the index of the Node we want to edit and the new year value, and edits the node.
*
* Parameters:
*   int index: the index of the node we are considering (head means 1, head->next means 2)
*   int newYear: the new year value meant to replace the old year value in the node.
* Return: void
**********************************************************************/
   void EditNodeYear(int index, int newYear){
      int count = 1;
      Node* currentNode = nullptr;
      for (currentNode = head; currentNode && count != index; currentNode = currentNode->next, count++);
      currentNode->year = newYear;
   }

/*********************************************************************
* Function: This program takes in the index of the Node we want to edit and the new rating value, and edits the node.
*
* Parameters:
*   int index: the index of the node we are considering (head means 1, head->next means 2)
*   int newRating: the new rating value meant to replace the old rating value in the node.
* Return: void
**********************************************************************/
   void EditNodeRating(int index, int newRating){
      int count = 1;
      Node* currentNode = nullptr;
      for (currentNode = head; currentNode && count != index; currentNode = currentNode->next, count++);
      currentNode->rating = newRating;
   }

/*********************************************************************
* Function: This program sorts the linked list by title using the method introduced in class. To sort the names case insensitively
the to_upper function defined above is used.
*
* Parameters: NA
* Return: void
**********************************************************************/
   void SortByTitle(){
      for (Node *currNode = head; currNode; currNode = currNode->next){
         for (Node* secondNode = currNode->next; secondNode; secondNode = secondNode->next){
            if (to_upper(currNode->name) < to_upper(secondNode->name)){
               std::swap(*currNode, *secondNode);

               std::swap(currNode->next, secondNode->next);
            }
         }
      }
   }

/*********************************************************************
* Function: This program sorts the linked list by year using the method introduced in class.
*
* Parameters: NA
* Return: void
**********************************************************************/
   void SortByYear(){
      for (Node *currNode = head; currNode; currNode = currNode->next){
         for (Node* secondNode = currNode->next; secondNode; secondNode = secondNode->next){
            if (currNode->year < secondNode->year){
               std::swap(*currNode, *secondNode);

               std::swap(currNode->next, secondNode->next);
            }
         }
      }
   }

/*********************************************************************
* Function: This program sorts the linked list by rating using the method introduced in class.
*
* Parameters: NA
* Return: void
**********************************************************************/
   void SortByRating(){
      for (Node *currNode = head; currNode; currNode = currNode->next){
         for (Node* secondNode = currNode->next; secondNode; secondNode = secondNode->next){
            if (currNode->rating < secondNode->rating){
               std::swap(*currNode, *secondNode);

               std::swap(currNode->next, secondNode->next);
            }
         }
      }
   }

   
/*********************************************************************
* Function: This program removes the node right after a given node.
*
* Parameters: 
Node* currentNode: the current node that we are considering.
* Return: void
**********************************************************************/
   void RemoveAfter(Node* currentNode) {
      if (head){
         numElems--;
      }
      if (currentNode == nullptr && head) {
         
         Node* nodeBeingRemoved = head;
         head = head->next;
         delete nodeBeingRemoved;

         if (head == nullptr) {
             // Last item was removed
             tail = nullptr;
         }
      }
      else if (currentNode->next) {
         Node* nodeBeingRemoved = currentNode->next;
         Node* succeedingNode = currentNode->next->next;
         currentNode->next = succeedingNode;
         delete nodeBeingRemoved;
         if (succeedingNode == nullptr) {
            // Remove tail
            tail = currentNode;
         }
      }
   }
};

#endif
