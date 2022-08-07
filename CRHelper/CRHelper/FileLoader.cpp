#include "FileLoader.h"

FileLoader::FileLoader(const std::vector<std::string>& fileNames)
{
	mFilenames = fileNames;
}

void FileLoader::Load()
{
	mCodeList.clear();

	for (const auto& f : mFilenames)
	{
		std::ifstream reader(f);

		if (reader.is_open())
		{
			size_t count = 0;

			while (!reader.eof() || count < gMaxKeyInput)
			{
				std::string tempString = "";
				std::getline(reader, tempString);
				if (tempString.empty() == false)
					mCodeList[f].push_back(tempString);

				++count;
			}

			reader.close();
		}
	}
}

std::vector<std::string> FileLoader::String() const
{
	return mFilenames;
}

std::unordered_map<std::string, std::vector<std::string>> FileLoader::CodeList() const
{
	return mCodeList;
}