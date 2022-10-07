#ifndef __STACK_H //if macro __STACK_H is not defined, define it
#define __STACK_H // includes the stuff below only if stack doesn't exist

#define BOOL char





struct Stack {
	int* _t;
	int _mxs;
	int _sz;
};

typedef struct Stack StackOfInt;

StackOfInt* makestack(int mxs);
void freeStack(StackOfInt* s);
void pushInt(StackOfInt* s, int v);
int popInt(StackOfInt* s);
BOOL isStackEmpty(StackOfInt* s);

#endif
