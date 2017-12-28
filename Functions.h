#ifndef FUNCTIONS_H
#define FUNCTIONS_H
extern const int ENTRIES;

//Prints the program output header 
void initialize();


//Checks if character code is legal input
bool checkCode(char x);


//Writes the output of the program to a file specified by user input
void writeDataToFile(const char* x);


//Read commands from a file specified by user input
void readDataFromFile(const char* x);


//nycancat value function
double findNyanCatValue(double x);


//Returns the factorial value of the given integer arguement
int factorial(int x);


//Fibonacci
int fibonacci(int x);


//Square root
double findSqrtValue(double x);


//Natural log
double naturalLog(double x);


//next odd value
int findNextOddValue(int x);


#endif
