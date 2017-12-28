#include <iostream>

using namespace std;

//Produces a function for installing numbers into rhombus, for later
void Row(int n, int max)
{

  if(n < max)
    {
      cout << n << "  ";
      Row(n + 1, max);
    }

  cout << n << "  ";

}



//Prints upper portion of rhombus
void PrintUpper(int x)
{

  //Will determine how far indented to start
  int  nmoves = 27 -(3 * x);

  if(x > 1)
    {
      //Recursion all the way down
      PrintUpper(x - 1);

    }
  //Outputs string spaces
   cout << string(nmoves,' ');

   Row(1, x);

   cout << endl;

 
}



//Prints lower rhombus
void PrintLower(int y)
{
  //Delocates spaces
  int nmoves = 27 - (3 * y);

  if(y >= 1)
{
  //Spaces
  cout << string(nmoves, ' ');

  Row(1, y);

  cout << endl;
  //Recursion
  PrintLower(y - 1);
}

}

//Main function
void PrintRhombus(int n)
{

  PrintUpper(n);
  PrintLower(n - 1);

  cout << endl;


}


//Main function
int main()
{
  //Defines Number
  int num;

  cout << "Enter a number [1-9]: ";
  cin >> num;

  //Error check
  while(num < 1 || num > 9)
    {
      cout << "You have entered a number outside the range, try again: ";
      cin >> num;
    }

  PrintRhombus(num);
 



  return 0;


}
