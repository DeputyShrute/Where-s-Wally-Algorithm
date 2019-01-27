#pragma once
class Base_Image
{
protected:
	double* i_Array;
	int V_size;

public:
	void popArray(const char *filename, int V_size);
	double* ReturnArray();
};

