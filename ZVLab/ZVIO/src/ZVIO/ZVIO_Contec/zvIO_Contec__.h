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

	CString	GetInputSize(int &iSize);					//�Էº�Ʈ�� ũ��
	CString	GetInput(int iInputIndex, BOOL& b);		//1��Ʈ�Է�

	CString	GetOutputSize(int &iSize);				//��º�Ʈ�� ũ��
	CString	SetOutput(int iOutPutIndex, BOOL bOn);		//1��Ʈ ��� 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);	//1��Ʈ ��� 
};

