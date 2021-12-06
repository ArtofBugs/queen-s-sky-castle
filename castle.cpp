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

// Items in the castle, which have a name and ________.
Struct Item {
  char* name;
  // location?;
};

const int maxNameLength = 100; // Maximum character length of room names
const int maxDescLength = 1000; // Maximum character length of room descriptions

int main() {

  cout << "Welcome to the Queen's Sky Castle - Zuul!" << endl;


  while (!balcony->containsItem(crown)) {

  }
  cout << "You won! Thank you for playing!" << endl;
  //map stuff




  return 0;
}
balcony.addItem(crown);

// Set up rooms, names, descriptions, items, and locations
void initializeRooms() {
  char* newName = new char[maxNameLength];
  char* newDesc = new char[maxDescLength];
  Room* inventory = new Room(); // Player inventory acts like a room not on the

  Room* bedroom = new Room();

  bedroom.setName();
  Room* balcony = new Room();
  Item* crown = new Item();
  bedroom.addItem(crown);


}

void printHelp() {
  cout << "Welcome to the queen's sky castle. Explore the castle and move objects to try to win the grand prize!" << endl;
  cout << "Your command words are:" << endl;

}
