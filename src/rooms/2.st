Room subclass: Room2 [
  init [
    description := 'As your eyes slowly adjust to the gloom, you see that from further down in the cave a faint light emanates.'.
    ^super init
  ]

  read: message with: player [
    (message = 'listen') ifTrue: [
      'Every few seconds you hear the sound of water dripping from the ceiling onto the damp floor.' displayNl.
      ^2
    ].

    (message = 'touch') ifTrue: [
      'The floor and walls are cold and damp, the stone rough, even jagged in some places.' displayNl.
      ^2
    ].

    (message = 'look') ifTrue: [
      'The tunnel of the cave isn''t large, but isn''t small enough to induce claustrophobia.' displayNl.
      ^2
    ].

    (message = 'west') ifTrue: [
      'Staring out the exit of the cave, you see that night has fallen, and that numerous pairs of eyes are staring back at you. You decide to remain in the cave.' displayNl.
      ^2
    ].

    (message = 'up') ifTrue: [
      'A necessary property of caves is enclosure.' displayNl.
      ^2
    ].

    (message = 'down') ifTrue: [
      'The stone floor could not be pierced.' displayNl.
      ^2
    ].

    (message = 'east') ifTrue: [
      'You continue down the tunnel and emerge through the doorway into the light.'.
      ^2
    ].

    ^super read: message with: player at: 2
  ]
]
