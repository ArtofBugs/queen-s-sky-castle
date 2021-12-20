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

// Returns name of room
char* Room::getName() {
  return name;
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
  bool firstEntry = true; // don't include spacer before first entry
  // iterate through neighbors map and print directions (keys)
  for (auto it = neighbors->begin(); it != neighbors->end(); it++) {
    if (firstEntry) {
      firstEntry = false;
    }
    else {
      cout << "  ";
    }
    // I didn't find a reference page, but from the examples on
    // https://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap-and-put-them-into-a-vector
    // first is the key in a map element and second is the value in the element.
    cout << it->first;
  }
  cout << endl;
}

// Adds given item to the room's presentItems
void Room::addItem(Item* newItem) {
  presentItems->emplace_back(newItem);
}

// Prints names of all items in room.
void Room::printItems() {
  bool firstEntry = true; // don't include spacer before first entry
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    if (firstEntry) {
      firstEntry = false;
    }
    else {
      cout << "  ";
    }
    cout << (*it)->getName();
  }
  cout << endl;
}


// Deletes given item and removes it from presentItems.
Item* Room::rmItem(char* oldName) {
  for (auto it = presentItems->begin(); it != presentItems->end(); it++) {
    if (strcmp(oldName, (*it)->getName()) == 0) {
      Item* oldItem = *it;
      presentItems->erase(it);
      return oldItem;
    }
  }
  cout << "There's no item with that name!" << endl;
  Item* placeholder = NULL;
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

// Adds neighboring room to neighbors map.
void Room::addNeighbor(char* direction, Room* newRoom) {
  neighbors->insert(pair<char*, Room*> (direction, newRoom));
}

// For a given direction, sees if the room has a neighbor in that direction. If
// so, returns a pointer to the neighbor.
Room* Room::findNeighbor(char* direction) {

  for (auto it = neighbors->begin(); it != neighbors->end(); it++) {
    // I didn't find a reference page, but from the examples on
    // https://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap-and-put-them-into-a-vector
    // first is the key in a map element and second is the value in the element.
    if (strcmp(direction, it->first) == 0) {
      cout << "Found element at " << direction << endl;
      cout << "It is ";
      it->second->printName();
      cout << endl;
      return it->second;
    }
  }
  return NULL;
}
