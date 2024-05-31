#include <iostream>
#include <sstream>
#include "/Users/Brian/Documents/D022b projects and code/Proj 2 D022b/VariableListManager.h"
using namespace std;

bool isDigit(string str){
    bool check = true;
    for (int i = 0; i < str.length(); i++)  {
        if (!isdigit(str[i])){
            check = false;
        }
    
  }
  return check;
}


int main() {
    VariableListManager listManager;
    istringstream inSS;
    bool flag = true;


    while (flag){
        cout << "Please enter variable assignment, variable name only or list or exit:" << endl;
        string entireLine;
        string input1;
        getline(cin, entireLine);
        inSS.clear();
        inSS.str(entireLine);

        inSS >> input1;
        if (isdigit(input1[0])){
            cout << "Invalid variable name. Cannot start with a digit." << endl;
        }
        else if (inSS.bad() || input1 == "exit"){
            flag = false;
            cout << "Exiting...." << endl;
        }
        else if (input1 == "list"){
            listManager.PrintAll();
        }
        else if (inSS.eof()){
            bool flag;
            int intInVariable = listManager.accessVariable(input1, flag);
            if (flag){
                cout << input1 << "(" << intInVariable << ")" << endl;
            }
            else {
                cout << "Undefined" << endl;
            }
            

        }
        else {
            string input2;
            inSS >> input2;
            if (input2 == "="){
                string input3;
                inSS >> input3;
                if (isDigit(input3)){
                    listManager.assignVariable(input1, stoi(input3));
                }
                else{
                    listManager.assignVariable(input1, input3);
                }
            }
            else {
                cout << "Error, needs equals operator" << endl;
                //cout << endl;
            }


        }
    }
        
        
   return 0;
}

