#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

char *ft_strdup(char *src);

int main(void)
{
   char *string = "this is a copy";
   char *newstr;
   char *newstr2;

   /* Make newstr point to a duplicate of string                              */
   if ((newstr = strdup(string)) != NULL)
      printf("The new string is: %s\n", newstr);

//   free (newstr);

  
   if ((newstr2 = ft_strdup(string)) != NULL)
      printf("The new string is: %s\n", newstr);

//   free (newstr2);
   return 0;
}
