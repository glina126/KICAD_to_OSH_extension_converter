#include <iostream>
#include <string.h>
using namespace std;

// disable if you dont want it to be loud
#define VERBOSE 1

// definitions
bool findExtension(string,string); 
bool renameFile(char *, string);

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
			if (findExtension(".grb", temp)) // what we are looking for
			{
				// extension found, convert to *.GKO - board outline
				renameFile(argv[i], ".GKO"); // what we want to convert to

			}
			else if (findExtension(".drl", temp))
			{
				// extension found, convert to *.XLN - drill file
				renameFile(argv[i], ".XLN");
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
}

bool findExtension(string extension, string argument_string)
{
	if (argument_string.find(extension))
		return true;
	else
		return false;
}

bool renameFile(char * old_file, string new_extension)
{
	// extract file name from old_file - contains the whole directory
	string temp = old_file;
	int token_pos = temp.find_last_of('\\');

	// eliminate everything before and including the '\'
	temp.erase(0, token_pos);

	// concatinate the string with our new extension
	temp += new_extension;

	// rename the file
	if (rename(old_file, new_extension.c_str()))
		return true;
	else
		return false;
}

