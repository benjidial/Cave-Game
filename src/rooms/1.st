Room subclass: Room1 [
  init [
    description := 'It is a warm, summer evening.  You are standing in a large field, and starting into the depths of a dark and foreboding cave to the east.'.
    ^super init
  ]

  read: message with: player [
    (message = 'east') ifTrue [
      'You cautiously step into the cave.' printNl.
      ^roomlist at: 1
    ].

    (message = 'listen') ifTrue [
      'You hear bagpipes in the distance' printNl.
    ].

    (message = 'feel') ifTrue [
      'The ground feels like... I think... I've got it!  Ground!'
    ].

    (message = 'north') ifTrue [
      'The forest to your north is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.' printNl
    ].

    (message = 'south') ifTrue [
      'The forest to your south is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.' printNl
    ].

    (message = 'west') ifTrue [
      'The forest to your west is lush and dense.  You doubt you can breach the thick foliage, and wonder how you even arrived here.  Come to think of it, you aren't really sure of anything at all before you awoke in the field.  A sudden and powerful inclination urges you to disembark from this train of thought, so you do.' printNl
    ].

    ^super read
  ]
]
