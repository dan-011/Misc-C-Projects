#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;

int ll_has_cycle(node *head){
	if (!head) return 0;
	node* turtoise = head;
	node* hare = head;
	do{
		if (turtoise->next) turtoise = turtoise->next;
		else return 0;
		if (hare->next && hare->next->next) hare = hare->next->next;
		else return 0;
	} while(hare != turtoise);
	return 1;
}

int main(void){
	node start;
	node n1;
	node n2;
	node n3;
	node n4;
	start = (node){0, &n1};
	n1 = (node){1, &n2};
	n2 = (node){2, &n3};
	n3 = (node){3, &n4};
	n4 = (node){4, NULL};
	printf("0 == %d\n", ll_has_cycle(&start));
	return 0;
}
