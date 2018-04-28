'Cave Game, v0.2.0 alpha' printNl
'Copyright 2016-2018 Benji Dial and James Thompson' printNl
'Please read the MIT license (http://opensource.org/licenses/MIT) before using.' printNl
'You can see the source at https://github.com/benjidial/Cave-Game.' printNl

Room add: (room := Room0 new).
Room add: (Room1 new).
Room add: (Room2 new).
Room add: (Room3 new).
Room add: (Room4 new).
Room add: (Room5 new).
Room add: (Room6 new).
Room add: (Room7 new).
room addEntity: (player := Player new).
true whileTrue: [
  room := room read: (stdin nextLine) with: player
]
