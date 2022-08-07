#pragma once

#include "FileLoader.h"

class CRApplication
{
public:
	CRApplication(FileLoader* fileLoader);
	int Run();

private:
	BOOL ClipboardCopy(const char* copyData);
	void ClearCursorTarget();

private:
	std::unordered_map<std::string, std::vector<std::string>> mCommands;
	std::vector<std::string> mStringList;

};
