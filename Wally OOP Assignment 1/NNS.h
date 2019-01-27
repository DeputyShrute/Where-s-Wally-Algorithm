#pragma once
#include "Base_Image.h"
#include <vector>

class NNS : public Base_Image
{
public:
	int xStore;
	int yStore;
	std::vector<int> nBest;
	double total_array = 0;
	double curr_sum = 0;
	double identifier = 0;
	

	void outlineWally();

	void WallyLSearch(double* Wally, double* Cluttered);

	NNS(const char *filename, int V_size);
	~NNS();
};

