/*
 * Prog1.cpp
 *
 *      Author: Mark
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool smaller (int A[], int x, int y)
{
	if (A[x] < A[y])
		return true;
	else
		return false;
}

int main()
{
	int COMPCOUNT1 = 0; //The number of key comparisons for the worst case
	int COMPCOUNT2 = 0; //The number of key comparisons for the average case
	int insort1[32]; //Best Case
	int insort2[32]; //Worst Case
	int insort3[32]; //Average Case


	cout << "Best Case" << endl;
	int best = 0;
	for (int i = 0; i < 32; i++)
	{
		insort1[i] = best;
		best++;
	}
	//Comparison not needed since the array is already sorted
	//Input and output array will be the same
	cout << "Input and Output Array: " << endl;
	for (int i = 0; i < 32; i++)
		cout << insort1[i] << " ";
	cout << endl;
	cout << "The number of key comparisons is 0" << endl; //0 since everything is sorted already

	cout << "\n" << "\n";

	cout << "Worst Case" << endl;

	int rando;
	for (int i = 0; i < 32; i++){
			insort2[i] = best;
			best--;
		}
	cout << "The input array: " << endl;
		for (int i = 0; i < 32; i++)
			cout << insort2[i] << " ";
		cout << endl;


	for (int j = 0; j < 31; j++)
	{
			for (int i = j+1; i > 0; i--)
			{

				if (smaller(insort2, i, (i-1) ))
				{
					COMPCOUNT1++;
					//Swap the elements
					int temp = insort2[i];
					insort2[i] = insort2[i-1];
					insort2[i-1] = temp;
				}
			}
		}

	cout << "The output array: " << endl;
		for (int i = 0; i < 32; i++)
			cout << insort2[i] << " ";

	cout << endl << "The number of key comparisons is: " << COMPCOUNT1 << endl;

	cout << "\n" << "\n";

	cout << "Average Case" << endl;
	srand(time(NULL));
	for (int i = 0; i < 32; i++)
	{
		rando = rand() % 30;
		insort3[i] = rando;
	}

	cout << "The input array: " << endl;
	for (int i = 0; i < 32; i++)
		cout << insort3[i] << " ";
	cout << endl;


	for (int j = 0; j < 31; j++)
	{
		for (int i = j+1; i > 0; i--)
		{
			if (smaller(insort3, i, (i-1) ))
			{
				COMPCOUNT2++;

				//Swap the elements
				int temp = insort3[i];
				insort3[i] = insort3[i-1];
				insort3[i-1] = temp;
			}
		}
	}

	cout << "The output array: " << endl;
	for (int i = 0; i < 32; i++)
		cout << insort3[i] << " ";

	cout << endl << "The number of key comparisons is: " << COMPCOUNT2 << endl;
}
