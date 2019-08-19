#include <iostream>

#include "Island.h"
#include "Creature.h"

Creature::Creature(Island *island, char t)
{
  setIsland(island);

  int x = rand() % island->getRows();
  int y = rand() % island->getCols();
  
  while ( !(island->isValid(x, y) && !island->isOccupied(x, y)) ){
    x = rand() % island->getRows();
    y = rand() % island->getCols();

  }
  insect= t;
  xPosition=x;
  yPosition=y;
  daylived=false;
  lastSpawned=0;
  //setXPosition(x);
  //setYPosition(y);
  //setInsect(t);
  //setDayLived(false);
  //setLastSpawn(0);

  island->addCreature(this);
}

void Creature::getEmptyPosition( int x,  int y, int& newXpos, int& newYpos)
{
  Island *island = getIsland();

  int filledSpots = 0;

  if ( island->isValid(x, y - 1) ) {
    if ( island->isOccupied(x, y - 1) ) {
      filledSpots++;
    }
  } else {
    filledSpots++;
  }

  if ( island->isValid(x, y + 1) ) {
    if ( island->isOccupied(x, y + 1) ) {
      filledSpots++;
    }
  } else {
    filledSpots++;
  }

  if ( island->isValid(x - 1, y) ) {
    if ( island->isOccupied(x - 1, y) ) {
      filledSpots++;
    }
  } else {
    filledSpots++;
  }

  if ( island->isValid(x + 1, y) ) {
    if ( island->isOccupied(x + 1, y) ) {
      filledSpots++;
    }
  } else {
    filledSpots++;
  }

  // No spots available
  if (filledSpots >= 4) {
    newXpos = -1;
    newYpos = -1;
    return;
  }

    int spot = rand() % 4;
    while ( !(island->isValid(newXpos, newYpos) && !island->isOccupied(newXpos, newYpos))){
    	if(spot==0){
    		newXpos = x-1;
        	newYpos = y;
		}
		else if(spot==1){
    		newXpos = x+1;
        	newYpos = y;
		}
		else if(spot==2){
    		newXpos = x;
        	newYpos = y - 1;
		}
		else if(spot==3){
    		newXpos = x;
        	newYpos = y + 1;
		}
		else{
			break;
		}
		spot = rand()%4;
	}   
}

bool Creature::move()
{
  int newXpos = 0;
  int newYpos = 0;

  getEmptyPosition(getXPosition(), getYPosition(), newXpos, newYpos);

  // No adjacent spots available
  if (newXpos == -1 && newYpos == -1) {
    return false;
  }

  if ( !getIsland()->moveCreature(getXPosition(), getYPosition(), newXpos, newYpos) ) {
    return false;
  }

  setXPosition(newXpos);
  setYPosition(newYpos);
  return true;
}

