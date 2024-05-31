/*********************************************************************
* Name: Brian Li
* Week 3 - Practice on 2-dimensional arrays - Q1
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program takes in an array of student scores and computes various 
outputs such as the number of students with 0s, the number of 100s, and the number of students who have at least
3 scores above 50.
**********************************************************************/

#include <iostream>

using namespace std;

int calcStudentScores(int[][4], int&, int&, int);

void printScores(int[][4], int);

/*********************************************************************
* Function: Main
**********************************************************************/
int main( )
{

    const int STUDENTS = 2; //change this value to determine how many students there are in the array
    const int TESTS = 4;
    int testScores[STUDENTS][TESTS];
    int value;


    //Input the array contents yourself through cin
    for (int i = 0; i < STUDENTS; i++){
        cout << "Student " << i << endl;
        for (int j = 0; j < TESTS; j++){
            cin >> value;
            testScores[i][j] = value;
        }
    }
    
    int num3Pass = 0;
    int hundreds = 0;
    int numStudentsWithZeros = calcStudentScores(testScores, num3Pass, hundreds, STUDENTS);

    cout << "num3Pass: " << num3Pass << endl;
    cout << "hundreds: " << hundreds << endl;
    cout << "numStudentsWithZeros: " << numStudentsWithZeros << endl;


    printScores(testScores, STUDENTS);

}


/*********************************************************************
* Function: This program takes in an array of student scores and computes various 
outputs such as the number of students with 0s, the number of 100s, and the number of students who have at least
3 scores above 50.
*
* Parameters:
*   testScores: the 2d array passed into the function
*   num3Pass: an integer passed by reference used to return number of students who have at least 3 scores above 50
*   hundreds: an integer passed by reference used to return number of 100s
    STUDENTS: a constant int that is declared in main dictating the number of students.
* Return: the number of students with 0s.
**********************************************************************/
int calcStudentScores(int testScores[][4], int& num3Pass , int& hundreds, int STUDENTS){
    hundreds = 0;
    num3Pass = 0;
    int numZeros = 0;
    for (int i = 0; i < STUDENTS; i++){
        bool hasZeros = false;
        int tempNumPass = 0;
        for (int j = 0; j < 4; j++){

            if (testScores[i][j] == 100){
                hundreds++;
            }

            if (testScores[i][j] >= 50){
                tempNumPass++;
            }

            if (testScores[i][j] == 0){
                hasZeros = true;
            }
        }
        if (tempNumPass >= 3){
            num3Pass++;
        }
        if (hasZeros){
            numZeros++;
        }
    }
    return numZeros;
}


//testing function to print out the 2d array
void printScores(int testScores[][4], int STUDENTS){
    for (int i = 0; i < STUDENTS; i++){
        cout << "Student " << i << endl;
        for (int j = 0; j < 4; j++){
            cout << testScores[i][j] << ", ";
        }
        cout << endl;
    }
}



