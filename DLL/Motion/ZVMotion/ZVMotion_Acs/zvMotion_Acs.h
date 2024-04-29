#pragma once

class AFX_EXT_CLASS CzvMotion_Acs final: public CzvMotion
{
	////member variables
protected:
	void* m_pzvMotion_Acs__;
	char m_strBoardType[DMotionNameSize];
	int m_iMaxUseAxis;

public:
	
	////member functions
protected:
	// initialize

public:
	CzvMotion_Acs();
	~CzvMotion_Acs();
	CzvMotion_Acs(CzvMotion_Acs& MotionSrc) = delete;
	CzvMotion_Acs& operator=(CzvMotion_Acs& MotionSrc) = delete;

	CString BoardInit() override;	//Board initialize
	CString BoardFinish() override; 	//Board Release 

	CString MotInit(int iMotIndex, TzvAxisInfo tAxisInfo) override;

	//get N set
	CString SetCommandPosition(int iMotIndex, double dPos_pulse) override;
	CString SetActPostion(int iMotIndex, double dPos_pulse) override;

	CString GetMotStatus(int iMotIndex, int& iMotStatus) override;
	CString GetHomeSensor(int iMotIndex, BOOL& b) override;
	CString GetPLimitSensor(int iMotIndex, BOOL& b) override;
	CString GetMLimitSensor(int iMotIndex, BOOL& b) override;
	CString GetAlaramSig(int iMotIndex, BOOL& b) override;
	CString GetHoldOnSig(int iMotIndex, BOOL& b) override;
	CString GetMotionSig(int iMotIndex, BOOL& b) override;
	CString GetInpositionSig(int iMotIndex, BOOL& b) override;
	CString GetActPosition(int iMotIndex, double& dPos_pulse) override;
	CString GetCommandPostion(int iMotIndex, double& dPos_pulse) override;
	CString GetHomeResult(int iMotIndex, EzvHomeState& eState) override;

	//Motion Move N Act
	CString AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//abs move ->  unit : pulse
	CString RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//rel move ->  unit : pulse
	CString AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//S - Curve abs move
	CString RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) override;//S - Curve rel move
	CString MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo) override;//jog

	CString Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo) override;

	CString Stop(int iMotIndex, double dDecTime = 0.1) override;//Stop
	CString EStop(int iMotIndex) override;//Estop

	//mot hold
	CString Hold(int iMotIndex, int iOnOff) override; //mot hold on off
	CString HoldOn(int iMotIndex) override;
	CString HoldOff(int iMotIndex) override;

	CString RebootController() override;

	//triggering
	CString SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel) override;
};

extern "C"
{
	AFX_EXT_API extern CzvMotion* CreateMotionAcs();
}

