#include "ZVMotor_Virtual.h"


namespace ZVLab {

	CzvMotor_Virtual::CzvMotor_Virtual(const std::string& label)
	{

	}

	CzvMotor_Virtual::~CzvMotor_Virtual()
	{

	}

	void CzvMotor_Virtual::Initialize(const TzvMotorInfo & info)
	{
	}

	void CzvMotor_Virtual::Shutdown()
	{
	}

	inline bool CzvMotor_Virtual::HasValue() const
	{
		return false;
	}

	inline TzvMotorInfo CzvMotor_Virtual::GetMotorInfo() const
	{
		return TzvMotorInfo();
	}

	inline TzvMotorInfo & CzvMotor_Virtual::FetchMotorInfo()
	{
		return TzvMotorInfo();
	}

}
