//Magic Square

#include <iostream>
using namespace std;

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

	for (int i = 0; i < size; i++)			//Loop that sets all elements to zero since C++ is lame and doesn't do it automatically									
	{
		for (int j = 0; j < size; j++)
		{
			MS[i * size + j] = 0; 
		}	
	}

	int i = size/2;					//Set position of 1(middle row, last column)
	int j = size - 1;

	for (int entry = 1; entry <= size*size;)	//Loop for populating Magic Square
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
	
	for (int i = 0; i < size; i++)		//Prints out Magic Square #1 (original)
	{
		for (int j = 0; j < size; j++)
		{
			cout << MS[i*size + j] << "\t";
		}
		cout << endl;
	}
	
	cout << endl;

	cout << "Checking the sums of every row:      ";

	int* rowAdd = new int[size];		//Array that stores all the row sums

	for (int i = 0; i < size; i++)		//Loop to calculate array row sums
	{
		rowAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			rowAdd[i] += MS[i*size + j];
		}
		cout << rowAdd[i] << " ";
	}

	cout << endl;

	cout << "Checking the sums of every column:   ";

	int* columnAdd = new int[size];			//Array that holds sum of columns

	for (int i = 0; i < size; i++)			//Loop that creates sum of columns
	{
		columnAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			columnAdd[i] += MS[i + size * j];
		}
		cout << columnAdd[i] << " ";
	}

	cout << endl;

	int diagonalAdd [2];			//Array that holds sum of diagonals
	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	for (int i = 0; i < size*size; i++)		//Loop that sums left to right diagonal
	{
		if (i % (size + 1) == 0)
		{
			diagonalAdd[0] += MS[i];
		}
	}

	for (int i = 1; i < size * size - 1; i++)		//Loop that sums right to left diagonal
	{
		if (i % (size - 1) == 0)
		{
			diagonalAdd[1] += MS[i];
		}
	}

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #2 is:\n";
	
	int* MSMirror = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #2)

	for (int i = 0; i < size; i++)			//Loop that sets all elements to zero								
	{
		for (int j = 0; j < size; j++)
		{
			MSMirror[i * size + j] = 0;
		}
	}

	for (int i = 0, j = size*size-1; i<size*size; i++, j--)			//Fills Mirror array with original values reversed
	{
		MSMirror[i] = MS[j];	
	}
	
	for (int i = 0; i < size; i++)			//Prints Mirrored array
	{
		for (int j = 0; j < size; j++)
		{
			cout << MSMirror[i*size + j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Checking the sums of every row:      ";

	for (int i = 0; i < size; i++)		//Loop to calculate array row sums
	{
		rowAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			rowAdd[i] += MSMirror[i*size + j];
		}
		cout << rowAdd[i] << " ";
	}

	cout << endl;

	cout << "Checking the sums of every column:   ";

	for (int i = 0; i < size; i++)			//Loop that creates sum of columns
	{
		columnAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			columnAdd[i] += MSMirror[i + size * j];
		}
		cout << columnAdd[i] << " ";
	}

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	for (int i = 0; i < size*size; i++)		//Loop that sums left to right diagonal
	{
		if (i % (size + 1) == 0)
		{
			diagonalAdd[0] += MSMirror[i];
		}
	}

	for (int i = 1; i < size * size - 1; i++)		//Loop that sums right to left diagonal
	{
		if (i % (size - 1) == 0)
		{
			diagonalAdd[1] += MSMirror[i];
		}
	}

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #3 is:\n";

	int* MSTranspose = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #3)

	for (int i = 0; i < size; i++)			//Loop that sets all elements to zero							
	{
		for (int j = 0; j < size; j++)
		{
			MSTranspose[i * size + j] = 0;
		}
	}

	for (int i = 0; i < size; i++)			//Loop that transposes original magic square						
	{
		for (int j = 0; j < size; j++)
		{
			MSTranspose[i * size + j] = MS[j*size + i];
		}
	}

	for (int i = 0; i < size; i++)			//Prints transposed array
	{
		for (int j = 0; j < size; j++)
		{
			cout << MSTranspose[i*size + j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Checking the sums of every row:      ";

	for (int i = 0; i < size; i++)		//Loop to calculate array row sums
	{
		rowAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			rowAdd[i] += MSTranspose[i*size + j];
		}
		cout << rowAdd[i] << " ";
	}

	cout << endl;

	cout << "Checking the sums of every column:   ";

	for (int i = 0; i < size; i++)			//Loop that holds sum of columns
	{
		columnAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			columnAdd[i] += MSTranspose[i + size * j];
		}
		cout << columnAdd[i] << " ";
	}

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	for (int i = 0; i < size*size; i++)		//Loop that sums left to right diagonal
	{
		if (i % (size + 1) == 0)
		{
			diagonalAdd[0] += MSTranspose[i];
		}
	}

	for (int i = 1; i < size * size - 1; i++)		//Loop that sums right to left diagonal
	{
		if (i % (size - 1) == 0)
		{
			diagonalAdd[1] += MSTranspose[i];
		}
	}

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl << endl;

	cout << "Magic Square #4 is:\n";

	int* MSMirrorTranspose = new int[size * size];			//Declaration of Magic Square Mirror array (Magic square #4)

	for (int i = 0; i < size; i++)			//Loop that sets all elements to zero								
	{
		for (int j = 0; j < size; j++)
		{
			MSMirrorTranspose[i * size + j] = 0;
		}
	}

	for (int i = 0; i < size; i++)			//Loop that transposes original mirror magic sqaure							
	{
		for (int j = 0; j < size; j++)
		{
			MSMirrorTranspose[i * size + j] = MSMirror[j*size + i];
		}
	}

	for (int i = 0; i < size; i++)			//Prints transposed mirror
	{
		for (int j = 0; j < size; j++)
		{
			cout << MSMirrorTranspose[i*size + j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Checking the sums of every row:      ";

	for (int i = 0; i < size; i++)		//Loop to calculate array row sums
	{
		rowAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			rowAdd[i] += MSMirrorTranspose[i*size + j];
		}
		cout << rowAdd[i] << " ";
	}

	cout << endl;

	cout << "Checking the sums of every column:   ";

	for (int i = 0; i < size; i++)			//Loop that holds sum of columns
	{
		columnAdd[i] = 0;
		for (int j = 0; j < size; j++)
		{
			columnAdd[i] += MSMirrorTranspose[i + size * j];
		}
		cout << columnAdd[i] << " ";
	}

	cout << endl;

	diagonalAdd[0] = 0;
	diagonalAdd[1] = 0;

	for (int i = 0; i < size*size; i++)		//Loop that sums left to right diagonal
	{
		if (i % (size + 1) == 0)
		{
			diagonalAdd[0] += MSMirrorTranspose[i];
		}
	}

	for (int i = 1; i < size * size - 1; i++)		//Loop that sums right to left diagonal
	{
		if (i % (size - 1) == 0)
		{
			diagonalAdd[1] += MSMirrorTranspose[i];
		}
	}

	cout << "Checking the sums of every diagonal: " << diagonalAdd[0] << " " << diagonalAdd[1] << endl;
}