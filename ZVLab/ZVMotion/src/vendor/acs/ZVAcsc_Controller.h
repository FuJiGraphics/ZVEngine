#pragma once

// ACS
#include "ACS/ACSC.h"
#pragma comment(lib, "ACSCL_x64.lib")

namespace ZVLab {

	enum EzvAcsc_Movement
	{
		ezvAcsc_Movement_AMF_None = 0,
		ezvAcsc_Movement_AMF_Wait = ACSC_AMF_WAIT,
		ezvAcsc_Movement_AMF_Relative = ACSC_AMF_RELATIVE
	};

	class CzvAcsc_Controller
	{
	public: // acsc feature functions
		static HANDLE	OpenCommSimulator();
		static HANDLE	OpenCommSerial(int channel, int rate);
		static HANDLE	OpenCommEthernetTCP(char* address, int port);
		static HANDLE	OpenCommEthernetUDP(char* address, int port);
		static void		CloseSimulator();
		static void		CloseComm(HANDLE handle);

		static void		SetVelocity(HANDLE handle, int axis, double velocity, ACSC_WAITBLOCK* wait = NULL);
		static void		SetAcceleration(HANDLE handle, int axis, double acceleration, ACSC_WAITBLOCK* wait = NULL);
		static void		SetDeceleration(HANDLE handle, int axis, double deceleration, ACSC_WAITBLOCK* wait = NULL);
		static void		ToPoint(HANDLE handle, int axis, double point, EzvAcsc_Movement flags = ezvAcsc_Movement_AMF_None, ACSC_WAITBLOCK* wait = NULL);
		static void		RunBuffer(HANDLE handle, int buffer, const char* label = NULL, ACSC_WAITBLOCK* wait = NULL);
		static void		Enable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait = NULL);
		static void		Disable(HANDLE handle, int axis, ACSC_WAITBLOCK* wait = NULL);

	public: // setter
		static void		SetSafetyInputPortInv(HANDLE handle, int axis, int value, ACSC_WAITBLOCK* Wait = NULL);

	public: // getter
		static int				GetAxesCount(HANDLE handle, ACSC_WAITBLOCK* wait = NULL);
		static unsigned int		GetLibraryVersion();
	};

} // namespace ZVLab
