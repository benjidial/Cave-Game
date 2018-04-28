Object subclass: Room [
  | contents description roomlist |

  add: room [
    roomlist add: room
  ]

  new [
    | r |
    r := super new.
    r init.
    ^r
  ]

  init [
    contents := Dictionary new
    roomlist := Set new
  ]

  read: message with: player [
    | split first rest item |

    (message = 'look') ifTrue [
      description printNl.
      ^self
    ].

    first := (split := message substrings) at: 1.
    rest := split allButFirst.

    (first = 'take') ifTrue [
      ((contents includesKey: rest) and ((item := contents at: rest) canPickUp)) ifTrue [
        (player pickUp: item) ifTrue [
          contents removeKey rest
        ]
      ]
      ^self
    ].

    (first = 'drop') ifTrue [
      player drop: rest to: room.
      ^self
    ].

    'I don''t know what you mean!' printNl
  ]

  drop: item [
    contents at: item getName put: item
  ]
]
