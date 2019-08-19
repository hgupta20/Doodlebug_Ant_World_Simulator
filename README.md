# Doodlebug_Ant_World_Simulator
A real life simulator where the planet is haunted by doodle bugs and ants. 

The simulation is a predator/prey scenario. Such simulations are fairly common and many variations of such simulations exist. The primary differences between these simulations are the rules by which the predator/prey entities live. 
Here, the doodlebugs will be the predator creature and the ants will prey creature. 

As the simulation runs, you will see the doodlebug population and the ant population grow and shrink in a cyclic manner; however, the built-in randomness may cause one or both creatures to die out completely.
In this simulation, the time will advance in “days”. The simulation will occur in a grid of 20x20 locations. 

We will randomly place down 5 doodlebugs and 100 ants into the grid to start the start of the simulation. Only one creature can exist in a location at any given time. So if the original intended location of a doodlebug or ant is already occupied, you will need to find a different location. At the end of each “day”, your program is to update an instance of the GridDisplay class showing the current locations of all doodlebugs, all ant and all empty positions. You are to use the mySleep( ) method to allow the changes per day to be noticeable by the user.
During each day of the simulation, the doodlebugs must all move first, then the ants will move after the doodlebugs. 

#### When a doodlebug moves on a given day it will do all of the following operations in the order given:
1. hunt – if there is an ant at an adjacent location (up, down, left or right), the doodblebug will move to that location and eat the ant. Otherwise move - (when it does not eat an ant), the doodlebug will pick a random direction (up, down, left or right) and attempts to move to the adjacent location in that direction. If that location is already occupied by another doodlebug or that location does not exist (because the doodlebug is at the edge of the grid), the doodlebug will not move to a different location but stay in its current location.
2. spawn – if the doodlebug has survived for 8 days, it will attempt to create a new
doodlebug. The new doodlebug will “be born” in an empty location adjacent (up, down, left or
right) to the parent doodlebug. If there is no empty adjacent location, no new doodlebug will be
born. Once a doodlebug has produced an offspring, it cannot produce another offspring until 8
more days has elapsed.
3. starve – if the doodlebug has not eaten an ant during the last 3 days, it will starve and
die. When a doodlebug dies, the grid location it is on becomes empty.
#### When an ant moves on a given day it will do all of the following operations in the order given:
1. move – the ants will pick a random direction (up, down, left or right) and attempts to
move to the adjacent location in that direction. If that location is already occupied by another
doodlebug or another ant or that location does not exist (because the ant is at the edge of the
grid), the ant will not move to a different location but stay in its current location.
2. spawn – if the ant has survived for 3 days, it will create a new ant. This new ant will “be
born” in an empty location adjacent (up, down, left or right) to the parent ant. If there is no
empty adjacent location, no new ant will be born. Once an ant has produced an offspring, it
cannot produce another offspring until 3 more days has elapsed.
Note that in one day a doodlebug could move to an adjacent location, spawn a new doodlebug,
and die of starvation. Also note that if a doodlebug cannot spawn on the 8th day because there is
no empty adjacent location, it will try to spawn on the 9th day. Also, note that ants only “die“
when eaten, they never starve.

#### To run the program type: "make" followed by "./hgupta20Proj7 -d"

#### and the miliseconds of delay between each day in the simulation.
