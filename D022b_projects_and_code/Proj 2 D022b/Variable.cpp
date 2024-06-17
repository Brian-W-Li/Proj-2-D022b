#include "/Users/Brian/Documents/D022b projects and code/Proj 2 D022b/Variable.h"
#include "Variable.h"


using namespace std;

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

