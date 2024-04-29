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

		std::string	GetInputSize(int &iSize);					//�Էº�Ʈ�� ũ��
		std::string	GetInput(int iInputIndex, BOOL& b);		//1��Ʈ�Է�

		std::string	GetOutputSize(int &iSize);				//��º�Ʈ�� ũ��
		std::string	SetOutput(int iOutPutIndex, BOOL bOn);		//1��Ʈ ��� 
		std::string	GetOutput(int iOutPutIndex, BOOL& bOut);	//1��Ʈ ��� 
	};

} // namespace ZVLab