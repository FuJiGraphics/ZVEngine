#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "Motion/ZVMotionAct.h"
#include "IO/ZVIoSystemAct.h"

using namespace ZVLab;

class Sidebar_left : public ZVLab::CzvLayer
{
private:
	CzvMotionAct	m_motionAct;
	CzvIoSystemAct	m_ioAct;

public:
	virtual void OnAttach() 
	{
		m_motionAct.Initialize();
		m_ioAct.Initialize();
	};
	 
	virtual void OnGUI() 
	{
		TzvDialogInfo info;
		info.SetNoDocking(false);
		CzvDialog dlgDialog("Sidebar", info);

		dlgDialog.Button(m_motionAct.GetButton());
		dlgDialog.Button(m_ioAct.GetButton());

		m_motionAct.OnButton();
		m_ioAct.OnButton();

		int   bar_data[2] = { 2, 3 };
		float x_data[10] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
		float y_data[10] = { 1.5f, 2.3f, 3.2f, 4.1f, 5.8f, 6.3f, 7.5f, 8.2f, 9.3f, 11.9f };

		ImGui::Begin("My Window");
		if (ImPlot::BeginPlot("My Plot")) 
		{
			ImPlot::PlotBars("My Bar Plot", bar_data, 2);
			ImPlot::PlotLine("My Line Plot", x_data, y_data, 10);

			ImPlot::EndPlot();
		}
		ImGui::End();
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(Sidebar_left);