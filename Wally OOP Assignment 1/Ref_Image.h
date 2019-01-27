#pragma once
#include "Base_Image.h"
class Ref_Image : public Base_Image
{
public:
	Ref_Image(const char *filename, int V_size);
	~Ref_Image();
};
