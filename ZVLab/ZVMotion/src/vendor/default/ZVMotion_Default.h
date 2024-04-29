#pragma once
#include "../../ZVMotion.h"

namespace ZVLab {

	class CzvMotion_Default : public CzvMotion
	{

	public: // 생성자, 소멸자
		CzvMotion_Default();
		virtual ~CzvMotion_Default();


	public: // 초기화
		virtual void ConnectSimulator() override;
		virtual void ConnectSerialPort(const TzvMotionInfo_SerialPort& info) override;
		virtual void ConnectEthernetTCP(const TzvMotionInfo_EthernetTCP& info) override;
		virtual void ConnectEthernetUDP(const TzvMotionInfo_EthernetUDP& info) override;
		virtual void Shutdown() override;

	public: // Setter
		virtual void AttachMotor(unsigned int index, const Shared<CzvMotor>& motor) override;
		virtual void DetachMotor(unsigned int index) override;

	public:
		virtual unsigned int	GetSlotSize() const override;
		virtual TzvMotorInfo&	FetchMotorInfo(unsigned int index) override;

	public:
		virtual void AbsMove(unsigned int index, double dPos_pulse) override;
		virtual void RelMove(unsigned int index, double dPos_pulse) override;
		virtual void Home(unsigned int index) override;
		virtual void Hold(unsigned int index, bool enabled) override;

	public:
		virtual Shared<CzvMotor>& operator[] (unsigned int index) override;
	};



} // namespace ZVLab