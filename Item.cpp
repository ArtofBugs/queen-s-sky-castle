#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

// Default constructor
Item::Item() {
  name = new char[1];
  name[0] = '\0';
}

Item::Item(char* newName) {
  name = newName;
}

Item::~Item() {
  delete name;
}


// Print name of item
void Item::printName() {
  cout << name << endl;
}
