#include <stdio.h>

int check_luhn1(int digit[], int len){
	int a[len*4];
	for(int i = 0; i < len; i++){
		int block = digit[i];
		int counter = 0;
		while(block){
			if (counter == 3 || counter == 1){
				int num = block % 10;
				//printf("%d\n", block);
				if (num*2 > 9) a[i*4+(3-counter)] = num*2 - 9;
				else a[i*4+(3-counter)] = num*2;
				//printf("%d\n", num);
			}
			else{
				int num = block % 10;
				//printf("%d\n", block);
				a[i*4+(3-counter)] = num;
				//printf("%d\n", num);
			}
			block = block/10;
			counter++;
		}
		while(counter < 4){
			a[i*4+(3-counter)] = 0;
			//printf("%d\n", a[i*4+(3 - counter)]);
			counter++;
		}
	}
	int sum = 0;
	for(int i = 0; i < len*4; i++) sum += a[i];
	//for(int i = 0; i < len*4; i++) printf("%d", a[i]);
	//printf("\n");
	if((sum % 10) == 0) return 1;
	else return 0;
}

int check_luhn(int digit[], int len){
	int a[len];
	int _switch = 1;
	int sum = 0;
	for (int i = 0; i < len; i++){
		if (_switch){
			int num = digit[i];
			if (num*2 >9) sum += num*2 - 9;
			else sum += num * 2;
			_switch = 0;
		}
		else{
			sum += digit[i];
			_switch = 1;
		}
	}
	if (sum % 10 == 0) return 1;
	else return 0;
}

int main(void){
	int test1[] = {7,6,4,6,1,4,9,3,0,5,7,3,9,0,2,6,5,3,8,4};
	int test2[] = {7,6,4,6,1,4,9,3,0,5,7,3,9,0,2,6,5,3,4,8};
	int test3[] = {7,6,4,6,1,4,9,3,0,5,7,3,9,0,2,6,5,3,8,5};
	printf("1 == %d\n", check_luhn(test1, 20));
	printf("0 == %d\n", check_luhn(test2, 20));
	printf("0 == %d\n", check_luhn(test3, 20));
	return 0;
}
