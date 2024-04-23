#include "pch.h"
#include "zvMotion_Virtual__.h"


CzvMotion_Virtual__::CzvMotion_Virtual__()
{
	InitMotion();
}


CzvMotion_Virtual__::~CzvMotion_Virtual__()
{

}

//// private
void CzvMotion_Virtual__::InitMotion()
{
	for (int i = 0; i < DzvMotionVirtualMaxAxisNumber; i++)
	{
		m_rgdPosition[i] = 0.;
	}
}

//// public
CString CzvMotion_Virtual__::BoardInit()
{
	m_iMaxUseAxis = DzvMotionVirtualMaxAxisNumber;

	InitMotion();

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::BoardFinish()
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::SetCommandPosition(int iMotIndex, double dPos_pulse)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::SetActPostion(int iMotIndex, double dPos_pulse)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetMotStatus(int iMotIndex, int & iMotStatus)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetHomeSensor(int iMotIndex, BOOL & b)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetPLimitSensor(int iMotIndex, BOOL & b)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetMLimitSensor(int iMotIndex, BOOL & b)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetAlaramSig(int iMotIndex, BOOL & b)
{

	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetMotionSig(int iMotIndex, BOOL & b)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetInpositionSig(int iMotIndex, BOOL & b)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::Stop(int iMotIndex, double dDecTime)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::EStop(int iMotIndex)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::Hold(int iMotIndex, int iOnOff)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::HoldOn(int iMotIndex)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::HoldOff(int iMotIndex)
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::RebootController()
{
	return zvStrSuccess;
}

CString CzvMotion_Virtual__::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return zvStrSuccess;
}
