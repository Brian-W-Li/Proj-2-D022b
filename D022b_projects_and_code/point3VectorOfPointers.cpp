#include <iostream>
using namespace std;

#include <vector>
using std::vector;


class Point {
public:
   Point(double xValue = 0, double yValue = 0);
   void Print();

   double X;
   double Y;
};

Point:: Point(double xValue, double yValue) {
   X = xValue;
   Y = yValue;
}

void Point::Print() {
   cout << "(" << X << ", ";
   cout << Y << ")" << endl;
}

int main() {
   // Allocate dynamic array of Points
   int i;
   int pointCount = 4;
   vector<Point*> manyPoints;
   vector<Point>  nPoints;
   Point *onePoint;

   // Create Points and save into vector
   for (i = 0; i < pointCount; i++) {
       onePoint = new Point(i, i*2);
       manyPoints.push_back(onePoint);
   }

   // Display Points
   cout << "Display points in vector \n";
   for (i = 0; i < pointCount; i++) {
       onePoint = manyPoints[i];
       onePoint->Print();
       delete onePoint;
   }


   return 0;
}
