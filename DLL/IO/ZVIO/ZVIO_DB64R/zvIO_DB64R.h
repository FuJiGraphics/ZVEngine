#pragma once

class AFX_EXT_CLASS CzvIO_DB64R final : public CzvIO
{
	//// member variables
private:
	void* m_pIO;

public:

	//// member functions
private:
public:
	CzvIO_DB64R();
	~CzvIO_DB64R();
	CzvIO_DB64R(const CzvIO_DB64R & ZVIOSrc) = delete;
	CzvIO_DB64R & operator=(const CzvIO_DB64R & ZVIOSrc) = delete;

	CString	BoardInit() override;
	CString	BoardFinish() override;
	CString	IOInit(void) override;
	CString	GetBoardInfo(unsigned char *pucbuf, int n) override;

	CString	GetInputSize(int &iSize) override;					//�Էº�Ʈ�� ũ��
	CString	GetInput(int iInputIndex, BOOL& b) override;		//1��Ʈ�Է�

	CString	GetOutputSize(int &iSize) override;				//��º�Ʈ�� ũ��
	CString	SetOutput(int iOutPutIndex, BOOL bOn) override;		//1��Ʈ ��� 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut) override;	//1��Ʈ ��� 
};

extern "C"
{
	AFX_EXT_API extern CzvIO* CreateIODB64R();
}