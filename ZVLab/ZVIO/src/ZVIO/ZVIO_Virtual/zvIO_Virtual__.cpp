#include "pch.h"
#include "zvIO_Virtual__.h"


CzvIO_Virtual__::CzvIO_Virtual__()
{
	InitIO();
}

CzvIO_Virtual__::~CzvIO_Virtual__()
{
	InitIO();
}

//// private
void CzvIO_Virtual__::InitIO()
{
	memset(&m_tIOInfo, 0, sizeof(TzvIOInfo));
	m_vbInput.clear();
	m_vbOutput.clear();
}

//// public
CString CzvIO_Virtual__::BoardInit()
{
	InitIO();

	char strBoard[32] = "Virtual IO Board";

	strcpy_s(m_tIOInfo.strBoardName, 32, strBoard);

	const int nMaxInput = 64;
	const int nMaxOutput = 64;

	m_tIOInfo.iInputSize = nMaxInput;
	m_tIOInfo.iOutputSize = nMaxOutput;

	for (int i = 0; i < nMaxInput; i++)
	{
		m_vbInput.push_back(FALSE);
	}

	for (int i = 0; i < nMaxOutput; i++)
	{
		m_vbOutput.push_back(FALSE);
	}

	return zvStrSuccess;
}

CString CzvIO_Virtual__::BoardFinish()
{
	InitIO();

	return zvStrSuccess;
}

CString CzvIO_Virtual__::IOInit(void)
{
	// init input 
	for (auto& bInput : m_vbInput)
	{
		bInput = FALSE;
	}

	// init output
	for (auto& bOutput : m_vbOutput)
	{
		bOutput = FALSE;
	}

	return zvStrSuccess;
}

CString CzvIO_Virtual__::GetInputSize(int & iSize)
{
	iSize = m_tIOInfo.iInputSize;

	return zvStrSuccess;
}

CString CzvIO_Virtual__::GetInput(int iInputIndex, BOOL & b)
{
	int nInputSize = (int)m_vbInput.size();
	if (iInputIndex < 0 || iInputIndex >= nInputSize) return _zvErr(EzvErr::CheckInputIndex);
	
	b = m_vbInput[iInputIndex];

	return zvStrSuccess;
}

CString CzvIO_Virtual__::GetOutputSize(int & iSize)
{
	iSize = (int)m_vbOutput.size();

	return zvStrSuccess;
}

CString CzvIO_Virtual__::SetOutput(int iOutPutIndex, BOOL bOn)
{
	int nOutputSize;
	GetOutputSize(nOutputSize);

	if (iOutPutIndex < 0 || iOutPutIndex >= nOutputSize) return _zvErr(EzvErr::CheckOutputIndex);

	m_vbOutput[iOutPutIndex] = bOn;

	return zvStrSuccess;
}

CString CzvIO_Virtual__::GetOutput(int iOutPutIndex, BOOL & bOut)
{
	int nOutputSize;
	GetOutputSize(nOutputSize);

	if (iOutPutIndex < 0 || iOutPutIndex >= nOutputSize) return _zvErr(EzvErr::CheckOutputIndex);

	bOut = m_vbOutput[iOutPutIndex];

	return zvStrSuccess;
}
