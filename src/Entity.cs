using System;
using System.Collections.Generic;

namespace CaveGame
{
  /// <summary>
  /// Represents something that exists and can move between rooms
  /// </summary>
  class Entity
  {
    /// <summary>
    /// A dictionary mapping the names of the items held by this entity, if any, to those items
    /// </summary>
    public Dictionary<string, Item> inventory;
    /// <summary>
    /// The maximum number of items that can be held by this entity
    /// </summary>
    public int maxItems;
    /// <summary>
    /// Creates a new entity
    /// </summary>
    /// <param name="maxItems">The maximum number of items that can be held by this entity</param>
    public Entity(int maxItems)
    {
      inventory = new Dictionary<string, Item>(this.maxItems = maxItems);
    }
  }
}
