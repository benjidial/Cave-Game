using System;
using System.Collections.Generic;

namespace CaveGame
{
  /// <summary>
  /// Represents a room
  /// </summary>
  class Room
  {
    /// <summary>
    /// A dictionary mapping the names of the entities in this room to those entities
    /// </summary>
    public Dictionary<string, Entity> contents;
    /// <summary>
    /// A dictionary mapping the names of the exits from this room to the rooms led to by those exits
    /// </summary>
    public Dictionary<string, Room> exits;
    /// <summary>
    /// A dictionary mapping room-specific commands to the action to be performed on the arguments to those commands when they are run
    /// </summary>
    public Dictionary<string, Action<string[ ]>> commands;
    /// <summary>
    /// The action to happen upon entering this room
    /// </summary>
    public Action onEnter;
    /// <summary>
    /// The action to happen upon leaving this room
    /// </summary>
    public Action onExit;
    /// <summary>
    /// A description of this room
    /// </summary>
    public string description;
    /// <summary>
    /// Creates a new room
    /// </summary>
    /// <param name="description">A description of this room</param>
    /// <param name="exits">A dictionary mapping the names of the exits from this room to the rooms led to by those exits</param>
    /// <param name="contents">A dictionary mapping the names of the entities in this room to those entities</param>
    /// <param name="onEnter">The action to happen upon entering this room</param>
    /// <param name="onExit">The action to happen upon leaving this room</param>
    /// <param name="commands">A dictionary mapping room-specific commands to the action to be performed on the arguments to those commands when they are run</param>
    public Room(string description, Dictionary<string, Room> exits = null, Dictionary<string, Entity> contents = null, Action onEnter = null, Action onExit = null, Dictionary<string, Action<string[ ]>> commands = null)
    {
      this.contents = contents ?? new Dictionary<string, Entity>();
      this.exits = exits ?? new Dictionary<string, Room>();
      this.commands = commands ?? new Dictionary<string, Action<string[ ]>>();
      this.onEnter = onEnter ?? (() => {});
      this.onExit = onExit ?? (() => {});
      this.description = description;
    }
  }
}
