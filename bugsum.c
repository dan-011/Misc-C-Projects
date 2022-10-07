#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int  n;

  if(argc == 1) {
     printf("usage: %s n\n", argv[0]);
     return 0;
  }

  n = atoi(argv[1]);

  int  sum = 0;
  int* A = malloc( sizeof(int)*n );

  for(int i=n-1; i>=0; i--)
      A[i] = i+1;

  for(int i=0; i<n; i++)
      sum += A[i];

  printf ("sum=%d\n", sum);

  free(A);
  return 0;
}
