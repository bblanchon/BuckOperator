// The C++ buck operator (or dollar sign operator) to return multiple values
// from a function
//
// A stupid idea of Benoit Blanchon in 2015
// MIT License

#include <string>
#include <iostream>

#include "buck.hpp"

using namespace std;

// Declare multiple return type with $<>
$<int, string> get_current_user() {
  // Pack the two return values with $()
  return $(0, "root");
}

int main() {
  int id;
  string name;

  // Unpack the two values with $()
  $(id, name) = get_current_user();

  cout << "User ID: " << id << endl;
  cout << "User Name: " << name << endl;

  // You can also ignore a value, just omit the variable
  $(, name) = get_current_user();
  cout << "User Name: " << name << endl;

  return 0;
}
