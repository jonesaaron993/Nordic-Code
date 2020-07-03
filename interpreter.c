/* This is a very, very, very, basic interpreter for the nordic code base. 
   Work to expand this code base is in the works, but it will be a while
   before this interpreter is fully operational.
   ALL CODE HERE AT THIS CURRENT DATE IS NOT PERFECT, AND CAN BE IMPROVED. */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include "variables.h"
#include "print.h"

//TODO: Get current directory on Linux

//Function prototypes

//Get the test directory from the main project file
const char* getTestDir(char currentDir[FILENAME_MAX]);

//Open a file and print all of its contents
void openAndPrintFile(char currentDir[FILENAME_MAX]);

//Check if a statment starts with certain values
bool StartsWith(const char *a, const char *b);

//Variable to count how many variables have been declared
int variableCount = 0;

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

/*Navigate to the test directory 
and load in the file*/
const char* getTestDir(char currentDir[FILENAME_MAX])
{
   //Get the current directory
   GetCurrentDir( currentDir, FILENAME_MAX );

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
   //char currentLine[100];

   char *currentLine = NULL;

   currentLine = calloc(10, sizeof(char));

   //Assert that the file location is not empty
   assert(testFile != NULL);

   int count = 0;

   //TODO: Improve this while loop for counting number of lines
   while (fgets(currentLine, sizeof(FILENAME_MAX), testFile) != NULL)
   {
      //Check if the statment is a print statment
      if (StartsWith(currentLine, ".."))
      {
         printf("%s\n", "Inside of the loop");
         char *array = currentLine;

         //Get the data between the perenthases
         array = getDataBetweenParentheses(array);

         if (evaluateQuotes(currentLine) == true)
         {
            printFromQuotes(currentLine);
         }
      }

      //Check if the statment is declaring a variable
      if (StartsWith(currentLine, "var"))
      {
         printf("%s\n", "Do variable stuff here");
         //char *array = currentLine;
         //DeclareVariable(array);
         //variableCount++;
      }

      count++;
   }

   //Free memory
   free(currentLine);

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

/*Get the array between parenthases*/
char* getDataBetweenParentheses(char *input)
{
   //TODO: Make this a dynamic array
   char a[50];

   printf("%s\n", "GetDataBetweenParentheses");
   
   sscanf(input,"%*'(', ')'",a)==1;

   return strncpy(input, a, 1);
}

/*Print the contents between quotes
of the nord print statment*/
bool evaluateQuotes(char *input)
{  
   //TODO: Make this a dynamic array
   char a[50] = {0};

   strcpy(a, input);

   printf("%s\n", "Evaluate Quotes");

   char *substring;

   substring = strtok(a, "'");
   substring = strtok(NULL, "'");
   
   if(!substring)
   {
      printf("%s\n", "Inside of the false evalueate quotes");
      
      return false;
   } 
   else
   {
      printf("%s\n", "Inside of the evalueate quotes");

      return true;
   }
}

/*Print the contents between quotes
of the nord print statment*/
void printFromQuotes(char *input)
{
   //TODO: Make this a dynamic array
   //char a[50];

   char *a = NULL;

   a = calloc(10, sizeof(char));

   printf("%s\n", "Print from quotes");
   
   if(sscanf(input, "%*[^']'%[^']'", a) == 1)
   {
      printf("%s\n", a);
   } 
   else
   {
      printf("%s\n", a);
   }
}

//Plan for integer variables:
//Allocate appropriate space using malloc
//Verify that it is an integer

/*Allocate space for an integer*/
void *createInt(long long object)
{
   long long *p = malloc(sizeof(object));
}