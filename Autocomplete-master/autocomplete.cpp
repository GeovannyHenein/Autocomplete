#include "autocomplete.h" // Including the header file for autocomplete implementation
#include <algorithm>      // Including the algorithm library for sorting
#include <fstream>        // Including the file stream library for file operations

using namespace std; // Using the standard namespace

void testBSTAll(); // Declaration of a function to test all BST operations

// Function to read a file and populate the autocomplete data structure
void Autocomplete::readFile(const string &fileName) {
  ifstream ifs(fileName); // Opening the file for reading
  int count;
  ifs >> count; // Reading the number of entries
  vector<BSTMap::value_type> v; // Creating a vector to store key-value pairs

  // Loop to read key-value pairs from the file
  for (int i = 0; i < count; i++) {
    BSTMap::value_type t; // Temporary variable to hold each key-value pair
    ifs >> t.second; // Reading the weight of the phrase
    ifs.seekg(1, ios::cur); // Moving the file pointer past the space
    getline(ifs, t.first); // Reading the phrase itself (including spaces)
    v.push_back(t); // Adding the key-value pair to the vector
  }

  delete phrases; // Deleting the previous BST to avoid memory leaks

  // Creating a new BSTMap using the vector of key-value pairs
  phrases = new BSTMap(v);

  ifs.close(); // Closing the file
  phrases->rebalance(); // Rebalancing the BST after insertion
}

// Function to sort nodes by weight in descending order
bool Autocomplete::sortByWeight(BSTMap::value_type &a, BSTMap::value_type &b) {
  return a.second > b.second; // Sorting in descending order of weights
}

// Function to suggest completions for a given prefix
vector<BSTMap::value_type>
Autocomplete::complete(const BSTMap::key_type &prefix) const {
  auto v = phrases->getAll(prefix); // Getting all phrases with the given prefix
  sort(v.begin(), v.end(), sortByWeight); // Sorting the suggestions by weight
  return v; // Returning the sorted list of suggestions
}
