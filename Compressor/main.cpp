#include <stdio.h>
#include <String>
#include <Windows.h>

using namespace std;

int main(int argc, char** argv) // the number (argc) of parameters and the parameters (argv)
{
	printf("Number of parameters: %d",argc);

	wstring file_path = L"C:\\Users\\user\\OneDrive\\Desktop\\LPR-Check.txt";

	HANDLE handle_to_file = CreateFileW(file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (handle_to_file == INVALID_HANDLE_VALUE)
	{
		printf("\nFailed to open file");
		return 1;
	}
	else
	{
		printf("\nall is well");
	}

	return 0;
}