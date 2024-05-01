// /**
//  * Testing BST - Binary Search Tree functions
//  *
//  * This file has series of tests for BST
//  * Each test is independent and uses assert statements
//  * Test functions are of the form
//  *
//  *      test_netidXX()
//  *
//  * where netid is UW netid and XX is the test number starting from 01
//  *
//  * Test functions can only use the public functions from BST
//  * testBSTAll() is called from main in main.cpp
//  * testBSTAll calls all other functions
//  * @author Helina Azer and Geovanny Henein
//  * @date 1/23/2021
//  */

// Including necessary header files
#include "bstmap.h" // Header file for Binary Search Tree implementation
#include <cassert>  // Header file for assertion library
#include <sstream>  // Header file for stringstream for testing purposes

using namespace std; // Using standard namespace

// Global stringstream object for testing purposes
// NOLINTNEXTLINE
stringstream globalSS;

// Function to print key-value pairs
void printer(const BSTMap::value_type &p) {
  globalSS << "[" << p.first << "=" << p.second << "]"; // Format: [key=value]
}

// Test function for testing ==, !=, [], and copy constructor
void test01() {
  cout << "Starting test01" << endl;
  cout << "* Testing ==, !=, [] and copy constructor" << endl;
  
  // Creating an instance of BSTMap
  BSTMap b1;

  // Testing operator [] for a key not present in the tree
  auto val = b1["hello"];
  assert(val == 0); // Asserting that value is 0
  
  // Adding key-value pairs to the tree
  b1["hello"] = 5;
  val = b1["hello"]; // Testing operator [] for an existing key
  assert(val == 5); // Asserting that value is updated correctly
  
  b1["world"] = 42; // Adding another key-value pair

  // Creating another instance of BSTMap
  BSTMap b2;

  // Asserting that b1 and b2 are not equal
  assert(b1 != b2);

  // Adding same key-value pairs to b2 as in b1
  b2["hello"] = 5;
  b2["world"] = 42;

  // Asserting that b1 and b2 are equal
  assert(b1 == b2);

  // Creating a new instance of BSTMap using copy constructor
  BSTMap b3(b2);

  // Asserting that b1 and b3 are equal
  assert(b1 == b3);

  cout << "Ending test01" << endl;
}

// Test function for testing traversal
void test02() {
  cout << "Starting test02" << endl;
  cout << "* Testing traversal" << endl;

  // Creating an instance of BSTMap
  BSTMap b;
  
  // Adding key-value pairs to the tree
  b["x"] = 10;
  b["f"] = 5;
  b["b"] = 3;
  b["e"] = 4;
  b["z"] = 50;

  // Testing inorder traversal
  globalSS.str("");
  b.inorder(printer);
  string order = globalSS.str();
  assert(order == "[b=3][e=4][f=5][x=10][z=50]"); // Asserting the order

  // Testing preorder traversal
  globalSS.str("");
  b.preorder(printer);
  order = globalSS.str();
  assert(order == "[x=10][f=5][b=3][e=4][z=50]"); // Asserting the order

  // Testing postorder traversal
  globalSS.str("");
  b.postorder(printer);
  order = globalSS.str();
  assert(order == "[e=4][b=3][f=5][z=50][x=10]"); // Asserting the order

  cout << "Ending test02" << endl;
}

// Test function for testing rebalance
void test03() {
  cout << "Starting test03" << endl;
  cout << "* Testing rebalance" << endl;

  // Creating an instance of BSTMap
  BSTMap b;
  
  // Adding key-value pairs to the tree
  b["1"] = 1;
  b["2"] = 2;
  b["3"] = 3;
  b["4"] = 4;
  b["5"] = 5;
  b["6"] = 6;

  // Asserting the height of the tree
  assert(b.height() == 6);

  // Rebalancing the tree
  b.rebalance();
  
  // Asserting the height of the tree after rebalance
  assert(b.height() == 3);

  // Clearing the tree
  b.clear();
  
  // Asserting the height of the tree after clearing
  assert(b.height() == 0);

  cout << "Ending test03" << endl;
}

// Test function for testing helper functions: height(), size(), and count()
void test04() {
  cout << "Starting test04" << endl;
  cout << "* Testing Helper Functions: height(), size(), and count()" << endl;

  // Creating an instance of BSTMap
  BSTMap b;
  
  // Adding key-value pairs to the tree
  b["1"] = 1;
  b["2"] = 2;
  b["3"] = 3;
  b["4"] = 4;
  b["5"] = 5;
  b["6"] = 6;
  b["7"] = 7;

  // Asserting the height of the tree
  assert(b.height() == 7);

  // Asserting the size of the tree
  assert(b.size() == 7);

  // Asserting the count of specific keys
  assert(b.count("1") == 1);
  assert(b.count("8") == 0);

  cout << "Ending test04" << endl;
}

// Test function for testing helper functions: empty() and clear()
void test05() {
  cout << "Starting test05" << endl;
  cout << "* Testing Helper Functions: empty() and clear()" << endl;

  // Creating an instance of BSTMap
  BSTMap b;
  
  // Adding key-value pairs to the tree
  b["1"] = 1;
  b["2"] = 2;
  b["3"] = 3;
  b["4"] = 4;
  b["5"] = 5;
  b["6"] = 6;
  b["7"] = 7;

  // Testing empty() function
  b.empty(); // This line does not have any effect
  
  // Clearing the tree
  b.clear(); // Clearing the tree
  
  cout << "Ending test05" << endl;
}

// Test function for testing contains()
void test06() {
  cout << "Starting test06" << endl;
  cout << "* Testing contains()" << endl;

  // Creating an instance of BSTMap
  BSTMap b;
  
  // Adding key-value pairs to the tree
  b["1"] = 1;

  // Asserting whether the tree contains specific keys
  assert(b.contains("1") == true);
  assert(b.contains("4") == false);
  assert(b.contains("0") == false);

  cout << "Ending test06" << endl;
}

// Test function for testing !=
void test07() {
  cout << "Starting test07" << endl;
  cout << "* Testing !=" << endl;

  // Creating instances of BSTMap
  BSTMap b1;
  BSTMap b2;
  BSTMap b3;
  BSTMap b4;
  b1["hello"] = 10;
  b2["help"] = 20;
  b3["herd"] = 5;
  b4["herd"] = 7;

  // Asserting inequality between instances
  assert(b1 != b2);
  assert(b3 != b4);

  cout << "Ending test07" << endl;
}

// Calling all test functions
void testBSTAll() {
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();
  test07();
}
