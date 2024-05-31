/*********************************************************************
* Name: Brian Li
* Week 3 - Practice on 2-dimensional arrays - Q2
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program takes in an array of student scores either as P or N and returns the number of students
with at least 2 passing tests and the number of passing students for each test
**********************************************************************/

#include <iostream>

using namespace std;

int reportOutGrades(char[][4], int[], int);

void printScores(char[][4], int);

/*********************************************************************
* Function: Main
**********************************************************************/
int main( )
{

    const int STUDENTS = 2; //change this value to determine how many students there are in the array
    const int TESTS = 4;
    char testScores[][TESTS] = { {'P', 'P', 'P', 'P'}, {'P', 'N', 'N', 'P'} };
    

    int tests[4] = {0, 0, 0, 0};
    int atLeast2 = reportOutGrades(testScores, tests, STUDENTS);

    cout << "At least two passes: " << atLeast2 << '\t' << "Passing count per test: " 
    << tests[0] << " " << tests[1] << " " << tests[2] << " " << tests[3] << endl;


    printScores(testScores, STUDENTS);

}


/*********************************************************************
* Function: This program takes in an array of student scores and computes various 
outputs such as the number of students with with at least 2 passing tests and the number 
of passing students for each test
*
* Parameters:
*   grades[][4]: the 2d array passed into the function
*   tests[]: an array of 4 integers signifying the 4 tests 
    STUDENTS: a constant int that is declared in main dictating the number of students.
* Return: the number of students with with at least 2 passing tests
**********************************************************************/
int reportOutGrades(char grades[][4], int tests[], int STUDENTS){
    int numAtLeast2 = 0;
    for (int i = 0; i < STUDENTS; i++){
        int has2 = 0;
        for (int j = 0; j < 4; j++){
            if (grades[i][j] == 'P'){
                has2++;
                tests[j]++;
            }
            else if (grades[i][j] != 'N'){
                cout << "Error" << endl;
            }

         }
        if (has2 >= 2){
            numAtLeast2++;
        }
    }
    return numAtLeast2;
}


//testing function to print out the 2d array
void printScores(char testScores[][4], int STUDENTS){
    for (int i = 0; i < STUDENTS; i++){
        cout << "Student " << i << endl;
        for (int j = 0; j < 4; j++){
            cout << testScores[i][j] << ", ";
        }
        cout << endl;
    }
}



