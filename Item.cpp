/*
Item class with name (char*). Includes accessors and functions to print name.
*/

#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

// Default constructor
Item::Item() {
  name = new char[1];
  name[0] = '\0';
}

// Constructs Item with given name.
Item::Item(char* newName) {
  name = newName;
}

// Deletes item.
Item::~Item() {
  delete[] name;
}

// Return pointer to name of item.
char* Item::getName() {
  return name;
}

// Set name of item.
void Item::setName(char* newName) {
  name = newName;
}

// Print name of item.
void Item::printName() {
  cout << name << endl;
}
