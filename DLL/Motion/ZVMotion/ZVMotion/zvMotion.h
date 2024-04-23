#pragma once

class AFX_EXT_CLASS CzvMotion
{
	////member variables
protected:
	char m_strBoardType[DMotionNameSize];
	int m_iMaxUseAxis;

public:

	////member functions
protected:
	// initialize
	void Init(void);

public:
	CzvMotion();
	virtual ~CzvMotion();
	CzvMotion(CzvMotion& MotionSrc) = delete;
	CzvMotion& operator=(CzvMotion& MotionSrc) = delete;

	virtual CString BoardInit() = 0;	//Board initialize
	virtual CString BoardFinish() = 0;	//Board Release 

	virtual CString MotInit(int iMotIndex, TzvAxisInfo tAxisInfo) = 0;

	//get N set
	virtual CString SetCommandPosition(int iMotIndex, double dPos_pulse) = 0;
	virtual CString SetActPostion(int iMotIndex, double dPos_pulse) = 0;

	virtual CString GetMotStatus(int iMotIndex, int& iMotStatus) = 0;
	virtual CString GetHomeSensor(int iMotIndex, BOOL& b) = 0;
	virtual CString GetPLimitSensor(int iMotIndex, BOOL& b) = 0;
	virtual CString GetMLimitSensor(int iMotIndex, BOOL& b) = 0;
	virtual CString GetAlaramSig(int iMotIndex, BOOL& b) = 0;
	virtual CString GetHoldOnSig(int iMotIndex, BOOL& b) = 0;
	virtual CString GetMotionSig(int iMotIndex, BOOL& b) = 0;
	virtual CString GetInpositionSig(int iMotIndex, BOOL& b) = 0;
	virtual CString GetActPosition(int iMotIndex, double& dPos_pulse) = 0;
	virtual CString GetCommandPostion(int iMotIndex, double& dPos_pulse) = 0;
	virtual CString GetHomeResult(int iMotIndex, EzvHomeState& eState) = 0;

	//Motion Move N Act
	virtual CString AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//abs move ->  unit : pulse
	virtual CString RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//rel move ->  unit : pulse
	virtual CString AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//S - Curve abs move
	virtual CString RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo) = 0;//S - Curve rel move
	virtual CString MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo) = 0;//jog

	virtual CString Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo) = 0;

	virtual CString Stop(int iMotIndex, double dDecTime = 0.1) = 0;//Stop
	virtual CString EStop(int iMotIndex) = 0;//Estop

	//mot hold
	virtual CString Hold(int iMotIndex, int iOnOff) = 0; //mot hold on off
	virtual CString HoldOn(int iMotIndex) = 0;
	virtual CString HoldOff(int iMotIndex) = 0;

	//reboot
	virtual CString RebootController() = 0;

	//trigger
	virtual CString SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel) = 0;

	//get board info
	void GetBoardType(char pBoardType[DMotionNameSize])
	{
		CopyMemory(pBoardType, m_strBoardType, sizeof(char) * DMotionNameSize);
	};

	int GetMaxUseAxis() { return m_iMaxUseAxis; };
};

extern "C"
{
	AFX_EXT_API extern CzvMotion* CreateMotion();
}