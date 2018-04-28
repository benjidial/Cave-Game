Entity subclass: Player [
  init [
    maxItems := 3.
    canPickUp := false.
    ^super init
  ]
]

'Cave Game, v0.2.0 alpha' printNl
'Copyright 2016-2018 Benji Dial and James Thompson' printNl
'Please read the MIT license (http://opensource.org/licenses/MIT) before using.' printNl
'You can see the source at https://github.com/benjidial/Cave-Game.' printNl

room := Room0 new.
player := Player new.
Room0 addEntity: player.
true whileTrue: [
  room := room read: (stdin nextLine) with: player
]
