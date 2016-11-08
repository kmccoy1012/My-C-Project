/* Name:		Kevin McCoy
   Project:		Final Project
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define SIZE 20

using namespace std;


struct COASTER
{
	string coasterName;
	string coasterPark;
	string coasterLoc;
	double coasterPeak;
	char coasterType;
	double thrill, hill, scariness;
	int ratingNumbers;
};

/*	Name: showMenu
    Preconditions: takes no parameters
	Postconditions: called in main without a function prototype
 */
void showMenu()
{
	
	cout << "1. Add Coaster" << endl;
	cout << "2. Add Coaster Ratings(Overall Thrill, Hills, Scariness)" << endl;
	cout << "3. Search for a Coaster by Name" << endl;
	cout << "4. Search for a Coaster by Type(Wood or Steel)" << endl;
	cout << "5. Show a Listing of All Coasters" << endl;
	cout << "6. Search for a Coaster by Rating" << endl;
	cout << "7. Save Database to a file" << endl;
	cout << "8. Load Database from a file" << endl;
	cout << "9. Exit" << endl;
}


/*	Name: showMenu
	Preconditions: takes in two parameters
	Postconditions: after the parameters are taken it, it allows the user to input their data about the roller coaster
 */
void inputdata(COASTER temp[], int numberofcoasters)
{
	cin.get();
	cout << "Enter the Coaster's name: " << endl;
	getline(cin, temp[numberofcoasters].coasterName);
	cout << "Enter the Theme Park's name: "<< endl;
	getline (cin, temp[numberofcoasters].coasterPark);
	cout << "Enter the park's location: "<< endl;
	getline(cin,temp[numberofcoasters].coasterLoc);
	cout << "Enter the peak height: " << endl;
	cin >> temp[numberofcoasters].coasterPeak;
	cin.get();
	cout << "Is the coaster Wood or Steel?(W or S);";
	cin.get(temp[numberofcoasters].coasterType);
	cout << endl << endl;
	
}


// Function Prototypes
void openInputFile(ifstream& fin);
void initializeRatings(COASTER rate[]);
void inputRatings(COASTER rate[], int numberofcoasters);
void nameSearch(COASTER rate[], int numberofcoasters);
void typeSearch(COASTER rate[], int numberofcoasters);
void ratingSearch(COASTER rate[], int numberofcoasters);
void outputCoasters(COASTER rate[], int numberofcoasters);
void outputFile(ofstream& out, COASTER rate[], int numberofcoasters);
void inputFile(ifstream& in, COASTER rate[], int& numberofcoasters);

// main function
int main(){
	
	//Array of structs
	COASTER info[SIZE];
	
	//Variable for the user's selection in the menu
	int selection = 0;
	
	// string variable for the input file
	string filename;

	//Bool value to check if selection 1 or 8 has been input
	bool check = false;
	//Bool value to check if selection 2 has been input
	bool checker = false;
	
	
	//input and output file varialbes
	ifstream fin;
	ofstream fout;
	fin.clear();
	

	
	// variable for the number of coasters
	int numberOfThings = 0;

	
	
	//Intro Statement
	
	cout << "****************************************************************" << endl;
	cout << "This program will allow you to input roller coaster data." << endl;
	cout << "You MUST complete SELECTIONS 1 and 2 before completing option 7." << endl;
	cout << "You MUST also complete option 1 or option 8 before proceeding." << endl;
	cout << "****************************************************************" << endl << endl << endl;
	//while loop for the menu
	//will exit if the user enters 9
	while (selection !=9) {
	
		// shows the user the menu
		showMenu();
		cout << "Enter your selection:";
		cin	>> selection;
		
		
		// if statement that calls the inputdata function
	if (selection == 1) {
		inputdata(info, numberOfThings);
		
		// sets the bool variable check to true
		check = true;
		
		//adds 1 to the numberOfThings varialbe
		numberOfThings++;
	}
	
		//if statement for selection 2, calls the coaster ratings function
	else if (selection == 2 && check == true)
	{
		inputRatings(info, numberOfThings);
		checker = true;
	}
	
		//if statement if the user enters 3, calls a function to search for the coaster name
	else if (selection == 3 && check == true)
	{
		nameSearch(info, numberOfThings);
	}
		//if statement for if the user enters 4, calls a function to allow the user to search by type 
	else if (selection == 4 && check == true)
	{
		typeSearch(info, numberOfThings);
	}
		//if statement for if the user enters 5, calls a function to output the current list of coasters
	else if (selection == 5 && check == true)
	{
		outputCoasters(info, numberOfThings);
	}
		//if statement for if the user enters 6, allows the user to search by ratings
	else if (selection == 6 && check == true && checker == true)
	{
		ratingSearch(info, numberOfThings);	
	}
		//if statement if the user enters 7, saves the data to the file "outputFile.txt"
	else if (selection == 7 && check == true && checker == true)
	{
		fout.open("outputFile.txt");
		outputFile(fout, info, numberOfThings);
		
	}
		//loads the data from a file
		
		//**************
		//this will only work if you run the program
		//input your coaster data, select 7 to output it to outputFile.txt
		//keep the program open or close it, select option 8, outputFile.txt
		//I couldn't get it to work with other input file
		//**************
	else if (selection == 8)
	{
			
		cout << "What is the name of your file?: ";
		cin >> filename;
		fin.open(filename.c_str());
		
		inputFile(fin, info, numberOfThings);
		
		check = true;
		
	}
		
		// else statement that issues a warning to the user if the user inputs a selection out of the range
		// of 1-8
		else if (selection == 9)
		{return 0;}
	else {
		cout << endl;
		cout << "********************************************************************" << endl;
		cout << "You must select 1 or 8 before selecting any other options!" << endl;
		cout << "********************************************************************" << endl << endl;
		}

}
	
	//closes the output file
	fout.close();
	fin.close();
	return 0; // exit main
}

/*	Function Name: initializeRatings
	Preconditions: takes in an array of structs as its input parameter
	Postcondition: initalizes the ratingNumbers, thrill, hill, and scariness to 0
 */
void initializeRatings(COASTER rate[])
{
	for (int i=0; i<SIZE; i++) {
		rate[i].ratingNumbers = 0;
		rate[i].thrill = 0;
		rate[i].hill = 0;
		rate[i].scariness = 0;
	}
}
/*	Name: inputRatings
	Preconditions: takes in an array of structs and an integer as its input parameters
	Postconditions: called in main with two paraters
 */

void inputRatings(COASTER rate[], int numberofcoasters)
{
	//variables named
	int selection = 0;
	double tempT, tempH, tempS;

	// for loop to count the number of coasters and store them and displays the stored coasters already input
	for (int i=0;i<numberofcoasters;i++)
		cout << i << ". "<< setw(15) << rate[i].coasterName << endl;
	
	// asks the user to select which coaster to add ratings to
	cout << "What roller coaster would you like to rate?" << endl;
	cin >> selection;
		if (selection < numberofcoasters)
		{
	cout << "You will enter the ratings on a 1-10 scale" << endl;
	cout << "Enter the Thrill Rating: ";
	cin >> tempT;
	cout << "Enter the Hill Rating: ";
	cin >> tempH;
	cout << "Enter the Scariness Rating: ";
	cin	>> tempS;
	}
	
	//If the user inputs a selection out of range, they are issued an error message
	else {
		cout << endl;
		cout << "*********************************" << endl;
		cout << "You entered an invalid selection!";
		cout << "*********************************" << endl;
		cout << endl;
	}

	//Calculate the new ratings
	rate[selection].thrill = (rate[selection].thrill * rate[selection].ratingNumbers + tempT) / (rate[selection].ratingNumbers + 1);
	rate[selection].hill = (rate[selection].hill * rate[selection].ratingNumbers + tempH) / (rate[selection].ratingNumbers + 1);
	rate[selection].scariness = (rate[selection].scariness * rate[selection].ratingNumbers + tempS) / (rate[selection].ratingNumbers + 1);
	rate[selection].ratingNumbers++;
	
}



/*	Name: nameSearch
	Preconditions: takes in an array of structs and an int as its parameters
	Postconditions: called in main with two paraters and allows users to search by coaster name
 */


void nameSearch(COASTER rate[], int numberofcoasters)
{
	//variable named
	string tempName;
	cin.get();
	cout << "Enter the Name of the Coaster you are searching for:";
	getline(cin, tempName);
	
	// for loop for the number of coasters
	for(int i=0;i<numberofcoasters;i++)
	{
		//if statement to allow searching based on if the user's input
		if (tempName == rate[i].coasterName)
		{
			cout << endl;
			cout << "Coaster:" << setw(15) << rate[i].coasterName << endl;
			cout << "Type:" << setw(18) << rate[i].coasterType << endl;
			cout << "Park:" << setw(18) << rate[i].coasterPark << endl;
			cout << "Location:" << setw(14) << rate[i].coasterLoc << endl;
			cout << "Peak Height:" << setw(11) << rate[i].coasterPeak << endl;
			cout << endl;
			
		}
		//If the user inputs a selection out of range, they are issued an error message
		else {
			cout << endl << endl;
			cout << "*************WARNING***********" << endl;
			cout << "!No Coasters match your search!" << endl;
			cout << "*******************************" << endl << endl;
		}
	}
}
/*	Name: inputRatings
	Preconditions: takes in an array of structs and an integer as its input parameters
	Postconditions: called in main with two paraters and allows the user to search coasters by type
 */


void typeSearch(COASTER rate[], int numberofcoasters)
{
	//char variable for the type of coaster (w or s)
		char tempType;
		cin.get();
		cout << "Enter the Type of the Coaster you are searching for:";
		cin.get(tempType);
		
	//for loop for the number of coasters
		for(int i=0;i<numberofcoasters;i++)
		{
			//if statement for if the user's type = a type already input
			if (tempType == rate[i].coasterType)
			{
				cout << endl;
				cout << "Coaster:" << setw(15) << rate[i].coasterName << endl;
				cout << "Type:" << setw(18) << rate[i].coasterType << endl;
				cout << "Park:" << setw(18) << rate[i].coasterPark << endl;
				cout << "Location:" << setw(14) << rate[i].coasterLoc << endl;
				cout << "Peak Height:" << setw(11) << rate[i].coasterPeak << " feet" << endl << endl;
			}
			//If the user inputs a selection out of range, they are issued an error message
			else {
				cout << endl << endl;
				cout << "*************WARNING***********" << endl;
				cout << "!No Coasters match your search!" << endl;
				cout << "*******************************" << endl << endl;
			}

		}
}


/*	Name: inputRatings
	Preconditions: takes in an array of structs and an integer as its input parameters
	Postconditions: called in main with two paraters, allows the user to search based on the ratings
 */

void ratingSearch(COASTER rate[], int numberofcoasters)
{
	//variables named
	double tempThrill, tempHills, tempScary;
	bool hit = false;
	
	cin.get();
	cout << endl;
	cout << "Here, you will input ratings and the program will display" << endl;
	cout << "any coasters with ratings that are greater than the value you are searching for." << endl << endl;
	cout << "Enter the Thrill Rating of the Coaster you are searching for:";
	cin >> tempThrill;
	cout << "Enter the Hill Rating of the Coaster you are searching for:";
	cin >> tempHills;
	cout << "Enter the Scariness Rating of the Coaster you are searching for:";
	cin >> tempScary;
	
	//for loop for the number of coasters already input
	for(int i=0;i<numberofcoasters;i++)
	{
		//if statement for if the thrill, hill, and scary ratings are < or = to what the user inputs
		if (tempThrill <= rate[i].thrill && tempHills <= rate[i].hill && tempScary <= rate[i].scariness)
		{
			cout << endl << endl;
			cout << "Coaster:" << setw(15) << rate[i].coasterName << endl;
			cout << "Park:" << setw(18) << rate[i].coasterPark << endl;
			cout << "Location:" << setw(14) << rate[i].coasterLoc << endl;
			cout << "Type:" << setw(18) << rate[i].coasterType << endl;
			cout << "Peak Height:" << setw(11) << rate[i].coasterPeak << " feet" << endl;
			cout << "Number of Ratings: " << setw(4) << rate[i].ratingNumbers << endl;
			cout << "Thrill:" << setw(16) << rate[i].thrill << endl;
			cout << "Hills:" << setw(17) << rate[i].hill << endl;
			cout << "Scariness:" << setw(13) << rate[i].scariness << endl << endl;
			hit = true;
		}
		
	}
	//if the user fails to select a correct coaster to rate, they will receive an error message
	if (hit == false) {
			cout << endl << endl;
			cout << "*************WARNING***********" << endl;
			cout << "!No Coasters match your search!" << endl;
			cout << "*******************************" << endl << endl;
		}
}

/*	Name: outputCoasters
	Preconditions: takes in an array of structs and an integer as its input parameters
	Postconditions: called in main with two paraters and will output the coasters input
 */

void outputCoasters(COASTER rate[], int numberofcoasters)
{
	for(int i=0;i<numberofcoasters;i++)
	{

			cout << endl;
			cout << "Coaster:" << setw(15) << rate[i].coasterName << endl;
			cout << "Type:" << setw(18) << rate[i].coasterType << endl;
			cout << "Park:     " << setw(18) << rate[i].coasterPark << endl;
			cout << "Location:        " << setw(14) << rate[i].coasterLoc << endl;
			cout << "Peak Height:" << setw(11) << rate[i].coasterPeak << " feet" << endl;
		cout << "Number of Ratings:" << setw(5) << rate[i].ratingNumbers<< endl;
			cout << "Thrill:" << setw(16) << rate[i].thrill << endl;
			cout << "Hills:" << setw(17) << rate[i].hill << endl;
			cout << "Scariness:" << setw(13) << rate[i].scariness << endl << endl;
			}
}

/*	Name: outputFile
	Preconditions: takes in an output file, an array of structs, and an integer as its input parameters
	Postconditions: called in main with two paraters and the output file declared
 */

void outputFile(ofstream& out, COASTER rate[], int numberofcoasters)
{
	
	
	for(int i=0;i<numberofcoasters;i++)
	{
		out << rate[i].coasterName << endl;
		out << rate[i].coasterType << endl;
		out << rate[i].coasterPark << endl;
		out << rate[i].coasterLoc << endl;
		out << rate[i].coasterPeak << endl;
		out << rate[i].ratingNumbers<< endl;
		out	<< rate[i].thrill << endl;
		out << rate[i].hill << endl;
		out << rate[i].scariness << endl;
	}
}

/*	Name: inputRatings
	Preconditions: takes in an array of structs and an integer as its input parameters
	Postconditions: called in main with three parameters; input file, array of structs, and an integer
*/

void inputFile(ifstream& in, COASTER rate[], int& numberofcoasters)
{
	//here i had to set numberofcoasters to -1
	//when it was set to 0, it would run the while loop twice for some reason
	numberofcoasters = -1;
while(!in.eof())
{
	numberofcoasters++;
	getline(in, rate[numberofcoasters].coasterName);
	in >> rate[numberofcoasters].coasterType;
	in.get();
	getline(in, rate[numberofcoasters].coasterPark);
	getline(in,rate[numberofcoasters].coasterLoc);
	in >> rate[numberofcoasters].coasterPeak; 
	in >> rate[numberofcoasters].ratingNumbers;
	in >> rate[numberofcoasters].thrill;
	in >> rate[numberofcoasters].hill;
	in >> rate[numberofcoasters].scariness;
	
}
	//close the input file
	in.close();
}