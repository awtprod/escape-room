## Escape Room Game
### Application Overview
This game was my final project in my Introduction to Computer Science class. The premise of the game is that you are unsuspecting passerby that is lured and trapped into a house. To get out, you must search the house for the key to unlock the door. The catch is that there are many keys inside and only one works. Also, you must eat a cookie to take a step or else you will die. You can refill on cookies in the kitchen but you must make it back before dying.

### Technical Overview
The game uses class inheritance to create the different rooms. There is a generic space class of which the kitchen, outside, and the rooms are derived from. Pointers are used as "keys" in the game. Each time the user collects a key, it's added to a queue. When the user attempts to unlock the door, all of the keys in the queue are compared with the key stored in the outside object. If there's a match, the door is unlocked and the user wins, otherwise they are asked to keep searching.

### Lessons Learned
