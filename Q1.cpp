#include <iostream>
#include <cmath>
#include "Functions.h"
#include <fstream>
using namespace std;

//Defines external constant for entries
const int ENTRIES = 10;



//Main function
int main()
{

	initialize();



	//Defines master code
	char MasterCode;

	//Defines single integer parameters to be used in Factorial or Fibonacci
	int FactFib;


	//Define files that we want to read or write from if user selects read or write to file
	//Come back here when you understand file I/O
	char * filename;




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






	cout << "Please enter a command code: ";
	cin >> MasterCode;

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
				cin >> FactFib;

				out1 = factorial(FactFib);

				//Stub 
				//Do we need?
				cout << "Factorial(" << FactFib << ")" << " = " << out1 << endl << endl;
			}

			//If Mastercode called for fibonacci
			else if(MasterCode == 'B' || MasterCode == 'b')
			{

			cout << "Please enter command parameter: ";
			cin >> FactFib;

			out1 = fibonacci(FactFib);

			//Stub
			//Do we need?
			cout << "Fibonacci(" << FactFib << ")" << " = " << out1 << endl << endl;
			}


      
		


			//Sets up program for if mastercode was read from input file or write to output file
			else if(MasterCode == 'I' || MasterCode == 'i' || MasterCode == 'O' || MasterCode == 'o')
			{

				char in[1000];

	
				if(MasterCode == 'I' || MasterCode == 'i')
				{
					cout << "Please enter code parameters: ";
					cin >> in;

					filename = in;
				
					readDataFromFile(filename);
		
				}
	
				else if(MasterCode == 'O' || MasterCode == 'o')
				{
		
					cout << "Please enter code parameters: ";
					cin >> in;

					filename = in;
		
					writeDataToFile(filename);
		
				}
	
	

     

			}


			//Sets up Program for is mastercode is Compute odd numbers 
			else if(MasterCode == 'D' || MasterCode == 'd')
			{



				//Collects first and last values, for data collection purposes
				cout << "Please input the first number in the sequence: ";
				cin >> firstOdd;

				cout << "Please input the last number in the sequence: ";
				cin >> lastOdd;




					//Error check
					while(firstOdd >= lastOdd)
					{
						cout << "Invalid numbers, please input first number in sequence: ";
						cin >> firstOdd;
	
						cout << "Please input last number of sequence: ";
						cin >> lastOdd;

					}


				//Reassigns i to be first odd number
				int i = firstOdd;


				for(i; i < lastOdd;)
				{

					out1 = findNextOddValue(i);

					i = i +2;

					cout << out1 << " ";
				}

					cout << endl << endl;
	



    

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
						cin >> firstSLN >> lastSLN >> deltaSLN;
	


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
							cout << "No operation needed" << endl;
	
	
	
						cout << endl;
					}

			


					//If code is natural log
					else if(MasterCode == 'L' || MasterCode == 'l')
					{

						//Collects first, last, and delta values
						cout << "Please enter first, last, and delta values, respectively: ";
						cin >> firstSLN >> lastSLN >> deltaSLN;



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
							cout << "No operation needed" << endl;
	
							cout << endl;
	
	
	
					}
			
			
			

					//If code is nyancat
					else if(MasterCode == 'N' || MasterCode == 'n')
					{

						//Collects first, last, and delta values
						cout << "Please enter first, last, and delta values, respectively: ";
						cin >> firstSLN >> lastSLN >> deltaSLN;



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
							cout << "No operation needed" << endl;
			
							cout << endl;
					}




   

			}
			

		
		
		cout << "Please enter a command code: ";
		cin >> MasterCode;

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
		
		
		

	}
	
	while(MasterCode == 'F' || MasterCode == 'f' || MasterCode == 'B' || MasterCode == 'b' || MasterCode == 'R' || MasterCode == 'r' || MasterCode == 'D' ||
			MasterCode == 'd' || MasterCode == 'L' || MasterCode == 'l' || MasterCode == 'N' || MasterCode == 'n' || 
			MasterCode == 'I' || MasterCode == 'i' || MasterCode == 'O' || MasterCode == 'o');


  return 0;
}
