#include <iostream>

using namespace std;

//Function for getting middle number of an array
double getMedian(int myarray[], int size)
{

  //Use bubble sort method to sort the array
  int temp;

  for(int i = 0; i < size; i++)
    {

      //Defines a min so far
      int minsofar = myarray[i];

      for(int j = i + 1; j < size; j++)
	{
	  if(myarray[j] < minsofar)
	    {

	      minsofar = myarray[j];

	      //swaps them
	      temp = myarray[i];
	      myarray[i] = myarray[j];
	      myarray[j] = temp;
	    }

	}

    }

  //now computes median
  int middle;
  double median;


  middle = size/2;

  if(size % 2 == 0)
    {

      median = ((myarray[middle-1] + myarray[middle])) / 2.0;

    }

  else

    median = myarray[middle];


  return median;



}


//Function for getting largest number in an array
int getLargest(int myarray[], int size)
{

 //Use bubble sort method to sort the array
  int temp;

  for(int i = 0; i < size; i++)
    {

      //creates a minimum so far
      int minsofar = myarray[i];


      for(int j = i + 1; j < size; j++)
	{
	  if(myarray[j] < minsofar)
	    {

	      minsofar = myarray[j];

	      //swaps them
	      temp = myarray[i];
	      myarray[i] = myarray[j];
	      myarray[j] = temp;
	    }

	}

    }


  //now outputs largest number in array, which is just at the end of the array
  int largest;

  largest = myarray[size - 1];


  return largest;



}
