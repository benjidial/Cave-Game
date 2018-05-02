class Room:
  def __init__():
    self.contents = {}

  def read(message, player, self):
    if message == 'examine':
      print self.description
      return self

    split = message.split(' ')
    first = split[0]
    rest = split[1..-1]

    if first == 'take':
      if self.contents.has_key('rest'):
        item = self.contents[rest]
        if self.contents[rest].can_pick_up:
          if player.pick_up(item):
            self.contents.remove_key(rest)
            player.inventory[rest] = item
        else:
          print '%s can not be picked up.' % rest
      else:
        print 'There isn\'t %s here.' % rest
      return self

    if first == 'drop':
      if player.inventory.has_key(rest):
        if player.drop(rest, self):
          self.contents[rest] = player.inventory[rest]
          player.inventory.remove_key(rest)
      else:
        print 'You aren\'t carrying %s' % rest
      return self

    if first in ['north', 'south', 'west', 'east']:
      print 'The wall is unyielding.'
      return self

    if first == 'up':
      print 'The ceiling above seems as steady as, well...rock.'
      return self

    if second == 'down':
      print 'The floor doesn\'t budge.'
      return self

    print 'I don\'t know what you mean!'
    return self
