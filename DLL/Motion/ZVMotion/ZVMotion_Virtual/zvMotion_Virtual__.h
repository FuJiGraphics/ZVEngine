#pragma once

#define DzvMotionVirtualMaxAxisNumber 8

class CzvMotion_Virtual__ final
{
	//// member variables
private:
	int m_iMaxUseAxis;
	double m_rgdPosition[DzvMotionVirtualMaxAxisNumber];

public:

	//// member functions
private:
	void InitMotion();

public:
	CzvMotion_Virtual__();
	~CzvMotion_Virtual__();
	CzvMotion_Virtual__(const CzvMotion_Virtual__& zvMotion_VirtualSrc) = delete;
	CzvMotion_Virtual__& operator=(const CzvMotion_Virtual__& zvMotion_VirtualSrc) = delete;

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

	//reboot
	CString RebootController();

	//trigger
	CString SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel);

	int GetMaxUseAxis() { return m_iMaxUseAxis; };
};

