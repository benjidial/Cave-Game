using System;
using System.Collections.Generic;

namespace CaveGame
{
  class Room
  {
    Dictionary<string, Item> items;
    Dictionary<string, Room> exits;
    Dictionary<string, Action> commands;//Room-specific
    Action onEnter, onExit;
    string description;
    public Room(Dictionary<string, Item> items, Dictionary<string, Room> exits, Dictionary<string, Action> commands,
                Action onEnter, Action onExit, string description)
    {
      this.items = items;
      this.exits = exits;
      this.commands = commands;
      this.onEnter = onEnter;
      this.onExit = onExit;
      this.description = description;
    }
  }
}
