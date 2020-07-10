#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "variables.h"
#include "print.h"
#include "readInFile.h"

/*Get the array between parentheses*/
char* getDataBetweenParentheses(char *input)
{
   //TODO: Make this a dynamic array
   char a[100];

   sscanf(input,"%*'(', ')'",a)==1;

   return strncpy(input, a, 1);
}

/*Print the contents between quotes
of the Nord print statement*/
bool evaluateQuotes(char *input)
{  
   //Create a dynamic array
   char *a = NULL;
   a = calloc(10, sizeof(char));
   
   if(sscanf(input, "%*[^']'%[^']'", a) == 1)
   {
      return true;
   } 
   else
   {
      return false;
   }
}

/*Print the contents between quotes
of the Nord print statement*/
void printFromQuotes(char *input)
{
   //Create a dynamic array
   char *a = NULL;
   a = calloc(10, sizeof(char));
   
   if(sscanf(input, "%*[^']'%[^']'", a) == 1)
   {
      printf("%s\n", a);
   } 
   else
   {
      printf("%s\n", a);
   }
}