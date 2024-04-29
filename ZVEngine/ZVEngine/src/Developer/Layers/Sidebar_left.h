#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "Motion/ZVMotionAct.h"
#include "IO/ZVIoSystemAct.h"

using namespace ZVLab;

class Sidebar_left : public ZVLab::CzvLayer
{
private:
	CzvMotionAct m_motionAct;

public:
	virtual void OnAttach() 
	{
		m_motionAct.Initialize();

	};
	 
	virtual void OnGUI() 
	{
		CzvDialog info("Sidebar");
		info.Button(m_motionAct.GetButton());

		m_motionAct.OnButton();
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(Sidebar_left);