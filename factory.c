#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define     MAX_INPUT       2000000000u
#define     DEBUG

typedef struct {
   unsigned int  nf;  // number of factors
   unsigned int* pf;  // pointer to int array holding prime factors in non-decreasing order
} factored_int;

/*================================================*/
/* Compute the prime factorization of the product */
/* given the prime factorizations of two integers */
/*================================================*/
factored_int* get_factored_product( const factored_int* f1, const factored_int* f2)
{
    factored_int* rv = (factored_int*)malloc(sizeof(factored_int));
    unsigned int s1 = f1->nf;
    unsigned int s2 = f2->nf;
    rv->nf = s1 + s2;
    unsigned int* n_pf = (unsigned int*)malloc(sizeof(unsigned int)*(rv->nf));
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < s1 && j < s2){
        if(f1->pf[i] < f2->pf[j]){
            n_pf[k] = f1->pf[i];
            i++;
        }
        else{
            n_pf[k] = f2->pf[j];
            j++;
        }
        k++;
    }
    while(i < s1){
        n_pf[k] = f1->pf[i];
        k++;
        i++;
    }
    while(j < s2){
        n_pf[k] = f2->pf[j];
        k++;
        j++;
    }
    rv->pf = n_pf;
    return rv;
}



/*================================================*/
/* Compute the prime factorization of the GCD     */
/* given the prime factorizations of two integers */
/*================================================*/
factored_int* get_gcd( const factored_int* f1, const factored_int* f2)
{
    int i = 0;
    int j = 0;
    unsigned int s1 = f1->nf;
    unsigned int s2 = f2->nf;
    unsigned int* p1 = f1->pf;
    unsigned int* p2 = f2->pf;
    unsigned int count = 0;
    while(i < s1 && j < s2){
        if(p1[i] == p2[j]){
            count++;
            i++;
            j++;
        }
        else if(p1[i] < p2[j]) i++;
        else j++;
    }
    if(!count){
        unsigned int* n_pf = (unsigned int*)malloc(sizeof(unsigned int)*1);
        n_pf[0] = 1;
        factored_int* rv = (factored_int*)malloc(sizeof(factored_int));
        rv->nf = 1;
        rv->pf = n_pf;
        return rv;
    }
    unsigned int* n_pf = (unsigned int*)malloc(sizeof(unsigned int)*count);
    int k = 0;
    i = 0;
    j = 0;
    while(i < s1 && j < s2){
        if(p1[i] == p2[j]){
            n_pf[k] = p1[i];
            k++;
            i++;
            j++;
        }
        else if(p1[i] < p2[j]) i++;
        else j++;
    }
    factored_int* rv = (factored_int*)malloc(sizeof(factored_int));
    rv->nf = count;
    rv->pf = n_pf;
    return rv;
}


/*==============================================*/
/* Compute the prime factorization of an integer*/
/* Do not change this function                  */
/*==============================================*/
factored_int* factor_integer (unsigned int n)
{
    factored_int* result = malloc( sizeof(factored_int) );
#ifdef DEBUG
    assert( result != NULL );
#endif
    result->nf = 0;
    result->pf = NULL;

    unsigned int sf = 2; // sf is the smallest prime factor candidate

    while (n > 1) {
        if(n % sf == 0) {
            // sf is a factor, append to the end of the array
            result->pf = realloc(result->pf, (result->nf+1) * sizeof(unsigned int));
#ifdef DEBUG
            assert(result->pf != NULL);
#endif
            result->pf[result->nf++] = sf;
            n /= sf;
        }
        else {
            if(sf==2)
                sf++;
            else
                sf += 2;
            if(sf * sf > n) { // n is prime
               result->pf = realloc(result->pf, (result->nf+1) * sizeof(unsigned int));
#ifdef DEBUG
               assert(result->pf != NULL);
#endif
               result->pf[result->nf++] = n;
               break;
            }
        }
    }
    return result;
}


/*==============================================*/
/* Print a given prime factorization            */
/* Do not change this function                  */
/*==============================================*/
void print_integer(const factored_int f)
{
    unsigned int i;

    if (f.pf == NULL) {
        printf("1\n");
        return;
    }

    for (i = 0; i < f.nf; i ++) {
        printf("%s%u", (i ? " * " : ""), f.pf[i]);
    }
    printf("\n");
}

/*==============================================*/
/* Do not change this function                  */
/*==============================================*/
unsigned long get_product(const factored_int f)
{
    unsigned long i, result = 1;

    if (f.pf == NULL)
        return result;

    for (i = 0; i < f.nf; i ++) {
        result *= f.pf[i];
    }
    return result;
}

/*==============================================*/
/* only add clean up statements at the end.     */
/*==============================================*/
int main(int argc, char **argv)
{
    unsigned long n1, n2;

    if (argc < 3) {
	printf("Usage: %s <n1> <n2>\n", argv[0]);
	return 0;
    }
    n1 = atol(argv[1]);
    n2 = atol(argv[2]);

    if (n1 <= 1 || n1 > MAX_INPUT || n2 <= 1 || n2 > MAX_INPUT) {
        printf("Integera must be > 1 and <= %d.\n", MAX_INPUT);
        return 0;
    }

    factored_int* f1 = factor_integer(n1);
    factored_int* f2 = factor_integer(n2);

    printf("%ld = ", n1);
    print_integer(*f1);
    printf("%ld = ", n2);
    print_integer(*f2);

    factored_int* prod = get_factored_product(f1, f2);
    printf("Product factorization: ");
    print_integer(*prod);

    factored_int* gcd = get_gcd(f1, f2);
    printf("GCD factorization: ");
    print_integer(*gcd);

    // clean up
    // TODO
    free(prod->pf);
    free(gcd->pf);
    free(prod);
    free(gcd);
    free(f1->pf);
    free(f1);
    free(f2->pf);
    free(f2);

    return 0;
}
