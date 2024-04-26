#include <stdio.h>
#include <String>
#include <Windows.h>

using namespace std;

int wmain(int argc, wchar_t** argv) // the number (argc) of parameters and the parameters (argv)
{
	if (argc < 2)
	{
		printf("no parameters sent");
		return 1;
	}

	wstring file_path = argv[1];

	HANDLE handle_to_file = CreateFileW(file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (handle_to_file == INVALID_HANDLE_VALUE)
	{
		printf("\nFailed to open file");
		return 1;
	}


	return 0;
}