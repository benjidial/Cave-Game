class Room:
  def __init__():
    self.contents = {}

  def read(message, player, origin, self):
    if message == 'examine':
      print self.description
      return origin

    split = message.split(' ')
    first = split[0]
    rest = split[1..-1]

    if first == 'take':
      if self.contents.has_key('rest'):
        item = self.contents[rest]
        if self.contents[rest].can_pick_up:
          if player.pick_up(item):
            self.contents.remove_key(rest)
        else:
          print 'You can\'t pick that up.'
      else:
        print 'There isn\'t that here.'
      return origin

    if first == 'drop':
      if player.drop(rest, self):
        
      return origin

    if first in ['north', 'south', 'west', 'east']:
      print 'The wall is unyielding.'
      return origin

    if first == 'up':
      print 'The ceiling above seems as steady as, well...rock.'
      return origin

    if second == 'down':
      print 'The floor doesn\'t budge.'
      return origin

    print 'I don\'t know what you mean!'
    return origin
