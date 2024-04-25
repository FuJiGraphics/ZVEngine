#pragma once
#include "ZVMotion.h"

namespace ZVLab {

	class CZVMotion_Default : public CZVMotion
	{
	private:
		void*				m_pzvMotion_Acs__;
		char				m_strBoardType[DMotionNameSize];
		int					m_iMaxUseAxis;
		Mot_Com_Config		m_tMotComConfig;
		bool				m_bInitialized;

	public: // 생성자, 소멸자
		CZVMotion_Default();
		~CZVMotion_Default();

	public: // 초기화
		virtual bool Initialize() override;
		virtual bool Shutdown() override;

	public:
		virtual bool CheckMotIndex(int iMotIndex) override;
		virtual bool MotInit(int iMotIndex, const TzvAxisInfo& tAxisInfo) override;

		//get N set
		virtual bool SetCommandPosition(int iMotIndex, double dPos_pulse) override;
		virtual bool SetActPostion(int iMotIndex, double dPos_pulse) override;

		virtual bool GetMotStatus(int iMotIndex, int& iMotStatus) override;
		virtual bool GetHomeSensor(int iMotIndex, bool b) override;
		virtual bool GetPLimitSensor(int iMotIndex, bool b) override;
		virtual bool GetMLimitSensor(int iMotIndex, bool b) override;
		virtual bool GetAlaramSig(int iMotIndex, bool b) override;
		virtual bool GetHoldOnSig(int iMotIndex, bool b) override;
		virtual bool GetMotionSig(int iMotIndex, bool b) override;
		virtual bool GetInpositionSig(int iMotIndex, bool b) override;
		virtual bool GetActPosition(int iMotIndex, double& dPos_pulse) override;
		virtual bool GetCommandPostion(int iMotIndex, double& dPos_pulse) override;
		virtual bool GetHomeResult(int iMotIndex, EzvHomeState& eState) override;

		//Motion Move N Act
		virtual bool AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//abs move ->  unit : pulse
		virtual bool RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//rel move ->  unit : pulse
		virtual bool AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//S - Curve abs move
		virtual bool RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//S - Curve rel move
		virtual bool MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo) override;//jog

		virtual bool Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo) override;

		virtual bool Stop(int iMotIndex, double dDecTime = 0.1) override;//Stop
		virtual bool EStop(int iMotIndex) override;//Estop

		//mot hold
		virtual bool Hold(int iMotIndex, int iOnOff) override; //mot hold on off
		virtual bool HoldOn(int iMotIndex) override;
		virtual bool HoldOff(int iMotIndex) override;

		virtual bool RebootController() override;

		//triggering
		virtual bool SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel) override;
	};



} // namespace ZVLab