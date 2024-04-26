#include <stdio.h>
#include <String>
#include <Windows.h>
#include <vector>

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

	DWORD size = GetFileSize(handle_to_file, NULL);//CHANGE LATER TO DEAL WITH LARGER FILES
	vector<uint8_t> file_data;
	file_data.resize(size);
	DWORD number_of_bytes_read = 0;
	bool result = ReadFile(handle_to_file, &file_data[0], size, &number_of_bytes_read, NULL);
	if (!result)
	{
		printf("Failed to read file");
		return 1;
	}
	printf("File size: %d\nNumber of bytes read: %d", size, number_of_bytes_read);
	return 0;
}