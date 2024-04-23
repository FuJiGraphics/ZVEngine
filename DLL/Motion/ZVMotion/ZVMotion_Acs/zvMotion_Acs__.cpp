#include "stdafx.h"
#include "zvMotion_Acs__.h"




CzvMotion_Acs__::CzvMotion_Acs__()
{
	Init();
}

CzvMotion_Acs__::~CzvMotion_Acs__()
{
	BoardFinish();
}

void CzvMotion_Acs__::Init(void)
{
	m_iMaxUseAxis = 0;
}

CString CzvMotion_Acs__::CheckMotIndex(int iMotIndex)
{
	if (iMotIndex < 0 || m_iMaxUseAxis <= iMotIndex) return _zvErr(EzvErr::CheckIndexRange);

	return zvStrSuccess;
}

CString CzvMotion_Acs__::BoardInit()
{
	m_tMotComConfig.handle = (HANDLE)-1;

	char* pchAddress;
#ifdef USE_ACS_SYMUL
		pchAddress = "127.0.0.1";
#else
		pchAddress = "10.0.0.100";
#endif

	m_tMotComConfig.handle = acsc_OpenCommEthernetTCP(pchAddress, 701);

	double dMaxIndex;

	if (!acsc_GetAxesCount(m_tMotComConfig.handle, &dMaxIndex, NULL))
	{
		return _zvErr(EzvErr::NotInitializeBoard);
	}

	m_iMaxUseAxis = (int)dMaxIndex;

	//

	return zvStrSuccess;
}

CString CzvMotion_Acs__::BoardFinish()
{
	if (m_iMaxUseAxis)
	{
		acsc_CloseComm(m_tMotComConfig.handle);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	//기본 설정 
		//기본 설정들은 acs의 버퍼에 저장이 된다.
	int iLevel = tAxisInfo.tHwInfo.iLimitLevel ? 0 : 1;

	//리밋 레벨 세팅
	int iState = 0;
	if (iLevel == L_LOW)
	{
		iState = (ACSC_SAFETY_RL | ACSC_SAFETY_LL);
	}

	if (!acsc_SetSafetyInputPortInv(m_tMotComConfig.handle, iMotIndex, 	iState, NULL))
	{
		return _zvErr(EzvErr::AxisNotIntialized);
	}

	double dOnePulseDist = tAxisInfo.tSwInfo.dOnePulseDist;
	if (dOnePulseDist < 0) _zvErr(EzvErr::ParameterSettingFailed);

	return zvStrSuccess;
}

CString CzvMotion_Acs__::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (!acsc_SetRPosition(m_tMotComConfig.handle, iMotIndex, dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::PosSettingFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::SetActPostion(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (!acsc_SetFPosition(m_tMotComConfig.handle, iMotIndex, dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::PosSettingFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	BOOL b = FALSE;

	iMotStatus = 0;
	int iState = 0;
	int iTemp = 0;

	//서보 온
	strErr = GetHoldOnSig(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if(b) iTemp += 1 << iState;
	iState++;

	//in motion
	strErr = GetMotionSig(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if (b) iTemp += 1 << iState;
	iState++;

	//인 포지션 
	strErr = GetInpositionSig(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if (b) iTemp += 1 << iState;
	iState++;
	
	//알람
	strErr = GetAlaramSig(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if (b) iTemp += 1 << iState;
	iState++;
	
	//홈
	strErr = GetHomeSensor(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if (b) iTemp += 1 << iState;
	iState++;
	
	//+리밋
	strErr = GetPLimitSensor(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;

	if (b) iTemp += 1 << iState;
	iState++;
	
	//-리밋
	strErr = GetMLimitSensor(iMotIndex, b);
	if (strErr != zvStrSuccess) return strErr;
	
	if (b) iTemp += 1 << iState;
	iState++;

	iMotStatus = iTemp;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetHomeSensor(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;


	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;

	int iFault = 0; //알람 상태 등등 
	acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);
	
	if (iFault & ACSC_SAFETY_RL)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;

	int iFault = 0; //알람 상태 등등 
	acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);

	if (iFault & ACSC_SAFETY_LL)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetAlaramSig(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;

	int iFault = 0; //알람 상태 등등 
	acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);
	if (iFault & ACSC_SAFETY_DRIVE)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;

	int iACSMotionState = 0;

	acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
	if (iACSMotionState & ACSC_MST_ENABLE)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetMotionSig(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;

	int iACSMotionState = 0;

	acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
	if (iACSMotionState & ACSC_MST_MOVE)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetInpositionSig(int iMotIndex, BOOL & b)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	b = FALSE;
	
	int iACSMotionState = 0;

	acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
	if (iACSMotionState & ACSC_MST_INPOS)
		b = TRUE;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	dPos_pulse = 0.;

	if (!acsc_GetFPosition(m_tMotComConfig.handle, iMotIndex, &dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::ReadMotionPositionFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	dPos_pulse = 0.;

	if (!acsc_GetRPosition(m_tMotComConfig.handle, iMotIndex, &dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::ReadMotionPositionFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	//<< 이거는 버퍼의 정보를 읽어야 하는 부분이므로 acs 세팅하신 분께 여쭤보고서 진행을 할 것
	int HomeFlag[32]; //현재 드라이버에 설정된 홈 갯수.

	for (int i = 0; i < 32; i++)
	{
		HomeFlag[i] = 0;
	}

	if (!acsc_ReadInteger(m_tMotComConfig.handle, ACSC_NONE, "HomeFlag", 0, 31, ACSC_NONE, ACSC_NONE, HomeFlag, NULL))
	{
		eState = EzvHomeState::eHomeFail;
		return _zvErr(EzvErr::ReadHomeResultFailed);
	}

	if (HomeFlag[iMotIndex] == 1)
		eState = EzvHomeState::eHomeSuccess;
	else 
		eState = EzvHomeState::eHomeSearching;

	return zvStrSuccess;
}

CString CzvMotion_Acs__::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dVm =  tMotSpeedInfo.dVm;
	double dAccTime =  tMotSpeedInfo.dAcc;
	double dDecTime =  tMotSpeedInfo.dDec;
	
	if (dAccTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);
	if (dDecTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);

	double dAcc = dVm / dAccTime;
	double dDec = dVm / dDecTime;

	if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAcc, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dDec, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}


	if (!acsc_ToPoint(m_tMotComConfig.handle, 0, iMotIndex, dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::MovingAxisFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dVm = tMotSpeedInfo.dVm;
	double dAccTime = tMotSpeedInfo.dAcc;
	double dDecTime = tMotSpeedInfo.dDec;

	if(dAccTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);
	if (dDecTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);

	double dAcc = dVm / dAccTime;
	double dDec = dVm / dDecTime;

	if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	// example of the waiting call of acsc_SetAcceleration
	if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAcc, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	// example of the waiting call of acsc_SetDeceleration
	if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dDec, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	if (!acsc_ToPoint(m_tMotComConfig.handle, ACSC_AMF_RELATIVE, iMotIndex, dPos_pulse, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}
	
	return zvStrSuccess;
}

CString CzvMotion_Acs__::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	//<< 이거는 설정된 저크 값에 따라서 구동이 되는 것이므로.... 이건 세팅하는 사람과 이야기를 진행을 해야된다.
	//<< 여기에 저크값을 재설정을 할 수 있게 해주면 된다.



	return AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs__::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	//<< 이거는 설정된 저크 값에 따라서 구동이 되는 것이므로.... 이건 세팅하는 사람과 이야기를 진행을 해야된다.
	//<< 여기에 저크값을 재설정을 할 수 있게 해주면 된다.

	return RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
}

CString CzvMotion_Acs__::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	double dVm = tMotSpeedInfo.dVm;
	double dAccTime = tMotSpeedInfo.dAcc;
	double dDecTime = tMotSpeedInfo.dDec;

	if (dAccTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);
	if (dDecTime <= 0) return _zvErr(EzvErr::ParameterSettingFailed);

	double dAcc = dVm / dAccTime;
	double dDec = dVm / dDecTime;

	if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAccTime, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dAccTime, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	int iDir = ACSC_POSITIVE_DIRECTION;
	if (dVm < 0) iDir = ACSC_NEGATIVE_DIRECTION;

	if (!acsc_Jog(m_tMotComConfig.handle, 0, iMotIndex, iDir, NULL))
	{
		return _zvErr(EzvErr::ParameterSettingFailed);
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (!acsc_RunBuffer(m_tMotComConfig.handle, iMotIndex, NULL, NULL))
	{
		return _zvErr(EzvErr::AxisHomeFailed);
	}


	int iLibVersion = acsc_GetLibraryVersion();
		
	// 컨트롤러 buffer 실행 딜레이 추가.
	Sleep(100);

	return zvStrSuccess;
}

CString CzvMotion_Acs__::Stop(int iMotIndex, double dDecTime)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (!acsc_Halt(m_tMotComConfig.handle, iMotIndex, NULL))
	{
		return _zvErr(EzvErr::MotionStopFailed);
	}

	//<<버퍼 정지 명령을 내려줄것. (특히 홈 버퍼 같은 경우 안하면 계속 동작하는 경우가 생기므로 주의

	return zvStrSuccess;
}

CString CzvMotion_Acs__::EStop(int iMotIndex)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (!acsc_Kill(m_tMotComConfig.handle, iMotIndex, NULL))
	{
		return _zvErr(EzvErr::MotionStopFailed);
	}

	//<<버퍼 정지 명령을 내려줄것. (특히 홈 버퍼 같은 경우 안하면 계속 동작하는 경우가 생기므로 주의

	return zvStrSuccess;
}

CString CzvMotion_Acs__::Hold(int iMotIndex, int iOnOff)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	if (iOnOff)
	{
		if (!acsc_Enable(m_tMotComConfig.handle, iMotIndex, NULL))
		{
			return _zvErr(EzvErr::HoldOnOffFailed);
		}
	}
	else
	{
		if (!acsc_Disable(m_tMotComConfig.handle, iMotIndex, NULL))
		{
			return _zvErr(EzvErr::HoldOnOffFailed);
		}
	}

	return zvStrSuccess;
}

CString CzvMotion_Acs__::HoldOn(int iMotIndex)
{
	return Hold(iMotIndex,TRUE);
}

CString CzvMotion_Acs__::HoldOff(int iMotIndex)
{
	return Hold(iMotIndex, FALSE);
}

CString CzvMotion_Acs__::RebootController()
{
	if(!acsc_ControllerReboot(m_tMotComConfig.handle, 100000))
		return _zvErr(EzvErr::FailedToRebootController);

	BoardFinish();
	BoardInit();

	return zvStrSuccess;
}

CString CzvMotion_Acs__::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{

	int iret = acsc_PegInc(m_tMotComConfig.handle,
		ACSC_AMF_SYNCHRONOUS, // synchronous PEG
		iMotIndex,			// 발생 모터 축
		dTriggeringWidth,	// 단위 : ms 
		dStartPosition,		// 시작 위치
		dTriggeringPeriod,	// 간격
		dEndPosition,		// 종료 위치
		ACSC_NONE,			// no time-based pulse generation
		ACSC_NONE,
		NULL // waiting call
	);

	if (!iret)
	{
		return _zvErr(EzvErr::FailedToPEG);
	}
	
	return zvStrSuccess;
}
