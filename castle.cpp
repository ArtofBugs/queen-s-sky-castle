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

void initializeRooms(Room* currRoom);
void printHelp();
void printCurrPlace(Room* currRoom);
void printInventory(Room* inventory);
void takeItem(char* itemName, Room* inventory, Room* currRoom);
void dropItem(char* itemName, Room* inventory, Room* currRoom);
char* promptText();

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
  castle->emplace_back(foyer);

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
  printCurrPlace(currRoom);

  while (!balcony->containsItem(crown)) {
    char* command = promptText();
    if (strcmp(command, "HELP") == 0) {
      printHelp();
    }
    // Given an integer n, strncmp() compares two cstrings to see if the first n
    // characters match; if they do, it returns 0.
    else if (strncmp(command, "GO ", 3) == 0) {
      char* direction = &(command[3]);
      cout << "Direction found: " << direction << endl;
      cout << "GOING..." << endl;
      // TODO: set currRoom to corresponding listing in map
      delete command;
      printCurrPlace(currRoom);
    }
    else if (strcmp(command, "INVENTORY") == 0) {
      printInventory(inventory);
      delete command;
    }
    else if (strncmp(command, "TAKE ", 5) == 0) {
      char* itemName = &(command[5]);
      cout << "Object found: " << itemName << endl;
      cout << "TAKING..." << endl;
      takeItem(itemName, inventory, currRoom);
      delete command;
      printCurrPlace(currRoom);
    }
    else if (strncmp(command, "DROP ", 5) == 0) {
      char* itemName = &(command[5]);
      cout << "Object found: " << itemName << endl;
      cout << "DROPPING..." << endl;
      dropItem(itemName, inventory, currRoom);
      delete command;
      printCurrPlace(currRoom);
    }
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Thank you for playing!" << endl;
      delete command;
      return 0;
    }
    else {
      cout << "Command not recognized. Type HELP for a list of command words." << endl;
      delete command;
      continue;
    }

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
  cout << endl;
}

// When the player has used the GO command - print the details of the current
// room.
void printCurrPlace(Room* currRoom) {
  cout << "You are in the ";
  currRoom->printName();
  cout << "." << endl;
  currRoom->printDescription();
  cout << "The following items are here:" << endl;
  currRoom->printItems();
  cout << "Paths:" << endl;
  currRoom->printPaths();
  cout << endl;
  cout << endl;
}

// When the player has used the INVENTORY command - print names of all items
// currently in the inventory
void printInventory(Room* inventory) {
  cout << "You currently have the following items:" << endl;
  inventory->printItems();
  cout << endl;
}

// When the player has used the DROP command - search for the given item in
// inventory; drop the item in the current room if it exists.
// I got the idea for the NULL pointer from looking up strstr() for my media
// database project.
void dropItem(char* itemName, Room* inventory, Room* currRoom) {
  Item* move = inventory->rmItem(itemName);
  if (move != NULL) {
    currRoom->addItem(move);
  }
  cout << endl;
}

// When the player has used the DROP command - search for the given item in
// inventory; drop the item in the current room if it exists.
void takeItem(char* itemName, Room* inventory, Room* currRoom) {
  Item* move = currRoom->rmItem(itemName);
  if (move != NULL) {
    inventory->addItem(move);
  }
  cout << endl;
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
