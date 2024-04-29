#include "ZVMotor_Default.h"


namespace ZVLab {

	CzvMotor_Default::CzvMotor_Default(const std::string& label)
	{

	}

	CzvMotor_Default::~CzvMotor_Default()
	{

	}

	void CzvMotor_Default::Initialize(const TzvMotorInfo & info)
	{
	}

	void CzvMotor_Default::Shutdown()
	{
	}

	inline bool CzvMotor_Default::HasValue() const
	{
		return false;
	}

	inline TzvMotorInfo CzvMotor_Default::GetMotorInfo() const
	{
		return TzvMotorInfo();
	}

	inline TzvMotorInfo & CzvMotor_Default::FetchMotorInfo()
	{
		return TzvMotorInfo();
	}

}
