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
    void printName();
  protected:
    char* name;
};

#endif
