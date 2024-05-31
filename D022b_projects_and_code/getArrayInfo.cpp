/*********************************************************************
* Name: Brian Li
* Week 2: Practice on arrays and C-strings Q3
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program checks if an array of ints is ascending or bounded, and also returns the largest number between the first
and last element.
**********************************************************************/
#include <iostream>

using namespace std;

int getArrayInfo(int myArray[], int size, bool& ascending, bool& bounded);


int main(){
    bool ascending = true;
    bool bounded = true;
    int size = 4;
    int array1[size];
    array1[0] = 1;
    array1[1] = 91;
    array1[2] = 90;
    array1[3] = 20;


    int ans = getArrayInfo(array1, size, ascending, bounded); //gets biggest value between first and last of the array.
    cout << "the biggest value between first and last: " << ans << endl;
    cout << "Ascending?" << ascending << endl;
    cout << "Bounded?" << bounded << endl;
}

int getArrayInfo(int myArray[], int sizee, bool &ascending, bool &bounded){
    int firstElem = myArray[0];
    int lastElem = myArray[sizee - 1];
    //if its a 2 element array, it will work
    //if its a 1 element array, same thing.
    for (int i = 0; i < sizee - 1; i++){
        if (myArray[i] < myArray[i-1] && i != 0){
            ascending = false;
        }
        if (myArray[i] > myArray[i+1] && i != sizee - 1){
            ascending = false;
        }
        if ((myArray[i] < firstElem || myArray[i] > lastElem) && firstElem <= lastElem){
            bounded = false;
        }
        if ((myArray[i] > firstElem || myArray[i] < lastElem ) && firstElem > lastElem){
            bounded = false;
        }

    }


    int bigger;
    if (firstElem >= lastElem){
        bigger = firstElem;
    }
    else{
        bigger = lastElem;
    }
    return bigger;
}


