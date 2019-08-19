
#include "Island.h"
#include "doodleBug.h"

bool DoodleBug::hunt()
{
  int newXpos = -1;
  int newYpos = -1;
  int x = getXPosition();
  int y = getYPosition();

  if (getIsland()->isValid(x, y - 1)) {
	  if (getIsland()->getCurrentInsect(x, y - 1) == '*'){
		  newXpos = x;
		  newYpos = y - 1;
	  }
  }
  if (getIsland()->isValid(x, y + 1)) {
	  if (getIsland()->getCurrentInsect(x, y + 1) == '*') {
		  newXpos = x;
		  newYpos = y + 1;
	  }

  }
  if (getIsland()->isValid(x - 1, y)) {
	  if (getIsland()->getCurrentInsect(x - 1, y) == '*') {
		  newXpos = x - 1;
		  newYpos = y;
	  }


  }
  if (getIsland()->isValid(x + 1, y)) {
	  if (getIsland()->getCurrentInsect(x + 1, y) == '*') {
		  newXpos = x+1;
		  newYpos = y;
	  }

  }

  if (newXpos == -1 && newYpos == -1) {
    return false;
  }
  if (!getIsland()->killCreature(newXpos, newYpos)){
    return false;
  }
  if ( !getIsland()->moveCreature(getXPosition(), getYPosition(), newXpos, newYpos) ) {
    return false;
  }  

  setXPosition(newXpos);
  setYPosition(newYpos);
  setLastEaten(-1); // change last Eaten

  return true;
}

bool DoodleBug::spawn()
{
  Island *island = getIsland();
  int lastSpawn = getLastSpawn();
  int newXpos = 0;
  int newYpos = 0;

  if (lastSpawn < 8) {
    return false;
  }

  getEmptyPosition(getXPosition(), getYPosition(), newXpos, newYpos);

  // No spots available
  if (newXpos == -1 && newYpos == -1) {
    return false;
  }

  DoodleBug *newBug = new DoodleBug(island);
  island->moveCreature(newBug->getXPosition(), newBug->getYPosition(), newXpos, newYpos);

  lastEaten=0;

  newBug->setDayLived(true);

  setLastSpawn(-1);
  return true;
}

void DoodleBug::live()
{
  if (!hunt() ) {
    // if didnt hunt then move
    move();
  }

  if (getLastSpawn() >= 8) {
    spawn();
    //getIsland()->addCreature( Creature::Insect::DOODLEBUG );
  }

  if (getLastEaten() >= 3) {
    getIsland()->killCreature( getXPosition(), getYPosition() );
    return;
  }

  setDayLived(true);
  setLastEaten( getLastEaten() + 1 );
  setLastSpawn( getLastSpawn() + 1 );
}

