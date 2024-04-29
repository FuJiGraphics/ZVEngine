#ifndef __ZV_ZVMOTION_VIRTUAL_H__
#define __ZV_ZVMOTION_VIRTUAL_H__
#pragma once

#include "ZVCore.h"
#include "ZVMotion_cfg.h"
#include "ZVMotor.h"

namespace ZVLab {

	class CzvMotion
	{
	protected: /// using
		using SerialPort	= std::optional<TzvMotionInfo_SerialPort>;
		using EthernetTCP	= std::optional<TzvMotionInfo_EthernetTCP>;
		using EthernetUDP	= std::optional<TzvMotionInfo_EthernetUDP>;

	public: 
		static Shared<CzvMotion> Create();

	public:
		virtual void ConnectSimulator() {}
		virtual void ConnectSerialPort(const TzvMotionInfo_SerialPort& info) {}
		virtual void ConnectEthernetTCP(const TzvMotionInfo_EthernetTCP& info) {}
		virtual void ConnectEthernetUDP(const TzvMotionInfo_EthernetUDP& info) {}
		virtual void Shutdown() {}

	public:
		virtual void AttachMotor(unsigned int index, const Shared<CzvMotor>& motor) = 0;
		virtual void DetachMotor(unsigned int index) = 0;

	public:
		virtual unsigned int	GetSlotSize() const = 0;
		virtual TzvMotorInfo&	FetchMotorInfo(unsigned int index) = 0;

	public:
		virtual void AbsMove(unsigned int index, double dPos_pulse) = 0;
		virtual void RelMove(unsigned int index, double dPos_pulse) = 0;
		virtual void Home(unsigned int index) = 0;
		virtual void Hold(unsigned int index, bool enabled) = 0;

	public:
		virtual Shared<CzvMotor>& operator[] (unsigned int index) = 0;
	};


} // namespace ZVLab


#endif /*__ZV_ZVMOTION_VIRTUAL_H__*/
