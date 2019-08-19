#include "Island.h"

Island::Island(GridDisplay *grid){
	setGrid(grid);
	setRows(20);
	setCols(20);
	
	//set the grid for creatures
	newCreatures = new Creature**[getRows()];
	int r= getRows();
	int c= getCols();
	for(int i=0; i< r; i++){
		newCreatures[i] = new Creature*[c];
		for(int j=0; j< c; j++){
			newCreatures[i][j] = nullptr;		
		}	
	}
	
}
bool Island::isValid ( int r,  int c){
    if (( r >= 0 && r < getRows() ) && ( c >= 0 && c < getCols())){
    	return true;
	}
    else{
    	return false;
	}

}
   
bool Island::isOccupied ( int r,  int c) {
	if (newCreatures[r][c] == nullptr){
		return false;
	}
	else{
		return true;
	}
}
bool Island::addCreature (Creature *creature){
	int r = creature->getXPosition();
	int c = creature->getYPosition();
    // verify to location is valid
    if ( isValid (r, c) == false )
      return false;
    // verify to location is empty
    if ( isOccupied (r, c) == true)
      return false;

    
	newCreatures[r][c] = creature;
    grid->setChar (r,c,creature->getInsect());
    return true;
}

bool Island::moveCreature ( int currX,  int currY, int nextX, int nextY){
    // verify to/from locations are valid
    if ( isValid (currX, currY) == false )
      return false;
    if ( isValid (nextX, nextY) == false )
      return false;
    // verify a beetle exists at current location
    if ( isOccupied (currX, currY) == false)
      return false;
    // verify to location is empty
    if ( isOccupied (nextX, nextY) == true)
      return false;
    char currInsect = newCreatures[currX][currY]->getInsect();
    newCreatures[nextX][nextY] = newCreatures[currX][currY]; 
    newCreatures[nextX][nextY]->setXPosition(nextX);
    newCreatures[nextX][nextY]->setYPosition(nextY);
    newCreatures[currX][currY] = nullptr; 
    grid->setChar (currX, currY, '.');
    grid->setChar (nextX, nextY, currInsect);
    return true;
}
bool Island::killCreature( int r, int c)
{
  if (newCreatures[r][c]==nullptr) {
    return false;
  }
  else{
  	delete newCreatures[r][c];
    newCreatures[r][c] = nullptr;
    grid->setChar(r, c, '.');  	
    return true;
  }
  	
}

void Island::startDay( char insect){
  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      Creature *creature = newCreatures[i][j];

      if (creature!=nullptr) {
        if ( creature->getInsect() == insect && !creature->isDayLived() ) {
          creature->live();
        }
      }
    }
  }
}

void Island::endDay(){
  for (int i = 0; i < getRows(); i++) {
    for (int j = 0; j < getCols(); j++) {
      Creature *creature = newCreatures[i][j];

      if (creature!=nullptr) {
        creature->setDayLived(false);
      }
    }
  }
}
char Island::getCurrentInsect( int r, int c){
	if(newCreatures[r][c]!= nullptr){
		return newCreatures[r][c]->getInsect();
	}
	else{
		return '.';
	}
}

char Island::getInsectSign( char insect) {
	if(insect== '*'){
		return '*';		
	}
	if(insect== '$'){
		return '$';		
	}
	else{
		return '.';		
	}
}

