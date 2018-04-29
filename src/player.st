Entity subclass: Player [
  init [
    maxItems := 3.
    canPickUp := false.
    name := 'Player'.
    ^super init
  ]

  pickUp: item [
    (inventory size = maxItems) ifTrue: [
      ^false
    ].
    (item pickUp: self) ifFalse: [
      ^false
    ].
    inventory at: item getName put: item.
    ^true
  ]

  drop: item to: room [
    | entity |
    (inventory includesKey: item) ifFalse: [
      ^false
    ].
    (entity := inventory at: item) drop ifFalse: [
      ^false
    ].
    room drop: entity.
    inventory removeKey: item.
    ^true
  ]
]
