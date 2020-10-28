# Bubbles

Okay not really a game. I was trying to get an idea of the backend architecture that
would be required to drive collisions. I had in mind Elastic collisions but it turns out many talented people are still trying to figure out the best way to do this. Some problems have to with the computer being binary data, while physics assumes infinite decimals, other problems have to do with reading and writing to the same data ie order updating and double buffer, multiple collisions at the same time, time increments not continuous leading to calculations that lead objects to be inside of each other, dealing with partitioning or optimizations of space are just a few problems or considerations I encountered in doing this project.

Overall I gained a better appreciation for game engines, how they are able to
solve an insurmountable problem. And even then there are bugs or artifacts, but now
I have a better understanding of why those artifacts exist. I'll keep the update logs below as a historical note.

It should be noted that all this was done in C. From the drawing of each circle pixel
by pixel, to the calculation of the forces, the structure and so on.

<br>
<img align="top" height="500" src="https://github.com/ASSERT-game/bubbles/blob/master/resources/bubbles.gif" />
<br>

Update:
Elastic collisions are difficult to do. For example, adding
a positive float vs its negative version produce different
results. I was losing momentum to a wall because of this.

Getting a bug where objects stay stuck inside one another
and this causes the velocities to increase abnormally. I have a guess why this happens, but this collision stuff is hard.