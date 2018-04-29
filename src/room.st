Object subclass: Room [
  | contents description |

  init [
    contents := Dictionary new
  ]

  read: message with: player [
    | split first rest item |

    (message = 'look') ifTrue: [
      description displayNl.
      ^self
    ].

    first := (split := message substrings) at: 1.
    rest := split allButFirst.

    (first = 'take') ifTrue: [
      ((contents includesKey: rest) and: ((item := contents at: rest) canPickUp)) ifTrue: [
        (player pickUp: item) ifTrue: [
          contents removeKey rest
        ]
      ].
      ^self
    ].

    (first = 'drop') ifTrue: [
      player drop: rest to: self.
      ^self
    ].

    'I don''t know what you mean!' displayNl
  ]

  drop: item [
    contents at: item getName put: item
  ]
].

Room class extend [
  | roomlist |

  initlist: size [
    roomlist := Array new: size
  ]

  add: room at: id [
    roomlist at: id put: room
  ]

  new [
    | r |
    r := super new.
    r init.
    ^r
  ]

  getRoom: id [
    ^roomlist at: id
  ]
]
