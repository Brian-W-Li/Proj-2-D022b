/*********************************************************************
* Name: Brian Li
* Week 2: Practice on arrays and C-strings Q2
* Editor(s) used: VScode
* Compiler(s) used: VScode clang++
* Description:
*     This program checks if a c string represents a hexadecimal number
**********************************************************************/
#include <iostream>
using namespace std;



bool isHexadecimal(char *charString, bool&);
bool isHexaChar(char ch);

int main() {
   char userStr[20] = "10x1"; // Input string
   bool prefix = false;
   bool isHex = isHexadecimal(userStr, prefix);
   cout << "Is it a hexadecimal? " << isHex << endl;
   cout << "Is 0x prefix in there? " << prefix << endl;
   
   return 0;
}

//function that takes in a charString pointer and a predefined boolean prefix and returns
//whether the c string starts with 0x and whether it is a proper hexadecimal number.
bool isHexadecimal (char *charString, bool& prefix){
    int i = 0;
    bool isHex = true;
    if (charString[0] == '\0'){
        isHex = false;
    }
    
    while (charString[i] != '\0'){
        if (!isHexaChar(charString[i])){
            isHex = false;
        }
        if ((charString[0] == '0' ) && (i == 1 || i == 2) && (charString[1] == 'x')){
            prefix = true;
            if (isHexaChar(charString[2]) && (i == 2)){
                isHex = true;
            }
        }
        i++;
    }
    return isHex;
}

//Function given to us that checks if a character is a hexadecimal character.
bool isHexaChar(char ch)
{
    return ((ch >= '0') && (ch <= '9')) ||
           ((ch >= 'a') && (ch <= 'f')) ||
           ((ch >= 'A') && (ch <= 'F')) ;
}