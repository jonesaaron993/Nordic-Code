#ifndef PRINT_H_   /* Include guard */
#define PRINT_H_

//Print out the paramaters from the nord print statment
bool evaluateQuotes(char *input);

//Print values between quotes
void printFromQuotes(char *input);

//Get the data between parentheses
char* getDataBetweenParentheses(char *input);

#endif // PRINT_H_