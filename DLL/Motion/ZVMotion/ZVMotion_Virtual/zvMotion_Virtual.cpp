#include "pch.h"
#include "zvMotion_Virtual.h"


CzvMotion_Virtual::CzvMotion_Virtual()
{
	m_pVoidMotion = new CzvMotion_Virtual__();
}

CzvMotion_Virtual::~CzvMotion_Virtual()
{
	delete (CzvMotion_Virtual__*)m_pVoidMotion;
}

//// private

//// public
CString CzvMotion_Virtual::BoardInit()
{
	CString strErr = ((CzvMotion_Virtual__*)m_pVoidMotion)->BoardInit();

	if (strErr != zvStrSuccess) return strErr;

	m_iMaxUseAxis = ((CzvMotion_Virtual__*)m_pVoidMotion)->GetMaxUseAxis();

	if (m_iMaxUseAxis <= 0)	return _zvErr(EzvErr::NotInitializeBoard);

	strcpy_s(m_strBoardType, 255, g_strMotionBoardType[(int)EzvMotionBoardType::eMotionBoardVirtual]);

	return zvStrSuccess;
}

CString CzvMotion_Virtual::BoardFinish()
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->BoardFinish();
}

CString CzvMotion_Virtual::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->MotInit(iMotIndex, tAxisInfo);
}

CString CzvMotion_Virtual::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->SetCommandPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Virtual::SetActPostion(int iMotIndex, double dPos_pulse)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->SetActPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Virtual::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetMotStatus(iMotIndex, iMotStatus);
}

CString CzvMotion_Virtual::GetHomeSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetHomeSensor(iMotIndex, b);
}

CString CzvMotion_Virtual::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetPLimitSensor(iMotIndex, b);
}

CString CzvMotion_Virtual::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetMLimitSensor(iMotIndex, b);
}

CString CzvMotion_Virtual::GetAlaramSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetAlaramSig(iMotIndex, b);
}

CString CzvMotion_Virtual::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetHoldOnSig(iMotIndex, b);
}

CString CzvMotion_Virtual::GetMotionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetMotionSig(iMotIndex, b);
}

CString CzvMotion_Virtual::GetInpositionSig(int iMotIndex, BOOL & b)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetInpositionSig(iMotIndex, b);
}

CString CzvMotion_Virtual::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetActPosition(iMotIndex, dPos_pulse);
}

CString CzvMotion_Virtual::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetCommandPostion(iMotIndex, dPos_pulse);
}

CString CzvMotion_Virtual::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->GetHomeResult(iMotIndex, eState);
}

CString CzvMotion_Virtual::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Virtual::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Virtual::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->AbsScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Virtual::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->RelScurveMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Virtual::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->MoveContinue(iMotIndex, tMotSpeedInfo);
}

CString CzvMotion_Virtual::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->Home(iMotIndex, tAxisSpeedInfo);
}

CString CzvMotion_Virtual::Stop(int iMotIndex, double dDecTime)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->Stop(iMotIndex, dDecTime);
}

CString CzvMotion_Virtual::EStop(int iMotIndex)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->EStop(iMotIndex);
}

CString CzvMotion_Virtual::Hold(int iMotIndex, int iOnOff)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->Hold(iMotIndex, iOnOff);
}

CString CzvMotion_Virtual::HoldOn(int iMotIndex)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->HoldOn(iMotIndex);
}

CString CzvMotion_Virtual::HoldOff(int iMotIndex)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->HoldOff(iMotIndex);
}

CString CzvMotion_Virtual::RebootController()
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->RebootController();
}

CString CzvMotion_Virtual::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return ((CzvMotion_Virtual__*)m_pVoidMotion)->SetMotionTrigger(iMotIndex, dStartPosition, dEndPosition, dTriggeringPeriod, dTriggeringWidth, iTriggerLevel);
}

CzvMotion * CreateMotionVirtual()
{
	CzvMotion* pMotion = new CzvMotion_Virtual();

	return pMotion;
}
