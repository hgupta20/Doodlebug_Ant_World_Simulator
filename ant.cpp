#include "Island.h"
#include "ant.h"

void Ant::live(){
	move(); // inherited function
	if (getLastSpawn() >= 3){
		spawn();
	}
	setDayLived(true);
	setLastSpawn(getLastSpawn() +1);
}
bool Ant::spawn(){
	Island *island = getIsland();
	int newXpos = 0;
	int newYpos = 0;
	int lastSpawn = getLastSpawn();
	
	if(lastSpawn <3){
		return false;
	}
	getEmptyPosition(getXPosition(), getYPosition(), newXpos, newYpos);
	
	if (newXpos == -1 && newYpos == -1){
		return false;
	}
	
	Ant *newAnt = new Ant(island);
	island->moveCreature(newAnt->getXPosition(), newAnt->getYPosition(), newXpos, newYpos);
	newAnt->setDayLived(true);
	setLastSpawn(-1);
	return true;
}

