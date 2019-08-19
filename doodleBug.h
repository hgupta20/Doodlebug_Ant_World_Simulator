
#pragma once

#include <string>
#include "Creature.h"

class DoodleBug : public Creature // inherited class
{
  public:

    DoodleBug(Island* island) : Creature(island, '$'), lastEaten(0)
    {
      //constructor
    }

    int getLastEaten(){
       return lastEaten; 
    }

    void setLastEaten(int dinner){
       lastEaten = dinner; 
    }

    void getAntPosition(int x,int y, int& newXpos, int& newYpos);

    bool hunt();

    virtual bool spawn();

    virtual void live();

  private:
    int lastEaten;  
};

