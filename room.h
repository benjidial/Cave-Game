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
  nav,
  hear,
  see,
  touch
};

class room
{
public:
  room(std::string desc, std::string hear, std::string see, std::string touch, int adjacentRooms[], bool canGo[], std::string failMessages[], std::string successMessages[]) :
    m_desc(desc), m_hear(hear), m_see(see), m_touch(touch), m_adjacentRooms(adjacentRooms), m_canGo(canGo), m_failMessages(failMessages), m_successMessages(successMessages)
  {
    if (m_failMessages[north] = "")
      m_failMessages[north] = "The wall is unyielding.";
    if (m_failMessages[south] = "")
      m_failMessages[south] = "The wall is unyielding.";
    if (m_failMessages[west] = "")
      m_failMessages[west] = "The wall is unyielding.";
    if (m_failMessages[east] = "")
      m_failMessages[east] = "The wall is unyielding.";
    if (m_failMessages[up] = "")
      m_failMessages[up] = "The ceiling above seems as steady as, well...rock.";
    if (m_failMessages[down] = "")
      m_failMessages[down] = "The floor doesn�t budge.";
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
  std::string m_desc;
  std::string m_hear;
  std::string m_see;
  std::string m_touch;
  int m_adjacentRooms[];     //Ids
  bool m_canGo[];
  std::string m_failMessages[];   //Message printed if you can't go that way
  std::string m_successMessages[];//Message printed if you can go that way
};
