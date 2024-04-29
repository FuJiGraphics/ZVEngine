#ifndef __ZV_ZV_MOTION_CONFIGURATION_ACS_H__
#define __ZV_ZV_MOTION_CONFIGURATION_ACS_H__

#pragma once
#include <string>
#include <optional>
#include "FZLib/Helpers/LogHelper.h"

namespace ZVLab {

	enum class EzvConnectMode
	{
		ezvConnectMode_None,
		ezvConnectMode_SerialPort,
		ezvConnectMode_EthernetTCP,
		ezvConnectMode_EthernetUDP,
		ezvConnectMode_Simulator,
	};


	struct TzvMotionInfo_SerialPort
	{
		int	iChannel;
		int iRate;
	};

	struct TzvMotionInfo_EthernetTCP
	{
		std::string		strAddress;
		int				nPort;
	};

	struct TzvMotionInfo_EthernetUDP
	{
		std::string		strAddress;
		int				nPort;
	};

	struct TzvMotion_SetupState
	{
	// Connect Port states
		bool	bConnectedSerialPort	= false;
		bool	bConnectedEthernetTCP	= false;
		bool	bConnectedEthernetUDP	= false;
		bool	bConnectedSimulator		= false;
	// 
	};

} // namespace ZVLab

#endif /*__ZV_ZV_MOTION_CONFIGURATION_ACS_H__*/
