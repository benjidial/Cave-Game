Object subclass: Entity [
  | inventory maxItems canPickUp name |

  new [
    | r |
    r := super new.
    r init.
    ^r
  ]

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
]
