#pragma once


// memory
template<typename T>
inline void zvDelete(T*& pMemory)
{
	if (pMemory != nullptr)
	{
		delete pMemory;
		pMemory = nullptr;
	}
}

template<typename T>
inline void zvDeleteArray(T*& pMemory)
{
	if (pMemory != nullptr)
	{
		delete[] pMemory;
		pMemory = nullptr;
	}
}

// string
#define zvStrNull _T("")
#define zvStrSuccess _T("Success")
#define zvStrEnglish _T("English")
#define zvStrKorean _T("Korean")
#define zvStrChinese _T("Chinese")
