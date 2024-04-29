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

	CString	GetInputSize(int &iSize);					//�Էº�Ʈ�� ũ��
	CString	GetInput(int iInputIndex, BOOL& b);			//1��Ʈ�Է�

	CString	GetOutputSize(int &iSize);					//��º�Ʈ�� ũ��
	CString	SetOutput(int iOutPutIndex, BOOL bOn);		//1��Ʈ ��� 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut);	//1��Ʈ ��� 
};