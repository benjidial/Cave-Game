'Cave Game, v0.2.0 alpha' displayNl.
'Copyright 2016–2018 Benji Dial and James Thompson' displayNl.
'Please read the MIT license (http://opensource.org/licenses/MIT) before using.' displayNl.
'You can see the source at https://github.com/benjidial/Cave-Game.' displayNl.

"This will be changed to 7 by v0.2.0:"
Room initlist: 2.
Room add: (Room1 new) at: 1.
Room add: (Room2 new) at: 2.
"Room add: (Room3 new) at: 3."
"Room add: (Room4 new) at: 4."
"Room add: (Room5 new) at: 5."
"Room add: (Room6 new) at: 6."
"Room add: (Room7 new) at: 7."
room := 1
(Room getRoom: room) drop: (player := Player new).
[ room := (Room getRoom: room) read: (stdin nextLine) with: player ] repeat
