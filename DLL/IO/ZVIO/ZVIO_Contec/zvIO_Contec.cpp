#include "stdafx.h"
#include "zvIO_Contec.h"
#include "zvIO_Contec__.h"

CzvIO_Contec::CzvIO_Contec()
{
	m_pzvIO_Contec__ = new CzvIO_Contec__();
}

CzvIO_Contec::~CzvIO_Contec()
{
	delete (CzvIO_Contec__*)m_pzvIO_Contec__;
}

CString CzvIO_Contec::BoardInit()
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->BoardInit();
}

CString CzvIO_Contec::BoardFinish()
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->BoardFinish();
}

CString CzvIO_Contec::IOInit(void)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->IOInit();
}

CString CzvIO_Contec::GetBoardInfo(unsigned char * pucbuf, int n)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->GetBoardInfo(pucbuf, n);
}

CString CzvIO_Contec::GetInputSize(int &iSize)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->GetInputSize(iSize);
}

CString CzvIO_Contec::GetInput(int iInputIndex, BOOL& b)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->GetInput(iInputIndex, b);
}

CString CzvIO_Contec::GetOutputSize(int &iSize)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->GetOutputSize(iSize);
}

CString CzvIO_Contec::SetOutput(int iOutPutIndex, BOOL bOn)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->SetOutput(iOutPutIndex, bOn);
}

CString CzvIO_Contec::GetOutput(int iOutPutIndex, BOOL & bOut)
{
	return ((CzvIO_Contec__*)m_pzvIO_Contec__)->GetOutput(iOutPutIndex, bOut);
}

CzvIO * CreateIOContec()
{
	CzvIO* p = new CzvIO_Contec();
	return p;
}
