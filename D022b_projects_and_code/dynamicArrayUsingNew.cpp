#include <fstream>
// dynamicArrayUsingNew.cpp

#include <iostream>
using namespace std;

int main()
{
  ifstream fin;
  fin.open("scores.txt");
  if (!fin.good()) throw "I/O error";

  // create array of user-specified size
  int size;
  fin >> size; // first line in TXT file
  cout << "size = " << size << endl;
  fin.ignore(1000, 10);
  //int score[size];
  int *score = new int[size];

  // read and save the scores
  int i;
  for (i = 0; i < size; i++)
  {
    fin >> score[i]; // remaining lines in TXT file
    fin.ignore(50, '\n');
  } // for
  fin.close();

  // output the scores to the console
  for (i = 0; i < size; i++)
    cout << score[i] << ' ';
  cout << endl;

} // main
