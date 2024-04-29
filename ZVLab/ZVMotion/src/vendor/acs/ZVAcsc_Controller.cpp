#include "ZVAcsc_Controller.h"
#include "ZVAssert.h"

namespace ZVLab {
	
	HANDLE CzvAcsc_Controller::OpenCommSimulator()
	{
		// open communication (and open if needed) with SPiiPlus simulator
		HANDLE handle = acsc_OpenCommSimulator();
		ZVLOG_FAILED((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}
	
	HANDLE CzvAcsc_Controller::OpenCommSerial(int channel, int rate)
	{
		HANDLE handle = acsc_OpenCommSerial(channel, rate);
		ZVLOG_FAILED((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}

	HANDLE CzvAcsc_Controller::OpenCommEthernetTCP(char* address, int port)
	{
		HANDLE handle = acsc_OpenCommEthernetTCP(address, port);
		ZVLOG_FAILED((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}

	HANDLE CzvAcsc_Controller::OpenCommEthernetUDP(char* address, int port)
	{
		HANDLE handle = acsc_OpenCommEthernetUDP(address, port);
		ZVLOG_FAILED((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);	}

	void CzvAcsc_Controller::CloseSimulator()
	{
		ZVLOG_FAILED(acsc_CloseSimulator(),
					 "CzvAcsc_Controller: Error closing simulator communication: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::CloseComm(HANDLE handle)
	{
		ZVLOG_FAILED(acsc_CloseComm(handle),
					 "CzvAcsc_Controller: Error closing communication: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetVelocity(HANDLE handle, int axis, double velocity, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_SetVelocity(handle, axis, velocity, wait),
					 "CzvAcsc_Controller: Transaction error: {0}", 					 acsc_GetLastError());	}

	void CzvAcsc_Controller::SetAcceleration(HANDLE handle, int axis, double acceleration, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_SetAcceleration(handle, axis, acceleration, wait),
					 "CzvAcsc_Controller: Transaction error: {0}", 
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetDeceleration(HANDLE handle, int axis, double deceleration, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_SetDeceleration(handle, axis, deceleration, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::ToPoint(HANDLE handle, int axis, double point, EzvAcsc_Movement flags, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_ToPoint(handle, flags, axis, point, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::RunBuffer(HANDLE handle, int buffer, const char* label, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_RunBuffer(handle, buffer, const_cast<char*>(label), wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::Enable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_Enable(handle, axis, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::Disable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait)
	{
		ZVLOG_FAILED(acsc_Disable(handle, axis, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetSafetyInputPortInv(HANDLE handle, int axis, int value, ACSC_WAITBLOCK* wait)
	{
		if (value == 0) {
			value = (ACSC_SAFETY_RL | ACSC_SAFETY_LL);
		}
		ZVLOG_FAILED(acsc_SetSafetyInputPortInv(handle, axis, value, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	int CzvAcsc_Controller::GetAxesCount(HANDLE handle, ACSC_WAITBLOCK* wait)
	{
		double count = NULL;
		int result = acsc_GetAxesCount(handle, &count, wait);
		ZVLOG_FAILED(result, "CzvAcsc_Controller: Error Get Axes Count: {0}",
					 acsc_GetLastError());
		return (static_cast<int>(count));
	}

	unsigned int CzvAcsc_Controller::GetLibraryVersion()
	{
		return (acsc_GetLibraryVersion());
	}

} // namespace ZVLab