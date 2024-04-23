#include "pch.h"
#include "zvMotion_AD8158__.h"


CzvMotion_AD8158__::CzvMotion_AD8158__()
{
	Init();
}

CzvMotion_AD8158__::~CzvMotion_AD8158__()
{
	BoardFinish();
}

//// private
void CzvMotion_AD8158__::Init(void)
{
	m_iMaxUseAxis = 0;

	ZeroMemory(m_rgeHomeState, sizeof(EzvHomeState) * 100);
}


//// public
CString CzvMotion_AD8158__::CheckMotIndex(int iMotIndex)
{
	if (iMotIndex < 0 || m_iMaxUseAxis <= iMotIndex) return _zvErr(EzvErr::CheckIndexRange);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::BoardInit()
{
	U16	CardID_InBit;

	int iErr = _8158_initial(&CardID_InBit, 1);

	if (iErr == 0)
	{
		m_iMaxUseAxis = 8;
	}
	else
	{
		return _zvErr(EzvErr::NotInitializeBoard);
	}

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::BoardFinish()
{
	//모터축들을 풀어주도록 설정(Servo Off)
	if (m_iMaxUseAxis)
	{
		_8158_close();
	}

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::MotInit(int iMotIndex, TzvAxisInfo tAxisInfo)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	TzvMotHWInfo* ptMotHWInfo = &tAxisInfo.tHwInfo;;
	TzvMotSWInfo* ptMotSWInfo = &tAxisInfo.tSwInfo;

	// 홈 설정 
	_8158_set_home_config(iMotIndex, 0, ptMotHWInfo->iHomeLevel, 0, 0, 1);

	// 센서 설정
	_8158_set_limit_logic(iMotIndex, ptMotHWInfo->iLimitLevel);

	// 알람 설정 
	_8158_set_alm(iMotIndex, ptMotHWInfo->iAlarmLevel, ptMotSWInfo->iAlarmMode);
	_8158_set_sd(iMotIndex, ptMotHWInfo->iAlarmLevel, 0, 0);

	// 인포지션 설정 
	if (ptMotHWInfo->iMotType == SERVO)
	{
		_8158_set_inp(iMotIndex, 1, L_LOW);
	}
	else
	{
		_8158_set_inp(iMotIndex, 0, L_LOW);
	}

	// 펄스 설정 
	_8158_set_pls_outmode(iMotIndex, 1);

	// 엔코더 섫정 
	if (ptMotHWInfo->iEncoderType <= ENC_CW)
	{
		_8158_set_pls_iptmode(iMotIndex, 1, 0);
		_8158_set_feedback_src(iMotIndex, 0);
	}
	else
	{
		_8158_set_pls_iptmode(iMotIndex, 0, 0);
		_8158_set_feedback_src(iMotIndex, 1);
	}

	// 홀드 온 레벨 설정

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::SetCommandPosition(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	I16 iRet = _8158_set_command(iMotIndex, (I32)dPos_pulse);
	if (iRet) return _zvErr(EzvErr::PosSettingFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::SetActPostion(int iMotIndex, double dPos_pulse)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	I16 iRet = _8158_set_position(iMotIndex, dPos_pulse);
	if (iRet) return _zvErr(EzvErr::PosSettingFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetMotStatus(int iMotIndex, int & iMotStatus)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iMotStatus = 0;

	BOOL b = FALSE;

	int iState = 0;
	// hold on
	GetHoldOnSig(iMotIndex, b);

	iState = b;
	iMotStatus |= b;

	// motion
	GetMotionSig(iMotIndex, b);

	iState = b;
	iState = iState << 1;
	iMotStatus += iState;

	// inposition
	GetInpositionSig(iMotIndex, b);

	iState = b;
	iState = iState << 2;
	iMotStatus += iState;

	// alarm
	GetAlaramSig(iMotIndex, b);

	iState = b;
	iState = iState << 3;
	iMotStatus += iState;

	// home sensor
	GetHomeSensor(iMotIndex, b);

	iState = b;
	iState = iState << 4;
	iMotStatus += iState;

	// + limit
	GetPLimitSensor(iMotIndex, b);

	iState = b;
	iState = iState << 5;
	iMotStatus += iState;

	// - limit
	GetMLimitSensor(iMotIndex, b);

	iState = b;
	iState = iState << 6;
	iMotStatus += iState;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetHomeSensor(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b000000010000;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetPLimitSensor(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b000000000100;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetMLimitSensor(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b000000001000;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetAlaramSig(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b000000000010;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetHoldOnSig(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b010000000000;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetMotionSig(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b000000100000;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetInpositionSig(int iMotIndex, BOOL & b)
{
	b = FALSE;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	U16 u16IOStatust = 0;

	int iErr = _8158_get_io_status(iMotIndex, &u16IOStatust);
	if (iErr) return _zvErr(EzvErr::ReadMotionSignalFailed);

	b = u16IOStatust & 0b001000000000;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetActPosition(int iMotIndex, double & dPos_pulse)
{
	F64 Pos;

	_8158_get_position(iMotIndex, &Pos);
	dPos_pulse = Pos;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetCommandPostion(int iMotIndex, double & dPos_pulse)
{
	I32 Cmd;

	_8158_get_command(iMotIndex, &Cmd);
	dPos_pulse = Cmd;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::GetHomeResult(int iMotIndex, EzvHomeState & eState)
{
	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	eState = m_rgeHomeState[iMotIndex];

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	double dVs = tMotSpeedInfo.dVs;
	double dVm = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = _8158_start_ta_move(iMotIndex, dPos_pulse, dVs, dVm, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	double dVs = tMotSpeedInfo.dVs;
	double dVm = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = _8158_start_tr_move(iMotIndex, dPos_pulse, dVs, dVm, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	double dVs = tMotSpeedInfo.dVs;
	double dVm = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = _8158_start_ta_move(iMotIndex, dPos_pulse, dVs, dVm, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
{
	double dVs = tMotSpeedInfo.dVs;
	double dVm = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = _8158_start_tr_move(iMotIndex, dPos_pulse, dVs, dVm, dAcc, dDec);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
{
	double dVs = tMotSpeedInfo.dVs;
	double dVm = tMotSpeedInfo.dVm;
	double dAcc = tMotSpeedInfo.dAcc;
	double dDec = tMotSpeedInfo.dDec;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	int iErr = _8158_tv_move(iMotIndex, dVs, dVm, dAcc);
	if (iErr) return _zvErr(EzvErr::MovingAxisFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	m_rgeHomeState[iMotIndex] = EzvHomeState::eHomeSearching;

	double dFirstVel = tAxisSpeedInfo.dHomeSpd[0];
	double d2ndVel = tAxisSpeedInfo.dHomeSpd[1];
	double d3rdVel = tAxisSpeedInfo.dHomeSpd[2];
	double dLastVel = tAxisSpeedInfo.dHomeSpd[3];
	double dAcc = tAxisSpeedInfo.dHomeAcc;
	double dDec = tAxisSpeedInfo.dHomeDec;

	iErr = _8158_home_search(iMotIndex, 0, dFirstVel, dAcc, 0);
	if (iErr)
	{
		m_rgeHomeState[iMotIndex] = EzvHomeState::eHomeFail;

		return _zvErr(EzvErr::AxisHomeFailed);
	}

	m_rgeHomeState[iMotIndex] = EzvHomeState::eHomeSuccess;

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::Stop(int iMotIndex, double dDecTime)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = _8158_sd_stop(iMotIndex, dDecTime);
	if (iErr) return _zvErr(EzvErr::MotionStopFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::EStop(int iMotIndex)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = _8158_emg_stop(iMotIndex);
	if (iErr) return _zvErr(EzvErr::MotionStopFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::Hold(int iMotIndex, int iOnOff)
{
	int iErr = 0;

	CString strErr = CheckMotIndex(iMotIndex);
	if (strErr != zvStrSuccess) return strErr;

	iErr = _8158_set_servo(iMotIndex, iOnOff^1);		//8134와 반대로되어있다.
	if (iErr) return _zvErr(EzvErr::HoldOnOffFailed);

	return zvStrSuccess;
}

CString CzvMotion_AD8158__::HoldOn(int iMotIndex)
{
	return Hold(iMotIndex, TRUE);
}

CString CzvMotion_AD8158__::HoldOff(int iMotIndex)
{
	return Hold(iMotIndex, FALSE);
}

CString CzvMotion_AD8158__::RebootController()
{
	return zvStrSuccess;
}

CString CzvMotion_AD8158__::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
{
	return zvStrSuccess;
}
