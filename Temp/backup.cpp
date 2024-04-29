#include "ZVMotion_ACS.h"
#include "ZVAcsc_Controller.h"

namespace ZVLab {


	// ������, �Ҹ���



	bool CzvMotion_ACS::BoardFinish()
	{
		if (m_iMaxUseAxis)
		{
			acsc_CloseComm(m_tMotComConfig.handle);
		}
		FZLOG_INFO("CZVMotion_ACS BoardFinish() Done");
		return (true);
	}

	void CzvMotion_ACS::ActivateBootMotor(int iMotIndex, const TzvAxisInfo& tAxisInfo)
	{
		if (iMotIndex > m_vAxisData.size() && iMotIndex < 0)
		{
			ZVLOG_FAILED(false, "FAILED: iMotIndex is less than 0 or greater than {0}", m_vAxisData.size());
		}

		int iLevel = tAxisInfo.tHwInfo.iLimitLevel ? 0 : 1;
		//���� ���� ����
		int iState = 0;
		if (iLevel == L_LOW)
		{
			iState = (ACSC_SAFETY_RL | ACSC_SAFETY_LL);
		}

		CzvAcsc_Controller::SetSafetyInputPortInv(m_hHandle, iMotIndex, iState);

		double dOnePulseDist = tAxisInfo.tSwInfo.dOnePulseDist;
		ZVLOG_FAILED((dOnePulseDist > 0),
					 "FAILED: dOnePulseDist is not greater than 0 = {0}",
					 dOnePulseDist);
	}

	bool CzvMotion_ACS::SetCommandPosition(int iMotIndex, double dPos_pulse)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (!acsc_SetRPosition(m_tMotComConfig.handle, iMotIndex, dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::SetActPostion(int iMotIndex, double dPos_pulse)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (!acsc_SetFPosition(m_tMotComConfig.handle, iMotIndex, dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::GetMotStatus(int iMotIndex, int & iMotStatus)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		BOOL b = FALSE;

		iMotStatus = 0;
		int iState = 0;
		int iTemp = 0;

		//���� ��
		result = GetHoldOnSig(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//in motion
		result = GetMotionSig(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//�� ������ 
		result = GetInpositionSig(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//�˶�
		result = GetAlaramSig(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//Ȩ
		result = GetHomeSensor(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//+����
		result = GetPLimitSensor(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		//-����
		result = GetMLimitSensor(iMotIndex, b);
		if (result != (true)) return result;

		if (b) iTemp += 1 << iState;
		iState++;

		iMotStatus = iTemp;

		return (true);
	}

	bool CzvMotion_ACS::GetHomeSensor(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;


		return (true);
	}

	bool CzvMotion_ACS::GetPLimitSensor(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iFault = 0; //�˶� ���� ��� 
		acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);

		if (iFault & ACSC_SAFETY_RL)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetMLimitSensor(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iFault = 0; //�˶� ���� ��� 
		acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);

		if (iFault & ACSC_SAFETY_LL)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetAlaramSig(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iFault = 0; //�˶� ���� ��� 
		acsc_GetFault(m_tMotComConfig.handle, iMotIndex, &iFault, NULL);
		if (iFault & ACSC_SAFETY_DRIVE)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetHoldOnSig(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iACSMotionState = 0;

		acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
		if (iACSMotionState & ACSC_MST_ENABLE)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetMotionSig(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iACSMotionState = 0;

		acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
		if (iACSMotionState & ACSC_MST_MOVE)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetInpositionSig(int iMotIndex, bool b)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		b = FALSE;

		int iACSMotionState = 0;

		acsc_GetMotorState(m_tMotComConfig.handle, iMotIndex, &iACSMotionState, NULL);
		if (iACSMotionState & ACSC_MST_INPOS)
			b = TRUE;

		return (true);
	}

	bool CzvMotion_ACS::GetActPosition(int iMotIndex, double & dPos_pulse)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		dPos_pulse = 0.;

		if (!acsc_GetFPosition(m_tMotComConfig.handle, iMotIndex, &dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::GetCommandPostion(int iMotIndex, double & dPos_pulse)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		dPos_pulse = 0.;

		if (!acsc_GetRPosition(m_tMotComConfig.handle, iMotIndex, &dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::GetHomeResult(int iMotIndex, EzvHomeState & eState)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		//<< �̰Ŵ� ������ ������ �о�� �ϴ� �κ��̹Ƿ� acs �����Ͻ� �в� ���庸�� ������ �� ��
		int HomeFlag[32]; //���� ����̹��� ������ Ȩ ����.

		for (int i = 0; i < 32; i++)
		{
			HomeFlag[i] = 0;
		}

		if (!acsc_ReadInteger(m_tMotComConfig.handle, ACSC_NONE, "HomeFlag", 0, 31, ACSC_NONE, ACSC_NONE, HomeFlag, NULL))
		{
			eState = EzvHomeState::eHomeFail;
			return (false);
		}

		if (HomeFlag[iMotIndex] == 1)
			eState = EzvHomeState::eHomeSuccess;
		else
			eState = EzvHomeState::eHomeSearching;

		return (true);
	}

	bool CzvMotion_ACS::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		double dVm = tMotSpeedInfo.dVm;
		double dAccTime = tMotSpeedInfo.dAcc;
		double dDecTime = tMotSpeedInfo.dDec;

		if (dAccTime <= 0) return (false);
		if (dDecTime <= 0) return (false);

		double dAcc = dVm / dAccTime;
		double dDec = dVm / dDecTime;

		if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
		{
			return (false);
		}

		if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAcc, NULL))
		{
			return (false);
		}

		if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dDec, NULL))
		{
			return (false);
		}


		if (!acsc_ToPoint(m_tMotComConfig.handle, 0, iMotIndex, dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		double dVm = tMotSpeedInfo.dVm;
		double dAccTime = tMotSpeedInfo.dAcc;
		double dDecTime = tMotSpeedInfo.dDec;

		if (dAccTime <= 0) return (false);
		if (dDecTime <= 0) return (false);

		double dAcc = dVm / dAccTime;
		double dDec = dVm / dDecTime;

		if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
		{
			return (false);
		}

		// example of the waiting call of acsc_SetAcceleration
		if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAcc, NULL))
		{
			return (false);
		}

		// example of the waiting call of acsc_SetDeceleration
		if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dDec, NULL))
		{
			return (false);
		}

		if (!acsc_ToPoint(m_tMotComConfig.handle, ACSC_AMF_RELATIVE, iMotIndex, dPos_pulse, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		//<< �̰Ŵ� ������ ��ũ ���� ���� ������ �Ǵ� ���̹Ƿ�.... �̰� �����ϴ� ����� �̾߱⸦ ������ �ؾߵȴ�.
		//<< ���⿡ ��ũ���� �缳���� �� �� �ְ� ���ָ� �ȴ�.



		return AbsMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
	}

	bool CzvMotion_ACS::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		//<< �̰Ŵ� ������ ��ũ ���� ���� ������ �Ǵ� ���̹Ƿ�.... �̰� �����ϴ� ����� �̾߱⸦ ������ �ؾߵȴ�.
		//<< ���⿡ ��ũ���� �缳���� �� �� �ְ� ���ָ� �ȴ�.

		return RelMove(iMotIndex, dPos_pulse, tMotSpeedInfo);
	}

	bool CzvMotion_ACS::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		double dVm = tMotSpeedInfo.dVm;
		double dAccTime = tMotSpeedInfo.dAcc;
		double dDecTime = tMotSpeedInfo.dDec;

		if (dAccTime <= 0) return (false);
		if (dDecTime <= 0) return (false);

		double dAcc = dVm / dAccTime;
		double dDec = dVm / dDecTime;

		if (!acsc_SetVelocity(m_tMotComConfig.handle, iMotIndex, dVm, NULL))
		{
			return (false);
		}

		if (!acsc_SetAcceleration(m_tMotComConfig.handle, iMotIndex, dAccTime, NULL))
		{
			return (false);
		}

		if (!acsc_SetDeceleration(m_tMotComConfig.handle, iMotIndex, dAccTime, NULL))
		{
			return (false);
		}

		int iDir = ACSC_POSITIVE_DIRECTION;
		if (dVm < 0) iDir = ACSC_NEGATIVE_DIRECTION;

		if (!acsc_Jog(m_tMotComConfig.handle, 0, iMotIndex, iDir, NULL))
		{
			return (false);
		}

		return (true);
	}

	bool CzvMotion_ACS::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (!acsc_RunBuffer(m_tMotComConfig.handle, iMotIndex, NULL, NULL))
		{
			return (false);
		}


		int iLibVersion = acsc_GetLibraryVersion();

		// ��Ʈ�ѷ� buffer ���� ������ �߰�.
		Sleep(100);

		return (true);
	}

	bool CzvMotion_ACS::Stop(int iMotIndex, double dDecTime)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (!acsc_Halt(m_tMotComConfig.handle, iMotIndex, NULL))
		{
			return (false);
		}

		//<<���� ���� ����� �����ٰ�. (Ư�� Ȩ ���� ���� ��� ���ϸ� ��� �����ϴ� ��찡 ����Ƿ� ����

		return (true);
	}

	bool CzvMotion_ACS::EStop(int iMotIndex)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (!acsc_Kill(m_tMotComConfig.handle, iMotIndex, NULL))
		{
			return (false);
		}

		//<<���� ���� ����� �����ٰ�. (Ư�� Ȩ ���� ���� ��� ���ϸ� ��� �����ϴ� ��찡 ����Ƿ� ����

		return (true);
	}

	bool CzvMotion_ACS::Hold(int iMotIndex, int iOnOff)
	{
		bool result = CheckMotIndex(iMotIndex);
		if (result != (true)) return result;

		if (iOnOff)
		{
			if (!acsc_Enable(m_tMotComConfig.handle, iMotIndex, NULL))
			{
				return (false);
			}
		}
		else
		{
			if (!acsc_Disable(m_tMotComConfig.handle, iMotIndex, NULL))
			{
				return (false);
			}
		}

		return (true);
	}

	bool CzvMotion_ACS::HoldOn(int iMotIndex)
	{
		return Hold(iMotIndex, TRUE);
	}

	bool CzvMotion_ACS::HoldOff(int iMotIndex)
	{
		return Hold(iMotIndex, FALSE);
	}

	bool CzvMotion_ACS::RebootController()
	{
		if (!acsc_ControllerReboot(m_tMotComConfig.handle, 100000))
			return (false);

		BoardFinish();
		BoardInit();

		return (true);
	}

	bool CzvMotion_ACS::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
	{

		int iret = acsc_PegInc(m_tMotComConfig.handle,
							   ACSC_AMF_SYNCHRONOUS, // synchronous PEG
							   iMotIndex,			// �߻� ���� ��
							   dTriggeringWidth,	// ���� : ms 
							   dStartPosition,		// ���� ��ġ
							   dTriggeringPeriod,	// ����
							   dEndPosition,		// ���� ��ġ
							   ACSC_NONE,			// no time-based pulse generation
							   ACSC_NONE,
							   NULL // waiting call
		);

		if (!iret)
		{
			return (false);
		}

		return (true);
	}

}