#ifndef __ZV_ZVAPPLICATION_H__
#define __ZV_ZVAPPLICATION_H__
#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

class CZVapp final : public ZVLab::CZVsystem
{
public:
	CZVapp(const TApplicationSpecification& spec)
		: CZVsystem(spec)
	{
		AttachLayer(new Button1);
	}
	virtual ~CZVapp()
	{

	}
};



#endif /*__ZV_ZVAPPLICATION_H__*/
