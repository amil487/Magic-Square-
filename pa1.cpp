//Magic Square
#include "stdafx.h"			//may need to remove this if not in VS
#include <iostream>
using namespace std;

void zero(int * head, int size);		//helper functions
void print(int * head, int size);
void row(int * head,int *sum, int size);
void column(int * head, int *sum, int size);
void diagonal(int *head, int *sum, int size);

int main()
{
	cout << "Enter the size of a magic square: ";	//Asking user for the size
	int size;

	do		//A while loop to check for evens/small numbers/big numbers
	{
		cin >> size;

		if (size % 2 == 0)
		{
			cout << "The number is not odd!\n";
		}

		if (size < 3)
		{
			cout << "Number is too small!\n";
		}

		if (size > 15)
		{
			cout << "Number is too big!\n";
		}

	} while (size % 2 == 0 || size > 15 || size < 3);

	cout << endl;

	int* MS = new int[size * size];			//Declaration of Magic Square array

	zero(MS, size);		//zero out array

	int i = size / 2;					//Set position of 1(middle row, last column)
	int j = size - 1;

	for (int entry = 1; entry <= size * size;)	//Loop for populating Magic Square
	{
		if (i == -1 && j == size)		//Out of bounds catcher
		{
			i = 0;
			j = size - 2;
		}
		else							//Fixer when only one of the variable breaks pattern
		{
			if (i < 0)					//When number breaks through top of magic square
			{
				i = size - 1;
			}
			if (j == size)				//When number exits through side of magic square
			{
				j = 0;
			}
		}

		if (MS[i*size + j] == 0)		//If an element in the magic square equals zero, then it is given the next number
		{
			MS[i*size + j] = entry;
			entry++;
		}
		else							//If the number is a nonzero number
		{
			i++;
			j = j - 2;
			continue;
		}

		i--;							//increments and decrements for row/ column (row goes up, column to the right)
		j++;
	}

	cout << "Magic Square #1 is:\n";

	print(MS, size);        //print original array

	cout << endl;

	cout << "Checking the sums of every row:      ";

	int* rowAdd = new int[size];		//Array that stores all the row sums

	row(MS,rowAdd, size);		//summation of row

	cout << endl;

	cout << "Checking the sums of every column:   ";

	int* columnAdd = new int[size];			//Array that holds sum of columns

	column(MS, columnAdd, size);		//summation of columns

	cout << endl;

	int diagonalAdd[2];			//Array that holds sum of diagonals
	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	diagonal(MS, diagonalAdd, size);	//summation of diagonals

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #2 is:\n";

	int* MSMirror = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #2)

	zero(MSMirror, size);		//zero out array

	for (int i = 0, j = size * size - 1; i<size*size; i++, j--)			//Fills Mirror array with original values reversed
	{
		MSMirror[i] = MS[j];
	}

	print(MSMirror, size);      //print mirror

	cout << endl;

	cout << "Checking the sums of every row:      ";

	row(MSMirror, rowAdd, size);		//summation of row

	cout << endl;

	cout << "Checking the sums of every column:   ";

	column(MSMirror, columnAdd, size);		//summation of column

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	diagonal(MSMirror, diagonalAdd, size);		//summation of diagonals

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #3 is:\n";

	int* MSTranspose = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #3)

	zero(MSTranspose, size);		//zero out array

	for (int i = 0; i < size; i++)			//Loop that transposes original magic square						
	{
		for (int j = 0; j < size; j++)
		{
			MSTranspose[i * size + j] = MS[j*size + i];
		}
	}

	print(MSTranspose, size); //Print transpose

	cout << endl;

	cout << "Checking the sums of every row:      ";

	row(MSTranspose, rowAdd, size);		//summation of row

	cout << endl;

	cout << "Checking the sums of every column:   ";

	column(MSTranspose, columnAdd, size);		//summation of column

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	diagonal(MSTranspose, diagonalAdd, size);		//summation of diagonal

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #4 is:\n";

	int* MSMirrorTranspose = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #4)

	zero(MSMirrorTranspose, size);		//zero out array

	for (int i = 0; i < size; i++)			//Loop that transposes original mirror magic sqaure							
	{
		for (int j = 0; j < size; j++)
		{
			MSMirrorTranspose[i * size + j] = MSMirror[j*size + i];
		}
	}

	print(MSMirrorTranspose, size);     //print transpose mirror size

	cout << endl;

	cout << "Checking the sums of every row:      ";

	row(MSMirrorTranspose, rowAdd, size);		//summation of rows

	cout << endl;

	cout << "Checking the sums of every column:   ";

	column(MSMirrorTranspose, columnAdd, size);		//summation of columns

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	diagonal(MSMirrorTranspose, diagonalAdd, size);		//summation of diagonals

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl;
}

void zero(int * head, int size) {
	for (int i = 0; i < size; i++)			//Loop that sets all elements to zero since C++ is lame and doesn't do it automatically									
	{
		for (int j = 0; j < size; j++)
		{
			head[i * size + j] = 0;
		}
	}
}

void print(int * head, int size) {
	for (int i = 0; i < size; i++)		//Prints out Magic
	{
		for (int j = 0; j < size; j++)
		{
			cout << head[i*size + j] << "\t";
		}
		cout << endl;
	}
}

void row(int * head,int * sum ,int size) {
	for (int i = 0; i < size; i++)		//Loop to calculate array row sums
	{
		sum[i] = 0;
		for (int j = 0; j < size; j++)
		{
			sum[i] += head[i*size + j];
		}
		cout << sum[i] << " ";
	}

}

void column(int * head, int *sum, int size) {
	for (int i = 0; i < size; i++)			//Loop that creates sum of columns
	{
		sum[i] = 0;
		for (int j = 0; j < size; j++)
		{
			sum[i] += head[i + size * j];
		}
		cout << sum[i] << " ";
	}
}

void diagonal(int *head, int * sum,  int size) {
	for (int i = 0; i < size*size; i++)		//Loop that sums left to right diagonal
	{
		if (i % (size + 1) == 0)
		{
			sum[0] += head[i];
		}
	}

	for (int i = 1; i < size * size - 1; i++)		//Loop that sums right to left diagonal
	{
		if (i % (size - 1) == 0)
		{
			sum[1] += head[i];
		}
	}
}
