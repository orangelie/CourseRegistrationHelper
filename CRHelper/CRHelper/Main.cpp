#include "CRApplication.h"

int main()
{
	std::vector<std::string> fileNames = {
		"ClassBin1.txt",
		"ClassBin2.txt"
	};

	FileLoader fileLoader(fileNames);
	CRApplication CRApp(&fileLoader);
	return CRApp.Run();
}
