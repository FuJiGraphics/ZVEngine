#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class ZVWindowMenu final: public ZVLab::CzvLayer
{
//// Member Variables
private:

//// Member Functions
public:
	virtual void OnAttach() override;
	virtual void OnMainMenuBar() override;
};

