#include <string>
#include <iostream>

/* * * * * * * * * * *
 * Cave Game, room.h *
 * Copyright 2016    *
 * * Benji Dial and  *
   * James Thompson  * *
 * * under MIT License * *
 * This file written by  *
 * * Benji Dial  * * * * *
   * * * * * * * */

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
  nav,
  hear,
  see,
  touch
};

class room
{
public:
  room(string desc, string hear, string see, string touch, int adjacentRooms[], bool canGo[], string failMessages[], string successMessages[])
  {
    m_desc = desc;
    m_hear = hear;
    m_see = see;
    m_touch = touch;
    m_adjacentRooms = adjacentRooms;
    m_canGo = canGo;
    m_failMessages = failMessages;
    m_successMessages = successMessages;
  }

  room *go(direction dir)  //returns new roomId or 0
  {
    if (m_canGo[dir])
    {
      std::cout << m_successMessages[dir] << std::endl;
      return m_adjacentRooms[dir];
    }
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

private:
  string m_desc;
  string m_hear;
  string m_see;
  string m_touch;
  int m_adjacentRooms[];     //Ids
  bool m_canGo[];
  string m_failMessages[];   //Message printed if you can't go that way
  string m_successMessages[];//Message printed if you can go that way
};
