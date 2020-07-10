#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "readInFile.h"
#include "print.h"
#include "variables.h"

/*Navigate to the test directory 
and load in the file*/
const char* getTestDir(char currentDir[FILENAME_MAX])
{
   //Get the current directory
   getcwd( currentDir, FILENAME_MAX );

   //The path to the test Nord code file
   char tests[] = "/tests/helloworld.nord";

   //Make sure that the file is a valid file
   //by checking its extension
   char * ext = strrchr(tests, '.');

   //Assert if the extension is not a Nord file
   assert(ext != "nord");

   //Concatenate the strings
   strcat(currentDir, tests);

   return currentDir;
}

/*Open all contents of the file
and split them into multilines*/
void openAndPrintFile(char currentDir[FILENAME_MAX])
{
   //Open the file with the current path
   FILE *testFile = fopen(currentDir, "r");

   //TODO: Make this a dynamic array
   char currentLine[100];

   //Assert that the file location is not empty
   assert(testFile != NULL);

   //TODO: Improve this while loop for counting number of lines
   while (fgets(currentLine, sizeof(currentLine), testFile) != NULL)
   {
      //Check if the statement is a print statement
      if (StartsWith(currentLine, ".."))
      {
         char *array = currentLine;

         //Get the data between the parentheses  
         array = getDataBetweenParentheses(array);

         if (evaluateQuotes(currentLine) == true)
         {
            printFromQuotes(currentLine);
         }
      }

      //Check if the statement is declaring a variable
      if (StartsWith(currentLine, "var"))
      {
         //char *array = currentLine;
         //DeclareVariable(array);
         //variableCount++;
      }
   }

   //Free memory
   free(currentLine);

   //Close the file
   fclose(testFile);
} 
