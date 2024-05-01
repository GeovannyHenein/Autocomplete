#include "bstmap.h" // Including the header file for Binary Search Tree implementation
#include <cmath>    // Including the cmath library for mathematical functions
#include <iomanip>  // Including the iomanip library for formatted output
#include <sstream>  // Including the sstream library for string stream operations

using namespace std; // Using the standard namespace

// Overloaded output operator to print a Node in easy to read format
ostream &operator<<(ostream &out, const BSTMap::Node &n) {
  out << "[" << n.data.first << "=" << n.data.second << "]"; // Printing the key-value pair
  return out;
}

// Overloaded output operator to display BST tree in a human-readable format
ostream &operator<<(ostream &out, const BSTMap &bst) {
  BSTMap::printSideways(out, bst.root); // Printing the BST sideways with root on left
  out << endl;
  // BSTMap::printVertical([out], bst.root); // Alternatively, printing the BST with the root at top
  return out;
}

// Function to print tree sideways with root on left
ostream &BSTMap::printSideways(ostream &out, const Node *curr, int level) {
  const static char space = ' '; // Static character for space
  const static int readabilitySpaces = 4; // Static integer for readability spaces
  
  // Base case: if current node is nullptr, return
  if (curr == nullptr) {
    return out;
  }
  
  // Recursively print right subtree
  printSideways(out, curr->right, ++level);
  
  // Printing current node with appropriate indentation
  out << setfill(space) << setw(level * readabilitySpaces) << space;
  out << *curr << endl; // Printing the current node
  // Recursively print left subtree
  printSideways(out, curr->left, level);
  
  return out;
}

// Helper function to print centered text
ostream &BSTMap::centeredPrint(ostream &out, int space, const string &str, char fillChar) {
  auto strL = static_cast<int>(str.length()); // Length of the string
  int extra = (space - strL) / 2; // Extra space required for centering
  if (extra > 0) {
    out << setfill(fillChar) << setw(extra + strL) << str;
    out << setfill(fillChar) << setw(space - extra - strL) << fillChar;
  } else {
    out << setfill(fillChar) << setw(space) << str;
  }
  return out;
}

// Function to print each level of the tree with the root at top
ostream &BSTMap::printTreeLevel(ostream &out, queue<const Node *> &q, int width,
                                int depth, int maxDepth) {
  const static char space = ' '; // Static character for space
  const static char underline = '_'; // Static character for underline
  
  int nodes = 0;
  int maxN = pow(2, depth - 1); // Maximum number of nodes at current level
  int spaceForEachItem = static_cast<int>(width * pow(2, maxDepth - 1) / maxN); // Space for each item
  string bigspace = string(static_cast<uint64_t>(spaceForEachItem / 4), space); // Extra space for formatting
  
  // Loop through each node at the current level
  while (nodes++ < maxN) {
    const Node *tp = q.front(); // Front node in the queue
    Node *tpl = nullptr; // Left child of current node
    Node *tpr = nullptr; // Right child of current node
    q.pop(); // Remove the front node from the queue
    string label = "N"; // Default label for node (used if node is nullptr)
    if (tp != nullptr) {
      stringstream ss; // String stream for converting data to string
      ss << *tp; // Extracting data from node
      label = ss.str(); // Converting data to string
      tpl = tp->left; // Left child of current node
      tpr = tp->right; // Right child of current node
    }
    char filler = depth == maxDepth ? space : underline; // Filler character based on depth
    if (depth == maxDepth) {
      centeredPrint(out, spaceForEachItem, label, filler); // Printing centered label
    } else {
      out << bigspace; // Adding extra space for formatting
      centeredPrint(out, spaceForEachItem / 2, label, filler); // Printing centered label
      out << bigspace; // Adding extra space for formatting
      q.push(tpl); // Pushing left child to the queue
      q.push(tpr); // Pushing right child to the queue
    }
  }
  out << endl; // New line after printing all nodes at the current level
  return out;
}

// Helper function for displaying tree vertically, works recursively
ostream &BSTMap::printVertical(ostream &out, Node *curr) {
  const static int width = 6; // Width of each node (must be even)
  if (curr == nullptr) {
    return out << "[__]"; // If current node is nullptr, print placeholder
  }
  // Figure out the maximum depth which determines how wide the tree is
  int maxDepth = getHeight(curr); // Getting the height of the tree
  queue<const Node *> q; // Queue to perform level order traversal
  q.push(curr); // Pushing root node to the queue
  // Loop through each level of the tree
  for (int depth = 1; depth <= maxDepth; ++depth) {
    printTreeLevel(out, q, width, depth, maxDepth); // Printing nodes at current level
  }
  return out;
}
