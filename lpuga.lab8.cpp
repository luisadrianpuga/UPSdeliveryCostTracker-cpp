//Luis Puga
// November 30, 2021
// This Program runs various function depending on user choice

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

// constants for menu items
const int PI = 1;
const int SP = 2;
const int PP = 3;
const int EXIT = 4;

//constant for revnue per package
const double REVENUE = 0.34;
 
//Constant for days in a week
const double DAYS = 7;
//display title
int displayMenu(int);

//Calculate PnL
void stringMath();

//Boolean function to confirm exit.
bool AconfirmExit();

//C-String Manipulation
void cStringManip();

const int SIZE = 24; // Sub String Constant
const int MAX = 10;// 
const int FINALSIZE = 55;// Full string 



void welcome();// Program title
void alphaCounter(char array[]);//Count the alpha
//Boolean function to confirm exit.
bool confirmExit();

int main() {
	// Variables for making a choice
	int choice = -1;
	bool aContflag = false;
	char output[FINALSIZE] = "How R cStrings 4 U? They can B tricky 4 C++ students!";
	bool bContFlag = false;

	welcome();//Welcome User
	do {

		choice = displayMenu(choice);
		//Ask user for their input 
			switch (choice)
			{
			case PI: {
				//Calculate PnL
				do {
					stringMath();

					aContflag = AconfirmExit();
				} while (aContflag);

				break;
			}
			
			
			case SP: {
				cout << "\nThe test string is: " << output << endl;
				alphaCounter(output);
				break;
			}
				

			case PP: {
				cStringManip();
				break;

			}
			

			case EXIT:	{
				//Boolean function to confirm exit.
				bContFlag = confirmExit();
				break;
			}
				

			default: {
				cout << "ERROR - This is not a valid option, please try again.\n" << endl;
				choice = displayMenu(choice);
				
			}
				
		}


	} while (bContFlag != true);





	return 0;
}

// Program title
void welcome() {

	cout << "Lab 8 - Strings\n";
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.\n\n";
	cout << right << setw(5) << "             Welcome to CMSY-141 C-String Manipulation Program" << right << endl;

}

int displayMenu(int choice)
{

	// Menu
	cout << "\nString Lab Menu:" << endl;
	cout << right << setw(5) << PI << "- Doing Math with Strings" << right << endl;
	cout << right << setw(5) << SP << "- Counting Elements" << endl;
	cout << right << setw(5) << PP << "- C-String Manipulation" << endl;
	cout << right << setw(5) << EXIT << "- Exit Program" << endl;

	// Ask user for menu selection choice
	cout << "Please enter menu choice: ";
	cin >> choice;


	return choice;
}



void stringMath() {



	char miles[SIZE];
	char milesPerGallon[SIZE];
	char cost[SIZE];
	char delivered[SIZE];
	
	
	
	
		cin.ignore();

		//double
		cout << "\nPlease enter in the number of miles driven in a week: ";
		cin.getline(miles, SIZE);

		double i = atof(miles);



		//double
		cout << "\nPlease enter in the miles per gallon your vehicle gets: ";
		cin.getline(milesPerGallon, SIZE);

		double e = atof(milesPerGallon);
	

		//double
		cout << "\nPlease enter the cost of a gallon of diesel: ";
		cin.getline(cost, SIZE);

		double f = atof(cost);
	
		//int
		cout << "\nPlease enter the number of packages delivered per week: ";
		cin.getline(delivered, SIZE);

		int g = atoi(delivered);

	
		//Convert c-string to int or double


		//Display
		cout << setprecision(2) << fixed << showpoint;
		cout << "\nThe number of miles driven in a week was: " << i << endl;
		//Calculate fuel
		double fuel = (i / e);
		cout << "The amount of fuel used in a week was " << fuel << endl;
		//Calculate the cost
		double fCost = (fuel * f);
		cout << "The cost of fuel for the week was: $" << fCost << endl;
		//Calculate the average deliveries
		double AvgDel = (static_cast<double>(g) / DAYS);
		cout << "The average packages delivered per day was: " << AvgDel << endl;
		//Calculate the average miles driven per day
		double AvgMiles = (i / DAYS);
		cout << "The average miles driven per day was: " << AvgMiles << endl;
		//Calculate the average amount of fuel per day
		double avgFuel = (fuel / DAYS);
		cout << "The average amount of fuel used per day was: " << avgFuel << endl;
		//Calculate the average cose per day
		double AvgCost = (avgFuel * f);
		cout << "The average cost per day was: $" << AvgCost << endl;
		//Calculate the total revenue per week
		double totalRevenue = (static_cast<double>(g) * REVENUE);
		cout << "The total revenue for the week was: $" << totalRevenue << endl;
		//Calculate profit
		double profit = (totalRevenue - fCost);
		cout << "The company made $" << profit << " in deliveries this week." << endl;
		

	
}






void alphaCounter(char output[]) {
	int alphas = 0;
	int digits = 0;
	int uppers = 0;
	int lowers = 0;
	int spaces = 0;
	int puncts = 0;

	for (int count = 0; count < FINALSIZE; count++) {
		if (isalpha(output[count]))
			alphas++;
		if (isupper(output[count]))
			uppers++;
		if (islower(output[count]))
			lowers++;
		if (isdigit(output[count]))
			digits++;


		if (isspace(output[count]))
			spaces++;

		if (ispunct(output[count]))
			puncts++;
	}

	cout << "\nThe number of alphas = " << alphas << endl;

	cout << "The number of digits = " << digits << endl;

	cout << "The number of uppers = " << uppers << endl;

	cout << "The number of lowers = " << lowers << endl;

	cout << "The number of spaces = " << spaces << endl;

	cout << "The number of puncts = " << puncts << endl;
}
//Boolean function to confirm exit.
bool AconfirmExit() {
	char cYesNO;

	do
	{
		cout << "Do you wish to enter another value? (y / n) ";
		cin >> cYesNO;

		if (cYesNO != 'Y' && cYesNO != 'y' && cYesNO != 'N' && cYesNO != 'n')
		{
			cout << "Error - Only y or n is valid, please reenter: " << endl;
		}
	} while (cYesNO != 'Y' && cYesNO != 'N' && cYesNO != 'n' && cYesNO != 'y');
	
	if (cYesNO == 'Y' || cYesNO == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//C-String Manipulation
void cStringManip() {
	cin.ignore();
	char testString[SIZE];
	cout << "Enter in a string for test string: ";
	cin.getline(testString, SIZE);

	//Tell the user the length of the string
	int length = 0;
	length = strlen(testString);
	cout << "The size of the string is: " << length << endl;



	//First Name
	char firstName[SIZE];
	cout << "\nEnter in a first name: ";
	cin.getline(firstName, SIZE);

	//Last Name
	char lastName[SIZE];
	cout << "Enter in a last name: ";
	cin.getline(lastName, SIZE);

	//Complete name
	char completeName[FINALSIZE];
	//Put the String Together
	strcpy_s(completeName, firstName);
	strcat_s(completeName, " ");
	strcat_s(completeName, lastName);

	int tlength = 0;
	tlength = strlen(completeName);
	cout << "\nAfter strcpy, string completeName is " << completeName << " and the length of the string is: " << tlength << endl;

	//Replace a character
	char character;
	int number;

	cout << "\nEnter in a single character: ";
	cin >> character;

	cout << "Enter in the character number in the string holding the full name to replace: ";
	cin >> number;

	completeName[number-1] = character; 

	cout << "After replacement, string completeName is " << completeName << endl;

	//Get address
	cin.ignore();
	
	char city[SIZE];
	cout << "\nEnter in a city: ";
	cin.getline(city, SIZE);

	char state[SIZE];
	cout << "Enter in a state: ";
	cin.getline(state, SIZE);
	
	char zip[SIZE];
	cout << "Enter in a zip: ";
	cin.getline(zip, SIZE);

	
	char completeAddress[FINALSIZE];
	//Put the String Together
	strncpy_s(completeAddress, city, 10);
	
	cout << "When doing strncpy of city into completeAddress, max 10, you get: " << completeAddress << endl;

	cout << "\nWhen fist copied, city and completeAdress do not equal each other." << endl;
	
	
	
	strcat_s(completeAddress, ", ");
	strcat_s(completeAddress, state);
	strcat_s(completeAddress, " ");
	strcat_s(completeAddress, zip);

	cout << "The complete address is: " << completeAddress << endl;

	int slength = 0;
	slength = strlen(completeAddress);
	cout << "The length of the address is: " << slength << endl;
	char* strPtr = nullptr;

	strPtr = strstr(completeAddress, "Maryland");

	cout << "\n When looking for 'Maryland' in the name using strstr you get: " << strPtr;
}


//Boolean function to confirm exit.
bool confirmExit()
{
	char cYesNO;

	do
	{
		cout << "\nDo you want to exit the program (y / n) ";
		cin >> cYesNO;

		if (cYesNO != 'Y' && cYesNO != 'y' && cYesNO != 'N' && cYesNO != 'n')
		{
			cout << "Error - Only y or n is valid, please reenter: " << endl;
		}
	} while (cYesNO != 'Y' && cYesNO != 'N' && cYesNO != 'n' && cYesNO != 'y');
	cin.clear();
	cin.ignore();
	if (cYesNO == 'Y' || cYesNO == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}