#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Media {
  public:
    Room();
    void addItem(Item*);
    void printItems();
    void rmItem(Item*);
    bool containsItem(Item*);

  protected:
    vector <Item*> * presentItems;
    char* name;
    char* description;
    bool locked;

#endif
