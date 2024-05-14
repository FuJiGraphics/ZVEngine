#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"

class CzvApp : public ZVLab::CzvSystem
{
private:
	static ZVLab::CzvSystem* s_pApp;

public:
	static ZVLab::CzvSystem* GetInstance();
	CzvApp();
	virtual ~CzvApp() = default;
};

#endif /*__ZV_ZVAPPLICATION_H__*/
