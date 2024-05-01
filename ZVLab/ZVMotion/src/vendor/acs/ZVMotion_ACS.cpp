#include "ZVMotion_ACS.h"
#include "ZVAcsc_Controller.h"

namespace ZVLab {

	CzvMotion_ACS::CzvMotion_ACS()
		: m_hHandle((HANDLE)-1)
	{

	}

	CzvMotion_ACS::~CzvMotion_ACS()
	{
		this->Shutdown();
	}

	void CzvMotion_ACS::ConnectSimulator()
	{
		m_SetupState.bConnectedSimulator = true;
		m_hHandle = CzvAcsc_Controller::OpenCommSimulator();
		m_eCurrConnectMode = EzvConnectMode::ezvConnectMode_Simulator;
		m_iMaxMotorSlot = CzvAcsc_Controller::GetAxesCount(m_hHandle);
		m_vZvMotors.resize(m_iMaxMotorSlot, nullptr);
	}

	void CzvMotion_ACS::ConnectSerialPort(const TzvMotionInfo_SerialPort& info)
	{
		m_SetupState.bConnectedSerialPort = true;
		m_optSerialPortInfo = info;
		m_eCurrConnectMode = EzvConnectMode::ezvConnectMode_SerialPort;

		m_hHandle = CzvAcsc_Controller::OpenCommSerial(m_optSerialPortInfo->iChannel,
													   m_optSerialPortInfo->iRate);
		m_iMaxMotorSlot = CzvAcsc_Controller::GetAxesCount(m_hHandle);
		m_vZvMotors.resize(m_iMaxMotorSlot, nullptr);
	}

	void CzvMotion_ACS::ConnectEthernetTCP(const TzvMotionInfo_EthernetTCP& info)
	{
		m_SetupState.bConnectedEthernetTCP = true;
		m_optEthernetTCPInfo = info;
		m_hHandle = CzvAcsc_Controller::OpenCommEthernetTCP(m_optEthernetTCPInfo->strAddress.data(), 
															m_optEthernetTCPInfo->nPort);
		m_eCurrConnectMode = EzvConnectMode::ezvConnectMode_EthernetTCP;
		m_iMaxMotorSlot = CzvAcsc_Controller::GetAxesCount(m_hHandle);
		m_vZvMotors.resize(m_iMaxMotorSlot, nullptr);
	}

	void CzvMotion_ACS::ConnectEthernetUDP(const TzvMotionInfo_EthernetUDP& info)
	{
		m_SetupState.bConnectedEthernetUDP = true;
		m_optEthernetUDPInfo = info;
		m_hHandle = CzvAcsc_Controller::OpenCommEthernetUDP(m_optEthernetTCPInfo->strAddress.data(),
															m_optEthernetTCPInfo->nPort);
		m_eCurrConnectMode = EzvConnectMode::ezvConnectMode_EthernetUDP;
		m_iMaxMotorSlot = CzvAcsc_Controller::GetAxesCount(m_hHandle);
		m_vZvMotors.resize(m_iMaxMotorSlot, nullptr);
	}

	void CzvMotion_ACS::Shutdown()
	{
		if (m_eCurrConnectMode == EzvConnectMode::ezvConnectMode_None)
			return;
		if (m_eCurrConnectMode == EzvConnectMode::ezvConnectMode_Simulator)
			CzvAcsc_Controller::CloseSimulator();
		CzvAcsc_Controller::CloseComm(m_hHandle);
	}

	void CzvMotion_ACS::AttachMotor(unsigned int index, const Shared<CzvMotor>& motor)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");
		m_vZvMotors[index] = motor;
		auto& motInfo = motor->GetMotorInfo();
		int iLevel = motInfo.tHwInfo.iLimitLevel ? 0 : 1;
		CzvAcsc_Controller::SetSafetyInputPortInv(m_hHandle, index, iLevel);
	}

	void CzvMotion_ACS::DetachMotor(unsigned int index)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");
		m_vZvMotors.erase(m_vZvMotors.begin() + index);
	}

	unsigned int CzvMotion_ACS::GetSlotSize() const
	{
		return (m_iMaxMotorSlot);
	}

	TzvMotorInfo& CzvMotion_ACS::FetchMotorInfo(unsigned int index)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");
		return (m_vZvMotors[index]->FetchMotorInfo());
	}

	void CzvMotion_ACS::AbsMove(unsigned int index, double dPos_pulse)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");

		TzvSpeedInfo& speedInfo = m_vZvMotors[index]->GetMotorInfo().tSpeedInfo;
		double dVm = speedInfo.dVm;
		double dAccTime = speedInfo.dAcc;
		double dDecTime = speedInfo.dDec;

		DZVLog_Failed((dAccTime > 0), "FAILED: Unexpended Error! dAccTime is less than 0 = {0}", dAccTime);
		DZVLog_Failed((dDecTime > 0), "FAILED: Unexpended Error! dDecTime is less than 0 = {0}", dDecTime);

		double dAcc = dVm / dAccTime;
		double dDec = dVm / dDecTime;

		CzvAcsc_Controller::SetVelocity(m_hHandle, index, dVm);
		CzvAcsc_Controller::SetAcceleration(m_hHandle, index, dAcc);
		CzvAcsc_Controller::SetDeceleration(m_hHandle, index, dDec);
		CzvAcsc_Controller::ToPoint(m_hHandle, index, dPos_pulse);
	}

	void CzvMotion_ACS::RelMove(unsigned int index, double dPos_pulse)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");

		const TzvSpeedInfo& speedInfo = m_vZvMotors[index]->GetMotorInfo().tSpeedInfo;
		double dVm = speedInfo.dVm;
		double dAccTime = speedInfo.dAcc;
		double dDecTime = speedInfo.dDec;

		DZVLog_Failed((dAccTime > 0), "FAILED: Unexpended Error! dAccTime is less than 0 = {0}", dAccTime);
		DZVLog_Failed((dDecTime > 0), "FAILED: Unexpended Error! dDecTime is less than 0 = {0}", dDecTime);

		double dAcc = dVm / dAccTime;
		double dDec = dVm / dDecTime;

		CzvAcsc_Controller::SetVelocity(m_hHandle, index, dVm);
		CzvAcsc_Controller::SetAcceleration(m_hHandle, index, dAcc);
		CzvAcsc_Controller::SetDeceleration(m_hHandle, index, dDec);
		CzvAcsc_Controller::ToPoint(m_hHandle, index, dPos_pulse, ezvAcsc_Movement_AMF_Relative);
	}

	void CzvMotion_ACS::Home(unsigned int index)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");

		CzvAcsc_Controller::RunBuffer(m_hHandle, index);

		// 컨트롤러 buffer 실행 딜레이 추가.
		Sleep(100);
	}

	void CzvMotion_ACS::Hold(unsigned int index, bool enabled)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");
		if (enabled)
			CzvAcsc_Controller::Enable(m_hHandle, index);
		else
			CzvAcsc_Controller::Disable(m_hHandle, index);
	}

	Shared<CzvMotor>& CzvMotion_ACS::operator[](unsigned int index)
	{
		DZVLog_Failed((index < m_vZvMotors.size() && index >= 0),
					 "FAILED: The range of unsigned int has been exceeded.");
		return (m_vZvMotors[index]);
	}



}