#include <stdio.h>
#include <stdlib.h>

typedef struct tagged_value {
	int tag;
	union uTag {
		int iVal;
		float fVal;
		char* sVal;
	} u;
} UType;

#define INTEGER_TAG 0
#define FLOAT_TAG 1
#define STRING_TAG 2

void printUType(UType* x){
	switch(x->tag){
		case INTEGER_TAG: printf("%d\n", x->u.iVal); break;
		case FLOAT_TAG: printf("%f\n", x->u.fVal); break;
		case STRING_TAG: printf("%s\n", x->u.sVal); break;
	}
}

UType makeUTFloat(float v){ // returns a struct
	UType rv;
	rv.tag = FLOAT_TAG;
	rv.u.fVal = v;
	return rv;
}

UType makeUTString(char* s){
	UType rv;
	rv.tag = STRING_TAG;
	rv.u.sVal = s;
	return rv;
}

int main(){
	UType x = makeUTFloat(5.25);
	printUType(&x);
	UType y = makeUTString("Hello world!\n"); // the pointer to "Hello world!" is being passed to make UTString and you're storing that pointer in sVal. When the UType is no longer necessary, there is no need to deallocate. "Hello world!" is stored in the statics
	printUType(&y);
	return 0;
}
