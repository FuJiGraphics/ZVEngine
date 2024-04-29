#ifndef __ZV_ZVMOTION_VIRTUAL_H__
#define __ZV_ZVMOTION_VIRTUAL_H__
#pragma once

#include "ZVMotion_Core.h"
#include "ZVMotion_cfg.h"

namespace ZVLab {

	class CZVMotion
	{
	protected: /// using
		using SerialPort = std::optional<TzvMotionInfo_SerialPort>;
		using EthernetTCP = std::optional<TzvMotionInfo_EthernetTCP>;
		using EthernetUDP = std::optional<TzvMotionInfo_EthernetUDP>;

	public:
		static CZVMotion* Create();

	public:
		virtual void Initialize() {}
		virtual void Initialize(const TzvMotionInfo_SerialPort& info) {}
		virtual void Initialize(const TzvMotionInfo_EthernetTCP& info) {}
		virtual void Initialize(const TzvMotionInfo_EthernetUDP& info) {}
		virtual void Shutdown() = 0;

		virtual bool CheckMotIndex(int iMotIndex) = 0;
		virtual bool MotInit(int iMotIndex, const TzvAxisInfo& tAxisInfo) = 0;

		//get N set
		virtual bool SetCommandPosition(int iMotIndex, double dPos_pulse) = 0;
		virtual bool SetActPostion(int iMotIndex, double dPos_pulse) = 0;

		virtual bool GetMotStatus(int iMotIndex, int& iMotStatus) = 0;
		virtual bool GetHomeSensor(int iMotIndex, bool b) = 0;
		virtual bool GetPLimitSensor(int iMotIndex, bool b) = 0;
		virtual bool GetMLimitSensor(int iMotIndex, bool b) = 0;
		virtual bool GetAlaramSig(int iMotIndex, bool b) = 0;
		virtual bool GetHoldOnSig(int iMotIndex, bool b) = 0;
		virtual bool GetMotionSig(int iMotIndex, bool b) = 0;
		virtual bool GetInpositionSig(int iMotIndex, bool b) = 0;
		virtual bool GetActPosition(int iMotIndex, double& dPos_pulse) = 0;
		virtual bool GetCommandPostion(int iMotIndex, double& dPos_pulse) = 0;
		virtual bool GetHomeResult(int iMotIndex, EzvHomeState& eState) = 0;

		//Motion Move N Act
		virtual bool AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//abs move ->  unit : pulse
		virtual bool RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//rel move ->  unit : pulse
		virtual bool AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//S - Curve abs move
		virtual bool RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//S - Curve rel move
		virtual bool MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo) = 0;//jog

		virtual bool Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo) = 0;

		virtual bool Stop(int iMotIndex, double dDecTime = 0.1) = 0;//Stop
		virtual bool EStop(int iMotIndex) = 0;//Estop

		//mot hold
		virtual bool Hold(int iMotIndex, int iOnOff) = 0; //mot hold on off
		virtual bool HoldOn(int iMotIndex) = 0;
		virtual bool HoldOff(int iMotIndex) = 0;

		virtual bool RebootController() = 0;

		//triggering
		virtual bool SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel) = 0;
	};


} // namespace ZVLab


#endif /*__ZV_ZVMOTION_VIRTUAL_H__*/