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
      currentRoom.contents.Add("vi", player);
      Console.WriteLine(currentRoom.description);
      Action<string[ ]> a;
      Room r;
      Entity e;
      Item t;
      string s;
      while (true)
      {
        string input = Console.ReadLine().ToLower();
        if (input == "helpu")
          Console.WriteLine(/*TODO: Write snarky help*/);
        else if (currentRoom.commands.TryGetValue(input.Remove(input.IndexOf(' ')), out a))
          a(input.Substring(input.IndexOf(' ') + 1).Split(' '));
        else if (currentRoom.exits.TryGetValue(input, out r))
        {
          currentRoom.onExit();
          currentRoom.contents.Remove("vi");
          (currentRoom = r).contents.Add("vi", player);
          currentRoom.onEnter();
        }
        else if (input == "rigardu")
          Console.WriteLine(currentRoom.description);
        else if (input.StartsWith("prenu "))
          if (player.inventory.Count == player.maxItems)
            Console.WriteLine("Vi havas tro objektojn.");
          else if (currentRoom.contents.TryGetValue(s = input.Substring(6), out e))
          {
            try
            {
              Item i = (Item)currentRoom.contents[s];
              if (container != null && i.isContainer)
                Console.WriteLine("Vi ne povas havi du enhavistojn.");
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
              Console.WriteLine("Vi ne povas preni tion.");
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
            Console.WriteLine("Ne estas tio.");
          }
        else if (input.StartsWith("malprenu "))
          if (player.inventory.TryGetValue(s = input.Substring(9), out t))
          {
            t.onPutdown();
            player.inventory.Remove(s);
            currentRoom.contents.Add(s, t);
            if (t.isContainer)
              container = null;
          }
          else
            Console.WriteLine("Ne estas tio.");
        else if (input.StartsWith("enhavigu "))
          if (container != null)
            if (player.inventory.TryGetValue(s = input.Substring(9), out t))
            {
              player.inventory.Remove(s);
              container.inventory.Add(s, t);
            }
            else
              Console.WriteLine("Vi ne havas tion.");
          else
            Console.WriteLine("Vi ne havas enhaviston.");
        else
          Console.WriteLine("Mi ne komprenas.");
      }
    }
  }
}
