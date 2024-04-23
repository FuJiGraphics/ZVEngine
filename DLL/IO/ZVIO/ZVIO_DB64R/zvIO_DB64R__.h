#pragma once

class CzvIO_DB64R__ final
{
	//// member variables
private:
	vector<TzvIOInfo> m_vtIOInfo;
public:

	//// member functions
private:
public:
	CzvIO_DB64R__();
	~CzvIO_DB64R__();
	CzvIO_DB64R__(const CzvIO_DB64R__ & zvIOSrc) = delete;
	CzvIO_DB64R__ & operator=(const CzvIO_DB64R__ & zvIOSrc) = delete;

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

