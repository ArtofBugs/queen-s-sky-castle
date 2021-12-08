/*
For a map of the castle, visit this link:



                       ENTRANCE
*/

using namespace std

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"
#include "Item.h"

/*
// Items in the castle, which have a name and ________.
Struct Item {
  char* name;
  // location?;
};
*/

void initializeRooms(Room* currRoom);
void printHelp(Room* currRoom);
void printCurrPlace(Room* currRoom);
void printInventory(Room* inventory);
void takeItem(Room* inventory, Room* currRoom);
void dropItem(Room* inventory, Room* currRoom);

const int maxNameLength = 100; // Maximum character length of room names
const int maxDescLength = 1000; // Maximum character length of room descriptions

int main() {

  Room* currRoom;

  cout << "Welcome to the Queen's Sky Castle - Zuul!" << endl;
  printHelp();

  while (!balcony->containsItem(crown)) {
    // Main game here
  }
  cout << "You won! Thank you for playing!" << endl;
  return 0;
}

// Set up rooms, names, descriptions, items, and locations
void initializeRooms(Room* currRoom) {
  char* newName = new char[maxNameLength];
  char* newDesc = new char[maxDescLength];
  newName[0] = '\0';
  newDesc[0] = '\0';
  Room* inventory = new Room(newName, newDesc); // Player inventory acts like a room

  Room* foyer = new Room();
  // Item* jadeCard = new Item();
  currRoom = foyer;

  // newName = "bedroom"; // FIXME
  // Room* bedroom = new Room(newName, newDesc); // FIXME
  Item* crown = new Item();
  bedroom->addItem(crown);


  Room* balcony = new Room();



  bedroom->addNeighbor(balcony);



}

// When the player has used the HELP command - print help information on how to
// play the game
void printHelp(Room* currRoom) {
  cout << "Welcome to the queen's sky castle. Explore the castle and move objects to try to win the grand prize!" << endl;
  cout << "Your command words are:" << endl;
  cout << "GO {direction}    INVENTORY    TAKE {object in inventory}    DROP {object in room}    HELP    QUIT" << endl;
}

// When the player has used the GO command - print the details of the current
// room.
void printCurrPlace(Room* inventory, Room* currRoom) {
  cout << "You are in the ";
  currRoom->printName();
  currRoom->printDescription();
  cout << "The following items are here:" << endl;
  currRoom->printItems();
  cout << "Paths:" << endl;
  currRoom->printPaths();
  cout << endl;
}

// When the player has used the INVENTORY command - print names of all items
// currently in the inventory
void printInventory(Room* inventory, Room* currRoom) {
  cout << "You currently have the following items:" << endl;
  inventory->printItems();
}

// When the player has used the DROP command - search for the given item in
// inventory; drop the item in the current room if it exists.
void dropItem() {

}

// When the player has used the DROP command - search for the given item in
// inventory; drop the item in the current room if it exists.
void takeItem() {

}
