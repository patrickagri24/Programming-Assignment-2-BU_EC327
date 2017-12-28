#include <iostream>
#include "Functions.h"
#include <fstream>
#include <cmath>
using namespace std;

extern const int ENTRIES;

//Initializer Function to start program
void initialize()
{

  cout << "EC327: Introduction to Software Engineering" << endl;

  cout << "Fall 2017" << endl;

  cout << "Programming Assignment 2" << endl;

  cout << "Value of entries is: "<< ENTRIES << endl; //Come back to here once defined value in int main

}

//Logical function for declaring legal code
bool checkCode(char x)
{

  //Conditons that must be checked
  return(x == 'F' || x == 'f' || x == 'B' || x == 'b' || x  == 'R' || x == 'r' || x == 'D' || x == 'd' || 
	 x == 'L' || x == 'l' || x == 'N' || x == 'n' || x == 'I' || x == 'i' || x == 'O' || x == 'o' || x == 'Q' || x == 'q');

}




//Function for writing data to a file
void writeDataToFile(const char* x)
{


	//Defines master code
	char MasterCode;

	//Defines single integer parameters to be used in Factorial or Fibonacci
	int FactFib;


	//Defines parameters for Computing odd numbers
	int firstOdd;
	int lastOdd;


	//Defines parameters for Square Root, etc functions
	double firstSLN;
	double lastSLN;
	double deltaSLN;


	//Defines outputs for use when needed
	int out1;
	double out2;


	ofstream file;
	
	file.open(x);
	
	
	file << "EC327: Introduction to Software Engineering" << "\r\n";

	file << "Fall 2017" << "\r\n";

	file << "Programming Assignment 2" << "\r\n";

	file << "Value of entries is: "<< ENTRIES << "\r\n"; //Come back to here once defined value in int main



	cout << "Please enter a command code: ";
	file << "Please enter a command code: ";
  
	cin >> MasterCode;
	file << MasterCode << "\r\n";

	//Checks if command code was illegal
	//Calls code Key1 for being the first key to continue program
	bool Key1 = checkCode(MasterCode);

  //While loop for checking the code
	while(Key1 == 0)
    {
		cout << "You have entered an incorrect code, try again: ";
		cin >> MasterCode;

		Key1 = checkCode(MasterCode);
	}

	
	
	do
    {

	

      //If Mastercode called for factorial
      if(MasterCode == 'F' || MasterCode == 'f')
		{
			cout << "Please enter command parameter: ";
			file << "Please enter command parameter: ";
	  
			cin >> FactFib;
			file << FactFib << "\r\n";

			out1 = factorial(FactFib);

			//Stub 
			//Do we need?
			cout << "Factorial(" << FactFib << ")" << " = " << out1 << endl << endl;
			file << "Factorial(" << FactFib << ")" << " = " << out1 << "\r\n";
		}

      //If Mastercode called for fibonacci
      else if(MasterCode == 'B' || MasterCode == 'b')
		{

			cout << "Please enter command parameter: ";
			file << "Please enter command parameter: ";
	  
			cin >> FactFib;
			file << FactFib << "\r\n";

			out1 = fibonacci(FactFib);

			//Stub
			//Do we need?
			cout << "Fibonacci(" << FactFib << ")" << " = " << out1 << endl << endl;
			file << "Fibonacci(" << FactFib << ")" << " = " << out1 << "\r\n";
	  
	  
		}

    


	//Sets up Program for is mastercode is Compute odd numbers 
	  else if(MasterCode == 'D' || MasterCode == 'd')
		{



			//Collects first and last values, for data collection purposes
			cout << "Please input the first number in the sequence: ";
			file << "Please input the first number in the sequence: ";
	  
			cin >> firstOdd;
			file << firstOdd << "\r\n";

			cout << "Please input the last number in the sequence: ";
			file << "Please input the last number in the sequence: ";
	  
			cin >> lastOdd;
			file << lastOdd << "\r\n";




			//Error check
			while(firstOdd >= lastOdd)
			{
				cout << "Invalid numbers, please input first number in sequence: ";
				file << "Invalid numbers, please input first number in sequence: ";
				
				cin >> firstOdd;
				file << firstOdd << "\r\n";

				cout << "Please input last number of sequence: ";
				file << "Please input last number of sequence: ";
				
				cin >> lastOdd;
				file << lastOdd << "\r\n";

			}


			//Reassigns i to be first odd number
			int i = firstOdd;


			for(i; i < lastOdd;)
			{

				out1 = findNextOddValue(i);

				i = i +2;

				cout << out1 << ' ';
				file << out1 << ' ';
	
			}

			cout << endl << endl;
			file << "\r\n";

		}
			
			
    


		//Sets up program for if mastercode is nyancat value, natural log, or square root
		//MIGHT HAVE TO ALTER DELTA ONCE FIGURE OUT WHAT EXACTLY THIS MEANS
		else if(MasterCode == 'R' || MasterCode == 'r' || MasterCode == 'L' || MasterCode == 'l' || MasterCode == 'N' || MasterCode == 'n')
		{

			//If code is square root
			if(MasterCode == 'R' || MasterCode == 'r')
			{

				//Collects first, last, and delta values
				cout << "Please enter first, last, and delta values, respectively: ";
				file << "Please enter first, last, and delta values, respectively: ";
				
				cin >> firstSLN >> lastSLN >> deltaSLN;
				file << firstSLN << lastSLN << deltaSLN << "\r\n";
			

				//performs operation
				if(firstSLN <=  lastSLN && deltaSLN > 0)
				{
				//For loop to do operation
	      
				double i = firstSLN;	      
				double j = lastSLN;
				double m = deltaSLN;
							
				double k = 0;
				//Designates a counter
				int c = 1;

					for(i; i <=  j;c++)
					{

					//makes it so for loop will not iterate more than ENTRIES
					if(c <= ENTRIES)
					{
						out2 = findSqrtValue(firstSLN + (deltaSLN * k));
					
						cout<< "squareroot(" << i << ")" << " = " << out2 << endl;
					
						file<< "squareroot(" << i << ")" << " = " << out2 << "\r\n";
					

						i = i + m;
						
						if(i > j)
						{
							cout<< "squareroot(" << j << ")" << " = " << out2 << endl;
							file<< "squareroot(" << j << ")" << " = " << out2 << "\r\n";
						}
						
						k++;
					}

					else
						
						break;


					}
				
				}
			
			

				else
					cout << "No operation needed" << endl << endl;
					file << "No operation needed" << endl << "\r\n";


			}


			//If code is natural log
			else if(MasterCode == 'L' || MasterCode == 'l')
			{

				//Collects first, last, and delta values
				cout << "Please enter first, last, and delta values, respectively: ";
				file << "Please enter first, last, and delta values, respectively: ";
				
				cin >> firstSLN >> lastSLN >> deltaSLN;
				file << firstSLN << lastSLN << deltaSLN << "\r\n";



				//performs operation
				if(firstSLN <=  lastSLN && deltaSLN > 0)
				{
						//For loop to do operation
	      
						double i = firstSLN;	      
						double j = lastSLN;
						double m = deltaSLN;
							
						double k = 0;

						//Designates a counter
						int c = 1;

					for(i; i <= j;c++)
					{

						//Makes it so loop will not iterate more than ENTIRES
						if(c <= ENTRIES)
						{

							out2 = naturalLog(firstSLN + (deltaSLN * k));
							
							cout<< "ln(" << i << ")" << " = " << out2 << endl;
							
							file<< "ln(" << i << ")" << " = " << out2 << "\r\n";
							
							i = i + m;
							
							if(i > j)
							{
								cout<< "ln(" << j << ")" << " = " << out2 << endl;
								file<< "ln(" << i << ")" << " = " << out2 << "\r\n";
							}

							
							k++;

						}

						else
							break;


					}
				}
				else
					cout << "No operation needed" << endl << endl;
					file << "No operation needed" << endl << "\r\n";
			}

			//If code is nyancat
			else if(MasterCode == 'N' || MasterCode == 'n')
			{

					//Collects first, last, and delta values
					cout << "Please enter first, last, and delta values, respectively: ";
					file << "Please enter first, last, and delta values, respectively: ";
					
					cin >> firstSLN >> lastSLN >> deltaSLN;
					file << firstSLN << lastSLN << deltaSLN << "\r\n";



					//performs operation
					if(firstSLN <=  lastSLN && deltaSLN > 0)
					{
						//For loop to do operation
	      
						double i = firstSLN;	      
						double j = lastSLN;
						double m = deltaSLN;
							
						double k = 0;

						//Designates a counter
						int c = 1;

						for(i; i <= j;c++)
						{
		  
							//Sets up for loop to never run more than ENTRIES
							if(c <= ENTRIES)
							{

								out2 = findNyanCatValue(firstSLN + (deltaSLN * k));
								
								cout<< "Nyan Cat value of(" << i << ")" << " = " << out2 << endl;
								
								file<< "Nyan Cat value of(" << i << ")" << " = " << out2 << "\r\n";

								i = i + m;
								
								if(i > j)
								{
									cout<< "Nyan Cat value of(" << j << ")" << " = " << out2 << endl;
									
									file<< "Nyan Cat value of(" << i << ")" << " = " << out2 << "\r\n";
								}
								
								
								k++;
							}

							else
								break;



						}
					}	
					
	  
					else
						cout << "No operation needed" << endl << endl;
						file << "No operation needed" << endl << "\r\n";
			}	




					

		}

		
					//Calls back master function to keep looping
					cout << "Please enter a command code: ";
					file << "Please enter a command code: ";
  
					cin >> MasterCode;
					file << MasterCode << "\r\n";
					
					
					
					
					
					 //Checks if command code was illegal
					//Calls code Key1 for being the first key to continue program
					bool Key1 = checkCode(MasterCode);

					//While loop for checking the code
					while(Key1 == 0)
					{
						cout << "You have entered an incorrect code, try again: ";
						file << "You have entered an incorrect code, try again: ";
						
						cin >> MasterCode;
						file << MasterCode << "\r\n";

						Key1 = checkCode(MasterCode);
					}
					
					
		file.close();
		
	}
	
	//Sets up Program if mastercode was either factorial or fibonacci
	while(MasterCode == 'F' || MasterCode == 'f' || MasterCode == 'B' || MasterCode == 'b' || MasterCode == 'R' || MasterCode == 'r' || MasterCode == 'D' ||
	MasterCode == 'd' || MasterCode == 'L' || MasterCode == 'l' || MasterCode == 'N' || MasterCode == 'n');


	


}


//Functin for reading data to a file
void readDataFromFile(const char *x)
{

    ifstream file(x);
   
	//character for operation
	char MasterCode;
	
	//integer for one parameter operations
	int y;
	
	
	//odd integers
	int o;
	int p;
	
	//Result for odd operations that return an int
	int out1;
	
	
	
	//doubles for three parameter operations
	double a;
	double b;
	double c;
   
	double out2;
	
	if(file.is_open())
	{
		
		
		while(file >> MasterCode)
		{
			
				cout << "Please enter command code: " << MasterCode << endl;

				//If Mastercode called for factorial
				if(MasterCode == 'F' || MasterCode == 'f')
				{
					//this will be the integer we need
					file >> y;
					
					cout << "Please enter command parameter: " << y << endl;
					

					out1 = factorial(y);

					//Stub 
					//Do we need?
					cout << "Factorial(" << y << ")" << " = " << out1 << endl << endl;
					
				}

				//If Mastercode called for fibonacci
				else if(MasterCode == 'B' || MasterCode == 'b')
				{

					//This will be int we need
					file >> y;
			
					cout << "Please enter command parameter: " << y << endl;;
					
	  

					out1 = fibonacci(y);

					//Stub
					//Do we need?
					cout << "Fibonacci(" << y << ")" << " = " << out1 << endl << endl;
					
	  
	  
				}

    


				//Sets up Program for is mastercode is Compute odd numbers 
				else if(MasterCode == 'D' || MasterCode == 'd')
				{

					//integers we need
					file >> o >> p;

					//Collects first and last values, for data collection purposes
					cout << "Please input the first number in the sequence: " << o << endl;;
				

					cout << "Please input the last number in the sequence: " << p << endl;
				



							//Reassigns i to be first odd number
							int i = o;


							for(i; i < p;)
							{

								out1 = findNextOddValue(i);

								i = i + 2;

								cout << out1 << ' ';
							
	
							}

							cout << endl << endl;
							

				}
			

				//If code is square root
				if(MasterCode == 'R' || MasterCode == 'r')
				{

						//values we need
						file >> a >> b >> c;
				
						//Collects first, last, and delta values
						cout << "Please enter first, last, and delta values, respectively: " << a << ' ' << b << ' ' << c;
						
				
			

						//performs operation
						if(a <=  b && c > 0)
						{
							//For loop to do operation
	      
							double i = a;	      
							double j = b;
							double m = c;
							
							double k = 0;

							//LEFT OFF HERE
							
							
							//Designates a counter
							int c = 1;
	
							for(i; i <=  j;c++)
							{

								//makes it so for loop will not iterate more than ENTRIES
								if(c <= ENTRIES)
								{
									out2 = findSqrtValue(a + (c * k));
									
									cout<< "squareroot(" << i << ")" << " = " << out2 << endl;
					
									i = i + m;

									if(i > j)
									{
										cout<< "squareroot(" << j << ")" << " = " << out2 << endl;
									}
									
								
									k++;
								}

								else
							
									break;


							}
				
						}
			
			

						else
							cout << "No operation needed" << endl << endl;


				}
	

				//If code is natural log
				else if(MasterCode == 'L' || MasterCode == 'l')
				{

							//what we need
							file>> a >> b >> c;
				
							//Collects first, last, and delta values
							cout << "Please enter first, last, and delta values, respectively: " <<  a << ' ' << b << ' ' << c;
							
				
			


							//performs operation
							if(a <=  b && c > 0)
							{
								//For loop to do operation
	      
								double i = a;	      
								double j = b;
								double m = c;
							
								double k = 0;

								//Designates a counter
								int c = 1;

								for(i; i <= j;c++)
								{

									//Makes it so loop will not iterate more than ENTIRES
									if(c <= ENTRIES)
									{

										out2 = naturalLog(a + (c * k));
										
										cout<< "ln(" << i << ")" << " = " << out2 << endl;
							
										i = i + m;
										
										if(i > j)
										{
											cout<< "ln(" << j << ")" << " = " << out2 << endl;
										}
										
										
										
										k++;

									}

									else
										break;


								}
							}
							else
								cout << "No operation needed" << endl << endl;
				}

				//If code is nyancat
				else if(MasterCode == 'N' || MasterCode == 'n')
				{

							//what we need
							file >> a >> b >> c;
				
							//Collects first, last, and delta values
							cout << "Please enter first, last, and delta values, respectively: " << a << ' ' << b << ' ' << c;
						


							//performs operation
							if(a <=  b && c > 0)
							{
								//For loop to do operation
	      
								double i = a;	      
								double j = b;
								double m = c;
							
								double k = 0;


								//Designates a counter
								int c = 1;

								for(i; i <= j;c++)
								{
		  
									//Sets up for loop to never run more than ENTRIES
									if(c <= ENTRIES)
									{

										out2 = findNyanCatValue(a + (c * k));
										
										cout<< "Nyan Cat value of(" << i << ")" << " = " << out2 << endl;
										

										i = i + m;
										
										if(i > j)
										{
											cout<< "Nyan Cat value of(" << j << ")" << " = " << out2 << endl;
										}
										
										
										k++;
									}

									else
										break;



								}
							}	
					
	  
							else
								cout << "No operation needed" << endl << endl;
				}	

					

		}

					
 
			
			

			
 
				
			
	}
	
	else
		cout << "Cannot open file" << endl;
			
			
		file.close();

		
		
		
}
	





//finds nyancat value
double findNyanCatValue(double x)
{
  //Defines output
  double out;

  out = ((2 * x) + (x * pow(6,x)));

  return out;

}

//Finds factorial of a number
int factorial(int x)
{

  //Defines variables to be used in function
  int i;
  int result = 1;

  //calculates factorial
  for(i = x; i > 0; i --)
    {
      result = result * i;
    }

  return result;

}



//finds fibonacci of the number
int fibonacci(int x)
{
  //Defines variables to be used
  int c;
  int fT = 0;
  int sT = 1;
  int next;

  for(c = 0; c < x; c++)
    {
      if(c <= 1)
	{
	next = c;
	}

      else
	{
	  next = fT + sT;
	  fT = sT;
	  sT = next;
	}
    }

  return  next;

}



//Finds square root
double findSqrtValue(double x)
{
  //Defines result
  double out;

  out = sqrt(x);

  return out;


}


//Finds natural log of number
double naturalLog(double x)
{

  //Finds result
  double out;

  out = log(x);

  return out;

}

//Finds next odd number
int findNextOddValue(int x)
{

  //Result of function
  int out;

  //Checks to see if number is odd
  if(x % 2 == 0)
    {
      out = x + 1;
    }

  else
    {
      out = x + 2;
    }

  return out;

}
