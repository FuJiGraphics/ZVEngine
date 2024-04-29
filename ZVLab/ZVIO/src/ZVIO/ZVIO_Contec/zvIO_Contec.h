#pragma once
#include "ZVCore.h"

namespace ZVLab {

	struct TzvIOInfo
	{
		char strBoardName[32];
		short sBoardID;
		int iInputSize;
		int iOutputSize;

	};

	class CzvIO_Contec
	{
		////member variables
	protected:
		std::vector<TzvIOInfo> m_vtIOInfo;

	public:

		////member functions
	protected:

	public:
		CzvIO_Contec() = default;
		~CzvIO_Contec();

		void		BoardInit();
		void		BoardFinish();
		std::string	IOInit(void);
		std::string	GetBoardInfo(unsigned char *pucbuf, int n);

		std::string	GetInputSize(int &iSize);					//입력비트의 크기
		std::string	GetInput(int iInputIndex, BOOL& b);		//1비트입력

		std::string	GetOutputSize(int &iSize);				//출력비트의 크기
		std::string	SetOutput(int iOutPutIndex, BOOL bOn);		//1비트 출력 
		std::string	GetOutput(int iOutPutIndex, BOOL& bOut);	//1비트 출력 
	};

} // namespace ZVLab