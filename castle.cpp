/*
For a map of the castle, visit this link:



                       ENTRANCE
*/

using namespace std;

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
void printHelp();
void printCurrPlace(Room* currRoom);
void printInventory(Room* inventory);
void takeItem(Room* inventory, Room* currRoom);
void dropItem(Room* inventory, Room* currRoom);

// const int maxNameLength = 100; // Maximum character length of room names
// const int maxDescLength = 1000; // Maximum character length of room descriptions

int main() {

  Room* currRoom;
  vector <Room*> * castle = new vector <Room*>;

  // Rooms and items setup ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  char* newName = new char[1];
  char* newDesc = new char[1];
  char* newDirection;
  newName[0] = '\0';
  newDesc[0] = '\0';
  Room* inventory = new Room(newName, newDesc); // Player inventory acts like a
  // room

  newName = new char[6];
  strcpy(newName, "foyer"); // do I need \0 at the end? TODO
  newDesc = new char[90];
  strcpy(newDesc, "Yes, both the chandeliers and floors are made of ice crystals - I mean, these ARE clouds."); // do I need \0 at the end? TODO
  Room* foyer = new Room(newName, newDesc);

  currRoom = foyer;

  newName = new char[10];
  strcpy(newName, "jade card"); // do I need \0 at the end? TODO
  Item* jadeCard = new Item(newName);
  foyer->addItem(jadeCard);

  newName = new char[16];
  strcpy(newName, "queen's bedroom"); // do I need \0 at the end? TODO
  newDesc = new char[5];
  strcpy(newDesc, "TODO"); // do I need \0 at the end? TODO
  Room* bedroom = new Room(newName, newDesc);

  newName = new char[6];
  strcpy(newName, "crown"); // do I need \0 at the end? TODO
  Item* crown = new Item(newName);
  bedroom->addItem(crown);


  Room* balcony = new Room();



  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  bedroom->addNeighbor(newDirection, balcony);


  cout << "Welcome to the Queen's Sky Castle - Zuul!" << endl;
  printHelp();

  while (!balcony->containsItem(crown)) {
    // Main game here
  }
  cout << "You won! Thank you for playing!" << endl;
  return 0;
}


// When the player has used the HELP command - print help information on how to
// play the game
void printHelp() {
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
// I got the idea for the NULL pointer from looking up strstr() for my media
// database project.
void dropItem(Room* inventory, Room* currRoom) {
  // Item* move = currRoom->rmItem(specified);
  // if (move != NULL) {
    // currRoom->addItem(move);
  // }
}

// When the player has used the DROP command - search for the given item in
// inventory; drop the item in the current room if it exists.
void takeItem(Room* inventory, Room* currRoom) {
  // Item* move = currRoom->rmItem(specified);
  // if (move != NULL) {
    // inventory->addItem(move);
  // }

}


// Take in user input and return it as a char* to a cstring.
// (Creates a cstring on the heap!)
// Code taken from my media database project: ----------------------------------
char* promptText() {

  // Adapted from setNames() code from my student list project
  char* newArr = new char[1];
  newArr[0] = '\0';
  char* oldArr = new char[1];
  oldArr[0] = '\0';
  int oldSize = 1;

  while (cin.peek() != '\n') {
    delete oldArr;
    oldArr = &(*newArr);
    oldSize++;
    newArr = new char[oldSize + 1];
    strcpy(newArr, oldArr);
    newArr[oldSize - 2] = cin.peek();
    newArr[oldSize - 1] = '\0';
    cin.ignore();
  }
  cin.ignore(); // ending '\n'

  delete oldArr;

  return newArr;
}
//----------------------------------------------------------------------------
