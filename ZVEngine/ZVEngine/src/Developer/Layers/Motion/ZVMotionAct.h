#pragma once
#include "ZVCore.h"
#include "ZVMotion/src/ZVMotion.h"

using namespace ZVLab;

class CzvMotionAct
{
private:
	bool					m_isOpen;
	CzvImageButton			ibStage;
	Shared<CzvMotion>		spZVMotion;

private:
	float	m_fSpeedX;
	float	m_fSpeedY;

public:
	CzvMotionAct();

	void Initialize();
	void OnButton();
	void IsClicked() { (m_isOpen) ? m_isOpen = false : m_isOpen = true; }
	CzvImageButton& GetButton() { return (ibStage); }

private:
	void CreateMotor(unsigned int index, const std::string& label, const TzvMotorInfo& info);
};

