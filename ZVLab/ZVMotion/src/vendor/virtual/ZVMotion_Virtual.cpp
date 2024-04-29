#include "ZVMotion_Virtual.h"

namespace ZVLab {

	

	CzvMotion_Virtual::CzvMotion_Virtual()
	{
	}

	CzvMotion_Virtual::~CzvMotion_Virtual()
	{
	}

	void CzvMotion_Virtual::ConnectSimulator()
	{
	}

	void CzvMotion_Virtual::ConnectSerialPort(const TzvMotionInfo_SerialPort & info)
	{
	}

	void CzvMotion_Virtual::ConnectEthernetTCP(const TzvMotionInfo_EthernetTCP & info)
	{
	}

	void CzvMotion_Virtual::ConnectEthernetUDP(const TzvMotionInfo_EthernetUDP & info)
	{
	}

	void CzvMotion_Virtual::Shutdown()
	{
	}

	void CzvMotion_Virtual::AttachMotor(unsigned int index, const Shared<CzvMotor>& motor)
	{
	}

	void CzvMotion_Virtual::DetachMotor(unsigned int index)
	{
	}

	unsigned int CzvMotion_Virtual::GetSlotSize() const
	{
		return 0;
	}

	TzvMotorInfo& CzvMotion_Virtual::FetchMotorInfo(unsigned int index)
	{
		return (TzvMotorInfo());
	}

	void CzvMotion_Virtual::AbsMove(unsigned int index, double dPos_pulse)
	{
	}

	void CzvMotion_Virtual::RelMove(unsigned int index, double dPos_pulse)
	{
	}

	void CzvMotion_Virtual::Home(unsigned int index)
	{
	}

	void CzvMotion_Virtual::Hold(unsigned int index, bool enabled)
	{
	}

	Shared<CzvMotor>& CzvMotion_Virtual::operator[](unsigned int index)
	{
		return Shared<CzvMotor>(nullptr);
	}

} // namespace ZVLab