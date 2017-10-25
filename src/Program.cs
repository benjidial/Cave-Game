using System;
using System.Collections.Generic;

namespace CaveGame
{
  public class Program
  {
    /// <summary>
    /// The room which the player is currently in
    /// </summary>
    public static Room currentRoom;
    /// <summary>
    /// The player
    /// </summary>
    public static Entity player = new Entity(3);
    /// <summary>
    /// The container being held by the player, if any
    /// </summary>
    public static Item container = null;
    static void Main( )
    {
      currentRoom = null;//TODO: Create rooms, make connections
      currentRoom.contents.Add("you", player);
      Console.WriteLine(currentRoom.description);
      Action<string[ ]> a;
      Room r;
      Entity e;
      Item t;
      string s;
      while (true)
      {
        string input = Console.ReadLine().ToLower();
        if (input == "help")
          Console.WriteLine();//TODO: Write snarky help
        else if (currentRoom.commands.TryGetValue(input.Remove(input.IndexOf(' ')), out a))
          a(input.Substring(input.IndexOf(' ') + 1).Split(' '));
        else if (currentRoom.exits.TryGetValue(input, out r))
        {
          currentRoom.onExit();
          currentRoom.contents.Remove("you");
          (currentRoom = r).contents.Add("you", player);
          currentRoom.onEnter();
        }
        else if (input == "look")
          Console.WriteLine(currentRoom.description);
        else if (input.StartsWith("take "))
          if (player.inventory.Count == player.maxItems)
            Console.WriteLine("You have too many items!");
          else if (currentRoom.contents.TryGetValue(s = input.Substring(5), out e))
          {
            try
            {
              Item i = (Item)currentRoom.contents[s];
              if (container != null && i.isContainer)
                Console.WriteLine(/*TODO*/);
              else
              {
                i.onPickup();
                currentRoom.contents.Remove(s);
                player.inventory.Add(s, i);
                if (i.isContainer)
                  container = i;
              }
            }
            catch (InvalidCastException)
            {
              Console.WriteLine("You can't pick that up.");
            }
          }
          else
          {
            foreach (Item c in player.inventory.Values)
              if (c.isContainer && c.inventory.TryGetValue(s, out t))
              {
                t.onPickup();
                c.inventory.Remove(s);
                player.inventory.Add(s, t);
                break;
              }
            Console.WriteLine("I don't see that.");
          }
        else if (input.StartsWith("drop "))
          if (player.inventory.TryGetValue(s = input.Substring(5), out t))
          {
            t.onPutdown();
            player.inventory.Remove(s);
            currentRoom.contents.Add(s, t);
            if (t.isContainer)
              container = null;
          }
          else
            Console.WriteLine("I don't see that.");
        else if (input.StartsWith("store "))
          if (container != null)
            if (player.inventory.TryGetValue(s = input.Substring(6), out t))
            {
              player.inventory.Remove(s);
              container.inventory.Add(s, t);
            }
            else
              Console.WriteLine("You don't have that!");
          else
            Console.WriteLine("You don't have anything to store that in.");
        else
          Console.WriteLine("I don't know what you mean!");
      }
    }
  }
}
