#include "pch.h"
#include "zvIO_DB64R__.h"


CzvIO_DB64R__::CzvIO_DB64R__()
{
	m_vtIOInfo.clear();
}

CzvIO_DB64R__::~CzvIO_DB64R__()
{
}

//// private

//// public
CString CzvIO_DB64R__::BoardInit()
{
	DWORD dwCode;

	dwCode = AxlOpenNoReset(7);
	if (dwCode != AXT_RT_SUCCESS)
		return _zvErr(EzvErr::NotConnectedAnyBoard);

	DWORD dwStatus;

	AxdInfoIsDIOModule(&dwStatus);
	if (dwStatus != STATUS_EXIST)
		return _zvErr(EzvErr::NotConnectedAnyBoard);

	// if (AxlOpen(7) != AXT_RT_SUCCESS)
	// 	return _zvErr(EzvErr::NotInitializeBoard);

	m_vtIOInfo.clear();

	long lModuleCounts;
	dwCode = AxdInfoGetModuleCount(&lModuleCounts);
	if (dwCode == AXT_RT_SUCCESS)
	{
		for (int i = 0; i < lModuleCounts; i++)
		{
			TzvIOInfo tIoInfo;
			memset(&tIoInfo, 0, sizeof(TzvIOInfo));

			long lInputCounts = 0;
			long lOutputCounts = 0;

			tIoInfo.sBoardID = i;

			dwCode = AxdInfoGetInputCount(i, &lInputCounts);
			if (dwCode == AXT_RT_SUCCESS)
				tIoInfo.iInputSize = lInputCounts;

			dwCode = AxdInfoGetOutputCount(i, &lOutputCounts);
			if (dwCode == AXT_RT_SUCCESS)
				tIoInfo.iOutputSize = lOutputCounts;

			m_vtIOInfo.push_back(tIoInfo);
		}
	}

	return zvStrSuccess;
}

CString CzvIO_DB64R__::BoardFinish()
{
	if (AxlIsOpened())
		AxlClose();

	m_vtIOInfo.clear();

	return zvStrSuccess;
}

CString CzvIO_DB64R__::IOInit(void)
{

	return zvStrSuccess;
}

CString CzvIO_DB64R__::GetBoardInfo(unsigned char * pucbuf, int n)
{

	return zvStrSuccess;
}

CString CzvIO_DB64R__::GetInputSize(int & iSize)
{
	iSize = 0;

	if (m_vtIOInfo.empty()) return _zvErr(EzvErr::NotConnectedAnyBoard);

	int iInputSize = 0;

	for (auto& tIOInfo : m_vtIOInfo)
	{
		iInputSize += tIOInfo.iInputSize;
	}

	iSize = iInputSize;

	return zvStrSuccess;
}

CString CzvIO_DB64R__::GetInput(int iInputIndex, BOOL & b)
{
	b = FALSE;

	int iErr = 0;

	if (m_vtIOInfo.empty()) return _zvErr(EzvErr::NotConnectedAnyBoard);
	if (iInputIndex < 0) return _zvErr(EzvErr::CheckInputIndex);

	DWORD dwCode;

	int nTemp1, nTemp2;

	nTemp1 = iInputIndex;

	BYTE ucResult = 0;

	for (auto& tIOInfo : m_vtIOInfo)
	{
		nTemp2 = nTemp1;

		short sBoardID = tIOInfo.sBoardID;
		int iInputSize = tIOInfo.iInputSize;

		nTemp1 -= iInputSize;
		if (nTemp1 < 0)
		{
			DWORD dwInput;
			dwCode = AxdiReadInportBit(sBoardID, nTemp2, &dwInput);
			if (dwCode != AXT_RT_SUCCESS)
				return _zvErr(EzvErr::CheckInputIndex);

			b = (BOOL)dwInput;

			break;
		}
	}

	return zvStrSuccess;
}

CString CzvIO_DB64R__::GetOutputSize(int & iSize)
{
	iSize = 0;

	if (m_vtIOInfo.empty()) return _zvErr(EzvErr::NotConnectedAnyBoard);

	int iOutputSize = 0;

	m_vtIOInfo.begin();
	for (auto& tIOInfo : m_vtIOInfo)
	{
		iOutputSize += tIOInfo.iOutputSize;
	}

	iSize = iOutputSize;

	return zvStrSuccess;
}

CString CzvIO_DB64R__::SetOutput(int iOutPutIndex, BOOL bOn)
{
	if (m_vtIOInfo.empty()) return _zvErr(EzvErr::NotConnectedAnyBoard);
	if (iOutPutIndex < 0) return _zvErr(EzvErr::CheckOutputIndex);

	DWORD dwCode;

	int nTemp1, nTemp2;

	nTemp1 = iOutPutIndex;

	BYTE ucOn = 0;

	if (bOn) ucOn = 1;

	for (auto& tIOInfo : m_vtIOInfo)
	{
		nTemp2 = nTemp1;

		short sBoardID = tIOInfo.sBoardID;
		int iOutputSize = tIOInfo.iOutputSize;

		nTemp1 -= iOutputSize;
		if (nTemp1 < 0)
		{
			dwCode = AxdoWriteOutportBit(sBoardID, nTemp2, bOn);
			if (dwCode != AXT_RT_SUCCESS) return _zvErr(EzvErr::CheckOutputIndex);
			break;
		}
	}

	return zvStrSuccess;
}

CString CzvIO_DB64R__::GetOutput(int iOutPutIndex, BOOL & bOut)
{
	bOut = FALSE;

	if (iOutPutIndex < 0) return _zvErr(EzvErr::CheckOutputIndex);

	DWORD dwCode;

	int nTemp1, nTemp2;
	nTemp1 = iOutPutIndex;

	for (auto& tIOInfo : m_vtIOInfo)
	{
		nTemp2 = nTemp1;

		short sBoardID = tIOInfo.sBoardID;
		int iOutputSize = tIOInfo.iOutputSize;

		nTemp1 -= iOutputSize;
		if (nTemp1 < 0)
		{
			DWORD dwLevel;
			dwCode = AxdoReadOutportBit(sBoardID, nTemp2, &dwLevel);
			if (dwCode != AXT_RT_SUCCESS) return _zvErr(EzvErr::CheckOutputIndex);

			bOut = dwLevel;
			break;
		}
	}

	return zvStrSuccess;
}