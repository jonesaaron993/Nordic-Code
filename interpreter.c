/* This is a very, very, very, basic interpreter for the nordic code base. 
   Work to expand this code base is in the works, but it will be a while
   before this interpreter is fully operational.
   ALL CODE HERE AT THIS CURRENT DATE IS NOT PERFECT, AND CAN BE IMPROVED. */

#include <stdio.h>
#include <direct.h>
#include <string.h>
#include <assert.h>
#include<stdbool.h>

//Function prototypes

//Get the test directory from the main project file
const char* getTestDir(char currentDir[FILENAME_MAX]);

//Open a file and print all of its contents
void openAndPrintFile(char currentDir[FILENAME_MAX]);

//Check if a statment starts with certain values
bool StartsWith(const char *a, const char *b);

//Print out the paramaters from the nord print statment
void printFromQuotes(char *input);

int main()
{
   //Get the current directory
   char currentDir[FILENAME_MAX];

   //Add the tests folder to the char array
   getTestDir(currentDir);

   //Get the number of lines
   openAndPrintFile(currentDir);

  return 0;
}

/*Navigate to the test directory 
and load in the file*/
const char* getTestDir(char currentDir[FILENAME_MAX])
{
   //Get the current directory
   _getcwd( currentDir, FILENAME_MAX );

   //The path to the test nordcode file
   char tests[] = "/tests/helloworld.nord";

   //Make sure that the file is a valid file
   //by checking its extention
   char * ext = strrchr(tests, '.');

   //Assert if the extention is not a nord file
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
      //Check if the statment is a print statment
      if (StartsWith(currentLine, ".."))
      {
         char *array = currentLine;
         printFromQuotes(array);
      }
   }

   //Close the file
   fclose(testFile);
}

/*Check the begining values of the lines
if a line starts with '..' that means
the user is trying to output to the terminal*/
bool StartsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

/*Print the contents between quotes
of the nord print statment*/
void printFromQuotes(char *input)
{
   char a[50];
   
   if(sscanf(input,"%*[^']'%[^']'",a)==1)
   {
      printf("%s\n", a);
   } 
   else
   {
      printf("%s\n", a);
   }
}