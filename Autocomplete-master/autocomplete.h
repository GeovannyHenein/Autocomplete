#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "bstmap.h" // Including the header file for Binary Search Tree implementation

using namespace std; // Using the standard namespace

class Autocomplete {
public:
  // Default constructor for Autocomplete
  Autocomplete() = default;

  // Copy constructor deleted to prevent copying of Autocomplete objects
  Autocomplete(const Autocomplete &other) = delete;

  // Move constructor deleted to prevent moving of Autocomplete objects
  Autocomplete(Autocomplete &&other) = delete;

  // Copy assignment operator deleted to prevent copying of Autocomplete objects
  Autocomplete &operator=(const Autocomplete &other) = delete;

  // Move assignment operator deleted to prevent moving of Autocomplete objects
  Autocomplete &operator=(Autocomplete &&other) = delete;

  // Function to read a file and populate the autocomplete data structure
  void readFile(const string &fileName);

  // Function to suggest completions for a given prefix
  vector<BSTMap::value_type> complete(const string &prefix) const;

  // Destructor for Autocomplete
  virtual ~Autocomplete() { delete phrases; }

private:
  BSTMap *phrases = nullptr; // Pointer to a Binary Search Tree storing phrases and their frequencies

  // Static function to sort nodes by weight in descending order
  bool static sortByWeight(BSTMap::value_type &a, BSTMap::value_type &b);
};

#endif // AUTOCOMPLETE_H
