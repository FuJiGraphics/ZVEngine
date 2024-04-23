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

	CString	GetInputSize(int &iSize) override;					//입력비트의 크기
	CString	GetInput(int iInputIndex, BOOL& b) override;		//1비트입력

	CString	GetOutputSize(int &iSize) override;				//출력비트의 크기
	CString	SetOutput(int iOutPutIndex, BOOL bOn) override;		//1비트 출력 
	CString	GetOutput(int iOutPutIndex, BOOL& bOut) override;	//1비트 출력 
};

extern "C"
{
	AFX_EXT_API extern CzvIO* CreateIODB64R();
}