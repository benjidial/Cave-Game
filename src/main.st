Entity subclass: Player [
  init [
    maxItems := 3.
    canPickUp := false.
    ^super init
  ]
]

room := Room0 new.
player := Player new.
Room0 addEntity: player.
true whileTrue: [
  room := room read: (stdin nextLine) with: player
]
