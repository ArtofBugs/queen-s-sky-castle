#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room {
  public:
    Room();
    Room(char* name, char* description);
    ~Room();
    void printName();
    void printDescription();
    void printPaths();
    void addItem(Item*);
    void printItems();
    Item* rmItem(char*);
    bool containsItem(Item*);
    void addNeighbor(char*, Room*);

  protected:
    vector <Item*> * presentItems;
    char* name;
    map <char*, Room*> * neighbors;
    char* description;
    bool locked;
};

#endif
