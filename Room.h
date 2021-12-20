/*
Room class with name (char*), description (char*), neighbors (map), and present
items (vector. Each map element has a direction char* as a key and a Room* as a
value. Inventory is a Room with \0 name and description and empty neighbors.
Includes accessors, functions to print attributes, functions to add and search
for neighbors, and functions to add and remove Items.
*/

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
    char* getName();
    void printName();
    void printDescription();
    void printPaths();
    void addItem(Item*);
    void printItems();
    Item* rmItem(char*);
    bool containsItem(Item*);
    void addNeighbor(char*, Room*);
    Room* findNeighbor(char*);

  protected:
    vector <Item*> * presentItems;
    char* name;
    map <char*, Room*> * neighbors;
    char* description;
};

#endif
