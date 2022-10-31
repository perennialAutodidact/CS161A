/******************************************************************************
# Author:           Keegan Good
# Assignment:       A04 (CS161A)
# Date:             October 22, 2022
# Description:      This program will break a user-entered email address
                    into its constituent parts: username and domain.
                    If the email address is missing an '@' symbol, an
                    error will be displayed instead.

# Input:            emailAddress as string

# Output:           username as string, domain as string


# Sources: Assignment 4 Document. Zybooks
#******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
   string emailAddress = "abc@def.com";
   size_t atSignIndex = string::npos;
   string username = "";
   string domain = "";

   cout << "Welcome to the Email Address Breakdown program!\n";
   cout << "\nEnter an email address: ";
   cin >> emailAddress;

   atSignIndex = emailAddress.find('@');

   cout << "\nYou entered: " << emailAddress << endl;

   if (atSignIndex != string::npos) {
      username = emailAddress.substr(0, atSignIndex);
      domain = emailAddress.substr(atSignIndex + 1, emailAddress.length());
      cout << "Username: " << username << endl;
      cout << "Domain Name: " << domain << endl;
   }
   else {
      cout << "\nThis is missing the \"@\" sign. Please check and try again "
              "later.\n";
   }

   cout << "\nThank you for using the Email Address Breakdown program!\n";
}