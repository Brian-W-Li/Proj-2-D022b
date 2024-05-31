/*********************************************************************
* Name: Brian Li
* Week 2: Write functions Q1
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program has to user enter a key and asks the user to 
      re-enter this key 3 times before the key is reset.
**********************************************************************/
#include <iostream>

using namespace std;

// Declaring function prototypes.
int readSecretKey(int &keyValue);

/*********************************************************************
* Function: Main
**********************************************************************/
int main(){
    int key = 0;
    int numTries = readSecretKey(key);
    cout << "The key is " << key << endl;
    cout << "Number of tries: " << numTries << endl;

}


/*********************************************************************
* Function: Takes in a keyValue reference that changes the keyValue in main, and returns number of tries.
*
* Parameters:
*   int reference keyValue so that the keyValue can change and affect main.
* Return: int for number of tries.
**********************************************************************/
int readSecretKey(int &keyValue){
    int count = 0;
    cout << "Please enter the key:" << endl;
    cin >> keyValue;
    int guess = keyValue - 1;
    while (keyValue != guess){
        if (count == 3){
            keyValue = 0;
            break;
        }
        if (keyValue != guess && count != 0){
            cout << "Unmatched. " << endl;
        }
        cout << "Please re-enter the key:" << endl;
        cin >> guess;
        count++;
    }

    
    return count;

}