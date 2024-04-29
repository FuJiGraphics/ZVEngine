#ifndef __ZV_ZVMOTOR_CONFIGURATION_H__
#define __ZV_ZVMOTOR_CONFIGURATION_H__
#pragma once

#include <string>

//Active Level을 나타내는 Define 
#define L_LOW			0
#define L_HIGH			1

enum class EzvHomePriority
{
	eHomePriority1,
	eHomePriority2,
	eHomePriority3,
	eHomePriority4,
	Max
};

enum class EzvMotorAxis
{
	eAxis_X,
	eAxis_Y,
	eAxis_Z,
	eAxis_R,
};

//////struct
struct TzvHardwareInfo
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

struct TzvSoftwareInfo
{
	int iAlarmMode;
	int iHomeDir;

	double dOnePulseDist;
	double dHomeOffset;
	double dWaitPos;

};

struct TzvSpeedInfo
{
	double dVs;
	double dVm;
	double dAcc;
	double dDec;

	double dHomeSpd[4]; // home speed : start, return, exit, home
	double dHomeAcc;
	double dHomeDec;
};

struct TzvMotorInfo
{
	std::string		strAxisName;
	int				iBoardType;
	int				iMotIndexInBoard;

	TzvSoftwareInfo	tSwInfo;
	TzvHardwareInfo	tHwInfo;
	TzvSpeedInfo	tSpeedInfo;

	double			dSwMLimit;
	double			dSwPLimit;

	EzvHomePriority eHomePriority;

	bool			bUsedHome;
}; //모터 설정 파라미터

#endif /*__ZV_ZVMOTOR_CONFIGURATION_H__*/
