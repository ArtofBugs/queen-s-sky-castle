/*
Item class with name (char*). Includes accessors and functions to print name.
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Item {
  public:
    Item();
    Item(char*);
    ~Item();
    char* getName();
    void setName(char*);
    void printName();
  protected:
    char* name;
};

#endif
