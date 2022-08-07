#include "CRApplication.h"

CRApplication::CRApplication(FileLoader* fileLoader)
{
	fileLoader->Load();
	mStringList = fileLoader->String();

	mCommands.clear();
	mCommands = fileLoader->CodeList();
}

int CRApplication::Run()
{
	std::vector<std::string> visualList = mCommands[mStringList[0]];

	for (;;)
	{
		ClearCursorTarget();

		for (int i = 0; i < gMaxKeyInput; ++i)
		{
			std::cout << '[' << i + 1 << "]> " << visualList[i] << gSpaceZero << std::endl;

			BOOL isSuccessed = TRUE;

			if (Clicked((char)(i + 49)))
				isSuccessed = ClipboardCopy(visualList[i].c_str());

			if (isSuccessed == FALSE)
				// ERORR EXCLUSION.
				continue;
		}

		std::cout << "[ESC]> Close a Window." << std::endl;
		if (Clicked(VK_ESCAPE))
			break;

		int maxClassInput = min(gMaxClassInput, mStringList.size());

		std::cout << "\n\n\n";
		for (int i = 0; i < maxClassInput; ++i)
		{
			std::cout << '[' << (char)(i + 65) << "]> " << mStringList[i] << std::endl;
			if (Clicked((char)(i + 65)))
			{
				visualList = mCommands[mStringList[i]];
				std::system("cls");
			}
		}
	}

	return 0;
}

BOOL CRApplication::ClipboardCopy(const char* copyData)
{
	HGLOBAL hMem;
	char* pszbuffer = nullptr;

	if (OpenClipboard(NULL) == FALSE)
	{
		return FALSE;
	}

	size_t nLen = strlen(copyData) + 1;
	hMem = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, nLen);
	if (hMem == NULL)
	{
		CloseClipboard();
		return FALSE;
	}

	pszbuffer = (char*)GlobalLock(hMem);
	if (pszbuffer == nullptr)
	{
		return FALSE;
	}

#pragma warning(push)
#pragma warning(disable:4996)
	sprintf(pszbuffer, "%s", copyData);
#pragma warning(pop)

	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	GlobalUnlock(hMem);
	CloseClipboard();

	return TRUE;
}

void CRApplication::ClearCursorTarget()
{
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	CONSOLE_CURSOR_INFO cursorInfo = {};
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}