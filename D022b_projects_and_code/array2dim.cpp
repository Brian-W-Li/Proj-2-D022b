#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring> // need it for strcpy

#include <cstdlib> // for atoi

const int STUDENTS = 3;
const int TESTS = 2;

void printScores(int testScores[][2]); // must speficfy 2nd dimension

int main( )
{

  int testScores[STUDENTS][TESTS];

  // loop to enter all test scores
  string buf; // input buffer
  for (int col = 0; col < TESTS; col++)
  {
    cout << "\nEnter scores for exam #" << (col + 1) << '\n';
    for (int row = 0; row < STUDENTS; row++)
    {
      cout << " Enter score for student #" << (row + 1) << endl;
      cin >> buf; testScores[row][col] = atoi(buf.c_str( ));
    }
  }

  // output in a nicely-formatted table
  cout << "\nStudent#  exam#1  exam#2  \n";
  cout << "--------  ------  ------   \n";
  for (int row = 0; row < STUDENTS; row++)
  {
    cout.width(5);
    cout << (row + 1);
    for (int col = 0; col < TESTS; col++)
    {
      cout.width(8);
      cout << testScores[row][col];
    }
    cout << endl;
  }

  // Calling function to print scores
  printScores(testScores);

}

void printScores(int testScores[][2])
{
  cout << "\n----- printScores function: \n";
  cout << "\nStudent#  exam#1  exam#2  \n";
  cout << "--------   ------  ------   \n";
  for (int row = 0; row < STUDENTS; row++)
  {
    cout.width(5);
    cout << (row + 1);
    for (int col = 0; col < TESTS; col++)
    {
      cout.width(8);
      cout << testScores[row][col];
    }
    cout << endl;
  }
}
