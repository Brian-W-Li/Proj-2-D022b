#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> dataVect;
   int value;
   int i;

   dataVect.push_back(12);
   dataVect.push_back(1);
   dataVect.push_back(-2);
   dataVect.push_back(10);
   dataVect.push_back(-1);



   int lastElem = dataVect.at(dataVect.size() - 2);
   for (int i = 0; i < dataVect.size() - 1; i++){
      if (dataVect.at(i) > lastElem){
         cout << "MISSED" << endl;
      }
      else{
         cout << dataVect.at(i) << endl;
      }
   }
   

   return 0;
}