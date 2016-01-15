#pragma once

#include "room.h"
#include <string>

/* * * * * * * * * * * *
 * Cave Game, rooms.h  *
 * Copyright 2016    * *
 * * Benji Dial and  *
   * James Thompson  * *
   * under MIT License *
   * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * *
 * /--   |--\  /--\  -||-  |     |--   |--\  *
 * \--\  |--/  |  |   ||   |     |--   |--/  *
 *  --/  |     \--/  -||-  |--   |--   |  \  *
 *                                           *
 *       /--\  |     |--   |--\  -||-        *
 *       |--|  |     |--   |--/   ||         *
 *       |  |  |--   |--   |  \   ||         *
 *                                           *
 * * * * * * * * * * * * * * * * * * * * * * *
This file contains all of the room descriptions and relations.
If you don't want anything spoiled, don't read past this line.
\*__________________________________________________________*/

room rooms[] =
{
  /* Offset so Room 01 is rooms[1] */
  room("", "", "", "", 0, 0, 0, 0, 0, 0, false, false, false, false, false, false, "", "", "", "", "", "", "", "", "", "", "", ""),

  /* Room 01 */
  room("It is a warm, summer evening.  You are standing in a large field, and staring into the depths of a dark and foreboding cave to the east.",
       "You hear bagpipes playing in the distance.",
       "Stray beams from the setting sun pierce the gloomy interior, and you see that the cave slopes sharply downward.  Behind you and on both sides is a dense forest, the foliage so thick you have little hope of penetrating it.",
       "The ground feels like... I think... I've got it!  Ground!",
       0, 0, 0, 2, 0, 0, false, false, false, true, false, false,
       "The forest to your north is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.",
       "The forest to your south is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.",
       "The forest to your west is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.",
       "",
       "You try to fly, then discover you can't.",
       "You are, as it turns out, not a mole.",
       "",
       "",
       "",
       "You cautiously step into the cave.",
       "",
       ""),

  /* Room 02 */
  room("As your eyes slowly adjust to the gloom, you see that from further down in the cave a faint light emanates.",
       "Every few seconds you hear the sound of water dripping from the ceiling onto the damp floor.",
       "The tunnel of the cave isn't large, but isn't small enough to induce claustrophobia.",
       "The floor and walls are cold and damp, the stone rough, even jagged in some places.",
       3, 0, 0, 4, 0, 0, false, false, false, true, false, false,
       "",//Default
       "",//Default
       "Staring out the exit of the cave, you see that night has fallen, and that numerous pairs of eyes are staring back at you. You decide to remain in the cave.",
       "",
       "A necessary property of caves is enclosure.",
       "The stone floor could not be pierced.",
       "You go through the newly created entrance.",
       "",
       "",
       "You continue down the tunnel and emerge through the doorway into the light.",
       "",
       ""),

  /* Room 03 */
  room("", "", "", "", 0, 0, 0, 0, 0, 0, false, false, false, false, false, false, "", "", "", "", "", "", "", "", "", "", "", ""),
  //^TODO: Room 03^

  /* Room 04 */
  room("You are in a dimly-lit chamber. A bundle of sheets takes up one corner, and a sword hangs on the opposite wall. Beside that sword is what appears to be a place for another, though nothing is there. Many gleaming, golden coins are heaped on a small wooden table.",
       "You hear the muffled sound of what might be footsteps. You'd better grab what you can.",
       "A half-eaten apple is also on the table, and you think you glimpse a piece of parchment under the pillow.",
       "The walls of the room are as rough as those of the tunnel leading to it.",
       0, 5, 0, 0, 0, 0, false, true, false, false, false, false,
       "",//Default
       "",
       "Worried that the smuggler may soon return, you accept that the only route to take is deeper into the cave.",
       "",//Default
       "",//Default
       "",//Default
       "",
       "You hurry through an adjoining tunnel as the smuggler enters the room behind you.",
       "",
       "",
       "",
       ""),

  /* Room 05 */
  //TODO: Room 05

  /*And so on*/
};
