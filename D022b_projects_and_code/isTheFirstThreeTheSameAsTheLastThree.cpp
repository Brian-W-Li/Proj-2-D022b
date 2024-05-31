/*********************************************************************
* Name: Brian Li
* Week 4 - Pointers - Q1
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program takes in a pointer to the start of an array and the size of that array, and returns if the first 3 values are
special and if the first 3 values are the same as the last 3 values.
**********************************************************************/

#include <iostream>

using namespace std;

bool isTheFirstThreeTheSameAsTheLastThree(int* pointer1, int sizeOfArray, bool&);

void printArray(int* , int);


/*********************************************************************
* Function: Main
**********************************************************************/
int main()
{
    const int sizeOfArray = 5;
    int array1[] = {2, 2, 2, 3, 1};
    int* pointer1 = array1;
    bool firstThreeSameAsLastThree = true;
    
    printArray(pointer1, sizeOfArray);
    bool specialFirstThree = isTheFirstThreeTheSameAsTheLastThree(pointer1, sizeOfArray, firstThreeSameAsLastThree);
    cout << "Is the first three special? " << specialFirstThree << endl;
    cout << "Is the first three the same as last 3? " << firstThreeSameAsLastThree << endl;



}

//simple printing testing function using pointer arithmetic
void printArray(int* pointer1, int sizeOfArray){
    for (int i = 0; i < sizeOfArray; i++){
        cout << *(pointer1 + i) << " ";
    }
    cout << endl;
}






/*********************************************************************
* Function: This function takes in a pointer to the start of an array, the size of the array, and a pass by reference boolean, 
and returns 2 boolean values. One boolean value returned using pass by reference signifies if the first 3 elements in the array
are the same as the last 3 elements. The second boolean value returned by the function itself indicates whether the first 3
values are considered special.
*
* Parameters:
*   pointer1: a pointer to the start of an array passed into the function
*   sizeOfArray: an integer indicating the size of the array passed into the function
*   firstThreeSameLastThree: a boolean passed by reference that indicates whether the first 3 elements are the same as the
last 3 elements.
**********************************************************************/
bool isTheFirstThreeTheSameAsTheLastThree(int* pointer1, int sizeOfArray, bool& firstThreeSameLastThree){
    bool specialFirstThree = false;
    
    //if sizeOfArray is 0, 1, or 2, ensure that the function returns two false values
    if (sizeOfArray < 3){
        firstThreeSameLastThree = false;
    }
    else{
        //check if the first three values are special without needing a loop using pointer arithmetic
        if (*(pointer1) == *(pointer1 + 1) && *(pointer1) == *(pointer1 + 2)){
            specialFirstThree = true;
        }
        if (*(pointer1) + 1 == *(pointer1 + 1) && *(pointer1) + 2 == *(pointer1 + 2)){
            specialFirstThree = true;
        }

        //using a loop, check if the first 3 elements of the array are the same as the last 3 elements of the array
        for (int i = 0; i < 3; i++){

            //code to check what elements are being compared in the if statement below:
            //cout << "elem1: " << *(pointer1 + i) << " " << "elem2: " << *(pointer1 + sizeOfArray - 3 + i) << endl;
            if (*(pointer1 + i) != *(pointer1 + sizeOfArray - 3 + i)){
                firstThreeSameLastThree = false;
            }
        }
    }
    
    return specialFirstThree;
}



