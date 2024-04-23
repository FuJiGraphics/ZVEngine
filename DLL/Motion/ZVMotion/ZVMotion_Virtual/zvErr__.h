#pragma once


// Errs
enum class EzvErr
{
	//// add Err codes here

	// general
	NotDefinedException,
	CheckIndexRange,
	CheckPointer,

	//acs
	NotInitializeBoard,
	AxisNotIntialized,
	PosSettingFailed,
	ReadMotionSignalFailed,
	ReadMotionPositionFailed,
	ReadHomeResultFailed,
	ParameterSettingFailed,
	MovingAxisFailed,
	AxisHomeFailed,
	MotionStopFailed,
	HoldOnOffFailed,
	FailedToRebootController,

	// max.
	Max
};


class CzvErr__ final
{
	//// member variables
private:
	static const CString m_rgstrEng[];
	static const CString m_rgstrKor[];
	static const CString m_rgstrChn[];

public:

	//// member functions
private:

public:
	CzvErr__();
	~CzvErr__();
	CzvErr__(const CzvErr__& zvErrSrc) = delete;
	CzvErr__& operator=(const CzvErr__& zvErrSrc) = delete;

	// get / set
	static CString GetName(EzvErr ezvErr);
};


static CString _zvErr(EzvErr ezvErr)
{
	return CzvErr__::GetName(ezvErr);
}
