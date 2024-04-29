#include "pch.h"
#include "zvIO_DB64R.h"

CzvIO_DB64R::CzvIO_DB64R()
{
	m_pIO =	new CzvIO_DB64R__();
}

CzvIO_DB64R::~CzvIO_DB64R()
{
	delete (CzvIO_DB64R__*)m_pIO;
}

//// private

//// public
CString CzvIO_DB64R::BoardInit()
{
	return ((CzvIO_DB64R__*)m_pIO)->BoardInit();
}

CString CzvIO_DB64R::BoardFinish()
{
	return ((CzvIO_DB64R__*)m_pIO)->BoardFinish();
}

CString CzvIO_DB64R::IOInit(void)
{
	return ((CzvIO_DB64R__*)m_pIO)->IOInit();
}

CString CzvIO_DB64R::GetBoardInfo(unsigned char * pucbuf, int n)
{
	return ((CzvIO_DB64R__*)m_pIO)->GetBoardInfo(pucbuf, n);
}

CString CzvIO_DB64R::GetInputSize(int & iSize)
{
	return ((CzvIO_DB64R__*)m_pIO)->GetInputSize(iSize);
}

CString CzvIO_DB64R::GetInput(int iInputIndex, BOOL & b)
{
	return ((CzvIO_DB64R__*)m_pIO)->GetInput(iInputIndex, b);
}

CString CzvIO_DB64R::GetOutputSize(int & iSize)
{
	return ((CzvIO_DB64R__*)m_pIO)->GetOutputSize(iSize);
}

CString CzvIO_DB64R::SetOutput(int iOutPutIndex, BOOL bOn)
{
	return ((CzvIO_DB64R__*)m_pIO)->SetOutput(iOutPutIndex, bOn);
}

CString CzvIO_DB64R::GetOutput(int iOutPutIndex, BOOL & bOut)
{
	return ((CzvIO_DB64R__*)m_pIO)->GetOutput(iOutPutIndex, bOut);
}

CzvIO * CreateIODB64R()
{
	CzvIO* p = new CzvIO_DB64R();
	return p;
}
