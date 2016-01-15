#pragma once

#include <string>
#include <iostream>

/* * * * * * * * * * *
 * Cave Game, room.h *
 * Copyright 2016    *
 * * Benji Dial and  *
   * James Thompson  * *
   * under MIT License *
   * * * * * * * * * * */

enum direction
{
  north = 0,
  south,
  west,
  east,
  up,
  down
};

enum command
{
  invalid = 0,
  ambiguous,
  nav,
  hear,
  see,
  touch,
  help
};

class room
{
public:
  room(std::string desc, std::string hear, std::string see, std::string touch,
    int arn, int ars, int arw, int are, int aru, int ard,      //adjacent rooms' ids
    bool cgn, bool cgs, bool cgw, bool cge, bool cgu, bool cgd,//can go to adjacent rooms
    std::string fmn, std::string fms, std::string fmw,         //fail messages
    std::string fme, std::string fmu, std::string fmd,         //more fail messages
    std::string smn, std::string sms, std::string smw,         //success messages
    std::string sme, std::string smu, std::string smd) :       //more success messages
    m_desc(desc), m_hear(hear), m_see(see), m_touch(touch)
  {
    m_adjacentRooms[0] = arn;
    m_adjacentRooms[1] = ars;
    m_adjacentRooms[2] = arw;
    m_adjacentRooms[3] = are;
    m_adjacentRooms[4] = aru;
    m_adjacentRooms[5] = ard;
    m_canGo[0] = cgn;
    m_canGo[1] = cgs;
    m_canGo[2] = cgw;
    m_canGo[3] = cge;
    m_canGo[4] = cgu;
    m_canGo[5] = cgd;
    m_failMessages[0] = fmn;
    m_failMessages[1] = fms;
    m_failMessages[2] = fmw;
    m_failMessages[3] = fme;
    m_failMessages[4] = fmu;
    m_failMessages[5] = fmd;
    m_successMessages[0] = smn;
    m_successMessages[1] = sms;
    m_successMessages[2] = smw;
    m_successMessages[3] = sme;
    m_successMessages[4] = smu;
    m_successMessages[5] = smd;
  }

  int go(direction dir)  //returns new roomId or 0
  {
    if (m_canGo[dir])
    {
      std::cout << m_successMessages[dir] << std::endl;
      return m_adjacentRooms[dir];
    }
    if (m_failMessages[dir] == "")
      switch (dir)
      {
        case north:
        case south:
        case west:
        case east:
          std::cout << "The wall is unyielding." << std::endl;
          break;
        case up:
          std::cout << "The ceiling above seems as steady as, well... rock." << std::endl;
          break;
        case down:
          std::cout << "The floor doesn't budge." << std::endl;
          break;
      }
    else
      std::cout << m_failMessages[dir] << std::endl;
    return 0;
  }

  void doSense(command sense)
  {
    switch (sense)
    {
      case hear:
        std::cout << m_hear << std::endl;
        break;
      case see:
        std::cout << m_see << std::endl;
        break;
      case touch:
        std::cout << m_touch << std::endl;
        break;
    }
  }

  void sayDesc()
  {
    std::cout << m_desc << std::endl;
  }

private:
  std::string m_desc;
  std::string m_hear;
  std::string m_see;
  std::string m_touch;
  int m_adjacentRooms[6];//Ids
  bool m_canGo[6];
  std::string m_failMessages[6];   //Message printed if you can't go that way
  std::string m_successMessages[6];//Message printed if you can go that way
};
