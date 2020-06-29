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

//TODO: Get current directory on Linux

//Function prototypes

//Get the test directory from the main project file
const char* getTestDir(char currentDir[FILENAME_MAX]);

//Open a file and print all of its contents
void openAndPrintFile(char currentDir[FILENAME_MAX]);

//Check if a statment starts with certain values
bool StartsWith(const char *a, const char *b);

//Print out the paramaters from the nord print statment
bool evaluateQuotes(char *input);

//Print values between quotes
void printFromQuotes(char *input);

//Get the data between parentheses
char* getDataBetweenParentheses(char *input);

/*Basic diagram of how variables are stored

   0    1   2   3
0 type name = value
1 type name = value
2 type name = value
3 type name = value

*/

//TODO: Make this a dynamic array
//also expand on second element of multidementional array
//so each declared variable sits in its own column
char *output[50][50];

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

         //Get the data between the perenthases
         array = getDataBetweenParentheses(array);

         if (evaluateQuotes(array) == true)
         {
            printFromQuotes(array);
         }
         else
         {
            printVariable(array);
         }
      }

      //Check if the statment is declaring a variable
      if (StartsWith(currentLine, "var"))
      {
         char *array = currentLine;
         DeclareVariable(array);
         variableCount++;
      }
   }

   HandleVariables();

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
   
   sscanf(input,"%*'(', ')'",a)==1;

   return strncpy(input, a, 1);
}

/*Print the contents between quotes
of the nord print statment*/
bool evaluateQuotes(char *input)
{
   //TODO: Make this a dynamic array
   char a[50];
   
   if(sscanf(input,"%*[^']'%[^']'",a) == 1)
   {
      return true;
   } 
   else
   {
      return false;
   }
}

/*Print the contents between quotes
of the nord print statment*/
void printFromQuotes(char *input)
{
   //TODO: Make this a dynamic array
   char a[50];
   
   if(sscanf(input,"%*[^']'%[^']'",a) == 1)
   {
      printf("%s\n", a);
   } 
   else
   {
      printf("%s\n", a);
   }
}

/*Print the variable by the name*/
void printVariable(char *input)
{
   int size = sizeof(output) / sizeof(*output);

   for (int i = 0; i < size; i++)
   {
      char *pointer = output[i][1];
      
      if(input == pointer)
      {
         int userInput = atoi(output[i][3]);
         printf("%d\n", userInput);
      } 
   }
}

/*Breaks down a line and stores
the corresponding values in the
appropriate spots in the array*/
void DeclareVariable(char *input)
{
   char delim[] = " ";

   //Get the first value between whitespace
   char *pch = strtok(input, delim);

   //Initalize the counter starting at zero
   int counter = 0;

   //Keep getting all values in between whitespaces
   while (pch != NULL)
   {
      //Get the next value between whitespaces
      pch = strtok(NULL, delim);

      //Add the value to the array
      //Don't need to add the first pch found outside of the 
      //while loop becuase we already know it begins with 'var'
      if (pch != NULL)
      {
         char *string_storage;

         string_storage = malloc(strlen(pch) + 1);

         if (string_storage != NULL)
         {
            strcpy(string_storage, pch);
         }

         output[variableCount][counter] = string_storage;
      }

      //Increase the counter
      counter++;
   }
}

/*Handles all functions if a
variable was declared*/
void HandleVariables()
{
   for (int i = 0; i < variableCount; i++)
   {
      //Once more datatypes are created, this if statment will have to change
      //I'm thinking of putting a switch statment here, but I'll see as the code expands
      if (output[i][0] = "int")
      {
         intDataType(i);
      }
   }
}

/*Handles integer data type*/
void intDataType(int index)
{
   //Convert the instance of the array to a character
   char digit = *output[index][3];

   //Check if the character is a digit
   if (isdigit(digit))
   {
      int userInput = atoi(output[index][3]);

      //Will sort out later
      //printf("%d\n", userInput);
   }
}