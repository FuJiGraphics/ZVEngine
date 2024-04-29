#pragma once

class AFX_EXT_CLASS CzvIO_Contec : public CzvIO 
{
	////member variables
protected:
	void* m_pzvIO_Contec__;

public:
	
	////member functions
protected:

public:
	CzvIO_Contec();
	virtual ~CzvIO_Contec();
	CzvIO_Contec(CzvIO_Contec& IOSrc) = delete;
	CzvIO_Contec& operator=(CzvIO_Contec& IOSrc) = delete;

	CString	BoardInit();
	CString	BoardFinish();
	CString	IOInit(void);
	CString	GetBoardInfo(unsigned char *pucbuf, int n);

	CString	GetInputSize(int &iSize);					//입력비트의 크기
	CString	GetInput(int iInputIndex, BOOL& b);				//1비트입력

	CString	GetOutputSize(int &iSize);					//출력비트의 크기
	CString	SetOutput(int iOutPutIndex, BOOL bOn);				//1비트 출력 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);			//1비트 출력 
};

extern "C"
{
	AFX_EXT_API extern CzvIO* CreateIOContec();
}

