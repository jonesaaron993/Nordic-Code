/* This is a very, very, very, basic interpreter for the Nordic code base. 
   Work to expand this codebase is in the works, but it will be a while
   before this interpreter is fully operational.
   ALL CODE HERE AT THIS CURRENT DATE IS NOT PERFECT, AND CAN BE IMPROVED. */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "variables.h"
#include "print.h"
#include "readInFile.h"

int main()
{
   //Get the current directory
   char currentDir[FILENAME_MAX];

   //Add the tests folder to the char array
   getTestDir(currentDir);

   //Get the number of lines
   openAndPrintFile(currentDir);

   //Test allocation of int data
   createInt(50);

  return 0;
}