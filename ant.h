#pragma once
#include "Creature.h"

class Ant : public Creature{ // inherited class
	public:
		Ant(Island* island) : Creature(island, '*'){
			// constructor
		}
		virtual bool spawn();
		virtual void live (); // overridong 
	
};

