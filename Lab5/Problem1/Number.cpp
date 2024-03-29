#include "Number.h"

Number::Number(const char* value, int base) : base(base)
{
	nrValue = new char[100] {};
	strcpy(nrValue, value);
	strNumberLen = strlen(nrValue);
}

Number::Number(int number): base(10)
{
	nrValue = new char[100] {};
	char* temp = new char[100] {};
	int length = 0;
	while (number > 0) {
		int rest = number % base;
		temp[length++] = (rest < 10) ? rest + '0' : rest - 10 + 'A';
		number /= base;
	}
	for (int i = 0; i < length; ++i) {
		nrValue[i] = temp[length - 1 - i];
	}
	nrValue[length] = '\0';
	strNumberLen = strlen(nrValue);
}

Number::~Number()
{
	delete[] nrValue;
	nrValue = nullptr;

}

Number::Number(const Number& nr) : base(nr.base), strNumberLen(nr.strNumberLen)
{
	nrValue = new char[100];
	strcpy(nrValue, nr.nrValue);
	
}

Number::Number(Number&& nr) :nrValue(nr.nrValue), base(nr.base), strNumberLen(nr.strNumberLen)
{
	nr.nrValue = nullptr;
	nr.base = 0;
	nr.strNumberLen = 0;
}

unsigned int Number::GetBase10Value() const
{
	unsigned int result = 0;
	unsigned int power = 1;
	for (int i = strNumberLen - 1; i >= 0; i--) {

		if (nrValue[i] >= '0' && nrValue[i] <= '9') {
			result = result + (nrValue[i] - '0') * power;
		}
		else
		{
			result = result + (nrValue[i] - 'A' + 10) * power;
		}
		
		power = power * base;
	}
	return result;
}


Number& Number::operator / (const Number& nr) {
	int n1 = GetBase10Value();
	int n2 = nr.GetBase10Value();

	int newBase = base > nr.base ? base : nr.base;

	if (n2 == 0) {

		delete[] nrValue;
		nrValue = new char[100] {};
		strcpy(nrValue, "0");
		base = newBase;
		strNumberLen = 1;
		return *this;
	}

	char* newValue = new char[100] {};
	char* finalValue = new char[100] {};

	int temp = n1 / n2;
	
	unsigned int count = 0;
	while (temp > 0) {
		int remainder = temp % newBase;
		newValue[count] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		temp /= newBase;
		count++;
	}

	for (int i = count - 1; i >= 0; i--) {
		finalValue[count - i - 1] = newValue[i];
	}
	finalValue[count] = '\0';

	delete[] nrValue;
	nrValue = new char[strlen(finalValue) + 1];
	strcpy(nrValue, finalValue);
	base = newBase;
	strNumberLen = strlen(nrValue);

	delete[] newValue;
	delete[] finalValue;

	return *this;
}

Number& Number::operator * (const Number& nr)
{
	int n1 = GetBase10Value();
	int n2 = nr.GetBase10Value();
	int temp = n1 * n2;
	int newBase = base > nr.base ? base : nr.base;
	char* newValue = new char[100] {};
	char* finalValue = new char[100] {};

	unsigned int count = 0;
	while (temp > 0) {
		int remainder = temp % newBase;
		newValue[count] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		temp = temp / newBase;
		count++;
	}
	for (int i = count - 1; i >= 0; i--) {
		finalValue[count - i - 1] = newValue[i];
	}
	finalValue[count] = '\0';

	delete[] nrValue;
	nrValue = new char[100] {};
	strcpy(nrValue, finalValue);
	delete[] newValue;
	delete[] finalValue;

	base = newBase;
	strNumberLen = strlen(nrValue);

	return (*this);
}

bool Number::operator > (const Number& nr)
{
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) > 0;
	}
	else {
		return GetBase10Value() > nr.GetBase10Value();
	}
}

bool Number::operator < (const Number& nr)
{
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) < 0;
	}
	else {
		return GetBase10Value() < nr.GetBase10Value();
	}
}

bool Number::operator >=(const Number& nr)
{
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) >= 0;
	}
	else {
		return GetBase10Value() >= nr.GetBase10Value();
	}
}

bool Number::operator <=(const Number& nr)
{
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) <= 0;
	}
	else {
		return GetBase10Value() <= nr.GetBase10Value();
	}
	
}

bool Number::operator == (const Number& nr)
{
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) == 0;
	}
	else {
		return GetBase10Value() == GetBase10Value();
	}
}

bool Number::operator!=(const Number& nr)
{	
	if (base == nr.base) {
		return strcmp(nrValue, nr.nrValue) != 0;
	}
	else {
		return GetBase10Value() != GetBase10Value();
	}
	
}

Number& Number::operator ++()
{
	int value = GetBase10Value();
	++value;
	char newValue[100]{};
	int length = 0;
	while (value > 0) {
		int rest = value % base;
		newValue[length++] = (rest < 10) ? rest + '0' : rest - 10 + 'A';
		value /= base;
	}
	char* finalValue = new char[length + 1];
	for (int i = 0; i < length; ++i) {
		finalValue[i] = newValue[length - 1 - i];
	}
	finalValue[length] = '\0';
	delete[] nrValue;
	nrValue = new char[100] {};
	strcpy(nrValue, finalValue);
	delete[] finalValue;
	strNumberLen = length;
	return *this;
	
}

Number Number::operator ++(int)
{
	Number temp("nrValue", base);
	++(*this);
	return temp;
}

Number& Number::operator --()
{

	if (strNumberLen > 0) {
		for (int i = 0; i < strNumberLen - 1; i++) {
			nrValue[i] = nrValue[i + 1];
		}
		nrValue[strNumberLen - 1] = '\0';
		strNumberLen--;
	}
	return (*this);
}

Number Number::operator --(int)
{
	nrValue[strNumberLen - 1] = '\0';
	strNumberLen--;
	return (*this);
}

Number& Number::operator=(const Number& nr)
{
	if (this != &nr) {
		delete[] nrValue;
		nrValue = new char[100] {};
		strcpy(nrValue, nr.nrValue);
		base = nr.base;
		strNumberLen = nr.strNumberLen;
	}
	
	return *this;
}

Number& Number::operator=(const char* value)
{
	if (nrValue != value) {
		delete[] nrValue;
		nrValue = new char[100] {};
		strcpy(nrValue, value);
		strNumberLen = strlen(nrValue);
	}

	return *this;
}

Number& Number::operator+=(const Number& nr)
{
	*this = *this + nr;
	return *this;
}

Number& Number::operator-=(const Number& nr)
{
	*this = *this - nr;
	return *this;
}

Number& Number::operator/=(const Number& nr)
{
	*this = *this / nr;
	return *this;
}

Number& Number::operator*=(const Number& nr)
{
	*this = *this * nr;
	return *this;
}

char& Number::operator[](int index)
{
	if (index >= 0 && index < strNumberLen) {
		return nrValue[index];
	}
	return nrValue[100];
}

void Number::SwitchBase(int newBase)
{
	int temp = GetBase10Value();
	char* newValue = new char[100] {};
	char* finalValue = new char[100] {};

	int count = 0;
	while (temp > 0) {
		int remainder = temp % newBase;
		newValue[count] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		temp = temp / newBase;
		count++;
	}
	for (int i = count-1; i >= 0; i--) {
		finalValue[count - i - 1] = newValue[i];
	}
	finalValue[count] = '\0';

	delete[] newValue;

	
	if (nrValue != nullptr) {
		delete[] nrValue; 
	}
	nrValue = new char[100];
	strcpy(nrValue, finalValue);

	delete[] finalValue;

	strNumberLen = count;
	base = newBase;

}

void Number::Print()
{
	std::cout << "Numarul este:" << nrValue << " in baza: " << base << std::endl;
}

int Number::GetDigitsCount()
{
	return strNumberLen;
}

int Number::GetBase()
{
	return base;
}

Number operator+(const Number& nr1, const Number& nr2)
{
	int n1 = nr1.GetBase10Value();
	int n2 = nr2.GetBase10Value();
	int temp = n1 + n2;
	int newBase = nr1.base > nr2.base ? nr1.base : nr2.base;
	char* newValue = new char[100] {};
	char* finalValue = new char[100] {};

	unsigned int count = 0;
	while (temp > 0) {
		int remainder = temp % newBase;
		newValue[count] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		temp = temp / newBase;
		count++;
	}
	for (int i = count - 1; i >= 0; i--) {
		finalValue[count - i - 1] = newValue[i];
	}
	finalValue[count] = '\0';
	Number result(finalValue, newBase);
	delete[] finalValue;
	delete[] newValue;

	return result;

}

Number operator-(const Number& nr1, const Number& nr2)
{
	int n1 = nr1.GetBase10Value();
	int n2 = nr2.GetBase10Value();
	unsigned int temp = abs(n1 - n2);
	int newBase = nr1.base > nr2.base ? nr1.base : nr2.base;
	char* newValue = new char[100] {};
	char* finalValue = new char[100] {};

	unsigned int count = 0;
	while (temp > 0) {
		int remainder = temp % newBase;
		newValue[count] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
		temp = temp / newBase;
		count++;
	}
	for (int i = count - 1; i >= 0; i--) {
		finalValue[count - i - 1] = newValue[i];
	}
	finalValue[count] = '\0';
	Number result(finalValue, newBase);
	delete[] finalValue;
	delete[] newValue;

	return result;
}
