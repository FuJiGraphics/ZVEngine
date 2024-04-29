#include "zvIO_Contec.h"
#include "CDio.h"

#pragma comment(lib,"CDIO.lib")

#define REGIO_MAXBD	4

const char *g_strDevice[REGIO_MAXBD] =
{
	"DIO-6464L-PE",
	"PIO-64/64L(PCI)H",
	"DIO-3232L-PE",
	"PIO-32/32L(PCI)H"
};


const int g_iArrInOutputSize[REGIO_MAXBD] =
{
	64,
	64,
	32,
	32
};

namespace ZVLab {

	CzvIO_Contec::~CzvIO_Contec()
	{
		BoardFinish();
	}

	void CzvIO_Contec::BoardInit()
	{
		int iErr = 0;

		m_vtIOInfo.clear();

		//search contec board 
		char strBoardName[32];
		char strBoard[32];

		for (int i = 0; i < 10; i++)
		{
			iErr = DioQueryDeviceName(i, strBoardName, strBoard);

			TzvIOInfo tIOInfo;
			ZeroMemory(&tIOInfo, sizeof(TzvIOInfo));

			if (iErr == DIO_ERR_SUCCESS)
			{
				for (int j = 0; j < REGIO_MAXBD; j++)
				{
					iErr = strcmp(strBoard, g_strDevice[j]);
					if (iErr == 0)
					{
						short sBoardID;

						iErr = DioInit(strBoardName, &sBoardID);

						if (iErr == 0)
						{
							strcpy_s(tIOInfo.strBoardName, 32, strBoardName);
							tIOInfo.iInputSize = g_iArrInOutputSize[j];
							tIOInfo.iOutputSize = g_iArrInOutputSize[j];
							tIOInfo.sBoardID = sBoardID;

							m_vtIOInfo.push_back(tIOInfo);
						}
					}
				}
			}
		}
	}

	void CzvIO_Contec::BoardFinish()
	{
		if (m_vtIOInfo.empty()) return;

		for (auto& tIOInfo : m_vtIOInfo)
		{
			short sBoardID = tIOInfo.sBoardID;
			DioExit(sBoardID);
		}
	}

	std::string CzvIO_Contec::IOInit(void)
	{
		if (m_vtIOInfo.empty()) return std::string();

		//lwc 
		// IO 전체 FALSE로 초기화
		std::vector<TzvIOInfo>::iterator it = m_vtIOInfo.begin();

		for (; it != m_vtIOInfo.end(); it++)
		{
			short BoardID = (*it).sBoardID;
			int iOutSize = (*it).iOutputSize;
			for (int i = 0; i < iOutSize; i++)
				DioOutBit(BoardID, (short)i, 0);
		}

		int iOutputSize;
		GetOutputSize(iOutputSize);

		for (int i = 0; i < iOutputSize; i++)
			SetOutput(i, FALSE);

		return std::string();
	}

	std::string CzvIO_Contec::GetBoardInfo(unsigned char * pucbuf, int n)
	{
		return std::string();
	}

	std::string CzvIO_Contec::GetInputSize(int &iSize)
	{
		iSize = 0;

		if (m_vtIOInfo.empty()) return std::string();;

		int iInputSize = 0;

		for (auto& tIOInfo : m_vtIOInfo)
		{
			iInputSize += tIOInfo.iInputSize;
		}

		iSize = iInputSize;

		return std::string();
	}

	std::string CzvIO_Contec::GetInput(int iInputIndex, BOOL& b)
	{
		b = FALSE;

		int iErr = 0;

		if (m_vtIOInfo.empty()) return std::string();
		if (iInputIndex < 0) return std::string();

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
				iErr = DioInpBit(sBoardID, nTemp2, &ucResult);
				if (iErr != DIO_ERR_SUCCESS)
				{
					return std::string();
				}

				break;
			}
		}

		if (ucResult) b = TRUE;
		else b = FALSE;

		return std::string();
	}

	std::string CzvIO_Contec::GetOutputSize(int &iSize)
	{
		iSize = 0;

		if (m_vtIOInfo.empty()) return std::string();

		int iOutputSize = 0;

		m_vtIOInfo.begin();
		for (auto& tIOInfo : m_vtIOInfo)
		{
			iOutputSize += tIOInfo.iOutputSize;
		}

		iSize = iOutputSize;

		return std::string();
	}

	std::string CzvIO_Contec::SetOutput(int iOutPutIndex, BOOL bOn)
	{
		int iErr = 0;

		if (m_vtIOInfo.empty()) return std::string();
		if (iOutPutIndex < 0) return std::string();

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
				iErr = DioOutBit(sBoardID, nTemp2, ucOn);
				if (iErr != DIO_ERR_SUCCESS) return std::string();
				break;
			}
		}

		return std::string();
	}

	std::string CzvIO_Contec::GetOutput(int iOutPutIndex, BOOL& bOut)
	{
		int iErr;

		bOut = FALSE;

		if (iOutPutIndex < 0) return std::string();

		int nTemp1, nTemp2;

		nTemp1 = iOutPutIndex;

		BYTE ucOn = 0;

		for (auto& tIOInfo : m_vtIOInfo)
		{
			nTemp2 = nTemp1;

			short sBoardID = tIOInfo.sBoardID;
			int iOutputSize = tIOInfo.iOutputSize;

			nTemp1 -= iOutputSize;
			if (nTemp1 < 0)
			{
				iErr = DioEchoBackBit(sBoardID, nTemp2, &ucOn);
				if (iErr != DIO_ERR_SUCCESS) return std::string();

				bOut = ucOn;

				break;
			}
		}

		return std::string();
	}

} 