#include <iostream>
#include <string.h>
using namespace std;

// disable if you dont want it to be loud
#define VERBOSE 1

// definitions
bool findExtension(string,string); 
bool renameFile(char *, string);
void compressFiles(char *);

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
		for (int i = 1; i < argc; i++)
		{
			// convert the char[] to string for easier parsing
			string temp = argv[i];

#if VERBOSE
			cout << "i = " << i << " and argv[i] = " << endl << argv[i] << endl;
#endif

			/************************** ADD NEW EXTENSIONS HERE **************************/
			if (findExtension(".gbr", temp)) // what we are looking for
			{
				// extension found, convert to *.GKO - board outline
				if (renameFile(argv[i], ".GKO"))// what we want to convert to
				{
#if VERBOSE
					cout << "sucessful rename to .GKO" << endl;
#endif
				}

			}
			else if (findExtension(".drl", temp))
			{
				// extension found, convert to *.XLN - drill file
				if(renameFile(argv[i], ".XLN"))
				{
#if VERBOSE
					cout << "sucessful rename to .XLN" << endl;
#endif
				}
			}
		}	
		// zip the directory
		compressFiles(argv[1]);
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
	int temp = argument_string.find(extension);

	if (temp > 0)
	{
#if VERBOSE
		cout << "sucessful find of " << extension.c_str() << " at pos " << temp << endl;
#endif
		return true;
	}
	else
	{
#if VERBOSE
		cout << "unsucessful find of " << extension.c_str() << " at pos " << temp << endl;
#endif
		return false;
	}
}

bool renameFile(char * old_file, string new_extension)
{
	// extract file name from old_file - contains the whole directory
	string temp = old_file;
	int token_pos = temp.find_last_of('\\');

#if VERBOSE
	cout << "token_pos: " << token_pos << endl;
#endif
	
	// eliminate everything before and including the '\'
	temp.erase(0, token_pos+1);

	// find the first '.'
	token_pos = temp.find(".");

	// erase the extension
	temp.erase(token_pos, temp.length());

	// concatinate the string with our new extension
	temp += new_extension;

#if VERBOSE
	cout << "old_file: " << old_file << endl;
	cout << "new file name: " << temp.c_str() << endl;
#endif

	// rename the file
	if (rename(old_file, temp.c_str()))
		return true;
	else
		return false;
}

void compressFiles(char * name)
{
#ifdef _WIN32 
	//zip directory
	string command = "compact /c /s ";

	// holds the directory with the file name
	string file_name = name;

	// find the token
	int token_pos = file_name.find_last_of("\\");

	// erase the file name leaving just the directory
	file_name.erase(token_pos, file_name.length());

	// append the command with the directory
	command.append(file_name);
	
	// execute the command 
	system(command.c_str());

#else
	//tar directory
#endif
}