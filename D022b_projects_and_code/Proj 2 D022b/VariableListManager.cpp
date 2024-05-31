#include <iostream>
#include "/Users/Brian/Documents/D022b projects and code/Proj 2 D022b/VariableListManager.h"
using namespace std;

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



