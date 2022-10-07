#include <stdio.h>
#include <stdlib.h>

void print_m(char** matrix, int sqr){
	for(int i = 0; i < sqr; i++){
		for(int j = 0; j < sqr; j++){
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

char* encode(char plaintext[]){
	int size = 0;
	while(plaintext[size] != '\0'){
		size++;
	}
	int sqr = 0;
	while(sqr*sqr < size){
		sqr++;
	}
	char** matrix = (char**)malloc(sizeof(char*)*sqr);
	int index = 0;
	for(int i = 0; i < sqr; i++){
		matrix[i] = (char*)malloc(sizeof(char)*sqr);
		for(int j = 0; j < sqr; j++){
			matrix[i][j] = plaintext[index%size];
			index++;
		}
	}
	char* rv = (char*)malloc(sizeof(char)*((sqr*sqr)+1));
	int increment = 0;
	for(int i = 0; i < sqr; i++){
		for(int j = 0; j < sqr; j++){
			rv[increment] = matrix[j][i];
			increment++;
		}
	}
	for(int i = 0; i < sqr; i++){
		free(matrix[i]);
	}
	free(matrix);
	rv[(sqr*sqr)] = '\0';
	return rv;
}

int main(void){
	//printf("ACDATKATTAWTATNA == %s\n", encode("ATTACKATDAWN"));
	printf("ACBD == %s\n", encode("ABCD"));
	return 0;
}

