#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"

class CzvApp : public ZVLab::CzvSystem
{
//// Member Variables
private:
	static ZVLab::Unique<ZVLab::CzvSystem> s_upApp;

//// Member Functions
public:
	// Constructor, Destructor
	CzvApp();
	virtual ~CzvApp() = default;

	// Getter
	static ZVLab::Unique<ZVLab::CzvSystem>& GetInstance();

};

#endif /*__ZV_ZVAPPLICATION_H__*/
