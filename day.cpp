#include <iostream>
#include <ctime>

using namespace std;

int dayOfWeek(int year, int month, int day)
{
  tm t = {0, 0, 0, day, month - 1, year - 1900};
  mktime(&t);
  return t.tm_wday == 0 ? 7 : t.tm_wday;
}

int main()
{
  switch (dayOfWeek(1992, 5, 31))
  {
    case 1: cout << "Monday"    << endl; break;
    case 2: cout << "Tuesday"   << endl; break;
    case 3: cout << "Wednesday" << endl; break;
    case 4: cout << "Thursday"  << endl; break;
    case 5: cout << "Friday"    << endl; break;
    case 6: cout << "Saturday"  << endl; break;
    case 7: cout << "Sunday"    << endl; break;
  }

  return 0;
}
