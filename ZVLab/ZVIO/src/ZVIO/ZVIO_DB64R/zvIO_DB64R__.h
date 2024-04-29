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

	CString	GetInputSize(int &iSize);					//�Էº�Ʈ�� ũ��
	CString	GetInput(int iInputIndex, BOOL& b);		//1��Ʈ�Է�

	CString	GetOutputSize(int &iSize);				//��º�Ʈ�� ũ��
	CString	SetOutput(int iOutPutIndex, BOOL bOn);		//1��Ʈ ��� 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);	//1��Ʈ ��� 
};

