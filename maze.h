/*
 * Enum type representing an item in the maze.
 */
typedef enum {
    NOTHING, SPELLBOOK, POTION, WAND
} Item;


/*
 * Type representing a cell in the maze.  The N/S/E/W pointers contain the
 * address of adjecent cells in the north, south, east, and west directions
 * when these cells are connected by passages, and are NULL otherwise
 */

typedef struct MazeCell {
    Item whatsHere; // Which item, if any, is present.
    struct MazeCell* N;
    struct MazeCell* S;
    struct MazeCell* E;
    struct MazeCell* W;
} MazeCell;

int check_path(MazeCell* start, char* moves);
