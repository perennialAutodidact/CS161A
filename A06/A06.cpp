/******************************************************************************
# Author:           Keegan Good
# Assignment:       A06 (CS161A)
# Date:             November 14, 2022
# Description:      This program will estimate the number of jelly beans
                    that can fit in a jar. The user will be prompted for
                    the width and length of one jelly bean as well as the
                    volume of the jar and the program will tell them how
                    many jelly beans could fit in the jar. The program will
                    repeat until the user decides to exit and will display
                    the total number of entries, the average number of jelly
                    beans per entry, the largest jelly bean and the jar size
                    for the largest jelly bean estimation.

# Input:            double jellyBeanHeight, double jellyBeanLength
                    double jellyBeanVol, int jarVolume, char userInput
                    const float LOAD_FACTOR = 0.698

# Output:           int jellyBeanTotal, int totalEntries, int jellyBeanAvg,
                    double jellyBeanVolLargest, int jarSizeLargestEstimate

# Sources: Assignment 4 Document. Zybooks
#******************************************************************************/

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

const float LOAD_FACTOR = 0.698;
const double PI = M_PI;

int main()
{
   int jarVolume = 0;
   int jellyBeanTotal = 0;
   int totalEntries = 1;
   int jellyBeanLargestTotal = 0;
   int jarVolLargestEstimate = 0;

   double jellyBeanHeight = 0.0;
   double jellyBeanLength = 0.0;
   double jellyBeanVol = 0.0;
   double jellyBeanAvg = 0.0;
   double jellyBeanSum = 0.0;
   double jellyBeanVolLargest = 0.0;

   bool shouldContinue = true;
   char userInput = 'y';

   cout << endl
        << setw(55) << setfill('*') << '\n'
        << "\nWelcome to the Jar of Jelly Beans Estimator!\n\n"
        << setw(55) << setfill('*') << '\n';

   do {
      cout << "\nEnter the length and width of one jelly bean in centimeters, "
              "separated by a space:\n> ";
      cin >> jellyBeanLength >> jellyBeanHeight;

      cout << "\nEnter the volume of the jar (mL):\n> ";
      cin >> jarVolume;

      // calculate the volume of the current jelly bean
      jellyBeanVol
          = (5 * PI * (jellyBeanLength * pow(jellyBeanHeight, 2))) / 24;

      // calculate the number of jelly beans that could fit in the jar
      jellyBeanTotal = jarVolume * LOAD_FACTOR / jellyBeanVol;

      // update running jelly bean count
      jellyBeanSum += jellyBeanTotal;

      // update the largest jellybean if appropriate
      if (jellyBeanVol > jellyBeanVolLargest) {
         jellyBeanVolLargest = jellyBeanVol;
      }

      cout << "\nApproximately " << jellyBeanTotal
           << " jelly beans could fit in a jar with a volume of " << jarVolume
           << " mL." << endl;

      // ask they user if they want to loop again
      cout << "\nDo you want to estimate again? y/n:\n> ";
      cin >> userInput;

      // ensure the user enters either 'y' or 'n'
      userInput = tolower(userInput);
      while (userInput != 'y' && userInput != 'n') {
         cout << "\nInvalid selection! Please enter 'y' or 'n'.\n> ";
         cin >> userInput;
      };

      if (userInput == 'y') {
         cout << "\nOkay, let's continue!\n";
         ++totalEntries;

         // check if the total is larger than the largest total
         if (jellyBeanTotal > jellyBeanLargestTotal) {
            jellyBeanLargestTotal = jellyBeanTotal;
            jarVolLargestEstimate = jarVolume;
         }
      }
      else if (userInput == 'n') {
         shouldContinue = false;
         jellyBeanAvg = static_cast<double>(jellyBeanSum) / totalEntries;
      }
   } while (shouldContinue);

   // display final values
   cout << fixed << setprecision(2);
   cout << "\nNumber of entries: " << totalEntries << endl;
   cout << "Average number of jelly beans: " << jellyBeanAvg << endl;
   cout << "Largest jelly bean: " << jellyBeanVolLargest << " cm^3" << endl;
   cout << "Jar size for largest jelly bean estimate: "
        << jarVolLargestEstimate << " mL.\n\n";

   return 0;
}