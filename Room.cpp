
#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

// When constructing rooms, provide room name
// Add items to room after construction.
Room::Room(char* newName, char* description) {
  name = newName;
  presentItems = new vector <Item*>;
}

// Delete attributes and items in room
Room::~Room() {
  delete[] name;
  delete[] description;
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    delete (*(*it)).name;
    delete *it;
  }
  delete presentItems;
}

// Adds given item to the room's presentItems
void addItem(Item* newItem) {
  presentItems.emplace_back(*newItem);
}

// Prints names of all items in room
void printItems() {
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    cout << presentItems.name << endl;
  }
}

// Prints description of room
void printDescription() {
  cout << "There are the following items here:" << endl;
  cout << description << endl;
}

// Deletes given item and removes it from presentItems
void rmItem(Item* oldItem) {
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    if (*oldItem == *it) {
      delete *it;
      erase it;
      return;
    }
  }
  cout << "Deletion error - item not found." << endl;
}

// Return true if the given item is in the room; return false otherwise.
bool containsItem(Item* searchItem) {
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    if (*oldItem == *it) {
      return true;
    }
  }
}
