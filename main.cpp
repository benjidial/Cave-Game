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
  std::cout << "Cave Game, v0.2.0 alpha\nCopyright 2016 Benji Dial and James Thompson\nPlease read the MIT license (http://opensource.org/licenses/MIT) before using.\nYou can see the source at https://github.com/benjidial/Cave-Game.\n" << std::endl;
  room *currentRoom = &(rooms[1]);
  currentRoom->sayDesc();
  while (true)
  {
    std::string input;
    std::cin >> input;
    direction inDir;
    command inCom = nav;
    if (input == "north" || input == "n" || input =="no")
      inDir = north;
    else if (input == "south" || input == "so")
      inDir = south;
    else if (input == "west" || input == "w" || input == "we")
      inDir = west;
    else if (input == "east" || input == "e" || input == "ea")
      inDir = east;
    else if (input == "up" || input == "u")
      inDir = up;
    else if (input == "down" || input == "d" || input == "do")
      inDir = down;
    else if (input == "hear" || input == "listen" || input == "li")
      inCom = hear;
    else if (input == "see" || input == "se" || input == "look" || input == "lo" || input == "view" || input == "v" || input == "vi")
      inCom = see;
    else if (input == "touch" || input == "t" || input == "to" || input == "feel" || input == "f" || input == "fe")
      inCom = touch;
    else if (input == "help")
      inCom = help;
    else if (input.length() == 1)
    {
      inCom = ambiguous;
      switch (input[0])
      {
        case 's':
          std::cout << "South or see?" << std::endl;
          break;
        case 'l':
          std::cout << "Listen or look?" << std::endl;
          break;
        case 'h':
          std::cout << "Hear or help?" << std::endl;
          break;
        default:
          inCom = invalid;
          break;
      }
    }
    else
      inCom = invalid;
    switch (inCom)
    {
      case nav:
        { // Have to destroy newRoomId to make c++ happy
          int newRoomId = currentRoom->go(inDir);
          if (newRoomId != 0)
          {
            currentRoom = &(rooms[newRoomId]);
            currentRoom->sayDesc();
          }
        } // Have to destroy newRoomId to make c++ happy
        break;
      case ambiguous:
        break;
      case invalid:
        std::cout << "I don't understand \"" << input << "\".\nType help for a list of commands." << std::endl;
        break;
      case help:
        std::cout << "To do:     | Type one of:\n";
        std::cout << "----------------------------\n";
        std::cout << "go north   | north  | n | no\n";
        std::cout << "go south   | south  |   | so\n";
        std::cout << "go west    | west   | w | we\n";
        std::cout << "go east    | east   | e | ea\n";
        std::cout << "go up      | up     | u |\n";
        std::cout << "go down    | down   | d | do\n";
        std::cout << "hear room  | hear   |   |\n";
        std::cout << "hear room  | listen |   | li\n";
        std::cout << "see room   | see    |   | se\n";
        std::cout << "see room   | look   |   | lo\n";
        std::cout << "see room   | view   | v | vi\n";
        std::cout << "touch room | touch  | t | to\n";
        std::cout << "touch room | feel   | f | fe\n";
        std::cout << "get help   | help   |   |" << std::endl;
        break;
      default:
        currentRoom->doSense(inCom);
        break;
    }
  }
}
