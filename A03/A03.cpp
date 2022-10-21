#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to the Oreo sugar calculator!\n";

  const int GRAMS_SUGAR_PER_COOKIE = 14;
  const int COOKIES_PER_SERVING = 5;
  int cookiesEaten = 0;
  int gramsSugar = 0;
  double totalServings = 0.0;

  cout << "Please enter the number of cookies you've eaten:\n";
  cin >> cookiesEaten;

  totalServings = static_cast<double>(cookiesEaten) / COOKIES_PER_SERVING;
  gramsSugar = cookiesEaten * GRAMS_SUGAR_PER_COOKIE;

  cout << cookiesEaten << " cookies is " << gramsSugar;
  cout << " grams of sugar and ";
  cout << fixed << setprecision(1) << totalServings << " servings.\n\n";

  cout << "Thanks for enjoying Oreos!" << endl;

  return 0;
}