#include "ZVMotion_Default.h"

namespace ZVLab {

	

	CzvMotion_Default::CzvMotion_Default()
	{
	}

	CzvMotion_Default::~CzvMotion_Default()
	{
	}

	void CzvMotion_Default::ConnectSimulator()
	{
	}

	void CzvMotion_Default::ConnectSerialPort(const TzvMotionInfo_SerialPort & info)
	{
	}

	void CzvMotion_Default::ConnectEthernetTCP(const TzvMotionInfo_EthernetTCP & info)
	{
	}

	void CzvMotion_Default::ConnectEthernetUDP(const TzvMotionInfo_EthernetUDP & info)
	{
	}

	void CzvMotion_Default::Shutdown()
	{
	}

	void CzvMotion_Default::AttachMotor(unsigned int index, const Shared<CzvMotor>& motor)
	{
	}

	void CzvMotion_Default::DetachMotor(unsigned int index)
	{
	}

	unsigned int CzvMotion_Default::GetSlotSize() const
	{
		return 0;
	}

	TzvMotorInfo& CzvMotion_Default::FetchMotorInfo(unsigned int index)
	{
		return (TzvMotorInfo());
	}

	void CzvMotion_Default::AbsMove(unsigned int index, double dPos_pulse)
	{
	}

	void CzvMotion_Default::RelMove(unsigned int index, double dPos_pulse)
	{
	}

	void CzvMotion_Default::Home(unsigned int index)
	{
	}

	void CzvMotion_Default::Hold(unsigned int index, bool enabled)
	{
	}

	Shared<CzvMotor>& CzvMotion_Default::operator[](unsigned int index)
	{
		return Shared<CzvMotor>(nullptr);
	}

} // namespace ZVLab