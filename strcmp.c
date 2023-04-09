#include <stdio.h>
#include <string.h>

int main ()
{
  char key[] = "apple";
  char buffer[80];
  do {
     printf ("Guess my favorite fruit? ");
     fflush (stdout);
     scanf ("%79s",buffer);
     printf("%s,%s\n", key, buffer);
  } while (key != buffer);
  puts ("Correct answer!");
  return 0;
}