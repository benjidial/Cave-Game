using System;
using System.Collections.Generic;

namespace CaveGame
{
  class Item : Entity
  {
    public Action onPickup;
    public Action onPutdown;
    public bool isContainer;
    public Item(Action onPickup, Action onPutdown, int maxItems, bool isContainer = false)
      : base(maxItems)
    {
      this.onPickup = onPickup;
      this.onPutdown = onPutdown;
      this.isContainer = isContainer;
    }
  }
}
