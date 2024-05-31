#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


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

void Variable::SetNameAndValue(std::string newName, int newValue){
    name = newName;
    value = newValue;
}

int Variable::GetValue() const{
    return value;
}

string Variable::GetName() const{
    return name;
}

void Variable::SetValue(int newValue){
    value = newValue;
}

void Variable::PrintNameAndValue(){
    cout << name << "(" << value << ")" << endl;
}

class VariableListManager {
    public:
        void PrintAll();
        void InputVariable(std::string varName, int varValue);
        virtual ~VariableListManager(){
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

void VariableListManager::PrintAll(){
    cout << "Printing all variables: " << endl;
    Variable* ourVariable;
    for (int i = 0; i < manyVariables.size(); i++){
        ourVariable = manyVariables[i];
        ourVariable->PrintNameAndValue();
    }
    cout << "Number of variables: " << manyVariables.size() << endl;
}

void VariableListManager::InputVariable(string varName, int varValue){
    Variable* ourVariable;
    ourVariable = new Variable();
    ourVariable->SetNameAndValue(varName, varValue);
    manyVariables.push_back(ourVariable);
}

//if the variable isn't there, present will be false. The return value cannot be trusted.
//if the variable is there, present will be true, and the return value can be trusted
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

void VariableListManager::assignVariable(string name, int toBeAssigned){
    bool flag = false;
    accessVariable(name, flag);
    if (flag){
        //go into manyVariables and change that variable
        //there is an element in manyvariables with that name
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
        //flag is false, so there is not value to that name yet.
        InputVariable(name, toBeAssigned);
    }
    cout << name << "(" << toBeAssigned << ")" << endl;
}

void VariableListManager::assignVariable(std::string name, string secondVariable){
    //here, we are using <var name> = <another var name>
    //so, first check if another var name is a valid name.
    //if its not, print undefined
    //if it is, call accessVariable to return the int
    //and assign it to the variable in question.

    bool flag = false;
    int secondValue = accessVariable(secondVariable, flag);
    if (flag){
        accessVariable(name, flag);
        if (flag){
            //if the first variable is good too,
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
            //here, the first variable isn't initiated yet
            assignVariable(name, secondValue);
        }

    }
    else{
        cout << "Undefined" << endl;
    }
}

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
            }


        }
    }
        
        
   return 0;
}

