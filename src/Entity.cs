using System;
using System.Collections.Generic;

namespace CaveGame
{
  class Entity
  {
    public Dictionary<string, Item> inventory;
    public int maxItems;
    public Entity(int maxItems)
    {
      inventory = new Dictionary<string, Item>();
      this.maxItems = maxItems;
    }
  }
}
