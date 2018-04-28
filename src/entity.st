Object subclass: Entity [
  | inventory maxItems canPickUp |

  new [
    | r |
    r := super new.
    r init.
    ^r
  ]

  init [
    inventory := Dictionary new
  ]
]
