#pragma once


class CzvIO_Contec__
{
	////member variables
protected:
	vector<TzvIOInfo> m_vtIOInfo;

public:

	////member functions
protected:

public:
	CzvIO_Contec__();
	~CzvIO_Contec__();
	CzvIO_Contec__(CzvIO_Contec__& IOSrc) = delete;
	CzvIO_Contec__& operator=(CzvIO_Contec__& IOSrc) = delete;

	CString	BoardInit();
	CString	BoardFinish();
	CString	IOInit(void);
	CString	GetBoardInfo(unsigned char *pucbuf, int n);

	CString	GetInputSize(int &iSize);					//입력비트의 크기
	CString	GetInput(int iInputIndex, BOOL& b);		//1비트입력

	CString	GetOutputSize(int &iSize);				//출력비트의 크기
	CString	SetOutput(int iOutPutIndex, BOOL bOn);		//1비트 출력 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);	//1비트 출력 
};

