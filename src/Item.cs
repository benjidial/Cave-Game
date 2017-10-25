using System;

namespace CaveGame
{
  /// <summary>
  /// Represents an entity that can be held by an entity
  /// </summary>
  class Item : Entity
  {
    /// <summary>
    /// An action to happen upon the picking up of this item
    /// </summary>
    public Action onPickup;
    /// <summary>
    /// An action to happen upon the putting down of this item
    /// </summary>
    public Action onPutdown;
    /// <summary>
    /// A boolean representing whether or not this item is a container to be held by the player such as a backpack
    /// </summary>
    public readonly bool isContainer;
    /// <summary>
    /// Creates a new item
    /// </summary>
    /// <param name="maxItems">The maximum number of items that can be held by this entity</param>
    /// <param name="onPickup">An action to happen upon the picking up of this item</param>
    /// <param name="onPutdown">An action to happen upon the putting down of this item</param>
    /// <param name="isContainer">A boolean representing whether or not this item is a container to be held by the player such as a backpack</param>
    public Item(int maxItems, Action onPickup = null, Action onPutdown = null, bool isContainer = false)
      : base(maxItems)
    {
      this.onPickup = onPickup ?? (() => {});
      this.onPutdown = onPutdown ?? (() => {});
      this.isContainer = isContainer;
    }
  }
}
