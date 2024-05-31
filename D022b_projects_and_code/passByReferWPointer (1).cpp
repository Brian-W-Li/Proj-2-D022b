#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <string>
using std::string;

#include <cstdlib> // for stoi

int gatherInput(int [], int);
void getStatistics(int [], int, double*, int*, int*); // using last 3 parameters for output

int main( )
{
  const int CAPACITY = 100; // does not mean we'll actually enter that many!
  int scores[CAPACITY]; // ...but there's space for that many.
  int totalScoresEntered = gatherInput(scores, CAPACITY);

  //CAPACITY = 200;  // compiling error becase of 'const'

  double averageScore; // uninitialized, to be used for output from the function
  int maximumScore, minimumScore; // same here...
  getStatistics(scores, totalScoresEntered, &averageScore, &maximumScore, &minimumScore);

  cout.setf(ios::fixed);
  cout.precision(1); // round to nearest tenth of a point
  cout << "The average of " << totalScoresEntered << " test scores is " << averageScore << " out of 100.\n";
  cout << "The range of scores is " << minimumScore << " to " << maximumScore << ".\n";
}

int gatherInput(int theArray[], int capacity)
{
  int result = 0; // track number of scores entered

  // gather input from the user
  string buf; // for cin input string buffer
  for (int i = 0; i < capacity; i++)
  {
    cout << "Enter a score [0-100, or Q to quit]: ";
    cin >> buf; // may be a number or Q
    if (buf == "q" || buf == "Q") break; // user elects to quit
    theArray[i] = stoi(buf); // if non-numeric, an exception is thrown
    result++; // not result = result++, EVER!
  }
  return result;
}

// a generic statistics function -- scores, temperatures, etc...
void getStatistics(int a[], int n, double *pAverage, int* pMaximum, int* pMinimum)
{
  int sum = a[0]; // add up all scores here, and divide by n
  int max = a[0]; // as far as we know, the zeroth score is the max
  int min = a[0]; // as far as we know, the zeroth score is the min, too
  for (int i = 1; i < n; i++) // a[0] already included, so start at 1
  {
    sum += a[i];
    if (a[i] < min) min = a[i];
    if (max < a[i]) max = a[i];
  }
  *pAverage = 1.0 * sum / n; // "1.0" so result will be floating point
  *pMaximum = max; // copy max into the location pointed to by pMaximum (where main's maximumScore is)
  *pMinimum = min; // copy min into the location pointed to by pMinimum (where main's minimumScore is)
}
