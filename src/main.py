from player import *
from rooms import *

player = new Player()
room = rooms[0]

while True:
  room = room.read(raw_input(), player)
