#include "pch.h"
#include "zvMotion_AD8158.h"

CzvMotion_AD8158::CzvMotion_AD8158()
{
	CzvMotion::Init();
	m_pzvMotion_AD8158__ = new CzvMotion_AD8158__();
}

CzvMotion_AD8158::~CzvMotion_AD8158()
{
	BoardFinish();

	delete (CzvMotion_AD8158__*)m_pzvMotion_AD8158__;
}

CString CzvMotion_AD8158::BoardInit()
{
	CString strErr = ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->BoardInit();

	if (strErr != zvStrSuccess) return strErr;

	m_iMaxUseAxis = ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetMaxUseAxis();
	if (m_iMaxUseAxis <= 0)	return _zvErr(EzvErr::NotInitializeBoard);

	strcpy_s(m_strBoardType, 255, g_strMotionBoardType[(int)EzvMotionBoardType::eMotionBoardAD8158]);

	return zvStrSuccess;
}

CString CzvMotion_AD8158::BoardFinish()
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->BoardFinish();
}

CString CzvMotion_AD8158::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->MotInit(iMotIndex, tAxisInfo);
}

CString CzvMotion_AD8158::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->SetCommandPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_AD8158::SetActPostion(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->SetActPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_AD8158::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetMotStatus(iMotIndex, iMotStatus);
}

CString CzvMotion_AD8158::GetHomeSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetHomeSensor(iMotIndex, b);
}

CString CzvMotion_AD8158::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetPLimitSensor(iMotIndex, b);
}

CString CzvMotion_AD8158::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetMLimitSensor(iMotIndex, b);
}

CString CzvMotion_AD8158::GetAlaramSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetAlaramSig(iMotIndex, b);
}

CString CzvMotion_AD8158::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetHoldOnSig(iMotIndex, b);
}

CString CzvMotion_AD8158::GetMotionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetMotionSig(iMotIndex, b);
}

CString CzvMotion_AD8158::GetInpositionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetInpositionSig(iMotIndex, b);
}

CString CzvMotion_AD8158::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetActPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_AD8158::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetCommandPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_AD8158::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->GetHomeResult(iMotIndex, eState);
}

CString CzvMotion_AD8158::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_AD8158::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_AD8158::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->AbsScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_AD8158::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->RelScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_AD8158::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->MoveContinue(iMotIndex, tMotSpeedInfo);
}

CString CzvMotion_AD8158::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->Home(iMotIndex, tAxisSpeedInfo);
}

CString CzvMotion_AD8158::Stop(int iMotIndex, double dDecTime)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->Stop(iMotIndex, dDecTime);
}

CString CzvMotion_AD8158::EStop(int iMotIndex)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->EStop(iMotIndex);
}

CString CzvMotion_AD8158::Hold(int iMotIndex, int iOnOff)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->Hold(iMotIndex, iOnOff);
}

CString CzvMotion_AD8158::HoldOn(int iMotIndex)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->HoldOn(iMotIndex);
}

CString CzvMotion_AD8158::HoldOff(int iMotIndex)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->HoldOff(iMotIndex);
}

CString CzvMotion_AD8158::RebootController()
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->RebootController();
}

CString CzvMotion_AD8158::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return ((CzvMotion_AD8158__*)m_pzvMotion_AD8158__)->SetMotionTrigger(iMotIndex, dStartPosition, dEndPosition, dTriggeringPeriod, dTriggeringWidth, iTriggerLevel);
}

CzvMotion * CreateMotionAD8158()
{
	return new CzvMotion_AD8158();
}
