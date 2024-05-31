#include <iostream>
#include <iomanip>
using namespace std;

struct di{
    int woo;
    double wooo;
};

const double pi = 3.14;
double ComputeAverage(int numCount){
    int valuesSum = 0;
    int currValue = 0;

    for (int i = 0; i < numCount; i++){
        cout << "Enter number: ";
        cin >> currValue;
        valuesSum += currValue;
    }
    return valuesSum / numCount;
}

double ComputeArea(double r, double PI = pi){
    return PI*r*r;
}

int main(){
    int numValues;
    double averageVal;

    cout << "Enter number of values: ";
    cin >> numValues;
    averageVal = ComputeAverage(numValues);

    cout << "Average: ";
    cout << fixed << std::setprecision(3) << averageVal << endl;
    cout << fixed << setprecision(2) << ComputeArea(1,3) << endl;

    di structEx;
    structEx.woo = 1;
    cout << structEx.woo << endl;
}