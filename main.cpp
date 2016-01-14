#include <string>
#include <iostream>
#include "room.h"
#include "rooms.h"

/* * * * * * * * * * * *
 * Cave Game, main.cpp *
 * Copyright 2016    * *
 * * Benji Dial and  *
   * James Thompson  * *
   * under MIT License *
   * * * * * * * * * * */

int main()
{
  room *currentRoom = &(rooms[1]);
  std::cout << currentRoom->desc << std::endl;
  while (true)
  {
    string input;
    std::cin >> input;
    direction inDir;
    command inCom = nav;
    if (input == "north")
      inDir = north;
    else if (input == "south")
      inDir = south;
    else if (input == "west")
      inDir = west;
    else if (input == "east")
      inDir = east;
    else if (input == "up")
      inDir = up;
    else if (input == "down")
      inDir = down;
    else if (input == "hear")
      inCom = hear;
    else if (input == "see")
      inCom = see;
    else if (input == "touch")
      inCom = touch;
    else
      inCom = invalid;
    switch (inCom)
    {
      case nav:
        int newRoomId = currentRoom->go(inDir);
        if (newRoomId != 0)
        {
          currentRoom = &(rooms[newRoomId]);
          std::cout << currentRoom->desc << std::endl;
        }
        break;
      case invalid:
        std::cout << "I don't understand \"" << input << "\"." << std::endl;
        break;
      default:
        currentRoom->doSense(inCom);
        break;
    }
  }
}
