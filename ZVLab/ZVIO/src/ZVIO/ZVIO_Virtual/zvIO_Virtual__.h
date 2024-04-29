#pragma once

class CzvIO_Virtual__ final
{
	//// member variables
private:
	TzvIOInfo m_tIOInfo;
	vector<BOOL> m_vbInput;
	vector<BOOL> m_vbOutput;

public:

	//// member functions
private:
	void InitIO();

public:
	CzvIO_Virtual__();
	~CzvIO_Virtual__();
	CzvIO_Virtual__(const CzvIO_Virtual__& zvIO_VirtualSrc) = delete;
	CzvIO_Virtual__& operator=(const CzvIO_Virtual__& zvIO_VirtualSrc) = delete;

	CString	BoardInit();
	CString	BoardFinish();
	CString	IOInit(void);

	CString	GetInputSize(int &iSize);					//입력비트의 크기
	CString	GetInput(int iInputIndex, BOOL& b);			//1비트입력

	CString	GetOutputSize(int &iSize);					//출력비트의 크기
	CString	SetOutput(int iOutPutIndex, BOOL bOn);		//1비트 출력 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);	//1비트 출력 
};