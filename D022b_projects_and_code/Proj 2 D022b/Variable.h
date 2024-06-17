#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>



class Variable {
    public:
        void SetNameAndValue(std::string newName, int newValue);
        virtual void SetValue(int newValue);
        int GetValue() const;
        std::string GetName() const;
        void PrintNameAndValue();
    private:
        std::string name;
        int value;
};

class Constant : public Variable {
public:
    void SetValue(int newValue) override{
        cout << "Cannot change constant value" << endl;
    }
};

#endif