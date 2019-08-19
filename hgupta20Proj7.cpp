#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>

#include "doodleBug.h"
#include "ant.h"
#include "Island.h"

int setDelay(const int argc, char** argv)
{
  if (argc == 3) {
    if ( strcmp(argv[1], "-d") != false) {
        return std::stoi(argv[2]);
    }else{
      printf("Invalid Argument");
    }
  }
  return 400;
}

void run(Island *island, GridDisplay *grid, const int delay)
{
  while (true) {
    // Ants
    island->startDay('*');
    // DoodleBugs
    island->startDay('$');
    // End of day
    island->endDay();

    // Display grid
    grid->mySleep(delay);
    grid->showGrid();
  }
}

int main(int argc, char** argv)
{
  srand( time(NULL) );

  int delay = setDelay(argc, argv);
  int antCount = 100;
  int doodleCount = 5;

  GridDisplay *myGrid = new GridDisplay(20, 20);
  Island *myIsland = new Island(myGrid);

  Ant **ants = new Ant*[antCount];
  DoodleBug **doodlebugs = new DoodleBug*[doodleCount];

  for (int i = 0; i < antCount; i++) {
    ants[i] = new Ant(myIsland);
  }
  for (int i = 0; i < doodleCount; i++) {
    doodlebugs[i] = new DoodleBug(myIsland);
  }

  myGrid->showGrid();
  run(myIsland, myGrid, delay);
  return 0;
}

