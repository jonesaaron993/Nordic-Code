#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "variables.h"
#include "print.h"
#include "readInFile.h"

/*Check the beginning values of the line 
starts with a certain value*/
bool StartsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

//Plan for integer variables:
//Allocate appropriate space using malloc
//Verify that it is an integer

/*Allocate space for an integer*/
void *createInt(long long object)
{
   long long *p = malloc(sizeof(object));
}