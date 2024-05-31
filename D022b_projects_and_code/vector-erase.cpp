#include <iostream>
#include <vector>
using namespace std;

/*
ZyBook: Figure 7.16.2: Using the vector erase() function.
*/

// Adds playerNum to end of vector
void PlayersAdd(vector<int>& players, int playerNum) {
   players.push_back(playerNum);
}

void PlayersPrint(const vector<int>& players) {
   unsigned int i;

   for (i = 0; i < players.size(); ++i) {
      cout << " " << players.at(i) << endl;
   }
}

// Deletes playerNum from vector
void PlayersDelete(vector<int>& players, int playerNum) {
   unsigned int i = 0;
   bool found = false;

   // Search for playerNum in vector
   while (!found && (i < players.size())) {
      if (players.at(i) == playerNum) {
         // Note: the position is NOT an integer.  It's iterator.  We pass in
         // the iterator pointing the beginning and add 'i' to it.
         players.erase(players.begin() + i); // Delete
         found = true;
      }
      ++i;
   }
}

// Maintains vector of player numbers
int main() {
   vector<int> players;
   int playerNum;
   char userKey;

   userKey = '?';

   cout << "Commands: 'a' add, 'p' print, 'd' del" << endl;
   cout << "   'q' quits" << endl;
   while (userKey != 'q') {
      cout << "Command: ";
      cin  >> userKey;
      if (userKey == 'a') {
         cout << " Player number: ";
         cin  >> playerNum;
         PlayersAdd(players, playerNum);
      }
      else if (userKey == 'p') {
         PlayersPrint(players);
      }
      else if (userKey == 'd') {
         cout << " Player number: ";
         cin  >> playerNum;
         PlayersDelete(players, playerNum);
      }
   }

   // Erase all elements
   players.clear();

   cout << "After clear(), players.size = " << players.size() << endl;

   return 0;
}
