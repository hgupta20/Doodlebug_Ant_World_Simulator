#pragma once // To prevent conflict between header files being read again
#include "GridDisplay.h"
#include "Creature.h"
#include <cstdio>
// for usleep
#include <unistd.h>

class Island{
	public:
		Island(GridDisplay *grid);
		GridDisplay* getGrid(){
			return grid;
		}
		int getRows() {
			return rows;
		}
		int getCols() {
			return cols;
		}
		void setRows(int newrows){
			rows = newrows;
		}
		void setCols(int newcols){
			cols = newcols;
		}
		void setGrid(GridDisplay *newgrid){
			grid = newgrid;
		}
		bool isValid( int r,  int c);
		bool isOccupied( int r, int c);
		void startDay( char insect);
		void endDay();
		bool addCreature(Creature *creature);
		bool moveCreature( int r,  int c,  int newXpos,  int newYpos);
		bool killCreature( int r,  int c);
		char getInsectSign( char insect);
		char getCurrentInsect( int r,  int c) ;
	private:
		int rows;
		int cols;
		GridDisplay *grid;
		Creature* **newCreatures;
		
		
};
