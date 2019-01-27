#include "Base_Image.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void Base_Image::popArray(const char * filename, int V_size)
{
	i_Array = new double[V_size];

	ifstream myfile(filename);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			for (int i = 0; i < V_size; i++)
			{
				myfile >> i_Array[i];
			}
		}
		myfile.close();
	}
}


double * Base_Image::ReturnArray()
{
	return i_Array;
}
