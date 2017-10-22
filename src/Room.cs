using System;
using System.Collections.Generic;

namespace CaveGame
{
  class Room
  {
    public Dictionary<string, Entity> items;
    public Dictionary<string, Room> exits;
    public Dictionary<string, Action<string[ ]>> commands;//Room-specific
    public Action onEnter, onExit;
    public string description;
    public Room(Dictionary<string, Entity> items, Dictionary<string, Room> exits, Dictionary<string, Action<string[ ]>> commands,
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
