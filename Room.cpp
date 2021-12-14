#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

using namespace std;

// Default constructor
Room::Room() {
  name = new char[1];
  name[0] = '\0';
  description = new char[1];
  description[0] = '\0';
  presentItems = new vector <Item*>;
  neighbors = new map <char*, Room*>;
  locked = false;
}

// When constructing rooms, provide room name
// Add items to room after construction.
Room::Room(char* newName, char* newDesc) {
  name = newName;
  description = newDesc;
  presentItems = new vector <Item*>;
  neighbors = new map <char*, Room*>;
  locked = false;
}

// Delete attributes and items in room
Room::~Room() {
  delete[] name;
  delete[] description;
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    delete *it;
  }
  delete presentItems;
}

// Prints name of room
void Room::printName() {
  cout << name;
}

// Prints description of room
void Room::printDescription() {
  cout << description << endl;
}

// Prints possible directions to move from current room
void Room::printPaths() {
  // iterate through neighbors map and print directions (keys)
}

// Adds given item to the room's presentItems
void Room::addItem(Item* newItem) {
  presentItems->emplace_back(newItem);
}

// Prints names of all items in room
void Room::printItems() {
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    cout << (*it)->getName() << endl;
  }
}


// Deletes given item and removes it from presentItems
Item* Room::rmItem(char* oldName) {
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    if (strcmp(oldName, (*it)->getName())) {
      Item* oldItem = *it;
      presentItems->erase(it);
      return oldItem;
    }
  }
  cout << "There's no item with that name!" << endl;
  Item* placeholder;
  return placeholder;
}

// Return true if the given item is in the room; return false otherwise.
bool Room::containsItem(Item* searchItem) {
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    if (strcmp((*it)->getName(), searchItem->getName()) == 0) {
      return true;
    }
  }
  return false;
}

// Adds neighboring room to neighbors map
void Room::addNeighbor(char* direction, Room* newRoom) {
  // TODO
}
