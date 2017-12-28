
#include <iostream>
#include "FileFunctions.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

//Function for writing random data to file
void WriteRandomData(int N, int M, const char * filename)
{

  srand(time(NULL));

  ofstream file;
  
  file.open(filename);

  for(int i = 0; i < N; i++)
    {

      int out = rand() % (M + 1);

      file << out << "\r\n";

    }

  file.close();

  return;

}



//Function for reading data from file
void ReadData(const char *filename, int &size, int myArray[])
{

	
	//string for line
	string line;
	
	ifstream file;
	
	file.open(filename);
	
	if(file.is_open())
	{
		while(getline(file,line))
		{
			size++;
		}
		
		file.close();
		
	}
	
	else
		cout << "Unable to open file" << endl;
	

	
	//gives my array a size
	// 	myArray[size];
	//	myArray = new int[size];
	
	
	
	file.open(filename);
	
	if(file.is_open())
	{
	  
		for(int i = 0; i <= size; i++)
		{
			file >> myArray[i];
			
		}
	  
	  /*
	  int i = 0;
	  while(getline(file,line))
	    {
	      myArray[i++] = atoi(line.c_str());
	    }
	  */  
		
		file.close();
		
	}
	
	else
		cout << "Could not open file" << endl;
	
	
	return;

}
