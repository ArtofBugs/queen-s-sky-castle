#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Item {
  public:
    Item(char*);
    printName();
  protected:
    char* name;
};

#endif
