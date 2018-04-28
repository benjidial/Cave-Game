Object subclass: Room [
  | contents |

  new [
    | r |
    r := super new.
    r init.
    ^r
  ]

  init [
    contents := Dictionary new
  ]
]
