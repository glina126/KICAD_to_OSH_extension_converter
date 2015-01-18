#include <iostream>
#include <string.h>
using namespace std;

// disable if you dont want it to be loud
#define VERBOSE 1

// definition
bool findExtension(string,string); 

int main(int argc, char *argv[])
{

#if VERBOSE
	cout << "number of arguments: " << argc << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << i << ": " << argv[i] << endl;
	}
#endif
	
	// if there are more than 1 arguments, do the conversion
	if (argc > 1)
	{
		// open file for reading - one at a time
		for (int i = 0; i < argc; i++)
		{
			// convert the char[] to string for easier parsing
			string temp = argv[i];

			/************************** ADD NEW EXTENSIONS HERE **************************/
			if (findExtension(".grb", temp))
			{
				// extension found, convert to *.GKO - board outline
				
			}
			else if (findExtension(".drl", temp))
			{
				// extension found, convert to *.XLN - drill file
			}
		}		
	}
	else
	{
		// nothing to convert, abort
		return 0;
	}

	// end of program
	return 0;
	system("pause");
}

bool findExtension(string extension, string argument_string)
{
	return true;
}


