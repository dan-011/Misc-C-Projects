#include <stdio.h>
#include "Maze.h"

#define MAX_MOVES 100

MazeCell* mazeFor(const char[]);

int main() {

    char moves[MAX_MOVES];

    MazeCell* startLocation = mazeFor("djp19008");

    /* Set a breakpoint here to explore your maze! */

    printf("Enter escape path: ");
    fgets(moves, sizeof(moves), stdin);
    if(isPathToFreedom(startLocation, moves))
       printf("Congratulations! You've found a way out of your labyrinth.\n");
    else
       printf("Sorry, but you're still stuck in your labyrinth.\n");
   
    free_maze(startLocation);

    return 0;
}


