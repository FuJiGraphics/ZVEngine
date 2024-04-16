#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

class CZVapp : public ZVLab::CZVsystem
{
public:
	CZVapp(const TApplicationSpecification& spec)
		: CZVsystem(spec)
	{/**/}
	virtual ~CZVapp() {}
};

#endif /*__ZV_ZVAPPLICATION_H__*/
