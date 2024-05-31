#ifndef VARIABLELISTMANAGER_H
#define VARIABLELISTMANAGER_H

#include <vector>
#include "/Users/Brian/Documents/D022b projects and code/Proj 2 D022b/Variable.h"

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

#endif