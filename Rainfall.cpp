//Adham Oudeif's Average Rainfall Calculator

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int monthSize = 12;
void getInfo(ifstream& file, string fileName, double Month[], int monthSize); //Function Prototype
string currentFile = "currentRainfall.txt"; //name of file so it can be used when calling the name to the function
string prevFile = "prevRainfall.txt";
string resultFile = "resultRainfall.txt";
string months[] = { "January", "Feburary", "March", "April", "May", "June","July", "August", "September", "October", "November", "December" };
void graphs(double monthData[], double otherMonthData[], int monthSize);

int main() {
	double currentMonth[monthSize];
	double prevMonth[monthSize];
	ifstream currentMonthReading;
	ifstream prevMonthReading;
	getInfo(currentMonthReading, currentFile, currentMonth, monthSize);
	getInfo(prevMonthReading, prevFile, prevMonth, monthSize); 
	graphs(prevMonth, currentMonth, monthSize);

	return 0;
}

// First, the function puts the string name of the file in the paranthesis to tell the funciton which file to open
// Next, the function ensures the file is able to be opened
// Once the file is opened, the array is incrementally initialized with the data in the file and stored in an array for later usage. 

void getInfo(ifstream& file, string fileName, double Month[], int monthSize) {
	file.open(fileName);
	if (file.fail())
	{
		cout << "Error: " << fileName << " can't be opened." << endl;
		exit(1);
	}
	cout << "NOTICE: " << fileName << " opened successfully." << endl;
	
	for (int i = 0; i <= monthSize; i++) {
		 file >> Month[i];
		cout << " " << Month[i];
		cout << "" << endl;
		
	}

	
 
}
// This function just grabs the data incrementally from the indexes of both arrays which the data was stored and computes an average and makes a graph

void graphs(double monthData[], double otherMonthData[], int monthSize) {
	for (int i = 0; i <= monthSize; i++) {
		cout << months[i]<<": " << endl;
		cout << "Current Rainfall: " << monthData[i] << endl;
		cout << "Previous Rainfall: " << otherMonthData[i] << endl;
		double avg = { (monthData[i] + otherMonthData[i]) / 2 };
		cout << "Average Rainfall: " << avg << endl;
		cout << "" << endl;
	}

}

/*
OUTPUT:

NOTICE: currentRainfall.txt opened successfully.
11 9 6 10 1.5 2.5 5.5 14 3.5 2.5 3.5 3 1.90067e+166

NOTICE : prevRainfall.txt opened successfully.
20 14 24 34 12 14 15 14 13 11 24 13 - 9.25596e+61

	January :
	Current Rainfall : 20
	Previous Rainfall : 11
	Average Rainfall : 15.5

	Feburary :
	Current Rainfall : 14
	Previous Rainfall : 9
	Average Rainfall : 11.5

	March :
	Current Rainfall : 24
	Previous Rainfall : 6
	Average Rainfall : 15

	April :
	Current Rainfall : 34
	Previous Rainfall : 10
	Average Rainfall : 22

	May :
	Current Rainfall : 12
	Previous Rainfall : 1.5
	Average Rainfall : 6.75

	June :
	Current Rainfall : 14
	Previous Rainfall : 2.5
	Average Rainfall : 8.25

	July :
	Current Rainfall : 15
	Previous Rainfall : 5.5
	Average Rainfall : 10.25

	August :
	Current Rainfall : 14
	Previous Rainfall : 14
	Average Rainfall : 14

	September :
	Current Rainfall : 13
	Previous Rainfall : 3.5
	Average Rainfall : 8.25

	October :
	Current Rainfall : 11
	Previous Rainfall : 2.5
	Average Rainfall : 6.75

	November :
	Current Rainfall : 24
	Previous Rainfall : 3.5
	Average Rainfall : 13.75

	December :
	Current Rainfall : 13
	Previous Rainfall : 3
	Average Rainfall : 8

	prevRainfall.txt :
	Current Rainfall : -9.25596e+61
	Previous Rainfall : 1.90067e+166
	Average Rainfall : 9.50337e+165

	C : \Users\adham\source\repos\AvgMonthlyRainfall\Debug\AvgMonthlyRainfall.exe(process 21856) exited with code 0.
	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
	Press any key to close this window . . .
	*/