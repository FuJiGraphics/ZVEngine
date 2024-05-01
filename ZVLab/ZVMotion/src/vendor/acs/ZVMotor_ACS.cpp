#include "ZVMotor_ACS.h"

namespace ZVLab {

	CzvMotor_ACS::CzvMotor_ACS(const std::string& label)
		: m_strLabel(label)
		, m_tInfo()
		, m_iState(0)
	{
	}

	CzvMotor_ACS::~CzvMotor_ACS()
	{
	}

	void CzvMotor_ACS::Initialize(const TzvMotorInfo& info)
	{
		m_tInfo = info;

		int iLevel = m_tInfo.tHwInfo.iLimitLevel ? 0 : 1;
		//리밋 레벨 세팅

		DZVLog_Failed((m_tInfo.tSwInfo.dOnePulseDist > 0), 
					 "FAILED: dOnePulseDist is not greater than 0 = {0}",
					 m_tInfo.tSwInfo.dOnePulseDist);
	}

	void CzvMotor_ACS::Shutdown()
	{

	}

} // namespace ZVLab
