#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

using namespace std;

// When constructing rooms, provide room name
// Add items to room after construction.
Room::Room(char* newName, char* newDesc) {
  name = newName;
  description = newDesc;
  presentItems = new vector <Item*>;
  neighbors = new map <char*, Room*>;
  locked = new bool false;
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

// Prints name of room
void Room::printName() {
  cout << name << endl;
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
  presentItems.emplace_back(*newItem);
}

// Prints names of all items in room
void Room::printItems() {
  cout << "There are the following items here:" << endl;
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    cout << presentItems.name << endl;
  }
}


// Deletes given item and removes it from presentItems
void Room::rmItem(Item* oldItem) {
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
bool Room::containsItem(Item* searchItem) {
  for (auto it = presentItems.begin(); it != presentItems.end(); it++) {
    if (*oldItem == *it) {
      return true;
    }
  }
}

// Adds neighboring room to neighbors map
void Room::addNeighbor(char* direction, Room* newRoom) {
  // TODO
}
