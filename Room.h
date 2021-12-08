#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room {
  public:
    Room(char* name, char* description);
    void printName();
    void printDescription();
    void printPaths();
    void addItem(Item*);
    void printItems();
    void rmItem(Item*);
    bool containsItem(Item*);
    void addNeighbor(char*, Room*);

  protected:
    vector <Item*> * presentItems;
    char* name;
    map* neighbors;
    char* description;
    bool* locked;
};

#endif
