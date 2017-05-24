#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // Mark 2
  // ------
  // Create a function which generates a vector of integers with a given size.
  // The elements can be read from the user or from file or even random numbers
  // can be used.
  // Create a function which returns whether the given vector contains the
  // given value.

  vector<int> v1 = generate(10);
  vector<int> v2 = generate(10);

  const int some_number = 42;

  if (contains(v1, some_number))
    cout << "The first vector contains " << some_number << endl;
  else
    cout << "The first vector doesn't contain " << some_number << endl;

  // Mark 3
  // ------
  // Compute the scalar multiplication of two vectors.
  // The scaÃlar multiplication of two vectors is:
  // a = <a1, a2, ..., an>
  // b = <b1, b2, ..., bn>
  // a * b = a1*b1 + a2*b2 + ... + an*bn
  
  int mult = scalarMultiplication(v1, v2);
  
  cout << "The scalar multiplication of the vectors is: " << mult << endl;
  
  // Mark 4
  // ------
  // Check whether a vector is a palindrome, i.e. its elements are the same in
  // the reverse order. For example 1 2 3 4 5 4 3 2 1 is a palindrome, but
  // 1 2 3 4 5 4 3 6 8 is not.
  
  if (palindrome(v2))
    cout << "The second vector is a palindrome" << endl;
  else
    cout << "The second vector is not a palindrome" << endl;
    
  // Mark 5
  // ------
  // Determine the intersection of the two vectors, i.e. the elements which are
  // contained by both. For example the intersection of 1 2 3 4 5 and 3 4 5 6 7
  // is 3 4 5. It doesn't matter whether the resulting vector contains an
  // element multiple times.
  
  vector<int> commonElements = intersection(v1, v2);
  
  cout << "The common elements in the two vectors are:" << endl;
  for (int i = 0; i < commonElements.size(); ++i)
    cout << commonElements[i] << ' ';
  cout << endl;

  return 0;
}
