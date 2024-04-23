#include "stdafx.h"
#include "zvMotion_Ajin.h"
#include "zvMotion_Ajin__.h"

CzvMotion_Ajin::CzvMotion_Ajin()
{
	CzvMotion::Init();
	m_pzvMotion_Ajin__ = new CzvMotion_Ajin__();

}


CzvMotion_Ajin::~CzvMotion_Ajin()
{
	BoardFinish();

	delete (CzvMotion_Ajin__*)m_pzvMotion_Ajin__;
}


CString CzvMotion_Ajin::BoardInit()
{
	CzvMotion::Init();

	CString strErr = ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->BoardInit();
	if (strErr != zvStrSuccess) return strErr;

	m_iMaxUseAxis = ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetMaxUseAxis();

	if (m_iMaxUseAxis <= 0)	return _zvErr(EzvErr::NotInitializeBoard);

	strcpy_s(m_strBoardType, 255, g_strMotionBoardType[(int)EzvMotionBoardType::eMotionBoardAjin]);

	return zvStrSuccess;
}

CString CzvMotion_Ajin::BoardFinish()
{
	((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->BoardFinish();
	CzvMotion::Init();

	return zvStrSuccess;
}

CString CzvMotion_Ajin::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->MotInit(iMotIndex, tAxisInfo);
}

CString CzvMotion_Ajin::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->SetCommandPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Ajin::SetActPostion(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->SetActPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Ajin::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetMotStatus(iMotIndex, iMotStatus);
}

CString CzvMotion_Ajin::GetHomeSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetHomeSensor(iMotIndex, b);
}

CString CzvMotion_Ajin::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetPLimitSensor(iMotIndex, b);
}

CString CzvMotion_Ajin::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetMLimitSensor(iMotIndex, b);
}

CString CzvMotion_Ajin::GetAlaramSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetAlaramSig(iMotIndex, b);
}

CString CzvMotion_Ajin::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetHoldOnSig(iMotIndex, b);
}

CString CzvMotion_Ajin::GetMotionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetMotionSig(iMotIndex, b);
}

CString CzvMotion_Ajin::GetInpositionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetInpositionSig(iMotIndex, b);
}

CString CzvMotion_Ajin::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetActPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Ajin::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetCommandPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Ajin::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->GetHomeResult(iMotIndex, eState);
}

CString CzvMotion_Ajin::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Ajin::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Ajin::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->AbsScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Ajin::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->RelScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Ajin::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->MoveContinue(iMotIndex, tMotSpeedInfo);
}

CString CzvMotion_Ajin::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->Home(iMotIndex, tAxisSpeedInfo);
}

CString CzvMotion_Ajin::Stop(int iMotIndex, double dDecTime)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->Stop(iMotIndex, dDecTime);
}

CString CzvMotion_Ajin::EStop(int iMotIndex)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->EStop(iMotIndex);
}

CString CzvMotion_Ajin::Hold(int iMotIndex, int iOnOff)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->Hold(iMotIndex, iOnOff);
}

CString CzvMotion_Ajin::HoldOn(int iMotIndex)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->HoldOn(iMotIndex);
}

CString CzvMotion_Ajin::HoldOff(int iMotIndex)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->HoldOff(iMotIndex);
}

CString CzvMotion_Ajin::RebootController()
{
	return zvStrSuccess;
}

CString CzvMotion_Ajin::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return ((CzvMotion_Ajin__*)m_pzvMotion_Ajin__)->SetMotionTrigger(iMotIndex, dStartPosition, dEndPosition, dTriggeringPeriod, dTriggeringWidth, iTriggerLevel);
}

CzvMotion * CreateMotionAjin()
{
	CzvMotion* p = new CzvMotion_Ajin();

	return p;
}