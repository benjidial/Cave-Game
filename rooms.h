#include "room.h"
#include <string>

/* * * * * * * * * * * *
 * Cave Game, rooms.h  *
 * Copyright 2016    * *
 * * Benji Dial and  *
   * James Thompson  * *
   * under MIT License *
   * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * *
 * /--   |--\  /--\  |     |--   |--\  *
 * \--\  |--/  |  |  |     |--   |--/  *
 *  --/  |     \--/  |--   |--   |  \  *
 *                                     *
 * /--\  |     |--   |--\  -||-   ||   *
 * |--|  |     |--   |--/   ||    ||   *
 * |  |  |--   |--   |  \   ||    --   *
 *                                     *
 * * * * * * * * * * * * * * * * * * * *
This file contains all of the room descriptions and relations.
If you don't want anything spoiled, don't read past this line.
\*__________________________________________________________*/

room *rooms[] =
{
  /* Offset so Room 01 is *(rooms[1]) */
  0,
  
  /* Room 01 */
  room("It is a warm, summer evening.  You are standing in a large field, and staring into the depths of a dark and foreboding cave to the east.",
       "You hear bagpipes playing in the distance.",
       "Stray beams from the setting sun pierce the gloomy interior, and you see that the cave slopes sharply downward.  Behind you and on both sides is a dense forest, the foliage so thick you have little hope of penetrating it.",
       "The ground feels like... I think... I've got it!  Ground!",
       {0, 0, 0, 2, 0, 0}, {false, false, false, true, false, false}, { //TODO: Confirm up, down
       "The forest to your north is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to cease this train of thought, so you do.",
       "The forest to your south is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to cease this train of thought, so you do.",
       "The forest to your west is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to cease this train of thought, so you do.",
       "",
       "",   //TODO: up   fail
       ""}, {//TODO: down fail
       "",
       "",
       "",
       "",   //TODO: east succ
       "",   //TODO: up   succ
       ""}), //TODO: down succ

  /* Room 02 */
  //TODO: Room 02

  /* Room 03 */
  //TODO: Room 03

  /* Room 04 */
  //TODO: Room 04

  /* Room 05 */
  //TODO: Room 05

  /*And so on*/
}
