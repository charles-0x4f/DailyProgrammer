// Written by Charles O.
// charles.0x4f@gmail.com
// Github: https://github.com/charles-0x4f

// Reddit r/dailyprogrammer
// Challenge 115 - Intermediate
// See challenge.txt

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int stringBreak(string str)
{
	int temp = atoi(str.c_str());

	return temp;
}

int main()
{
	int n, c, *array;
	string tempArray;

	cout << "Enter number of total integers: ";
	cin >> n;
	cin.ignore(80, '\n');

	array = new int[n];

	cout << "\nEnter array of integers separated by spaces: ";
	getline(cin, tempArray);

	for(int x = 0, index = 0;;)
	{
		if(tempArray[0] == ' ')
			tempArray.erase(0);

		x = tempArray.find(' ');

		if(x > 0)
		{
			array[index] = stringBreak(tempArray.substr(0, x));
			index++;
			tempArray.erase(0, (x + 1));
		}
		else if(tempArray.length() >= 1)
		{
			array[index] = stringBreak(tempArray);
			break;
		}
	}

	cout << "\nEnter the value for the pairs: ";
	cin >> c;

	cout << "\n";
	for(int x = 0; x < n; x++)
	{
		for(int y = (x + 1); y < n; y++)
		{
			if((array[x] + array[y]) == c)
				cout << array[x] << ", " << array[y] << "\n";
		}
	}

	delete [] array;

	return 0;
}

