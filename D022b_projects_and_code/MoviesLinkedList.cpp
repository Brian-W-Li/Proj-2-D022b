/*********************************************************************
* Name: Brian Li
* Project 1
* Editor(s) used: VScode
* Compiler(s) used: VScode
* Description:
*     This program is a interactive program that uses a linked list to implement a movie list. The user is able to add movies, 
update movies, remove movies, list all movies, and arrange the movies in various ways.
Only the main function is in this file, the rest of the functions are in MoviesLinkedList.h.
**********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include "MoviesLinkedList.h"
using namespace std;

/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
   LinkedList movieList; //The linked list we will be using.

   bool dontQuit = true;

   while (dontQuit){

        //Options given to the user
        cout << "MENU" << endl;
        cout << "A Add a movie" << endl;
        cout << "U Update a movie" << endl;
        cout << "E Remove a movie" << endl;
        cout << "L List all movies" << endl;
        cout << "T arrange by Title" << endl;
        cout << "V arrange by year Viewed" << endl;
        cout << "R arrange by Rating" << endl;
        cout << "Q Quit" << endl;
        cout << "...your choice: ";
        char choice;
        cin >> choice;

        //Sets the 'kill switch' for this loop. 
        if (toupper(choice) == 'Q'){
            dontQuit = false;
        }

        //Adding elements to the linked list.
        else if (toupper(choice) == 'A'){
            string movieName;
            int yearSeen;
            int rating;
            bool create = true;
            string buf;

            

            cout << "Enter a movie's name: " << endl;
            getline(cin >> ws, movieName);
            if (movieName == ""){
                cout << "movie name cannot be empty" << endl;
                create = false;
            }


            cout << "Enter the year you saw " << movieName << " [like 2016]:" << endl;
            cin >> buf;
            yearSeen = stoi(buf);

            if (yearSeen <= 0){
                cout << "you can't enter numbers below 0" << endl;
                create = false;
            }
            cout << "Enter your rating for " << movieName << " [1, 2, 3, 4, 5]:" << endl;
            cin >> buf;
            rating = stoi(buf);
            
            if (rating == 0 || rating > 5){
                cout << "not valid" << endl;
                create = false;
            }
            if (create){
                Node* newNode = new Node(movieName, yearSeen, rating);
                movieList.Prepend(newNode);
            }
            cout << endl;
        }

        //Removing elements in the list
        else if (toupper(choice) == 'E'){
            if (movieList.NumElems() == 0){
                cout << "there are no elements in the list" << endl;
            }
            else if (movieList.NumElems() == 1){
                cout << "...which movie to remove (1)?" << endl;
                
                int toRemove;
                cin >> toRemove;
                if (toRemove == 1){
                    movieList.RemoveAfter(nullptr);
                }
                else{
                    cout << "out of bounds" << endl;
                }
            }
            else{
                cout << "...which movie to remove (1-" << movieList.NumElems() << ")?" << endl;
                int toRemove;
                cin >> toRemove;
                if (toRemove > movieList.NumElems()){
                    cout << "out of bounds" << endl;
                }
                else{
                    movieList.RemoveAfter(movieList.NodeBefore(toRemove));
                }
            }
            cout << endl;

        }

        //Updating elements in the list
        else if (toupper(choice) == 'U'){
            if (movieList.NumElems() == 0){
                cout << "there are no elements in the list" << endl;
            }
            else {
                if (movieList.NumElems() == 1){
                    cout << "...which would you like to update (1)?" << endl;
                }
                else{
                    cout << "...which would you like to update (1-" << movieList.NumElems() << ")?" << endl;
                }
                int toUpdate;
                cin >> toUpdate;
                
                if (toUpdate > movieList.NumElems()){
                    cout << "out of bounds" << endl;
                }
                else{
                    cout << "...what would you like to update? (YEAR(1) or RATING(2))" << endl;
                    int input;
                    cin >> input;
                    if (input == 1){
                        cout << "...what would you like to update the year to be?" << endl;

                        cin >> input;
                        movieList.EditNodeYear(toUpdate, input);
                    }
                    else if (input == 2){
                        cout << "...what would you like to update the rating to be?" << endl;
                        cin >> input;
                        movieList.EditNodeRating(toUpdate, input);
                    }
                    else{
                        cout << "1 or 2 only please" << endl;
                    }
                }
            }
        }

        //Sorting elements by title
        else if (toupper(choice) == 'T'){
            movieList.SortByTitle();
        }

        //sorting elements by year
        else if (toupper(choice) == 'V'){
            movieList.SortByYear();
        }

        //sorting elements by rating
        else if (toupper(choice) == 'R'){
            movieList.SortByRating();
        }

        //printing out the list
        else if (toupper(choice) == 'L'){
            movieList.PrintList();
            cout << endl;
        }

        //Catch case for invalid inputs
        else{
            cout << "not a valid input" << endl;
        }

   }
   
}

