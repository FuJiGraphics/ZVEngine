#include "stdafx.h"
#include "zvMotion_Acs.h"
#include "zvMotion_Acs__.h"

CzvMotion_Acs::CzvMotion_Acs()
{
	CzvMotion::Init();
	m_pzvMotion_Acs__ = new CzvMotion_Acs__();
}


CzvMotion_Acs::~CzvMotion_Acs()
{
	BoardFinish();

	delete (CzvMotion_Acs__*)m_pzvMotion_Acs__;
}

CString CzvMotion_Acs::BoardInit()
{
	CString strErr = ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->BoardInit();

	if (strErr != zvStrSuccess) return strErr;

	m_iMaxUseAxis =	((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetMaxUseAxis();

	if (m_iMaxUseAxis <= 0)	return _zvErr(EzvErr::NotInitializeBoard);

	strcpy_s(m_strBoardType, 255, g_strMotionBoardType[(int)EzvMotionBoardType::eMotionBoardACS]);

	return zvStrSuccess;
}

CString CzvMotion_Acs::BoardFinish()
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->BoardFinish();
}

CString CzvMotion_Acs::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->MotInit(iMotIndex, tAxisInfo);
}

CString CzvMotion_Acs::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->SetCommandPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Acs::SetActPostion(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->SetActPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Acs::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetMotStatus(iMotIndex, iMotStatus);
}

CString CzvMotion_Acs::GetHomeSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetHomeSensor(iMotIndex, b);
}

CString CzvMotion_Acs::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetPLimitSensor(iMotIndex, b);
}

CString CzvMotion_Acs::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetMLimitSensor(iMotIndex, b);
}

CString CzvMotion_Acs::GetAlaramSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetAlaramSig(iMotIndex, b);
}

CString CzvMotion_Acs::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetHoldOnSig(iMotIndex, b);
}

CString CzvMotion_Acs::GetMotionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetMotionSig(iMotIndex, b);
}

CString CzvMotion_Acs::GetInpositionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetInpositionSig(iMotIndex, b);
}

CString CzvMotion_Acs::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetActPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Acs::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetCommandPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Acs::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->GetHomeResult(iMotIndex, eState);
}

CString CzvMotion_Acs::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->AbsScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->RelScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->MoveContinue(iMotIndex, tMotSpeedInfo);
}

CString CzvMotion_Acs::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->Home(iMotIndex, tAxisSpeedInfo);
}

CString CzvMotion_Acs::Stop(int iMotIndex, double dDecTime)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->Stop(iMotIndex, dDecTime);
}

CString CzvMotion_Acs::EStop(int iMotIndex)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->EStop(iMotIndex);
}

CString CzvMotion_Acs::Hold(int iMotIndex, int iOnOff)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->Hold(iMotIndex, iOnOff);
}

CString CzvMotion_Acs::HoldOn(int iMotIndex)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->HoldOn(iMotIndex);
}

CString CzvMotion_Acs::HoldOff(int iMotIndex)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->HoldOff(iMotIndex);
}

CString CzvMotion_Acs::RebootController()
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->RebootController();
}

CString CzvMotion_Acs::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return ((CzvMotion_Acs__*)m_pzvMotion_Acs__)->SetMotionTrigger(iMotIndex, dStartPosition, dEndPosition, dTriggeringPeriod, dTriggeringWidth, iTriggerLevel);
}

CzvMotion * CreateMotionAcs()
{
	CzvMotion* p = new  CzvMotion_Acs();

	return p;
}
