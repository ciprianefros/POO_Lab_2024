#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class Number
{
private:
	char* nrValue;
	int base;
	unsigned int strNumberLen;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int number);
	~Number();

	//copy constructor
	Number(const Number& nr);
	
	//move constructor
	Number(Number&& nr);
	// add operators and copy/move constructor
	unsigned int GetBase10Value() const;
	friend Number operator + (const Number& nr1, const Number& nr2);
	friend Number operator - (const Number& nr1, const Number& nr2);
	Number& operator / (const Number& nr);
	Number& operator * (const Number& nr);

	bool operator > (const Number& nr);
	bool operator < (const Number& nr);
	bool operator >= (const Number& nr);
	bool operator <= (const Number& nr);
	bool operator == (const Number& nr);
	bool operator != (const Number& nr);

	Number& operator ++ ();
	Number operator ++ (int);
	Number& operator -- ();
	Number operator -- (int);

	Number& operator=(const Number& nr);
	Number& operator=(const char* value);
	Number& operator+=(const Number& nr);
	Number& operator-=(const Number& nr);
	Number& operator/=(const Number& nr);
	Number& operator*=(const Number& nr);

	char& operator[](int index);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();  // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

