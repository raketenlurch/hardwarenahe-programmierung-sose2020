// C Programm to concatenate
// two strings without using strcat
#include <stdio.h>
#include <string.h>

int main() {
  // Get the two strings to be concatenated
  char str1[100] = "Geeks", str2[100] = "World";

  // Declare a new string
  // to store the concatenated string
  char str3[100];

  int i = 0, j = 0;

  printf("\nFirst string: %s", str1);
  printf("\nSecond string: %s", str2);

  // Insert the first string in the new string
  while (str1[i] != '\0') {
    str3[j] = str1[i];
    i++;
    j++;
  }

  // Insert the second string in the new string
  i = 0;
  while (str2[i] != '\0') {
    str3[j] = str2[i];
    i++;
    j++;
  }

  // \0 anfügen
  printf("Länge: %ld ", strlen(str3));
  str3[11] = '\0';

  // Print the concatenated string
  printf("\nConcatenated string: %s\n", str3);
  return 0;
}

/*#include <stdio.h>
int main()
{
   char str1[50], str2[50], i, j;
   printf("\nEnter first string: ");
   scanf("%s",str1);
   printf("\nEnter second string: ");
   scanf("%s",str2);
   /* This loop is to store the length of str1 in i
    * It just counts the number of characters in str1
    * You can also use strlen instead of this.
    */
   /*for(i=0; str1[i]!='\0'; ++i);

   /* This loop would concatenate the string str2 at
    * the end of str1
    */
   /*for(j=0; str2[j]!='\0'; ++j, ++i)
   {
      str1[i]=str2[j];
   }
   // \0 represents end of string
   str1[i]='\0';
   printf("\nOutput: %s",str1);

   return 0;
}*/
