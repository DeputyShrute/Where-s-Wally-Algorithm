#pragma once
#include "Base_Image.h"
class Large_Image : public Base_Image
{
public:
	Large_Image(const char *filename, int V_size);
	~Large_Image();
};

