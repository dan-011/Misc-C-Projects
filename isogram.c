#include <stdio.h>
#include <ctype.h>

/* Input:
 *    NUL terminated string 'phrase' which consists of lower-case letters,
 *    spaces, and punctuation marks
 *
 * Return value:
 *    1 if 'phrase' is an isogram, and 0 otherwise.
 */
int is_isogram( char phrase[] )
{
  char* alpha = (char*)calloc(26, sizeof(char));
  int i = 0;
  while(phrase[i] != '\0'){
    alpha[phrase[i]-97] += 1;
    i++;
  }
  int val = 0;
  for(int j = 0; j < 26; j++){
    if(!val && alpha[j]) val = alpha[j];
    else if(alpha[j] != 0 && alpha[j] != val){
      free(alpha);
      return 0;
    }
  }
  free(alpha);
  return 1;
}



// DO NOT MODIFY THE CODE BELOW

#define MAXLEN 1000

int main( void )
{
  int i;

  char buff[MAXLEN], phrase[MAXLEN];

  fgets(buff, sizeof buff, stdin);         // reads at most MAXLEN-1 chars to avoid buffer overflow

  for(i=0; buff[i] != '\n' && buff[i] != '\0'; i++) {
    if( isupper(buff[i]) )
      phrase[i] = tolower( buff[i] ); // convert uppercase letters to lowercase
    else
      phrase[i] = buff[i];            // copy everything else unchanged
  }

  phrase[i] = '\0';                   // add NUL terminator

  if( is_isogram(phrase) )
    printf("isogram\n");
  else
    printf("not isogram\n");

  return 0;
}
