/******************************************************************************
# Author:           Keegan Good
# Assignment:       A04 (CS161A)
# Date:             October 22, 2022
# Description:      This program will present the user with a pricing menu for
the Washington State Ferries service and allow the user to choose if they’re
bringing a vehicle on the ferry, how many adult, senior and youth tickets they
wish to purchase and how many bicycles they would like to bring. The vehicle
fee includes the price of its driver and also waives the bicycle fee. The user
will receive errors if they enter invalid choices and their total at the end if
their information is valid. If their order total is over $100.00, they will be
eligible for a free adult ticket for their next ride; otherwise, they’ll be
shown how much more they would need to spend in order to qualify for the free
ticket.

# Input:
  - char vehicleChoice (y, Y, n, N)
  - int adultRiders, seniorRiders, youthRiders, numberOfBikes

# Output:
  - Pricing menu
  - final order total
  - free ticket eligibility message
  - various error messages

# Sources: Assignment 4 Document. Zybooks
#******************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

// ticket prices
const double VEHICLE_FEE = 57.90;
const double ADULT_TICKET_PRICE = 14.95;
const double SENIOR_TICKET_PRICE = 7.40;
const double YOUTH_TICKET_PRICE = 5.55;
const double BIKE_FEE = 4.00;

// minimum order total needed to qualify for a free ticket
const double FREE_TICKET_MIN_ORDER = 100.00;

const int MAX_RIDERS = 20;

// define reusable messages as constants
const string INVALID_INPUT
    = "\nError!! Invalid answer!! Please try again later!!!\n";

const string MAX_RIDERS_EXCEEDED = "\nUh oh!! Too many people in your group. "
                                   "Split into 2 groups and try again!\n";

const string EMPTY_GROUP
    = "\nUh oh!! Please add at least one person to your group.\n\n";

const string GOODBYE
    = "\nThank you for using the Washington State Ferries Fare "
      "Calculator!\n";

int main()
{
   double orderTotal = 0.0;
   int totalRiders = 0;
   int adultRiders = 0;
   int seniorRiders = 0;
   int youthRiders = 0;
   int numberOfBikes = 0;

   bool hasVehicle = false;
   char vehicleChoice = ' ';

   // format prices to 2 decimal places
   cout << fixed << setprecision(2);

   cout << "Welcome to the Washington State Ferries Fare Calculator!";

   // display menu
   cout << "\n\nFare Description" << setw(50) << "Ticket $" << endl

        << setfill('-') << setw(38) << '-' << setfill(' ') << setw(21) << '-'
        << setfill('-') << setw(7) << '-' << endl

        << left << setfill(' ')

        << setw(59) << "Vehicle Under 14' (less than 168\") & Driver"
        << "$" << VEHICLE_FEE << endl

        << setw(59) << "Adult (age 19 - 64)"
        << "$" << ADULT_TICKET_PRICE << endl

        << setw(59) << "Senior (age 65 and over) / Disability"
        << "$" << SENIOR_TICKET_PRICE << endl

        << setw(59) << "Youth (age 6 - 18)"
        << "$" << YOUTH_TICKET_PRICE << endl

        << setw(59) << "Bicycle Surcharge (included with Vehicle)"
        << "$" << BIKE_FEE;

   // start collecting user input
   cout << "\n\nAre you riding a vehicle on the Ferry (Y/N): ";
   cin >> vehicleChoice;

   // the following conditionals have an exceptional amount of
   // repetition and should be simplified using a loop and/or a function
   if (vehicleChoice == 'y' || vehicleChoice == 'Y') {
      hasVehicle = true;
      orderTotal += VEHICLE_FEE;
   }
   else if (vehicleChoice != 'n' && vehicleChoice != 'N') {
      cout << INVALID_INPUT << GOODBYE;
      return 0;
   }

   cout << "\nHow many adults? ";
   cin >> adultRiders;

   if (adultRiders >= 0) {
      totalRiders += adultRiders;
      orderTotal += (adultRiders * ADULT_TICKET_PRICE);
   }
   else {
      cout << INVALID_INPUT << GOODBYE;
      return 0;
   }

   cout << "How many seniors? ";
   cin >> seniorRiders;

   if (seniorRiders >= 0) {
      totalRiders += seniorRiders;
      orderTotal += (seniorRiders * SENIOR_TICKET_PRICE);
   }
   else {
      cout << INVALID_INPUT << GOODBYE;
      return 0;
   }

   cout << "How many youth? ";
   cin >> youthRiders;

   if (youthRiders >= 0) {
      totalRiders += youthRiders;
      orderTotal += (youthRiders * YOUTH_TICKET_PRICE);
   }
   else {
      cout << INVALID_INPUT << GOODBYE;
      return 0;
   }

   if (totalRiders <= 0) {
      cout << EMPTY_GROUP << GOODBYE;
      return 0;
   }

   if (!hasVehicle) {
      cout << "How many bikes? ";
      cin >> numberOfBikes;

      if (numberOfBikes >= 0) {
         orderTotal += (numberOfBikes * BIKE_FEE);
      }
      else {
         cout << INVALID_INPUT << GOODBYE;
         return 0;
      }
   }

   if (totalRiders > MAX_RIDERS) {
      cout << MAX_RIDERS_EXCEEDED << GOODBYE;
      return 0;
   }

   // display results
   cout << "\nYour total charge is $" << orderTotal << ".\n";

   if (orderTotal > 100) {
      cout << "\nAs a gift for spending more than $100.00, you've "
           << "earned a free adult ticket on your next purchase!\n";
   }
   else if (orderTotal == 100) {
      cout << "\nIf you spend more than $100.00, you'll be "
           << "eligible for a free adult ticket for your next trip!\n";
   }
   else {
      cout << "\nIf you spend $" << (100 - orderTotal) << " more, your are "
           << "eligible for a free adult ticket for your next trip.\n";
   }

   cout << GOODBYE;

   return 0;
}