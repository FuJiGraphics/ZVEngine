#include "pch.h"
#include "zvIO_Virtual.h"

CzvIO_Virtual::CzvIO_Virtual()
{
	m_pVoidIO = new CzvIO_Virtual__();
}

CzvIO_Virtual::~CzvIO_Virtual()
{
	delete (CzvIO_Virtual__*)m_pVoidIO;
}

CString CzvIO_Virtual::BoardInit()
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->BoardInit();
}

CString CzvIO_Virtual::BoardFinish()
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->BoardFinish();
}

CString CzvIO_Virtual::IOInit(void)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->IOInit();
}

CString CzvIO_Virtual::GetBoardInfo(unsigned char * pucbuf, int n)
{
	return zvStrSuccess;
}

CString CzvIO_Virtual::GetInputSize(int & iSize)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->GetInputSize(iSize);
}

CString CzvIO_Virtual::GetInput(int iInputIndex, BOOL & b)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->GetInput(iInputIndex, b);
}

CString CzvIO_Virtual::GetOutputSize(int & iSize)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->GetOutputSize(iSize);
}

CString CzvIO_Virtual::SetOutput(int iOutPutIndex, BOOL bOn)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->SetOutput(iOutPutIndex, bOn);
}

CString CzvIO_Virtual::GetOutput(int iOutPutIndex, BOOL & bOut)
{
	return ((CzvIO_Virtual__*)m_pVoidIO)->GetOutput(iOutPutIndex, bOut);
}

CzvIO * CreateIOVirtual()
{
	CzvIO* p = new CzvIO_Virtual();
	return p;
}
