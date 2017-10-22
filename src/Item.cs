using System;
using System.Collections.Generic;

namespace CaveGame
{
  class Item : Entity
  {
    Action onPickup;
    Action onPutdown;
    public Item(Action onPickup, Action onPutdown)
    {
      this.onPickup = onPickup;
      this.onPutdown = onPutdown;
    }
  }
}
