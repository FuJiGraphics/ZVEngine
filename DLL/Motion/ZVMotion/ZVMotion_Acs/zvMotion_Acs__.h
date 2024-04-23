#pragma once
#include "ACSC.h"
#pragma comment(lib,"ACSCL_x64.lib")


struct Mot_Com_Config
{
	HANDLE handle;
	CString strAddress;
	int nPort;
};

class CzvMotion_Acs__
{
	////member variables
protected:
	int m_iMaxUseAxis;
	Mot_Com_Config m_tMotComConfig;

public:

	////member functions
protected:
	void Init(void);

public:
	CzvMotion_Acs__();
	~CzvMotion_Acs__();
	CzvMotion_Acs__(CzvMotion_Acs__& MotionSrc) = delete;
	CzvMotion_Acs__& operator=(CzvMotion_Acs__& MotionSrc) = delete;

	CString CheckMotIndex(int iMotIndex);
	CString BoardInit();	//Board initialize
	CString BoardFinish();	//Board Release 

	CString MotInit(int iMotIndex, TzvAxisInfo tAxisInfo);

	//get N set
	CString SetCommandPosition(int iMotIndex, double dPos_pulse);
	CString SetActPostion(int iMotIndex, double dPos_pulse);

	CString GetMotStatus(int iMotIndex, int& iMotStatus);
	CString GetHomeSensor(int iMotIndex, BOOL& b);
	CString GetPLimitSensor(int iMotIndex, BOOL& b);
	CString GetMLimitSensor(int iMotIndex, BOOL& b);
	CString GetAlaramSig(int iMotIndex, BOOL& b);
	CString GetHoldOnSig(int iMotIndex, BOOL& b);
	CString GetMotionSig(int iMotIndex, BOOL& b);
	CString GetInpositionSig(int iMotIndex, BOOL& b);
	CString GetActPosition(int iMotIndex, double& dPos_pulse);
	CString GetCommandPostion(int iMotIndex, double& dPos_pulse);
	CString GetHomeResult(int iMotIndex, EzvHomeState& eState);

	//Motion Move N Act
	CString AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo);//abs move ->  unit : pulse
	CString RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo);//rel move ->  unit : pulse
	CString AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo);//S - Curve abs move
	CString RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo);//S - Curve rel move
	CString MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo);//jog

	CString Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo);

	CString Stop(int iMotIndex, double dDecTime = 0.1);//Stop
	CString EStop(int iMotIndex);//Estop

	//mot hold
	CString Hold(int iMotIndex, int iOnOff); //mot hold on off
	CString HoldOn(int iMotIndex);
	CString HoldOff(int iMotIndex);

	CString RebootController();

	// triggering
	CString SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel);

	int GetMaxUseAxis() { return m_iMaxUseAxis; };
};

