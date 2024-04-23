#include "stdafx.h"
#include "zvMotion_Ajin__.h"
#include "AXL.h"
#include "AXM.h"
#include "AXHS.h"
#include "AXA.h"
#include "AXDev.h"
#include "AXHD.h"

#pragma comment(lib, "AXL.Lib")

CzvMotion_Ajin__::CzvMotion_Ajin__()
{
	Init();
}


CzvMotion_Ajin__::~CzvMotion_Ajin__()
{
	BoardFinish();
}

void CzvMotion_Ajin__::Init(void)
{
	m_iMaxUseAxis = 0;
}

CString CzvMotion_Ajin__::CheckMotIndex(int iMotIndex)
{
	if (iMotIndex < 0 || m_iMaxUseAxis <= iMotIndex) return _zvErr(EzvErr::CheckIndexRange);

	if (AxmInfoIsInvalidAxisNo(iMotIndex)) return _zvErr(EzvErr::CheckIndexRange);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::BoardInit()
{
	Init();

	int iErr = 0;

	int nMotionBoard = 0;
	const int nMaxBoardInit = 16;

	//[5] PCI_N804 검색
	DWORD dwCode = AxlOpen(7);
	if ((dwCode == AXT_RT_SUCCESS) || (dwCode == AXT_RT_OPEN_ALREADY))
	{
		DWORD dwStatus;
		dwCode = AxmInfoIsMotionModule(&dwStatus);
		if (dwCode == AXT_RT_SUCCESS)
		{
			if (dwStatus == STATUS_EXIST)
			{
				long lpAxisCount;
				AxmInfoGetAxisCount(&lpAxisCount);
				m_iMaxUseAxis += (int)lpAxisCount;
			}
		}
	}
	if (m_iMaxUseAxis <= 0)	return _zvErr(EzvErr::NotInitializeBoard);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::BoardFinish()
{
	if (m_iMaxUseAxis)
	{
		AxlClose();
	}

	m_iMaxUseAxis = 0;
	Init();

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	//기본 설정 
	int iErr = AxmMotSetAbsRelMode(iMotIndex, POS_REL_MODE);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);
	iErr = AxmMotSetProfileMode(iMotIndex, SYM_TRAPEZOIDE_MODE);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);
	iErr = AxmMotSetMoveUnitPerPulse(iMotIndex, 1, 1);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);
	iErr = AxmMotSetAccelUnit(iMotIndex, SEC);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	//모터 온 타입 설정
	iErr = AxmSignalSetServoOnLevel(iMotIndex, tAxisInfo.tHwInfo.iMotOnType);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	//센서 설정 
	iErr = AxmHomeSetSignalLevel(iMotIndex, tAxisInfo.tHwInfo.iHomeLevel);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	iErr = AxmSignalSetZphaseLevel(iMotIndex, 0); // z상 세팅 부분은 살펴 볼것.
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	iErr = AxmSignalSetServoAlarm(iMotIndex, tAxisInfo.tHwInfo.iAlarmLevel);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	int iSensorStyle = tAxisInfo.tHwInfo.iSensorStyle;

	if (iSensorStyle == S_PMH || iSensorStyle == S_PM)
	{
		iErr = AxmSignalSetLimit(iMotIndex, EMERGENCY_STOP, tAxisInfo.tHwInfo.iLimitLevel, tAxisInfo.tHwInfo.iLimitLevel);
		if (iErr) return _zvErr(EzvErr::AxisNotIntialized);
	}
	else
	{
		iErr = AxmSignalSetLimit(iMotIndex, EMERGENCY_STOP, UNUSED, UNUSED);
		if (iErr) return _zvErr(EzvErr::AxisNotIntialized);
	}

	//인포지션 설정 
	int iMotType = tAxisInfo.tHwInfo.iMotType;
	int iInpositionType = tAxisInfo.tHwInfo.iInpositionType;

	if (iMotType == SERVO)
	{
		switch (iInpositionType)
		{
		case INP_NONE:
			iErr = AxmSignalSetInpos(iMotIndex, UNUSED);
			break;
		case INP_LOW:
			iErr = AxmSignalSetInpos(iMotIndex, LOW);
			break;
		case INP_HIGH:
		default:
			iErr = AxmSignalSetInpos(iMotIndex, HIGH);
			break;
		}
	}
	else
		iErr = AxmSignalSetInpos(iMotIndex, UNUSED);

	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	//펄스 타입 설정 
	int iOutPulseType = tAxisInfo.tHwInfo.iOutPulseType;

	if (iOutPulseType == P_OUT_1PULSE)
		iErr = AxmMotSetPulseOutMethod(iMotIndex, OneHighLowHigh);
	else
		iErr = AxmMotSetPulseOutMethod(iMotIndex, TwoCwCcwHigh);

	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	//엔코더 설정.
	int iEncoderType = tAxisInfo.tHwInfo.iEncoderType;

	switch (iEncoderType)
	{
	case ENC_1:
		iErr = AxmMotSetEncInputMethod(iMotIndex, ObverseSqr1Mode);
		break;
	case ENC_2:
		iErr = AxmMotSetEncInputMethod(iMotIndex, ObverseSqr2Mode);
		break;
	case ENC_4:
		iErr = AxmMotSetEncInputMethod(iMotIndex, ObverseSqr4Mode);
		break;
	case ENC_CW:
		iErr = AxmMotSetEncInputMethod(iMotIndex, ObverseUpDownMode);
		break;
	case ENC_CMD:
		iErr = AxmMotSetEncInputMethod(iMotIndex, ObverseUpDownMode);
	default:
		break;
	}
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	double dOnePulseDist = tAxisInfo.tSwInfo.dOnePulseDist;
	if (dOnePulseDist < 0) _zvErr(EzvErr::ParameterSettingFailed);

	//홈 설정
	DWORD dwHomeDir = DIR_CCW;
	if (tAxisInfo.tSwInfo.iHomeDir)
		dwHomeDir = DIR_CW;

	int iOrgSensor = tAxisInfo.tHwInfo.iSelOrgSensor;
	DWORD dwHomeSig = HomeSensor;
	if (iOrgSensor == IN_EL_MINUS)
		dwHomeSig = NegEndLimit;
	else if (iOrgSensor == IN_EL_PLUS)
		dwHomeSig = PosEndLimit;

	DWORD dwZphas = 0;

	iErr = AxmHomeSetMethod(iMotIndex, dwHomeDir, dwHomeSig, dwZphas, 500, 0);
	if (iErr) return _zvErr(EzvErr::AxisNotIntialized);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = AxmStatusSetCmdPos(iMotIndex, dPos_pulse);
	if (iErr) return _zvErr(EzvErr::PosSettingFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::SetActPostion(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = AxmStatusSetActPos(iMotIndex, dPos_pulse);
	if (iErr) return _zvErr(EzvErr::PosSettingFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	iMotStatus = -1;
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iIOStatus = 0;
	int iState = 0;

	DWORD dwTemp;
	int iSigState = 0;

	//hold on 
	iErr = AxmSignalIsServoOn(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	//motion
	iErr = AxmStatusReadInMotion(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	//inposition
	iErr = AxmSignalGetInpos(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	iSigState = 0;

	if (dwTemp != UNUSED)
	{
		iErr = AxmSignalReadInpos(iMotIndex, &dwTemp);
		if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);
		if (dwTemp)
			iSigState = 1;
	}

	iIOStatus += iSigState << iState;
	iState++;

	//Alaram
	iErr = AxmSignalReadServoAlarm(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	//home sensor
	iErr = AxmHomeReadSignal(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	//+ limit sensor N - limit sensor
	DWORD dwPLimit, dwMLimit;
	iErr = AxmSignalReadLimit(iMotIndex, &dwPLimit, &dwMLimit);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwPLimit) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	if (dwMLimit) iSigState = 1;
	else iSigState = 0;

	iIOStatus += iSigState << iState;
	iState++;

	iMotStatus = iIOStatus;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetHomeSensor(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTemp;

	iErr = AxmHomeReadSignal(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwPLimit, dwMLimit;
	iErr = AxmSignalReadLimit(iMotIndex, &dwPLimit, &dwMLimit);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwPLimit) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwPLimit, dwMLimit;
	iErr = AxmSignalReadLimit(iMotIndex, &dwPLimit, &dwMLimit);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwMLimit) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetAlaramSig(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTemp;

	iErr = AxmSignalReadServoAlarm(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTemp;

	iErr = AxmSignalIsServoOn(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetMotionSig(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTemp;

	iErr = AxmStatusReadInMotion(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	if (dwTemp) b = TRUE;
	else b = FALSE;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetInpositionSig(int iMotIndex, BOOL & b)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTemp;

	iErr = AxmSignalGetInpos(iMotIndex, &dwTemp);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = FALSE;

	if (dwTemp != UNUSED)
	{
		iErr = AxmSignalReadInpos(iMotIndex, &dwTemp);
		if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

		if (dwTemp) b = TRUE;
	}

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = AxmStatusGetActPos(iMotIndex, &dPos_pulse);
	if (iErr) return _zvErr(EzvErr::ReadMotionPositionFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = AxmStatusGetCmdPos(iMotIndex, &dPos_pulse);
	if (iErr) return _zvErr(EzvErr::ReadMotionPositionFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwHome;

	iErr = AxmHomeGetResult(iMotIndex, &dwHome);
	if (iErr) return _zvErr(EzvErr::ReadHomeResultFailed);

	if (dwHome == HOME_SUCCESS)
		eState = EzvHomeState::eHomeSuccess;
	else if (dwHome == HOME_SEARCHING)
		eState = EzvHomeState::eHomeSearching;
	else
		eState = EzvHomeState::eHomeFail;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dStartVel = tMotSpeedInfo.dVs;
	double dMaxVel = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	iErr = AxmMotSetProfileMode(iMotIndex, SYM_TRAPEZOIDE_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetAbsRelMode(iMotIndex, POS_ABS_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetMinVel(iMotIndex, dStartVel);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMoveStartPos(iMotIndex, dPos_pulse, dMaxVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dStartVel = tMotSpeedInfo.dVs;
	double dMaxVel = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	iErr = AxmMotSetProfileMode(iMotIndex, SYM_TRAPEZOIDE_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetAbsRelMode(iMotIndex, POS_REL_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetMinVel(iMotIndex, dStartVel);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMoveStartPos(iMotIndex, dPos_pulse, dMaxVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);


	return zvStrSuccess;
}

CString CzvMotion_Ajin__::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dStartVel = tMotSpeedInfo.dVs;
	double dMaxVel = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	iErr = AxmMotSetProfileMode(iMotIndex, SYM_S_CURVE_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetAbsRelMode(iMotIndex, POS_ABS_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetMinVel(iMotIndex, dStartVel);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMoveStartPos(iMotIndex, dPos_pulse, dMaxVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dStartVel = tMotSpeedInfo.dVs;
	double dMaxVel = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	iErr = AxmMotSetProfileMode(iMotIndex, SYM_S_CURVE_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetAbsRelMode(iMotIndex, POS_REL_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetMinVel(iMotIndex, dStartVel);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMoveStartPos(iMotIndex, dPos_pulse, dMaxVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dStartVel = tMotSpeedInfo.dVs;
	double dMaxVel = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	iErr = AxmMotSetProfileMode(iMotIndex, SYM_TRAPEZOIDE_MODE);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMotSetMinVel(iMotIndex, dStartVel);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmMoveVel(iMotIndex, dMaxVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dFirstVel = tAxisSpeedInfo.dHomeSpd[0];
	double d2ndVel = tAxisSpeedInfo.dHomeSpd[1];
	double d3rdVel = tAxisSpeedInfo.dHomeSpd[2];
	double dLastVel = tAxisSpeedInfo.dHomeSpd[3];
	double dAcc = tAxisSpeedInfo.dHomeAcc;
	double dDec = tAxisSpeedInfo.dHomeDec;

	iErr = AxmHomeSetVel(iMotIndex, dFirstVel, d2ndVel, d3rdVel, dLastVel, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::ParameterSettingFailed);

	iErr = AxmHomeSetStart(iMotIndex);
	if (iErr) return _zvErr(EzvErr::AxisHomeFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::Stop(int iMotIndex, double dDecTime)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = AxmMoveStop(iMotIndex, dDecTime);
	if (iErr) return _zvErr(EzvErr::MotionStopFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::EStop(int iMotIndex)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = AxmMoveEStop(iMotIndex);
	if (iErr) return _zvErr(EzvErr::MotionStopFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::Hold(int iMotIndex, int iOnOff)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = AxmSignalServoOn(iMotIndex, iOnOff);
	if (iErr) return _zvErr(EzvErr::HoldOnOffFailed);

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::HoldOn(int iMotIndex)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	strErr = Hold(iMotIndex, TRUE);
	if (strErr != zvStrSuccess) return strErr;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::HoldOff(int iMotIndex)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	strErr = Hold(iMotIndex, FALSE);
	if (strErr != zvStrSuccess) return strErr;

	return zvStrSuccess;
}

CString CzvMotion_Ajin__::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	DWORD dwTrigLevel = LOW;
	if(iTriggerLevel > 0) dwTrigLevel = HIGH;

	//++ 지정 축에 트리거 펄스출력 시간 및 트리거 출력 레벨, 트리거 출력방법을 설정합니다.
	DWORD dwRetCode = AxmTriggerSetTimeLevel(iMotIndex, dTriggeringWidth, dwTrigLevel, ACTUAL, DISABLE);
	if (dwRetCode != AXT_RT_SUCCESS) 
		return _zvErr(EzvErr::TriggerSettingFailed);
	
	//++ AXL라이브러리의 인터럽트 발생을 금지합니다.
	AxlInterruptDisable();
	//++ 지정한 축에 인터럽트 발생을 금지합니다.
	AxmInterruptSetAxisEnable(iMotIndex, DISABLE);

	dwRetCode = AxmTriggerSetBlock(iMotIndex, dStartPosition, dEndPosition, dTriggeringPeriod);
	if (dwRetCode != AXT_RT_SUCCESS) 
		return _zvErr(EzvErr::TriggerSettingFailed);

	return zvStrSuccess;
}
