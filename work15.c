#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line) {
   //instructions say string has no more than 5 arguments
   char ** ret = calloc(5, sizeof(char *));

   //loops through line to set ret[i] to a pointer
   //to the first word before a space and etc.
   int i;
   for(i = 0; line; i++) {
      ret[i] = strsep(&line, " ");
   }

   return ret;
}

int main() {
   printf("Command: ");

   //gets inputted command
   char test[100];
   fgets(test, sizeof(test)-1, stdin);
   //adds the null at the end of a string to close it off
   test[strlen(test)-1] = '\0';

   //parses the entered string to become an array of strings
   char ** args = parse_args(test);
   //executes the entered command using the parsed array
   execvp(args[0], args);

   return 0;
}
