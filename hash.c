#include <stdio.h>
#include <ctype.h>

/* Input:
 *    s - NUL terminated string consisting of lower-case letters
 *    b - non-negative integer base
 *
 * Return:
 *    unsigned int polynomial hash code
 *
 *       hash_code(s) = d[0] + d[1]*b + ... + d[n-1]*b^{n-1}
 *
 *    where n is the number of letters in s and d[i] is the position
 *    of letter s[i] in the English alphabet ('a' has position 1,
 *    'b' has position 2, and so on).  Overflows, if any, are ignored.
 */

unsigned int hash_code( char s[], unsigned int b )
{
    int i = 0;
    unsigned int sum = 0;
    unsigned int pwr = 1;
    while(s[i] != '\0'){
        sum += pwr*(s[i] - 96);
        pwr *= b;
        i++;
    }
    return sum;
}



// DO NOT MODIFY THE CODE BELOW

#define MAXLEN 1000

int main()
{
   char buff[MAXLEN], s[MAXLEN];
   unsigned int b;
   int i, j;

   fgets(buff, sizeof buff, stdin);         // reads at most MAXLEN-1 chars to avoid buffer overflow

   for(i=j=0; buff[i] != '\n' && buff[i] != '\0'; i++) {
      if( isupper(buff[i]) )
          s[j++] = tolower( buff[i] ); // convert uppercase letters to lowercase
      else if( islower(buff[i]) )
          s[j++] = buff[i];
      else ;                           // ignore non-letters
   }
   s[j] = '\0';                   // add NUL terminator

   scanf("%u", &b);               // read the value of the base

   printf("hash_code(%s)=%u\n", s, hash_code(s, b) );

   return 0;
}
