#include "ZVMotionAct.h"

CzvMotionAct::CzvMotionAct()
	: ibStage()
	, spZVMotion(nullptr)
	, m_isOpen(false)
	, m_fSpeedX(0.0f)
	, m_fSpeedY(0.0f)
{/*Empty*/}

void CzvMotionAct::Initialize()
{
	ibStage.SetTexture(	"..\\..\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
						"..\\..\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png");

	spZVMotion = CzvMotion::Create();

	TzvMotionInfo_EthernetTCP tcpInfo;
	tcpInfo.nPort = 701;
#ifdef USE_ACS_SYMUL
	tcpInfo.strAddress = "127.0.0.1";
#else
	tcpInfo.strAddress = "10.0.0.50";
#endif
	spZVMotion->ConnectEthernetTCP(tcpInfo);

#pragma region AxisX
	TzvMotorInfo infoX;
	infoX.iBoardType = 0;
	infoX.iMotIndexInBoard = 0;
	infoX.tHwInfo.iMotType = 1;
	infoX.tHwInfo.iMotOnType = 1;
	infoX.tHwInfo.iOutPulseType = 1;
	infoX.tHwInfo.iOutPulseDir = 1;
	infoX.tHwInfo.iEncoderType = 1;
	infoX.tHwInfo.iInpositionType = 2;
	infoX.tHwInfo.iSensorStyle = 1;
	infoX.tHwInfo.iSelOrgSensor = 0;
	infoX.tHwInfo.iLimitLevel = 1;
	infoX.tHwInfo.iHomeLevel = 1;
	infoX.tHwInfo.iAlarmLevel = 1;
	infoX.tSwInfo.iAlarmMode = 0;
	infoX.tSwInfo.iHomeDir = 1;
	infoX.tSwInfo.dOnePulseDist = 1.0;
	infoX.tSwInfo.dHomeOffset = 0;
	infoX.tSwInfo.dWaitPos = 0;
	infoX.tSpeedInfo.dVs = 0;
	infoX.tSpeedInfo.dVm = 30.0;
	infoX.tSpeedInfo.dAcc = 0.0025;
	infoX.tSpeedInfo.dDec = 0.0025;
	infoX.tSpeedInfo.dHomeSpd[0] = 0.0;
	infoX.tSpeedInfo.dHomeSpd[1] = 0.0;
	infoX.tSpeedInfo.dHomeSpd[2] = 0.0;
	infoX.tSpeedInfo.dHomeSpd[3] = 0.0;
	infoX.tSpeedInfo.dHomeAcc = 0.1;
	infoX.tSpeedInfo.dHomeDec = 0.1;
	infoX.dSwMLimit = -286.0;
	infoX.dSwPLimit = 24.0;
	infoX.bUsedHome = 1;
	this->CreateMotor(0, "MotorX", infoX);
#pragma endregion

#pragma region AxisY
	TzvMotorInfo infoY;
	infoY.iBoardType = 0; // 보드 인덱스
	infoY.iMotIndexInBoard = 1; // 축 인덱스
	infoY.tHwInfo.iMotType = 1; // 서버 모터
	infoY.tHwInfo.iMotOnType = 1;
	infoY.tHwInfo.iOutPulseType = 1;
	infoY.tHwInfo.iOutPulseDir = 1;
	infoY.tHwInfo.iEncoderType = 1;
	infoY.tHwInfo.iInpositionType = 2;
	infoY.tHwInfo.iSensorStyle = 1;
	infoY.tHwInfo.iSelOrgSensor = 0;
	infoY.tHwInfo.iLimitLevel = 1;
	infoY.tHwInfo.iHomeLevel = 1;
	infoY.tHwInfo.iAlarmLevel = 1;
	infoY.tSwInfo.iAlarmMode = 0;
	infoY.tSwInfo.iHomeDir = 1;
	infoY.tSwInfo.dOnePulseDist = 1.0;		// 한 펄스당 이동거리
	infoY.tSwInfo.dHomeOffset = 0;
	infoY.tSwInfo.dWaitPos = 0;
	infoY.tSpeedInfo.dVs = 0;
	infoY.tSpeedInfo.dVm = 30.0;
	infoY.tSpeedInfo.dAcc = 0.0025;
	infoY.tSpeedInfo.dDec = 0.0025;
	infoY.tSpeedInfo.dHomeSpd[0] = 0.0;
	infoY.tSpeedInfo.dHomeSpd[1] = 0.0;
	infoY.tSpeedInfo.dHomeSpd[2] = 0.0;
	infoY.tSpeedInfo.dHomeSpd[3] = 0.0;
	infoY.tSpeedInfo.dHomeAcc = 0.1;
	infoY.tSpeedInfo.dHomeDec = 0.1;
	infoY.dSwMLimit = -286.0;
	infoY.dSwPLimit = 24.0;
	infoY.bUsedHome = 1;
	this->CreateMotor(1, "MotorY", infoY);
#pragma endregion

	ibStage.SetCallbackFunc(DBindMemberCallback(CzvMotionAct::IsClicked, this));
}

void CzvMotionAct::OnButton()
{
	if (m_isOpen == false)
		return;

	TzvDialogInfo info;
	info.SetNoTitleBar(true);
	CzvDialog sidebar_ZVMotion("ZVMotion", info);

	auto& motInfoX = spZVMotion->FetchMotorInfo(0);
	auto& motInfoY = spZVMotion->FetchMotorInfo(1);

	m_fSpeedX = static_cast<float>(motInfoX.tSpeedInfo.dVm);
	m_fSpeedY = static_cast<float>(motInfoY.tSpeedInfo.dVm);
	ImGui::SliderFloat("SpeedX", &m_fSpeedX, 0.0f, 50.0f);
	ImGui::SliderFloat("SpeedY", &m_fSpeedY, 0.0f, 50.0f);
	motInfoX.tSpeedInfo.dVm = static_cast<float>(m_fSpeedX);
	motInfoY.tSpeedInfo.dVm = static_cast<float>(m_fSpeedY);


	float MovePosY = 200.0f;
	float MovePosX = 30.0f;
	if (sidebar_ZVMotion.Button("Home", { 50.0f, 40.0f }, { 80.0f + MovePosX, 80.0f + MovePosY }))
	{
		spZVMotion->Hold(0, true);
		spZVMotion->Hold(1, true);
		spZVMotion->Home(0);
		spZVMotion->Home(1);
	}

	if (sidebar_ZVMotion.Button("Up", { 50.0f, 40.0f }, { 80.0f + MovePosX, 25.0f + MovePosY }))
	{
		spZVMotion->RelMove(1, -3);
	}
	if (sidebar_ZVMotion.Button("Down", { 50.0f, 40.0f }, { 80.0f + MovePosX, 135.0f + MovePosY }))
	{
		spZVMotion->RelMove(1, 3);
	}
	if (sidebar_ZVMotion.Button("Left", { 50.0f, 40.0f }, { 10.0f + MovePosX, 80.0f + MovePosY }))
	{
		spZVMotion->RelMove(0, 3);
	}
	if (sidebar_ZVMotion.Button("Right", { 50.0f, 40.0f }, { 150.0f + MovePosX, 80.0f + MovePosY }))
	{
		spZVMotion->RelMove(0, -3);
	}
}

void CzvMotionAct::CreateMotor(unsigned int index, const std::string& label, const TzvMotorInfo& info)
{
	auto motor = CzvMotor::Create(label);
	motor->Initialize(info);
	spZVMotion->AttachMotor(index, motor);
}
