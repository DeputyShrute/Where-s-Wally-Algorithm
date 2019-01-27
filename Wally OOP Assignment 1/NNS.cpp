#include <iostream>
#include "NNS.h"

using namespace std;

NNS::NNS(const char *filename, int V_size)
{
	popArray(filename, V_size);
	xStore = 0;
	yStore = 0;
	nBest.push_back(114704100); // Set the initial best position for nBest the highest acheivable value defined by (255 * 255 * 36 * 49);

}


NNS::~NNS()
{
}

void NNS::outlineWally()
{
	for (int i = 0; i < 49; i++)
	{
		for (int j = 0; j < 36; j++)
		{

			if ((i == 0) || (i == 49 - 1))
			{
				i_Array[(j + xStore) + (1024 * (i + yStore))] = 0;
			}

			if ((j == 0) || (j == 36 - 1))
			{
				i_Array[(j + xStore) + (1024 * (i + yStore))] = 0;
			}
		}
	}
}

void NNS::WallyLSearch(double *Wally, double *Cluttered) {
	

	for (int i = 0; i < 768 - 49; i++) //Defines Y coordinate of the Large Scene;
	{
		
		for (int j = 0; j < 1024 - 36; j++) //Defines X coordinate of the Large Scene;
		{
			total_array = 0;//reset after each iteration;
			
			for (int k = 0; k < 49; k++)//Loops through 49 rows of the targeted area;
			{
				
				for (int l = 0; l < 36; l++)// Loops across the 36 pixels in each row, jumps down each level in the previous loop;
				{
					
					
					identifier = Wally[l + (36 * k)];//identifier takes the the value at the Reference image index;

					if (identifier != 255) //Skips any white pixels to save time;
					{

						curr_sum = Wally[l + (36 * k)] - Cluttered[(j + l) + (1024 * (i + k))];
						curr_sum = curr_sum * curr_sum;
						total_array = total_array + curr_sum;
					}
				}
				if (total_array < nBest.size()) //Checks to see if the sum of squared difference stored in total_array is lower than the current value stored as nBest;
				{
					nBest.clear();
					nBest.push_back(total_array); //Replaces nBest with total_array;
					xStore = j; 
					yStore = i;
				}
			}
		}
	}
}