#include <iostream>

using namespace std;

int square(int i){
    return i*i;
}

void printLine(char symbol);

int main(){
    char myChar;

    myChar = '*';
    printLine(myChar);

    myChar = '&';
    printLine(myChar);
    
    return 0;
}

void changeIt(int i){
    i = i + 1;
}

void changeItReally(int &i){
    i = i + 1;
}

void printLine(char symbol){
    for(int i = 1; i <= 20; i++){
        cout << symbol;
    }
    cout << "\t\"hi" << endl << endl;
}
