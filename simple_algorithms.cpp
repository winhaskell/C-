#include <iostream>

using namespace std;

//--- Factorial ---//

// The factorial of a number "n" is the product of the numbers from 1 to "n":
// 5! = 1 * 2 * 3 * 4 * 5 = 120

int factorial1(int n)
{
  int f = 1;

  for (int i = 1; i <= n; ++i)
    f *= i; // Same as f = f * i;

  return f;
}

int factorial2(int n)
{
  if (n == 0)
    return 1;

  return n * factorial2(n - 1);
}

//--- Fibonacci ---//

// The Fibonacci sequence starts from 1, 1 and the next element of the list is
// the sum of the previous two:
// 1, 1, 2, 3, 5, 8, 13, 21, ...

int fibonacci1(int n)
{
  if (n <= 1)
    return 1;

  return fibonacci1(n - 2) + fibonacci1(n - 1);
}

int fibonacci2(int n)
{
  int a = 0;
  int b = 1;
  int t;

  for (int i = 0; i < n; ++i)
  {
    t = a + b;
    a = b;
    b = t;
  }

  return b;
}

//--- Greatest common divisor ---//

// The greatest common divisor of "a" and "b" is the greatest number which
// divides both "a" and "b".

int gcd1(int a, int b)
{
  int smaller;

  if (a < b)
    smaller = a;
  else
    smaller = b;

  // Same as:
  // int smaller = a < b ? a : b;

  while (a % smaller != 0 || b % smaller != 0)
    --smaller;

  return smaller;
}

int gcd2(int a, int b)
{
  while (a != b)
    if (a > b)
      a -= b; // Same as: a = a - b;
    else
      b -= a; // Same as: b = b - a;

  return a;
}

int gcd3(int a, int b)
{
  if (a == b)
    return a;

  if (a > b)
    return gcd3(a - b, b);
  else
    return gcd3(a, b - a);

  // Same as:
  // return a > b ? gcd3(a - b, b) : gcd3(a, b - a);
}

//--- Collatz sequence ---//

// The Collatz sequence can start from any integer. The next element is the half
// of this integer if it is even, otherwise 3 times the integer plus 1:
//
// Suppose that the sequence starts from 3:
// 3 is odd   -> next element is 3 * 3 + 1 = 10
// 10 is even -> next element is 10 / 2 = 5
// 5 is odd   -> next element is 5 * 3 + 1 = 16
// 16 is even -> next element is 16 / 2 = 8
// 8 is even  -> next element is 8 / 2 = 4
// 4 is even  -> next element is 4 / 2 = 2
// 2 is even  -> next element is 2 / 1 = 1
//
// So the sequence starting from 3 is 3, 10, 5, 16, 8, 5, 2, 1.
//
// The mathematicians have not proven that the sequence always reaches 1,
// however this statement seems to be true.
//
// This function computes the length of the Collatz sequence starting from a
// given number.

int collatz(int n)
{
  int counter = 1;

  while (n != 1)
  {
    if (n % 2 == 0)
      n /= 2; // Same as n = n / 2;
    else
      n = n * 3 + 1;

    // Same as:
    // n = n % 2 == 0 ? n / 2 : n * 3 + 1;

    ++counter;
  }

   return counter;
}

int sum(int array[], int size)
{
  int s = 0;

  for (int i = 0; i < size; ++i)
    s += array[i];

  return s;
}

void fill_array(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    array[i] = i + 1;

  // for (int i = 0; i < size; ++i)
  //   *(array + i) = i + 1;
}

int main()
{
  cout << "Factorial 1:" << endl;

  for (int i = 0; i < 10; ++i)
    cout << i << " -> " << factorial1(i) << endl;

  cout << "Factorial 2:" << endl;

  for (int i = 0; i < 10; ++i)
    cout << i << " -> " << factorial2(i) << endl;

  cout << "Fibonacci 1:" << endl;

  for (int i = 0; i < 10; ++i)
    cout << i << " -> " << fibonacci1(i) << endl;

  cout << "Fibonacci 2:" << endl;

  for (int i = 0; i < 10; ++i)
    cout << i << " -> " << fibonacci2(i) << endl;

  cout << "Greatest common divisor 1:" << endl;

  cout << "gcd1(54, 24) = " << gcd1(54, 24) << endl;
  cout << "gcd2(54, 24) = " << gcd2(54, 24) << endl;
  cout << "gcd3(54, 24) = " << gcd3(54, 24) << endl;

  cout << "Collatz" << endl;

  for (int i = 1; i <= 10; ++i)
    cout << i << " -> " << collatz(i) << endl;

  cout << "Sum" << endl;

  const int size = 10;
  int t[size];

  fill_array(t, size);
  cout << "sum(t, 10) = " << sum(t, size) << endl;

  return 0;
}
