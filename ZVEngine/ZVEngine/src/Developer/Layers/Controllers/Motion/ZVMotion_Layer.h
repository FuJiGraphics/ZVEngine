#pragma once
#include "ZVCore.h"
#include "GUI_Liberator.h"

class CZVMotionLayer : public ZVLab::CZVlayer
{
private:
	CZVImageButton		stage;
	Unique<CZVMotion>	m_ZVMotion;
	TzvAxisInfo			motinfo[4];
	float				m_speedX;
	float				m_speedY;

public:
	virtual void OnAttach()
	{
		stage.SetTexture("D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
						 "D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png");

		m_ZVMotion.reset(CZVMotion::Create());
		m_ZVMotion->Initialize();

#pragma region AxisX
		motinfo[0] = TzvAxisInfo();
		motinfo[0].iBoardType = 0; // 보드 인덱스
		motinfo[0].iMotIndexInBoard = 0; // 축 인덱스
		motinfo[0].tHwInfo.iMotType = 1; // 서버 모터
		motinfo[0].tHwInfo.iMotOnType = 1;
		motinfo[0].tHwInfo.iOutPulseType = 1;
		motinfo[0].tHwInfo.iOutPulseDir = 1;
		motinfo[0].tHwInfo.iEncoderType = 1;
		motinfo[0].tHwInfo.iInpositionType = 2;
		motinfo[0].tHwInfo.iSensorStyle = 1;
		motinfo[0].tHwInfo.iSelOrgSensor = 0;
		motinfo[0].tHwInfo.iLimitLevel = 1;
		motinfo[0].tHwInfo.iHomeLevel = 1;
		motinfo[0].tHwInfo.iAlarmLevel = 1;
		motinfo[0].tSwInfo.iAlarmMode = 0;
		motinfo[0].tSwInfo.iHomeDir = 1;
		motinfo[0].tSwInfo.dOnePulseDist = 1.0;		// 한 펄스당 이동거리
		motinfo[0].tSwInfo.dHomeOffset = 0;
		motinfo[0].tSwInfo.dWaitPos = 0;
		motinfo[0].tSpeedInfo.dVs = 0;
		motinfo[0].tSpeedInfo.dVm = 30.0;
		motinfo[0].tSpeedInfo.dAcc = 0.0025;
		motinfo[0].tSpeedInfo.dDec = 0.0025;
		motinfo[0].tSpeedInfo.dHomeSpd[0] = 0.0;
		motinfo[0].tSpeedInfo.dHomeSpd[1] = 0.0;
		motinfo[0].tSpeedInfo.dHomeSpd[2] = 0.0;
		motinfo[0].tSpeedInfo.dHomeSpd[3] = 0.0;
		motinfo[0].tSpeedInfo.dHomeAcc = 0.1;
		motinfo[0].tSpeedInfo.dHomeDec = 0.1;
		motinfo[0].dSwMLimit = -286.0;
		motinfo[0].dSwPLimit = 24.0;
		motinfo[0].bUsedHome = 1;

		m_speedX = static_cast<float>(motinfo[0].tSpeedInfo.dVm);
		m_ZVMotion->MotInit(0, motinfo[0]);
#pragma endregion

#pragma region AxisY
		motinfo[1] = TzvAxisInfo();
		motinfo[1].iBoardType = 0; // 보드 인덱스
		motinfo[1].iMotIndexInBoard = 1; // 축 인덱스
		motinfo[1].tHwInfo.iMotType = 1; // 서버 모터
		motinfo[1].tHwInfo.iMotOnType = 1;
		motinfo[1].tHwInfo.iOutPulseType = 1;
		motinfo[1].tHwInfo.iOutPulseDir = 1;
		motinfo[1].tHwInfo.iEncoderType = 1;
		motinfo[1].tHwInfo.iInpositionType = 2;
		motinfo[1].tHwInfo.iSensorStyle = 1;
		motinfo[1].tHwInfo.iSelOrgSensor = 0;
		motinfo[1].tHwInfo.iLimitLevel = 1;
		motinfo[1].tHwInfo.iHomeLevel = 1;
		motinfo[1].tHwInfo.iAlarmLevel = 1;
		motinfo[1].tSwInfo.iAlarmMode = 0;
		motinfo[1].tSwInfo.iHomeDir = 1;
		motinfo[1].tSwInfo.dOnePulseDist = 1.0;		// 한 펄스당 이동거리
		motinfo[1].tSwInfo.dHomeOffset = 0;
		motinfo[1].tSwInfo.dWaitPos = 0;
		motinfo[1].tSpeedInfo.dVs = 0;
		motinfo[1].tSpeedInfo.dVm = 30.0;
		motinfo[1].tSpeedInfo.dAcc = 0.0025;
		motinfo[1].tSpeedInfo.dDec = 0.0025;
		motinfo[1].tSpeedInfo.dHomeSpd[0] = 0.0;
		motinfo[1].tSpeedInfo.dHomeSpd[1] = 0.0;
		motinfo[1].tSpeedInfo.dHomeSpd[2] = 0.0;
		motinfo[1].tSpeedInfo.dHomeSpd[3] = 0.0;
		motinfo[1].tSpeedInfo.dHomeAcc = 0.1;
		motinfo[1].tSpeedInfo.dHomeDec = 0.1;
		motinfo[1].dSwMLimit = -286.0;
		motinfo[1].dSwPLimit = 24.0;
		motinfo[1].bUsedHome = 1;

		m_speedY = static_cast<float>(motinfo[1].tSpeedInfo.dVm);
		m_ZVMotion->MotInit(1, motinfo[1]);
#pragma endregion
	};


public:
	virtual void OnGUI()
	{
		CZVDialog sidebar_left(" ");
		static bool OnZVMotion = false;
		if (sidebar_left.Button(stage))
		{
			if (OnZVMotion)
				OnZVMotion = false;
			else
				OnZVMotion = true;
		}

		static float speed = 0.2f;
		if (OnZVMotion)
		{
			CZVDialog sidebar_ZVMotion("ZVMotion");

			ImGui::SliderFloat("SpeedX", &m_speedX, 0.0f, 50.0f);
			ImGui::SliderFloat("SpeedY", &m_speedY, 0.0f, 50.0f);

			motinfo[0].tSpeedInfo.dVm = static_cast<float>(m_speedX);
			motinfo[1].tSpeedInfo.dVm = static_cast<float>(m_speedY);

			float MovePosY = 200.0f;
			float MovePosX = 30.0f;
			if (sidebar_ZVMotion.Button("Home", 50.0f, 40.0f, 80.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->HoldOn(0);
				m_ZVMotion->HoldOn(1);
				m_ZVMotion->Home(0, motinfo[0].tSpeedInfo);
				m_ZVMotion->Home(1, motinfo[1].tSpeedInfo);

			}
			if (sidebar_ZVMotion.Button("Up", 50.0f, 40.0f, 80.0f + MovePosX, 25.0f + MovePosY))
			{
				m_ZVMotion->RelMove(1, 3, motinfo[1].tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Down", 50.0f, 40.0f, 80.0f + MovePosX, 135.0f + MovePosY))
			{
				m_ZVMotion->RelMove(1, 3, motinfo[1].tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Left", 50.0f, 40.0f, 10.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->RelMove(0, 3, motinfo[0].tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Right", 50.0f, 40.0f, 150.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->RelMove(0, 3, motinfo[0].tSpeedInfo);
			}

		}
	}
};

GENERATE_LAYER(CZVMotionLayer);