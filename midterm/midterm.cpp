
/******************************************************************************
# Author:           Keegan Good
# Assignment:       Midterm (CS161A)
# Date:             November 5, 2022
# Description:      This program will determine the winner of a rock collecting 
                    competition by determining which of three players collected 
                    the most rocks. The program will prompt for each player’s 
                    name and the number of rocks they collected. It will then 
                    output the first, second, and third place player and the 
                    number of rocks each collected, accounting for ties where 
                    players have equal numbers of rocks. Finally, the program 
                    will output the average number of rocks collected before 
                    exiting.
# Input:            string player1, string player2, string player3
                    int rockCount1, int rockCount2, int rockCount3
# Output:           prompts for names of each player and the amount of rocks
                    they collected. The winning placement of each player
                    and the average number of rocks per player.
#******************************************************************************/




#include <iomanip>
#include <iostream>
using namespace std;

const int NUM_PLAYERS = 3;
const string INVALID_AMOUNT =
    "\nInvalid amount! Zero will be entered instead.";

int main()
{
   string player1 = "";
   string player2 = "";
   string player3 = "";

   int rockCount1 = 0;
   int rockCount2 = 0;
   int rockCount3 = 0;

   int rockTotal = 0;
   double rockAverage = 0.0;

   cout << "\nWelcome to the Rock Collecting Championship!\n";

   cout << "\nPlease enter the name of the first contestant: \n> ";
   getline(cin, player1);

   cout << "How many rocks did " << player1 << " collect? ";
   cin >> rockCount1;

   if (rockCount1 < 0) {
      cout << INVALID_AMOUNT;
      rockCount1 = 0;
   }

   cout << "\nPlease enter the name of the second contestant: \n> ";
   cin.ignore();
   getline(cin, player2);

   cout << "How many rocks did " << player2 << " collect? ";
   cin >> rockCount2;

   if (rockCount2 < 0) {
      cout << INVALID_AMOUNT;
      rockCount2 = 0;
   }

   cout << "\nPlease enter the name of the third contestant: \n> ";
   cin.ignore();
   getline(cin, player3);

   cout << "How many rocks did " << player3 << " collect? ";
   cin >> rockCount3;

   if (rockCount3 < 0) {
      cout << INVALID_AMOUNT;
      rockCount3 = 0;
   }

   cout << endl;

   if ((rockCount1 == rockCount2) && (rockCount2 == rockCount3)) {
      cout << "All contestants are tied with " << rockCount1 << " rock(s).\n";
   }
   else if (rockCount1 == rockCount2) {
      if (rockCount1 > rockCount3) {
         cout << player1 << " and " << player2 << " are tied for first.\n";
         cout << player3 << " is in second place.";
      }
      else {
         cout << player3 << " is in first place. ";
         cout << player1 << " and " << player2
              << " are tied for second place.";
      }
   }
   else if (rockCount2 == rockCount3) {
      if (rockCount2 > rockCount1) {
         cout << player2 << " and " << player3 << " are tied for first.\n";
         cout << player1 << " is in second place.";
      }
      else {
         cout << player2 << " and " << player3
              << " are tied for second place. ";
         cout << player1 << " is in first place. ";
      }
   }
   else if (rockCount1 == rockCount3) {
      if (rockCount1 > rockCount2) {
         cout << player1 << " and " << player3 << " are tied for first.\n";
         cout << player2 << " is in second place.";
      }
      else {
         cout << player1 << " and " << player3
              << " are tied for second place. ";
         cout << player2 << " is in first place. ";
      }
   }

   else if ((rockCount1 > rockCount2) && (rockCount1 > rockCount3)) {
      cout << player1 << " is in first place.\n";
      if (rockCount2 > rockCount3) {
         cout << player2 << " is in second place.\n";
         cout << player3 << " is in third place.\n";
      }
      else {
         cout << player3 << " is in second place.\n";
         cout << player2 << " is in third place.\n";
      }
   }

   else if ((rockCount2 > rockCount1) && (rockCount2 > rockCount3)) {
      cout << player2 << " is in first place.\n";
      if (rockCount1 > rockCount3) {
         cout << player1 << " is in second place.\n";
         cout << player3 << " is in third place.\n";
      }
      else {
         cout << player3 << " is in second place.\n";
         cout << player1 << " is in third place.\n";
      }
   }
   else if ((rockCount3 > rockCount1) && (rockCount3 > rockCount1)) {
      cout << player3 << " is in first place.\n";
      if (rockCount2 > rockCount1) {
         cout << player2 << " is in second place.\n";
         cout << player1 << " is in third place.\n";
      }
      else {
         cout << player1 << " is in second place.\n";
         cout << player2 << " is in third place.\n";
      }
   }

   rockTotal = rockCount1 + rockCount2 + rockCount3;
   rockAverage = static_cast<double>(rockTotal) / NUM_PLAYERS;
   
   cout << fixed << setprecision(2);
   cout << "\n\nThe average number of rocks collected by the top three players is ";
   cout << rockAverage << " rocks!\n";
   
   cout << "\nCongratulations Rock Collectors!";

   cout << endl;

   return 0;
}