#include "ZVAcsc_Controller.h"
#include "ZVAssert.h"

namespace ZVLab {
	
	HANDLE CzvAcsc_Controller::OpenCommSimulator()
	{
		// open communication (and open if needed) with SPiiPlus simulator
		HANDLE handle = acsc_OpenCommSimulator();
		DZVLog_Failed((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}
	
	HANDLE CzvAcsc_Controller::OpenCommSerial(int channel, int rate)
	{
		HANDLE handle = acsc_OpenCommSerial(channel, rate);
		DZVLog_Failed((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}

	HANDLE CzvAcsc_Controller::OpenCommEthernetTCP(char* address, int port)
	{
		HANDLE handle = acsc_OpenCommEthernetTCP(address, port);
		DZVLog_Failed((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}

	HANDLE CzvAcsc_Controller::OpenCommEthernetUDP(char* address, int port)
	{
		HANDLE handle = acsc_OpenCommEthernetUDP(address, port);
		DZVLog_Failed((handle != ACSC_INVALID),
					 "CzvAcsc_Controller: Error opening communication: {0}",
					 acsc_GetLastError());
		return (handle);
	}

	void CzvAcsc_Controller::CloseSimulator()
	{
		int result = acsc_CloseSimulator();
		DZVLog_Failed(result, "CzvAcsc_Controller: Error closing simulator communication: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::CloseComm(HANDLE handle)
	{
		int result = acsc_CloseComm(handle);
		DZVLog_Failed(result, "CzvAcsc_Controller: Error closing communication: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetVelocity(HANDLE handle, int axis, double velocity, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_SetVelocity(handle, axis, velocity, wait);
		DZVLog_Failed(result, "CzvAcsc_Controller: Transaction error: {0}", 
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetAcceleration(HANDLE handle, int axis, double acceleration, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_SetAcceleration(handle, axis, acceleration, wait);
		DZVLog_Failed(result, "CzvAcsc_Controller: Transaction error: {0}", 
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::SetDeceleration(HANDLE handle, int axis, double deceleration, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_SetDeceleration(handle, axis, deceleration, wait);
		DZVLog_Failed("CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	void CzvAcsc_Controller::ToPoint(HANDLE handle, int axis, double point, EzvAcsc_Movement flags, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_ToPoint(handle, flags, axis, point, wait);
		/*ZVLOG_FAILED(result, "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());*/
	}

	void CzvAcsc_Controller::RunBuffer(HANDLE handle, int buffer, const char* label, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_RunBuffer(handle, buffer, const_cast<char*>(label), wait);
		/*ZVLOG_FAILED(result, "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());*/
	}

	void CzvAcsc_Controller::Enable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_Enable(handle, axis, wait);
		/*ZVLOG_FAILED(result, "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());*/
	}

	void CzvAcsc_Controller::Disable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait)
	{
		int result = acsc_Disable(handle, axis, wait);
		/*ZVLOG_FAILED(result, "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());*/
	}

	void CzvAcsc_Controller::SetSafetyInputPortInv(HANDLE handle, int axis, int value, ACSC_WAITBLOCK* wait)
	{
		if (value == 0) {
			value = (ACSC_SAFETY_RL | ACSC_SAFETY_LL);
		}
		DZVLog_Failed(acsc_SetSafetyInputPortInv(handle, axis, value, wait),
					 "CzvAcsc_Controller: Transaction error: {0}",
					 acsc_GetLastError());
	}

	int CzvAcsc_Controller::GetAxesCount(HANDLE handle, ACSC_WAITBLOCK* wait)
	{
		double count = NULL;
		int result = acsc_GetAxesCount(handle, &count, wait);
		DZVLog_Failed(result, "CzvAcsc_Controller: Error Get Axes Count: {0}",
					 acsc_GetLastError());
		return (static_cast<int>(count));
	}

	unsigned int CzvAcsc_Controller::GetLibraryVersion()
	{
		return (acsc_GetLibraryVersion());
	}

} // namespace ZVLab