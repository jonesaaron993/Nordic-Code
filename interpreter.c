/* This is a very, very, very, basic interpreter for the nordic code base. 
   Work to expand this code base is in the works, but it will be a while
   before this interpreter is fully operational.
   ALL CODE HERE AT THIS CURRENT WRITING DATE IS NOT PERFECT, AND CAN
   BE IMPROVED. */

#include <stdio.h>
#define WINDOWS
#include <direct.h>
#include <string.h>
#include <assert.h>

//Function prototypes

//Get the test directory from the main project file
const char* getTestDir(char currentDir[FILENAME_MAX]);

//Open a file and print all of its contents
void openAndPrintFile(char currentDir[FILENAME_MAX]);
 
int main(){
   //Get the current directory
   char currentDir[FILENAME_MAX];

   //Add the tests folder to the char array
   getTestDir(currentDir);

   openAndPrintFile(currentDir);

  return 0;
}

const char* getTestDir(char currentDir[FILENAME_MAX])
{
   //Get the current directory
   _getcwd( currentDir, FILENAME_MAX );

   //The path to the test nordcode file
   char tests[] = "/tests/helloworld.nord";

   //TODO: Make sure the file is a .nord file

   //Concantinate the strings
   strcat(currentDir, tests);

   return currentDir;
}

void openAndPrintFile(char currentDir[FILENAME_MAX])
{
   //Open the file with the current path
   FILE *testFile = fopen(currentDir, "r");

   char currentLine[100];

   //Assert the that file location is not empty
   assert(testFile != NULL);

   while (fgets(currentLine, sizeof(currentLine), testFile) != NULL)
   {
      fprintf(stderr, currentLine);
   }

   fclose(testFile);
}