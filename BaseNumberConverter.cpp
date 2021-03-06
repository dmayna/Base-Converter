// BaseNumberConverter.cpp : Defines the entry point for the console application.
//
//
//  main.cpp
//  Week2DylanMaynardBaseProgConvert
//
//  Created by Dylan Maynard on 1/31/18.
//  Copyright © 2018 Dylan Maynard. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Convert
{
public:
	Convert() :input{ 1 } {}
	int getInput() { return input; }
	void setInput(const int inInput) { input = inInput; }
	void toBase2(int x);
	void toBase8(int x);
	void toBase16(int x);

private:
	int input;
};
void Convert::toBase2(int x)
{
	const int base = 2;
	input = x;
	int rem;

	if (input <= 1)
	{
		cout << input;
		return;
	}
	rem = input % base;
	toBase2(input / base);
	cout << rem;
}

void Convert::toBase8(int x)
{
	const int base = 8;
	input = x;
	int rem;

	if (input <= 1)
	{
		cout << input;
		return;
	}
	rem = input % base;
	toBase8(input / base);
	cout << rem;
}

void Convert::toBase16(int x)
{
	const int base = 16;
	input = x;
	int rem;
	if (input <= 1)
	{
		cout << input;
		return;
	}
	rem = input % base;
	toBase16(input / base);
	if (rem == 10)
	{
		cout << "A";
	}
	else if (rem == 11)
	{
		cout << "B";
	}
	else if (rem == 12)
	{
		cout << "C";
	}
	else if (rem == 13)
	{
		cout << "D";
	}
	else if (rem == 14)
	{
		cout << "E";
	}
	else if (rem == 15)
	{
		cout << "F";
	}
	else
	{
		cout << rem;
	}
}

int isDataValid()
{
	bool valid = false;
	int num;
	while (!valid)
	{
		valid = true; //Assume the cin will be an integer.
		cout << "Please enter a positive integer to convert into a base 2, 8 and 16 > ";
		cin >> num;
		if (cin.fail()) //cin.fail() checks to see if the value in the cin
						//stream is the correct type, if not it returns true,
						//false otherwise.
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter an Integer only." << endl;
			valid = false; //The cin was not an integer so try again.
		}
	}
	return num;
}

int main()
{
	Convert c;
	cout << "Dylan Maynard \t 02/04/18" << endl;
	int userInput = isDataValid();
	cout << "\nBase 2 = ";
	c.toBase2(userInput);
	cout << "\nBase 8 = ";
	c.toBase8(userInput);
	cout << "\nBase 16 = "; 
	c.toBase16(userInput);
	cout << endl;
}