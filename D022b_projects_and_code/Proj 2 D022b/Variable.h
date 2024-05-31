#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>



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

#endif