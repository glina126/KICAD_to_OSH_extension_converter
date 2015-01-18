#include <iostream>
using namespace std;

// disable if you dont want it to be loud
#define VERBOSE 1

int main(int argc, char *argv[])
{

#if VERBOSE
	cout << "number of arguments: " << argc << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << i << ": " << argv[i] << endl;
	}
#endif

}