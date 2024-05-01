#include "autocomplete.h" // Include header file for Autocomplete class
#include <cassert> // Include header file for assert
#include <iostream> // Include header file for standard input and output operations
#include <string> // Include header file for string operations
#include <vector> // Include header file for vector operations

using namespace std; // Use the standard namespace

// Test case 1 for autocomplete using small.txt
void testAC01() {
  cout << "Starting AC test01" << endl; // Print start message
  cout << "* Testing basic autocomplete" << endl; // Print test description
  Autocomplete ac; // Create an instance of the Autocomplete class
  ac.readFile("small.txt"); // Read small.txt file
  auto v = ac.complete("hel"); // Get autocomplete results for prefix "hel"
  // Assertion checks
  assert(v.size() == 2); // Check size of result vector
  assert(v[0].first == "help"); // Check first autocomplete result
  assert(v[0].second == 20); // Check frequency of first autocomplete result
  assert(v[1].first == "hello"); // Check second autocomplete result
  assert(v[1].second == 10); // Check frequency of second autocomplete result
  cout << "Ending testAC01" << endl; // Print end message
}

// Test case 2 for autocomplete using cities.txt
void testAC02() {
  cout << "Starting AC test02" << endl; // Print start message
  cout << "* Testing cities autocomplete" << endl; // Print test description
  Autocomplete ac; // Create an instance of the Autocomplete class
  ac.readFile("cities.txt"); // Read cities.txt file
  auto v = ac.complete("Sea"); // Get autocomplete results for prefix "Sea"
  // Assertion checks
  assert(v.size() == 47); // Check size of result vector
  assert(v[0].first == "Seattle, Washington, United States"); // Check first autocomplete result
  assert(v[0].second == 608660); // Check frequency of first autocomplete result
  assert(v[46].first == "Seabeck, Washington, United States"); // Check last autocomplete result
  assert(v[46].second == 1105); // Check frequency of last autocomplete result
  cout << "Ending testAC02" << endl; // Print end message
}

// Test case 3 for autocomplete using wiktionary.txt
void testAC03() {
  cout << "Starting AC test03" << endl; // Print start message
  cout << "* Testing basic autocomplete" << endl; // Print test description
  Autocomplete ac; // Create an instance of the Autocomplete class
  ac.readFile("wiktionary.txt"); // Read wiktionary.txt file
  auto v = ac.complete("tho"); // Get autocomplete results for prefix "tho"
  // Assertion checks
  assert(v.size() == 16); // Check size of result vector
  assert(v[0].first == "those"); // Check first autocomplete result
  assert(v[0].second == 87862100); // Check frequency of first autocomplete result
  assert(v[2].first == "though"); // Check third autocomplete result
  assert(v[2].second == 57087700); // Check frequency of third autocomplete result
  cout << "Ending testAC03" << endl; // Print end message
}

// Test case 4 for autocomplete ensuring phrases is not nullptr
void testAC04() {
  cout << "Starting AC test04" << endl; // Print start message
  cout << "* Testing that phrases is not nullptr" << endl; // Print test description
  Autocomplete ac; // Create an instance of the Autocomplete class
  ac.readFile("wiktionary.txt"); // Read wiktionary.txt file
  ac.readFile("small.txt"); // Read small.txt file
  cout << "Ending testAC04" << endl; // Print end message
}

// Calling all test functions
void testACAll() {
  testAC01(); // Run test case 1
  testAC02(); // Run test case 2
  testAC03(); // Run test case 3
  testAC04(); // Run test case 4
}
