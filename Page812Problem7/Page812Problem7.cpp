// Page812Problem7.cpp : Defines the entry point for the console application.
//Anicet Akanza

//  Chapter 11 --  Assignment 7,  Corporate Sales
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_DIV = 6;   // Number of divisions

/*********** Insert your DivSales class here ****************/
class  DivSales {
private:
	double quarterSales[4];
	static double totalSales;
public:

	void setSales(double sales1, double sales2, double sales3, double sales4) {
		//Set the values of the sales in the array member variable for each quarter
		this->quarterSales[0] = sales1;
		this->quarterSales[1] = sales2;
		this->quarterSales[2] = sales3;
		this->quarterSales[3] = sales4;
		totalSales += (sales1 + sales2 + sales3 + sales4); //Adding the sales for each quarter to the total sales;
	}

	//The function below returns the sales number for a specific quarter
	double getQSales(int qtr) {
		//Check if the quarter number is within the vali range
		if (qtr >= 0 && qtr <= 3)
	   return  quarterSales[qtr];
		
		
	}

	double getCorpSales(){ //Returns the total sales for one division
		return totalSales; 
	}

	
};

 // Function prototype
void salesByDiv(DivSales[]);

//Define the static variable
double DivSales::totalSales = 0.00;

int main()
{
	DivSales divisions[NUM_DIV];
	double qtrs[4];

	for (int div = 0; div < NUM_DIV; div++)//Loop to get all sales number from the user for all divisions
	{

		cout << "Enter sales data for Division ";
		cout << (div + 1) << endl;
		for (int q = 0; q < 4; q++)
		{
			cout << "\tQuarter " << (q + 1) << ": ";
			do
			{
				cin >> qtrs[q];
				if (qtrs[q] < 0)
					cout << "Please enter 0 or greater.\n";
			} while (qtrs[q] < 0);
		}

		//Store the sales for each and calculate the total sales for each division
		divisions[div].setSales(qtrs[0], qtrs[1], qtrs[2], qtrs[3]);
	}
	cout << setprecision(2);
	cout << fixed << showpoint;
	salesByDiv(divisions);
	//Print the total sales for all divisions
	cout << "\nTotal Corporate Sales: $" << divisions[0].getCorpSales() << endl;
	return 0;
}

//*****************************************************************
//                       salesByDiv                               *
// The following function displays a list of sales figures        *
// by division.                                                   *
//*****************************************************************
void salesByDiv(DivSales d[])
{
	for (int div = 0; div < NUM_DIV; div++)
	{
		cout << "Sales for Division ";
		cout << (div + 1) << endl;
		for (int qtr = 0; qtr < 4; qtr++)
		{
			cout << "\tQuarter " << (qtr + 1) << ": $";
			cout << d[div].getQSales(qtr) << endl;
		}
	}
	cout << "Press Enter to Continue.";
	cin.get();
}