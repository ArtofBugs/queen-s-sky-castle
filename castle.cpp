/*
For a map of the castle, visit this link:
https://drive.google.com/file/d/1uFgxeS7I4TR3Gba0C-XyWu_gwyGmyH88/view?usp=sharing
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
  strcpy(newName, "foyer");
  newDesc = new char[100];
  strcpy(newDesc, "Yes, both the chandeliers and floors are made of ice crystals - I mean, this IS the cloud queendom.");
  Room* foyer = new Room(newName, newDesc);
  castle->emplace_back(foyer);

  currRoom = foyer;

  newName = new char[13];
  strcpy(newName, "front garden");
  newDesc = new char[85];
  strcpy(newDesc, "There are a lot of flowers and not a lot of people, just the way the queen likes it.");
  Room* frontGarden = new Room(newName, newDesc);
  castle->emplace_back(frontGarden);

  newName = new char[10];
  strcpy(newName, "main hall");
  newDesc = new char[153];
  strcpy(newDesc, "Other than having twenty chandeliers, this room isn't very interesting. On the other hand, there are delicious smells coming through one of the doors...");
  Room* mainHall = new Room(newName, newDesc);
  castle->emplace_back(mainHall);

  newName = new char[9];
  strcpy(newName, "ballroom");
  newDesc = new char[124];
  strcpy(newDesc, "There are plenty of tables covered in gold cloth, but the food's not on them yet. There is definitely food nearby though...");
  Room* ballroom = new Room(newName, newDesc);
  castle->emplace_back(ballroom);

  newName = new char[12];
  strcpy(newName, "dining hall");
  newDesc = new char[124];
  strcpy(newDesc, "Chandeliers, tables, and... only leftovers. There's no time to eat now, anyway. Maybe you'll catch another feast next time.");
  Room* diningHall = new Room(newName, newDesc);
  castle->emplace_back(diningHall);

  newName = new char[8];
  strcpy(newName, "gallery");
  newDesc = new char[107];
  strcpy(newDesc, "Art gallery? Photo gallery? Theater gallery? The queen's got everything here... except for the spectators.");
  Room* gallery = new Room(newName, newDesc);
  castle->emplace_back(gallery);

  newName = new char[13];
  strcpy(newName, "coat chamber");
  newDesc = new char[120];
  strcpy(newDesc, "The queen doesn't keep her coats here - only the guests do. From the looks of it, she's pretty selective in her guests.");
  Room* coatChamber = new Room(newName, newDesc);
  castle->emplace_back(coatChamber);

  newName = new char[12];
  strcpy(newName, "back garden");
  newDesc = new char[63];
  strcpy(newDesc, "Wait, there are ice sculptures here? (And flowers, of course.)");
  Room* backGarden = new Room(newName, newDesc);
  castle->emplace_back(backGarden);

  newName = new char[8];
  strcpy(newName, "kitchen");
  newDesc = new char[99];
  strcpy(newDesc, "A walk-in refrigerator, a walk-in freezer, and... a walk-in oven? Fortunately, they're all locked.");
  Room* kitchen = new Room(newName, newDesc);
  castle->emplace_back(kitchen);

  newName = new char[12];
  strcpy(newName, "west stairs");
  newDesc = new char[64];
  strcpy(newDesc, "The floor-to-ceiling windows give a great view of the queendom.");
  Room* westStairs = new Room(newName, newDesc);
  castle->emplace_back(westStairs);

  newName = new char[14];
  strcpy(newName, "sunrise tower");
  newDesc = new char[89];
  strcpy(newDesc, "You're sure the sunrise would look great from this tower... if it weren't the afternoon.");
  Room* sunriseTower = new Room(newName, newDesc);

  newName = new char[16];
  strcpy(newName, "queen's bedroom");
  newDesc = new char[142];
  strcpy(newDesc, "The queen's got everything here - canopy bed, spacious (locked) closet, lavish dressing table... the only thing missing is the queen herself.");
  Room* bedroom = new Room(newName, newDesc);

  newName = new char[8];
  strcpy(newName, "balcony");
  newDesc = new char[93];
  strcpy(newDesc, "The view is grand, but what's even more eye-catching is the large crown stand in the center.");
  Room* balcony = new Room(newName, newDesc);



  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  frontGarden->addNeighbor(newDirection, foyer);

  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  foyer->addNeighbor(newDirection, mainHall);

  newDirection = new char[6];
  strcpy(newDirection, "SOUTH");
  foyer->addNeighbor(newDirection, frontGarden);

  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  mainHall->addNeighbor(newDirection, ballroom);

  newDirection = new char[6];
  strcpy(newDirection, "SOUTH");
  mainHall->addNeighbor(newDirection, foyer);

  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  ballroom->addNeighbor(newDirection, coatChamber);

  newDirection = new char[6];
  strcpy(newDirection, "SOUTH");
  ballroom->addNeighbor(newDirection, mainHall);

  newDirection = new char[5];
  strcpy(newDirection, "EAST");
  ballroom->addNeighbor(newDirection, gallery);

  newDirection = new char[5];
  strcpy(newDirection, "WEST");
  ballroom->addNeighbor(newDirection, diningHall);

  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  coatChamber->addNeighbor(newDirection, backGarden);




  newDirection = new char[6];
  strcpy(newDirection, "NORTH");
  bedroom->addNeighbor(newDirection, balcony);



  newName = new char[10];
  strcpy(newName, "JADE CARD");
  Item* jadeCard = new Item(newName);
  foyer->addItem(jadeCard);

  newName = new char[6];
  strcpy(newName, "CROWN");
  Item* crown = new Item(newName);
  gallery->addItem(crown);






  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

      Room* newRoom = currRoom->findNeighbor(direction);
      if (newRoom == NULL) {
        cout << "You can't go that way!" << endl;
      }
      // game twists ~~~
      else if (strcmp(currRoom->getName(), "coat chamber") == 0 &&
        strcmp(direction, "NORTH") == 0 &&
        !coatChamber->containsItem("JADE CARD")) {
        cout << "Hmm... looks like it's locked right now. There is a card reader next to the door - looks like you'll need to drop a card in this room." << endl;
      }
      else if ()
      // ~~~
      else {
        currRoom = newRoom;
      }
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
    }
    else if (strncmp(command, "DROP ", 5) == 0) {
      char* itemName = &(command[5]);
      cout << "Object found: " << itemName << endl;
      cout << "DROPPING..." << endl;
      dropItem(itemName, inventory, currRoom);
      delete command;

      // game twists
      if (strcmp(itemName, "sun berries") == 0) {
        // diningHall.addItem(soup);
        // diningHall.addItem(spoon);
      }

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
  cout << "Welcome to the Queen's Sky Castle - Zuul! Explore the castle and move objects to try to win the grand prize!" << endl;
  cout << "Your command words are:" << endl;
  cout << "GO {DIRECTION}    INVENTORY    TAKE {OBJECT IN INVENTORY}    DROP {OBJECT IN ROOM}    HELP    QUIT" << endl;
  cout << "Commands should be written in all caps!" << endl;
  cout << endl;
}

// When the player has used the GO command - print the details of the current
// room.
void printCurrPlace(Room* currRoom) {
  cout << "You are in the ";
  currRoom->printName();
  cout << "." << endl;
  currRoom->printDescription();
  cout << endl;
  cout << "The following items are here:" << endl;
  currRoom->printItems();
  cout << endl;
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
void dropItem(char* itemName, Room* inventory, Room* currRoom) {
  Item* move = inventory->rmItem(itemName);
  if (move != NULL) { // Info on NULL is in the Linked List lesson :)
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
