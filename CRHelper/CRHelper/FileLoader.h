#pragma once

#include "Utils.h"

class FileLoader
{
public:
	FileLoader(const std::vector<std::string>& fileName);
	void Load();

	std::vector<std::string> String() const;
	std::unordered_map<std::string, std::vector<std::string>> CodeList() const;

private:
	std::vector<std::string> mFilenames;
	std::unordered_map<std::string, std::vector<std::string>> mCodeList;

};