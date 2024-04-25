#include "ZVCore.h"
#include "GUI_Liberator.h"

#include "ZVMotion/src/ZVMotion.h"

using namespace ZVLab;

class Sidebar_left : public ZVLab::CZVlayer
{
private:
	CZVImageButton		stage;
	Unique<CZVMotion>	m_ZVMotion;
	TzvAxisInfo			motinfoX;
	TzvAxisInfo			motinfoY;
	float				m_speedX;
	float				m_speedY;

public:
	virtual void OnAttach() 
	{
		stage.SetTexture("D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
						 "D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png" );

		m_ZVMotion.reset(CZVMotion::Create());
		m_ZVMotion->Initialize();

#pragma region AxisX
		motinfoX = TzvAxisInfo();
		motinfoX.iBoardType					= 0; // 보드 인덱스
		motinfoX.iMotIndexInBoard			= 0; // 축 인덱스
		motinfoX.tHwInfo.iMotType			= 1; // 서버 모터
		motinfoX.tHwInfo.iMotOnType			= 1; 
		motinfoX.tHwInfo.iOutPulseType		= 1; 
		motinfoX.tHwInfo.iOutPulseDir		= 1;  
		motinfoX.tHwInfo.iEncoderType		= 1; 
		motinfoX.tHwInfo.iInpositionType	= 2;
		motinfoX.tHwInfo.iSensorStyle		= 1; 
		motinfoX.tHwInfo.iSelOrgSensor		= 0; 
		motinfoX.tHwInfo.iLimitLevel		= 1; 
		motinfoX.tHwInfo.iHomeLevel			= 1; 
		motinfoX.tHwInfo.iAlarmLevel		= 1; 
		motinfoX.tSwInfo.iAlarmMode			= 0; 
		motinfoX.tSwInfo.iHomeDir			= 1; 
		motinfoX.tSwInfo.dOnePulseDist		= 1.0;		// 한 펄스당 이동거리
		motinfoX.tSwInfo.dHomeOffset		= 0; 
		motinfoX.tSwInfo.dWaitPos			= 0; 
		motinfoX.tSpeedInfo.dVs				= 0; 
		motinfoX.tSpeedInfo.dVm				= 30.0; 
		motinfoX.tSpeedInfo.dAcc			= 0.0025; 
		motinfoX.tSpeedInfo.dDec			= 0.0025; 
		motinfoX.tSpeedInfo.dHomeSpd[0]		= 0.0;
		motinfoX.tSpeedInfo.dHomeSpd[1]		= 0.0;
		motinfoX.tSpeedInfo.dHomeSpd[2]		= 0.0;
		motinfoX.tSpeedInfo.dHomeSpd[3]		= 0.0;
		motinfoX.tSpeedInfo.dHomeAcc		= 0.1; 
		motinfoX.tSpeedInfo.dHomeDec		= 0.1; 
		motinfoX.dSwMLimit					= -286.0; 
		motinfoX.dSwPLimit					= 24.0; 
		motinfoX.bUsedHome					= 1; 

		m_speedX = static_cast<float>(motinfoX.tSpeedInfo.dVm);
		m_ZVMotion->MotInit(0, motinfoX);

#pragma endregion

#pragma region AxisY
		motinfoY = TzvAxisInfo();
		motinfoY.iBoardType = 0; // 보드 인덱스
		motinfoY.iMotIndexInBoard = 1; // 축 인덱스
		motinfoY.tHwInfo.iMotType = 1; // 서버 모터
		motinfoY.tHwInfo.iMotOnType = 1;
		motinfoY.tHwInfo.iOutPulseType = 1;
		motinfoY.tHwInfo.iOutPulseDir = 1;
		motinfoY.tHwInfo.iEncoderType = 1;
		motinfoY.tHwInfo.iInpositionType = 2;
		motinfoY.tHwInfo.iSensorStyle = 1;
		motinfoY.tHwInfo.iSelOrgSensor = 0;
		motinfoY.tHwInfo.iLimitLevel = 1;
		motinfoY.tHwInfo.iHomeLevel = 1;
		motinfoY.tHwInfo.iAlarmLevel = 1;
		motinfoY.tSwInfo.iAlarmMode = 0;
		motinfoY.tSwInfo.iHomeDir = 1;
		motinfoY.tSwInfo.dOnePulseDist = 1.0;		// 한 펄스당 이동거리
		motinfoY.tSwInfo.dHomeOffset = 0;
		motinfoY.tSwInfo.dWaitPos = 0;
		motinfoY.tSpeedInfo.dVs = 0;
		motinfoY.tSpeedInfo.dVm = 30.0;
		motinfoY.tSpeedInfo.dAcc = 0.0025;
		motinfoY.tSpeedInfo.dDec = 0.0025;
		motinfoY.tSpeedInfo.dHomeSpd[0] = 0.0;
		motinfoY.tSpeedInfo.dHomeSpd[1] = 0.0;
		motinfoY.tSpeedInfo.dHomeSpd[2] = 0.0;
		motinfoY.tSpeedInfo.dHomeSpd[3] = 0.0;
		motinfoY.tSpeedInfo.dHomeAcc = 0.1;
		motinfoY.tSpeedInfo.dHomeDec = 0.1;
		motinfoY.dSwMLimit = -286.0;
		motinfoY.dSwPLimit = 24.0;
		motinfoY.bUsedHome = 1;

		m_speedY = static_cast<float>(motinfoY.tSpeedInfo.dVm);
		m_ZVMotion->MotInit(1, motinfoY);
#pragma endregion
	};

	virtual void OnEvent(CZVevent& event) 
	{

	};

	virtual void OnUpdate(const float& dt) 
	{
	};
	 
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

			motinfoX.tSpeedInfo.dVm = static_cast<float>(m_speedX);
			motinfoY.tSpeedInfo.dVm = static_cast<float>(m_speedY);

			float MovePosY = 200.0f;
			float MovePosX = 30.0f;
			if (sidebar_ZVMotion.Button("Home", 50.0f, 40.0f, 80.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->HoldOn(0); 
				m_ZVMotion->HoldOn(1);
				m_ZVMotion->Home(0, motinfoX.tSpeedInfo);
				m_ZVMotion->Home(1, motinfoY.tSpeedInfo);

			}
			if (sidebar_ZVMotion.Button("Up", 50.0f, 40.0f, 80.0f + MovePosX, 25.0f + MovePosY))
			{
				m_ZVMotion->RelMove(1, 3, motinfoY.tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Down", 50.0f, 40.0f, 80.0f + MovePosX, 135.0f + MovePosY))
			{
				m_ZVMotion->RelMove(1, 3, motinfoY.tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Left", 50.0f, 40.0f, 10.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->RelMove(0, 3, motinfoX.tSpeedInfo);
			}
			if (sidebar_ZVMotion.Button("Right", 50.0f, 40.0f, 150.0f + MovePosX, 80.0f + MovePosY))
			{
				m_ZVMotion->RelMove(0, 3, motinfoX.tSpeedInfo);
			}

		}
		
	};


	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(Sidebar_left);