#include "Sort.h"

using namespace std;

int Sort::partition(int left, int right, bool ascendent) 
{
	int pivot = vector[right];
	
	int i = (left - 1);

	for (int j = left; j < right; ++j) {
		if (ascendent) {
			if (vector[j] <= pivot) {
				++i;
				swap(vector[i], vector[j]);
			}
		}
		else {
			if (vector[j] >= pivot) {
				++i;
				swap(vector[i], vector[j]);
			}
		}
	}
	swap(vector[i + 1], vector[right]);
	return (i + 1);
}

Sort::Sort(int NrElements, int min, int max)
{
	length = NrElements;
	vector = new int[length];
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		vector[i] = rand() % (max - min) + min;
	}
}

Sort::Sort(int* array, int number)
{
	length = number;
	vector = new int[length];

	for (int i = 0; i < length; i++) {
		vector[i] = array[i];
	}
}

Sort::Sort(char* sir)
{
	char* input = new char[strlen(sir) + 1];
	strcpy(input, sir);

	char* token = strtok(input, ",");
	int count = 0;
	while (token != nullptr) {
		count++;
		token = strtok(nullptr, ",");
	}

	length = count;
	vector = new int[length];

	strcpy(input, sir);
	token = strtok(input, ",");
	int i = 0;
	while (token != nullptr) {
		vector[i++] = atoi(token);
		token = strtok(nullptr, ",");
	}

	delete[] input;
}

Sort::Sort(int count ...)
{
	va_list args;
	va_start(args, count);

	length = count;
	vector = new int[length];


	for (int i = 0; i < length; i++) {
		vector[i] = va_arg(args, int);
	}

}

void Sort::InsertSort(bool ascendent)
{
	int key, j;
	for (int i = 1; i < length; i++) {
		key = vector[i];
		j = i - 1;
		if (ascendent == true) {
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
				vector[j + 1] = key;
		}
		else {
			while (j >= 0 && vector[j] < key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
			vector[j + 1] = key;
		}
		
	}
}

void Sort::QuickSort(bool ascendent)
{
	stack<int> stack;
	int left = 0;
	int right = length - 1;

	stack.push(right);
	stack.push(left);

	while (!stack.empty()) {
		left = stack.top();
		stack.pop();
		right = stack.top();
		stack.pop();

		if (left < right) {
			int pivotIndex = partition(left, right, ascendent);

			if (pivotIndex - 1 > left) {
				stack.push(pivotIndex - 1);
				stack.push(left);
			}
			if (pivotIndex + 1 < right) {
				stack.push(right);
				stack.push(pivotIndex + 1);
			}
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool swapped = false;
	int n = length;
	if (ascendent == true) {
		for (int i = 0; i < n - 1; i++) {
			swapped = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (vector[j] > vector[j + 1]) {
					swap(vector[j], vector[j + 1]);
					swapped = true;
				}
			}

			if (swapped == false) {
				break;
			}
		}
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			swapped = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (vector[j] < vector[j + 1]) {
					swap(vector[j], vector[j + 1]);
					swapped = true;
				}
			}

			if (swapped == false) {
				break;
			}
		}
	}
	
}

void Sort::Print()
{
	for (int i = 0; i < length; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount() 
{
	return length;
}

int Sort::GetElementFromIndex(int index)
{
	return vector[index];
}
