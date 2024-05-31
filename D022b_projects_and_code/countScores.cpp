/*********************************************************************
* Name: Brian Li
* Week 2: Write functions Q2
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program takes a count of numbers and returns a boolean value for if half of the values entered
      are greater than 50, and returns an int representing the total minus the max and min.
**********************************************************************/
#include <iostream>

using namespace std;

int countScores(int count, bool &);


int main(){
    int num;
    bool flag = false;
    cin >> num;
    int totalScores = countScores(num, flag);
    cout << "The flag is" << flag << endl;
    cout << "Total scores: " << totalScores << endl;

}

int countScores(int count, bool & flag){
    cout << "Please enter the scores: " << endl;
    double countOver50;
    int currNum;
    int max;
    int min;
    int sum = 0;
    for (int i = 0; i < count; i++){
        cin >> currNum;
        if (currNum > 50){
            countOver50++;
        }
        if(i == 0){
            max = currNum;
            min = currNum;
        }
        if (currNum > max){
            max = currNum;
        }
        if (currNum < min){
            min = currNum;
        }
        sum += currNum;

        
    }
    if (countOver50/count >= .5){
        flag = true;
    }
    return sum - max - min;
}