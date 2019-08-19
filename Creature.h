#pragma once // to include only once

class Island; //instance Island class
class Creature{
	public:
		
		Creature(Island *island, char ins); // constructor
		virtual ~Creature(){
			//destructor
		}
		char getInsect(){
			return insect;
		}
		bool isDayLived(){
			return daylived;
		}
		int getXPosition(){
			return xPosition;
		}
		int getYPosition(){
			return yPosition;
		}
		int getLastSpawn(){
			return lastSpawned;
		}
		Island* getIsland(){
			return island;
		}
		void setXPosition( int x){
			xPosition = x;
		}
		void setYPosition( int y){
			yPosition = y;
		}
		void setLastSpawn( int spawn){
			lastSpawned = spawn;
		}
		void setIsland(Island *newIsland){
			island = newIsland;
		}
		void setInsect( char ins){
			insect = ins;
		}
		void setDayLived( bool days){
			daylived = days;
		}
		void getEmptyPosition( int r, int c, int& newXpos, int& newYpos);
		bool move();
		virtual bool spawn()=0;
		virtual void live()=0;
	private:
		char insect;
		Island* island;
		int xPosition;
		int yPosition;
		int lastSpawned;
		bool daylived;
		
			
};
