/*********************************************************************
* Name: Brian Li
* Project 2: Managing Variable Objects Inside A Vector
* Editor(s) used: VSCode
* Compiler(s) used: g++
* Description:
*     This program is a program that allows the user to assign numbers to variables and list them.
**********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


//This is the variable class. It is the basic building block for our program. Each variable has a string and a name, which are
//stored as private variables. There is no default constructor, but there are some basic setter and getter methods defined here.
class Variable {
    public:
        void SetNameAndValue(std::string newName, int newValue);
        void SetValue(int newValue);
        int GetValue() const;
        std::string GetName() const;
        void PrintNameAndValue();
    private:
        std::string name;
        int value;
};

/*********************************************************************
* Function: Simple setter function for name and value
*
* Parameters:
*   newName: the name we want our variable to have
*   newValue: the value we want our variable to have
* Return: NONE
**********************************************************************/
void Variable::SetNameAndValue(std::string newName, int newValue){
    name = newName;
    value = newValue;
}

/*********************************************************************
* Function: Simple getter function for value
*
* Parameters: NONE
* Return: the value for the variable
**********************************************************************/
int Variable::GetValue() const{
    return value;
}

/*********************************************************************
* Function: Simple getter function for name
*
* Parameters: NONE
* Return: the name for the variable
**********************************************************************/
string Variable::GetName() const{
    return name;
}

/*********************************************************************
* Function: Simple setter function for value
*
* Parameters: int newValue: the value we want the variable to have
* Return: NONE
**********************************************************************/
void Variable::SetValue(int newValue){
    value = newValue;
}

//Simple printing function
void Variable::PrintNameAndValue(){
    cout << name << "(" << value << ")" << endl;
}

//This is the Variable manager class. It uses a private vector of Variable object pointers in its private field.
//I defined a few methods that access and assign integers to the variables.
class VariableListManager {
    public:
        void PrintAll();
        void InputVariable(std::string varName, int varValue);
        //A destructor for the Variables, since they are created with new
        ~VariableListManager(){
            Variable* oneVariable;
            for (int i = 0; i < manyVariables.size(); i++) {
                oneVariable = manyVariables[i];
                delete oneVariable;
            }
        }
        int accessVariable(std::string name, bool& present);
        void assignVariable(std::string name, int toBeAssigned);
        void assignVariable(std::string name, std::string VariableInVector);
    private:
        std::vector<Variable*> manyVariables;
        
        
};

//simple printing function
void VariableListManager::PrintAll(){
    cout << "Printing all variables: " << endl;
    Variable* ourVariable;
    for (int i = 0; i < manyVariables.size(); i++){
        ourVariable = manyVariables[i];
        ourVariable->PrintNameAndValue();
    }
    cout << "Number of variables: " << manyVariables.size() << endl;
}

/*********************************************************************
* Function: Function to add a specific variable to the vector
*
* Parameters: 
string varName: the string that we want to add to the Variable
int varValue: the integer that we want to add to the Variable
* Return: NONE
**********************************************************************/
void VariableListManager::InputVariable(string varName, int varValue){
    Variable* ourVariable;
    ourVariable = new Variable();
    ourVariable->SetNameAndValue(varName, varValue);
    manyVariables.push_back(ourVariable);
}

/*********************************************************************
* Function: The real powerhouse of this program. This function takes in a string name, an identifier for the Variable we want
to access, and returns 0 and false if the variable is not in the vector, and returns what is in the variable and true if the
variable is in the vector
*
* Parameters: string name: the identifier name for the variable
bool& present: a boolean passed by value that will communicate whether the Variable is in the vector
* Return: the value in the variable or 0
**********************************************************************/
int VariableListManager::accessVariable(string name, bool& present){
    present = false;
    int result = 0;
    Variable* ourVariable;
    for (int i = 0; i < manyVariables.size(); i++){
        ourVariable = manyVariables[i];
        if (ourVariable->GetName() == name){
            present = true;
            result = ourVariable->GetValue();
            break;
        }
    }
    return result;
}

/*********************************************************************
* Function: An assignment function for when you are assigning an int to a variable. It takes into account whether the variable is
already defined in the vector or not. If it is, the function simply changes the value in the variable. If it isn't, a new Variable is
created.
*
* Parameters: string name: the identifier for the Variable.
int toBeAssigned: the int to be assigned to that variable.
* Return: NONE
**********************************************************************/
void VariableListManager::assignVariable(string name, int toBeAssigned){
    bool flag = false;
    accessVariable(name, flag);
    if (flag){

        Variable* ourVariable;
        for (int i = 0; i < manyVariables.size(); i++){
            ourVariable = manyVariables[i];
            if (ourVariable->GetName() == name){
                ourVariable->SetValue(toBeAssigned);
                break;
            }
        }
    }
    else {

        InputVariable(name, toBeAssigned);
    }
    cout << name << "(" << toBeAssigned << ")" << endl;
}

/*********************************************************************
* Function: An assignment function for when you are assigning a variable to an variable. It takes into account whether the first and 
the second variable are in the vector. If the second variable isn't 'valid', an error message is returned. If the first variable isn't
defined yet, one is created. If the first variable is defined, the function simply changes the value in the variable.
*
* Parameters: string name: the identifier for the Variable.
string secondVariable: the string on the right side of the equal sign.
* Return: NONE
**********************************************************************/
void VariableListManager::assignVariable(std::string name, string secondVariable){

    bool flag = false;
    int secondValue = accessVariable(secondVariable, flag);
    if (flag){
        accessVariable(name, flag);
        if (flag){

            Variable* ourVariable;
            for (int i = 0; i < manyVariables.size(); i++){
                ourVariable = manyVariables[i];
                if (ourVariable->GetName() == name){
                    ourVariable->SetValue(secondValue);
                    break;
                }
            }
            cout << name << "(" << secondValue << ")" << endl;
        }
        else{

            assignVariable(name, secondValue);
        }

    }
    else{
        cout << "Undefined" << endl;
    }
}

//simple user defined function to check if a string is a number
bool isDigit(string str){
    bool check = true;
    for (int i = 0; i < str.length(); i++)  {
        if (!isdigit(str[i])){
            check = false;
        }
    
  }
  return check;
}

/*********************************************************************
* Function: Main
**********************************************************************/
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
            }


        }
    }
        
        
   return 0;
}

