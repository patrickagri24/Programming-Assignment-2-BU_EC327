#include <iostream>
#include <ctime>
#include "FileFunctions.h"
#include "Statistics.h"
#include <fstream>

using namespace std;

//Pointer Function for doubling array and reversing array
int * DoubleandReverse(int *list, int size)
{
	
	//result array
	int *result = new int [size * 2];
	
	//prints in first half of array
	for(int i = 0; i < size; i++)
	{
		result[i] = *(list + i);
		
	}
	
	//reverses list
	/*int temp;
   
	for (int i = 0; i < size; ++i)
	{
		temp = *(list + i);
		*(list + i) = *(list + size-i-1);
		*(list + size -i-1) = temp;
	}
	*/
	
	int j = 1;
	for(int i = size; i < size * 2; i++)
	{
		
		result[i] = *(list + size - j);
		
		j++;
		
	}
	
	
	
	
	
	return result;
	
}
	
	



//Main function
int main()
{
	
	srand(time(NULL));
	
	//Define variables for text file manipulation
	char input[1000];
	char * filename;
	
	//Define numbers for function
	int M = (rand() % 25) + 0;
	int N = (rand() % M) + 0;
	
	cout << M << endl;
	cout << N << endl;
	
	//Defines more variables
	int size = 0;
	
	//Dynamic mem allocate
	int * myArray = new int[size];
	
	
	//Asks user for filename
	cout << "Enter a filename: ";
	cin >> input;
	
	cout << endl;
	
	//points pointer to new filename
	filename = input;
	
	
	cout << "Writing file: " << filename << endl;
	cout << "Reading file: " << filename << endl;
	
	
	//performs write random data
	WriteRandomData(N,M,filename);
	
	//performs read random data
	ReadData(filename, size, myArray);
	
	
	//Creates a pointer to the new array
	int * list = myArray;
	
	
	
	
	
	int * ptr_Array = DoubleandReverse(list, size);
	
	cout << "Double and Reversed is: [";
	
	for(int i = 0; i < size * 2; i++)
	{
		
		
		cout << *(ptr_Array + i) << ' ';
		
	}
	
	cout << "]" << endl;
	
	
	
	
	
	
	double one = getMedian(ptr_Array, size * 2);
	
	cout << "Median is: " << one << endl;
	
	
	int two = getLargest(ptr_Array, size * 2);
	
	cout << "Largest is: " << two << endl;
	
	cout << endl << endl;
	
	
	
	
	


  return 0;

}
