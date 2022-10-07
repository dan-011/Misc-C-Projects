#include <stdio.h>
#include <stdlib.h>

int check_path(MazeCell* start, char* moves){
	MazeCell* pos = start;
	char spellbook = 0;
	char potion = 0;
	char wand = 0;
	int i = 0;
	int counter = 0;
	do{
		if (pos->whatsHere == 1){
			//counter++;
			 spellbook = 1;
		}
		else if (pos->whatsHere == 2){
		        //counter++;
			potion = 2;
		}
		else if (pos->whatsHere == 3){
		        //counter++;
		        wand  = 3;
		}
		if (moves[i] == 'N' && pos->N) pos = pos->N;
		else if (moves[i] == 'S' && pos->S) pos = pos->S;
		else if (moves[i] == 'E' && pos->E) pos = pos->E;
		else if (moves[i] == 'W' && pos->W) pos = pos->W;
		else break;
	}while(moves[i++] != '\0');
	if (moves[i] != '\0') return -1;
	if (spellbook && potion && wand) return 3;
	else if((spellbook && potion)||(potion && wand)||(spellbook && wand)) return 2;
	else if(spellbook || potion || wand) return 1;
	else return 0;
	}
}
