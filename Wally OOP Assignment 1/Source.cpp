#include <iostream>
#include"read_write.h"
#include "Ref_Image.h"
#include "Large_Image.h"
#include <vector>
#include "NNS.h"
using namespace std;

int main()
{
	cout << "Welcome to Where's Wally Search" << endl;
	cout << "Reading in Text Files" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	
	
	
	Ref_Image SmallImage("Wally_grey.txt", 1764); // Making an object of Ref_Image called SmallImage. Parsing in file name and array dimensions (equal to 36 * 49);
	Large_Image BigImage("Cluttered_Scene.txt", 786432); // Making an object of Large_Image called BigImage. Parsing in file name for the large scene and dimensions (equal to 768 * 1024);
	NNS finalImage("Cluttered_Scene.txt", 786432); //Making an object of NNS called finalImage. Parsing in file name for the large scene to use as a copy from the first. Dimensions equal to (768 * 1024);

	cout << "Files read in" << endl;
	cout << "Searching for Wally" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

	finalImage.WallyLSearch(SmallImage.ReturnArray(), BigImage.ReturnArray()); // Calls WallyLSearch method from the NNS object named finalImage while returning the arrays created in SmallImage and BigImage;
	finalImage.outlineWally(); // Calls the outlineWally function from the NNS objected named outlineWally;

	cout << "Wally Found" << endl;
	cout << "Outputting Position" << endl;
	//Outputs the location of wally;
	//Gives the name of the output file, returns 1d array with outlined wally (finalImage.ReturnArray()), dimensions of image specified (768, 1024), black and white colour (255);
	write_pgm("Found_Wally.pgm", finalImage.ReturnArray(), 768, 1024, 255); 

	system("pause");

	return 0;
}