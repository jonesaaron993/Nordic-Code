#ifndef READ_IN_FILE_H_   /* Include guard */
#define READ_IN_FILE_H_

/*Navigate to the test directory 
and load in the file*/
const char* getTestDir(char currentDir[FILENAME_MAX]);

/*Open all contents of the file
and split them into multilines*/
void openAndPrintFile(char currentDir[FILENAME_MAX]);

#endif