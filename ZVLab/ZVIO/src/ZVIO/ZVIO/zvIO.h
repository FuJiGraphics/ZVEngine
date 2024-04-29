#pragma once
class AFX_EXT_CLASS CzvIO
{
	////member variables
protected:
public:

	////member functions
protected:
public:
	CzvIO();
	virtual ~CzvIO();
	CzvIO(CzvIO& IOSrc) = delete;
	CzvIO& operator=(CzvIO& IOSrc) = delete;

	virtual CString	BoardInit() = 0;
	virtual CString	BoardFinish() = 0;
	virtual CString	IOInit(void) = 0;
	virtual CString	GetBoardInfo(unsigned char *pucbuf, int n) = 0;

	virtual CString	GetInputSize(int &iSize) = 0;					//입력비트의 크기
	virtual CString	GetInput(int iInputIndex, BOOL& b) = 0;		//1비트입력

	virtual CString	GetOutputSize(int &iSize) = 0;				//출력비트의 크기
	virtual CString	SetOutput(int iOutPutIndex, BOOL bOn) = 0;		//1비트 출력 
	virtual CString	GetOutput(int iOutPutIndex, BOOL& bOut) = 0;	//1비트 출력 
};

