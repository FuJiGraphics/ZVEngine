#pragma once

//////def 
// motor type
#define STEP			0
#define SERVO			1

//Inposition Type
#define INP_NONE		0	//Inposition을 사용안함
#define INP_LOW			1	//Inposition을 사용(Low Active)
#define INP_HIGH		2	//Inposition을 사용(High Active)

//펄스방향 
#define P_DIR_BACK		0	//Backward
#define P_DIR_FOR		1	//Forward(Minus->Plus방향)

//펄스 출력 방식 
#define P_OUT_1PULSE	0	//OUT/DIR
#define P_OUT_2PULSE	1	//CW/CCW

//Active Level을 나타내는 Define 
#define L_LOW			0
#define L_HIGH			1

//Encoder Type
#define ENC_1	0	//1 x AB Phase
#define ENC_2	1	//2 x AB Phase
#define ENC_4	2	//4 x AB Phase
#define ENC_CW	3	//CW/CCW type
#define ENC_CMD	4	//Command Pulse(출력펄스 feedback)

//연결된 센서 SensorStyle 
#define S_PMH	0		//Plus,Minus,Home 모두 연결됨 
#define S_PM	1		//Plus,Minus만 연결됨
#define S_H		2		//Home만 연결됨 

//select home sesor
#define IN_EL_PLUS		0
#define IN_EL_MINUS		1
#define IN_ORG			2

#define DHomeStep 4

#define DMotionNameSize 255

#pragma region Enabled ZVMotion Vendors
#define DMotion_Default		0
#define DMotion_ACS			1	
	
/// Set ZVMotion Library
#define DMotion_Vendor DMotion_Default
#pragma endregion

/////enum
enum class EzvHomePriority
{
	eHomePriority1,
	eHomePriority2,
	eHomePriority3,
	eHomePriority4,
	Max
};

enum class EzvMotionBoardType
{
	eMotionBoardSharedMem,
	eMotionBoardAjin,
	eMotionBoardACS,
	eMotionBoardAD8158,
	eMotionBoardVirtual,
	eMotionBoardErr
};

enum class EzvMotStatus
{
	eMotOn = 0,
	eMotionSig,
	eInpositionSig,
	eAlaram,
	eHome,
	ePLimit,
	eMLimit,
	eMotStatusErr
};

enum class EzvHomeState
{
	eHomeSuccess,
	eHomeSearching,
	eHomeFail,
	eHomeStateMax
};

//////struct
struct TzvMotHWInfo
{
	int iMotType;
	int iMotOnType;
	int iOutPulseType;
	int iOutPulseDir;
	int iEncoderType;
	int iInpositionType;

	double dEncoderRatio;
	int iSensorStyle;
	int iSelOrgSensor;
	int iLimitLevel;
	int iHomeLevel;

	int iAlarmLevel;
};

struct TzvMotSWInfo
{
	int iAlarmMode;
	int iHomeDir;

	double dOnePulseDist;
	double dHomeOffset;
	double dWaitPos;

};

struct TzvMotSPInfo
{
	double dVs;
	double dVm;
	double dAcc;
	double dDec;

	double dHomeSpd[4]; // home speed : start, return, exit, home
	double dHomeAcc;
	double dHomeDec;
};

struct TzvAxisInfo
{
	char strAxisName[256];
	int iBoardType;
	int iMotIndexInBoard;

	TzvMotSWInfo tSwInfo;
	TzvMotHWInfo tHwInfo;
	TzvMotSPInfo tSpeedInfo;

	double dSwMLimit;
	double dSwPLimit;

	EzvHomePriority eHomePriority;

	bool bUsedHome;
}; //모터 설정 파라미터

struct TzvAxisFlag
{
	bool bHomeEndFlag;
	bool bAlarmFlag;
	bool bLimitMinusFlag;
	bool bLimitPlusFlag;
};

struct TzvMotState
{
	int iMotIndex;
	bool bMotOnSig;
	bool bMotionSig;
	bool bInpositionSig;
	bool bAlarmSig;
	bool bHomeSensor;
	bool bPLimitSensor;
	bool bMLimitSensor;

	bool bHomeEndFlag;

	double dActPosition;
	double dCommandPosition;
};


//string
const char g_strMotionBoardType[(int)EzvMotionBoardType::eMotionBoardErr][255] =
{
	"MotionBoardShardMem",
	"MotionBoardAjin",
	"MotionBoardACS",
	"MotionBoardAD8158",
	"MotionBoardVirtual",
};

const char strMotionStatusName[(int)EzvMotStatus::eMotStatusErr + 1][255] =
{
	("MotON"),
	("MotionSig"),
	("InpositionSig"),
	("Alarm"),
	("Home"),
	("+ LIMIT"),
	("- LIMIT"),
	("ERR"),
};


