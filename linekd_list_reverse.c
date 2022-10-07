#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} node;

node* _ll_reverse(node* prev, node *pos){
	if(!pos) return NULL;
	else if (pos->next==NULL){
		pos->next = prev;
		//printf("pos: %d, pos->next: %d\n", pos->value, pos->next->value);
		node* cur = pos;
		while(cur->next){
			printf("%d\n", cur->value);
			cur = cur->next;
		}
		return pos;
	}
	else{
		node* _next = pos->next;
		pos->next = prev;
		//printf("pos: %d, pos->next: %d\n", pos->value,pos->next == NULL? -1 : pos->next->value);
		node* cur = pos;
		while(cur->next){
			printf("%d\n", cur->value);
			cur = cur->next;
		}
		return _ll_reverse(pos, _next); 
	}
}

node* ll_reverse(node *head){
	//node* rv =  _ll_reverse(NULL, head);
	//return rv;
	if (!head) return NULL;
	node* prev = NULL;
	node* pos = head;
	while(pos->next){
		node* _next = pos->next;
		pos->next = prev;
		prev = pos;
		pos = _next;
	}
	pos->next = prev;
	return pos;
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
	n3 = (node){3, NULL};
	n4 = (node){4, NULL};
	node * head = ll_reverse(&start);
	node * pos = head;
	while(pos){
		printf("%d\n", pos->value);
		pos = pos->next;
	}
	printf("%d\n", head->next->value);
	return 0;
}
