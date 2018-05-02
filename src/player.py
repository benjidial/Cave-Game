from entity import *

class Player(Entity):
  def __init__():
    self.inventory_size = 3
    self.name = 'the player'

  def pick_up(item, self):
    if self.inventory.size() > self.inventory_size:
      print 'You can\'t carry that much!'
      return False
    if base(item):
      print 'You pick up %s.' % item.name
      return True
    print '%s doesn\'t let you pick it up.' % item.name
    return False

  def drop(item, self):
    if base():
      print 'You drop %s.' % item.name
      return True
    print '%s doesn\'t let you drop it.' % item.name
    return False
