#include "autocomplete.h" // Include header file for Autocomplete class
#include "bstmap.h" // Include header file for BSTMap class
#include <cassert> // Include header file for assert
#include <fstream> // Include header file for file stream operations
#include <iostream> // Include header file for standard input and output operations
#include <map> // Include header file for map data structure

using namespace std; // Use the standard namespace

// Forward declarations
void testBSTAll(); // Forward declaration of function to test BSTMap
void testACAll(); // Forward declaration of function to test Autocomplete

// Function to run all tests
void testMain() {
  testBSTAll(); // Run tests for BSTMap
  testACAll(); // Run tests for Autocomplete
}

// Main function that tests the functions implemented in BSTMap and Autocomplete
int main(int argc, char *argv[]) {
  // Check if command-line arguments are provided for filename and prefix
  if (argc == 3) {
    Autocomplete ac; // Create an instance of the Autocomplete class
    string filename = argv[1]; // Get filename from command-line argument
    string prefix = argv[2]; // Get prefix from command-line argument
    ac.readFile(filename); // Read file using filename
    auto results = ac.complete(prefix); // Get autocomplete results for prefix
    // Print results
    for (auto &p : results) {
      cout << p.first << "\t" << p.second << endl; // Print word and frequency
    }
  } else {
    // If no command-line arguments, run tests
    testMain(); // Run all tests
  }

  return EXIT_SUCCESS; // Exit with success
}
