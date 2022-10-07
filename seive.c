#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sieve(int max, int* *primes);
int main(void){
	int** p1 = (int**)malloc(sizeof(int*));
	int** p2 = (int**)malloc(sizeof(int*));
	int** p3 = (int**)malloc(sizeof(int*));

	printf("1 == %d\n", sieve(2, p1));
	printf("2 == %d\n", sieve(3, p2));
	printf("4 == %d\n", sieve(10, p3));

	free(p1);
	free(p2);
	free(p3);
	return 0;
}

int sieve(int max, int** primes){
	char* a = (char*)malloc(max+1);
	for(int i = 0; i <= max; i++){
		if((i == 0) | (i == 1)) a[1] = 0;	       
		else a[i] = 1;
	}
	for(int i = 2; i < max+1; i++){
		if(a[i] == 1){
			int index = 2;
			while(i*index <= max){
				a[i*index] = 0;
				index++;
			}
		}
	}
	int num_primes = 0;
	for(int i = 2; i <= max; i++){
		if (a[i] == 1) num_primes++;
	}
	int* p = (int*)malloc(sizeof(int)*num_primes);
	primes = &p;
	int j = 0;
	for(int i = 2; i <= max; i++){
		if(a[i] == 1){
			p[j] = i;
			j++;
		}
	}
	free(a);
	return num_primes;
}
/*
int sieve(int max, int** primes){
	int a[max-1];
	for(int i = 0; i < max; i++){
		a[i] = 1;
	}
	int num_primes = max-1;
	for(int i = 0; i < max; i++){
		if(a[i] == 1){
			int counter = 2;
			while((i+2)*counter <= max){
				a[i*counter] = 0;
				num_primes--;
				counter++;
			}
		}
	}
	int* p = (int*)malloc(sizeof(int)*num_primes);
	int index = 0;
	for(int i = 0; i < max; i++){
		if(a[i] == 1){
		       p[index] = i + 2;
			index++;
		}
	}
	for(int i = 0; i < num_primes; i++){
		printf("%d\n", p[i]);
	}
	primes = &p;
	free(p);
	return num_primes;
}*/
