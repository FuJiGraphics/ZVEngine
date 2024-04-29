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

	CString	GetInputSize(int &iSize);					//�Էº�Ʈ�� ũ��
	CString	GetInput(int iInputIndex, BOOL& b);				//1��Ʈ�Է�

	CString	GetOutputSize(int &iSize);					//��º�Ʈ�� ũ��
	CString	SetOutput(int iOutPutIndex, BOOL bOn);				//1��Ʈ ��� 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);			//1��Ʈ ��� 
};

extern "C"
{
	AFX_EXT_API extern CzvIO* CreateIOContec();
}

