#include <stdio.h>
#include <stdlib.h>

void print_t(int** triangle, int depth){
	for(int i = 0; i < depth; i++){
		for(int j = 0; j <= i; j++){
			printf("%d ", triangle[i][j]);
		}
		printf("\n");
	}
}

int** pascal(int rows){
	int** tri = (int**)malloc(sizeof(int*)*rows);
	for(int i = 0; i < rows; i++){
		tri[i] = (int*)malloc(sizeof(int)*(i+1));
		for(int j = 0; j < i+1; j++){
			if((j == 0) | (j == i)){
				tri[i][j] = 1;
			}
			else{
				tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
			}
		}
	}
	return tri;
}


int main(void){
	/*int** p = (int**)malloc(sizeof(int*)*3);
	p[0] = (int*)malloc(sizeof(int));
	p[1] = (int*)malloc(sizeof(int)*2);
	p[2] = (int*)malloc(sizeof(int)*3);
	p[0][0] = 1;
	p[1][0] = 1;
	p[1][1] = 1;
	p[2][0] = 1;
	p[2][1] = 2;
	p[2][2] = 1;
	print_t(p, 3);
	for(int i = 0; i < 3; i++) free(p[i]);
	free(p);*/
	print_t(pascal(1), 1);
	print_t(pascal(2), 2);
	print_t(pascal(3), 3);
	print_t(pascal(4), 4);
	print_t(pascal(5), 5);
	return 0;
}
