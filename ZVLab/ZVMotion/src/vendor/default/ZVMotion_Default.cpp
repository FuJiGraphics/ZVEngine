#include "ZVMotion_Default.h"

namespace ZVLab {

	CZVMotion_Default::CZVMotion_Default()
	{
	}

	CZVMotion_Default::~CZVMotion_Default()
	{
	}

	bool CZVMotion_Default::Initialize()
	{
		return false;
	}

	bool CZVMotion_Default::Shutdown()
	{
		return false;
	}

	bool CZVMotion_Default::CheckMotIndex(int iMotIndex)
	{
		return false;
	}

	bool CZVMotion_Default::MotInit(int iMotIndex, const TzvAxisInfo & tAxisInfo)
	{
		return false;
	}

	bool CZVMotion_Default::SetCommandPosition(int iMotIndex, double dPos_pulse)
	{
		return false;
	}

	bool CZVMotion_Default::SetActPostion(int iMotIndex, double dPos_pulse)
	{
		return false;
	}

	bool CZVMotion_Default::GetMotStatus(int iMotIndex, int & iMotStatus)
	{
		return false;
	}

	bool CZVMotion_Default::GetHomeSensor(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetPLimitSensor(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetMLimitSensor(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetAlaramSig(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetHoldOnSig(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetMotionSig(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetInpositionSig(int iMotIndex, bool b)
	{
		return false;
	}

	bool CZVMotion_Default::GetActPosition(int iMotIndex, double & dPos_pulse)
	{
		return false;
	}

	bool CZVMotion_Default::GetCommandPostion(int iMotIndex, double & dPos_pulse)
	{
		return false;
	}

	bool CZVMotion_Default::GetHomeResult(int iMotIndex, EzvHomeState & eState)
	{
		return false;
	}

	bool CZVMotion_Default::AbsMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::RelMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::AbsScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::RelScurveMove(int iMotIndex, double dPos_pulse, TzvMotSPInfo tMotSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::MoveContinue(int iMotIndex, TzvMotSPInfo tMotSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::Home(int iMotIndex, TzvMotSPInfo tAxisSpeedInfo)
	{
		return false;
	}

	bool CZVMotion_Default::Stop(int iMotIndex, double dDecTime)
	{
		return false;
	}

	bool CZVMotion_Default::EStop(int iMotIndex)
	{
		return false;
	}

	bool CZVMotion_Default::Hold(int iMotIndex, int iOnOff)
	{
		return false;
	}

	bool CZVMotion_Default::HoldOn(int iMotIndex)
	{
		return false;
	}

	bool CZVMotion_Default::HoldOff(int iMotIndex)
	{
		return false;
	}

	bool CZVMotion_Default::RebootController()
	{
		return false;
	}

	bool CZVMotion_Default::SetMotionTrigger(int iMotIndex, double dStartPosition, double dEndPosition, double dTriggeringPeriod, double dTriggeringWidth, int iTriggerLevel)
	{
		return false;
	}

} // namespace ZVLab