Object subclass: Entity [
  | inventory maxItems canPickUp name |

  init [
    inventory := Dictionary new
  ]

  canPickUp [
    ^canPickUp
  ]

  pickUp: player [
    ^true
  ]

  drop [
    ^true
  ]

  getName [
    ^name
  ]
].

Entity class extend [
  new [
    | r |
    r := super new.
    r init.
    ^r
  ]
]
