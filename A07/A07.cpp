/******************************************************************************
# Author:           Keegan Good
# Assignment:       A07 (CS161A)
# Date:             November 20, 2022
# Description:      This program is an online ordering system for a coffee
                    shop. It will continuously print a menu of options for
                    the user to choose from and when they are done it will
                    prompt for a tip amount and print the total pay amount.

# Input:            char choice, char subChoice, double tip

# Output:           double subTotal, double tipAmount, double orderTotal

# Sources:          Assignment 4 Document. Zybooks
#******************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

const string WELCOME_MESSAGE = "Welcome to Bean Dreams Coffee Shop!\n";

const double PRICE_AMERICANO = 2.25;
const double PRICE_CAPPUCCINO = 3.25;
const double PRICE_MOCHA = 4.25;

const double PRICE_GREEN_TEA = 1.33;
const double PRICE_OOLONG = 1.66;
const double PRICE_SPICED_CHAI = 2.33;

const double PRICE_MUFFIN = 1.99;
const double PRICE_BAGEL = 2.99;
const double PRICE_OMELETTE = 6.99;

const char COFFEE = '1';
const char TEA = '2';
const char FOOD = '3';
const char EXIT = '4';

const char AMERICANO = '1';
const char CAPPUCCINO = '2';
const char MOCHA = '3';

const char GREEN_TEA = '1';
const char OOLONG = '2';
const char SPICED_CHAI = '3';

const char MUFFIN = '1';
const char BAGEL = '2';
const char OMELETTE = '3';

int main()
{

   double subTotal = 0.0;
   double orderTotal = 0.0;
   double tipAmount = 0.0;
   char choice = ' ';
   char subChoice = ' ';

   cout << fixed << setprecision(2);

   cout << WELCOME_MESSAGE;

   do {
      // display menu
      cout << "\nPlease choose an option:\n"

           << setfill('-') << setw(23) << '-' << endl

           << "1. Coffee\n"
           << "2. Tea\n"
           << "3. Food\n"
           << "4. Exit\n";

      cout << "\nPlease enter the number of your selection:\n> ";
      cin >> choice;

      while (choice < '1' || choice > '4') {
         cout << "\nInvalid selection! Please try again!\n> ";
         cin >> choice;
      }

      switch (choice) {
      case COFFEE:
         cout << "\nWhat kind of coffee would you like?\n"
              << "1. Americano\n"
              << "2. Cappuccino\n"
              << "3. Mocha\n";

         cout << "\nPlease enter the number of your selection:\n> ";
         cin >> subChoice;
         while (subChoice < '1' || subChoice > '3') {
            cout << "\nInvalid selection! Please try again!\n> ";
            cin >> subChoice;
         }

         switch (subChoice) {
         case AMERICANO:
            cout << "\nAmericano added.";
            subTotal += PRICE_AMERICANO;
            break;
         case CAPPUCCINO:
            cout << "\nCappuccino added.";
            subTotal += PRICE_CAPPUCCINO;
            break;
         case MOCHA:
            cout << "\nMocha added.";
            subTotal += PRICE_MOCHA;
            break;
         }

         break;
      case TEA:
         cout << "\nWhat kind of tea would you like?\n"
              << "1. Green Tea\n"
              << "2. Oolong\n"
              << "3. Spiced Chai\n";

         cout << "\nPlease enter the number of your selection:\n> ";
         cin >> subChoice;
         while (subChoice < '1' || subChoice > '3') {
            cout << "\nInvalid selection! Please try again!\n> ";
            cin >> subChoice;
         }

         switch (subChoice) {
         case GREEN_TEA:
            cout << "\nGreen tea added.";
            subTotal += PRICE_GREEN_TEA;
            break;
         case OOLONG:
            cout << "\nOolong added.";
            subTotal += PRICE_OOLONG;
            break;
         case SPICED_CHAI:
            cout << "\nSpiced chai added.";
            subTotal += PRICE_SPICED_CHAI;
            break;
         }

         break;
      case FOOD:
         cout << "\nWhat kind of food would you like?\n"
              << "1. Muffin\n"
              << "2. Bagel with Cream Cheese\n"
              << "3. Omelette\n";

         cout << "\nPlease enter the number of your selection:\n> ";
         cin >> subChoice;
         while (subChoice < '1' || subChoice > '3') {
            cout << "\nInvalid selection! Please try again!\n> ";
            cin >> subChoice;
         }

         switch (subChoice) {
         case MUFFIN:
            cout << "\nMuffin added.";
            subTotal += PRICE_MUFFIN;
            break;
         case BAGEL:
            cout << "\nBagel with cream cheese added.";
            subTotal += PRICE_BAGEL;
            break;
         case OMELETTE:
            cout << "\nOmelette added.";
            subTotal += PRICE_OMELETTE;
            break;
         }

         break;
      default:
         break;
      }

      cout << "\n\nSubtotal: $" << subTotal << endl;
   } while (choice != EXIT);

   cout << "\nPlease add a tip. Suggested tip amounts:\n"
        << "15% = $" << subTotal * 0.15 << endl
        << "20% = $" << subTotal * 0.20 << endl
        << "25% = $" << subTotal * 0.25 << endl;

   cout << "\nPlease enter tip amount:\n> $";
   cin >> tipAmount;

   orderTotal = subTotal + tipAmount;

   cout << left << setfill(' ') << setw(14) << "\nSubtotal"
        << "$" << subTotal << left << setw(14) << "\nTip"
        << "$" << tipAmount << endl
        << left << setfill('-') << setw(20) << "-" << left << setfill(' ')
        << setw(14) << "\nGrand Total"
        << "$" << orderTotal

        << "\n\nThanks for your patronage!\n\n";

   return 0;
}