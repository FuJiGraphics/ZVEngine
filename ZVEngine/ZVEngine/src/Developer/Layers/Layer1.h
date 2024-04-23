#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "../platform/imgui/fonts/IconsLucide.h"

using namespace ZVLab;

class Layer1 : public ZVLab::CZVlayer
{
private:
	CZVImageButton stage;

public:
	virtual void OnAttach() 
	{
		stage.SetTexture("D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
						 "D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png" );
	};

	virtual void OnDetach() 
	{

	};

	virtual void OnEvent(CZVevent& event) 
	{

	};

	virtual void OnUpdate(const float& dt) 
	{
	};
	 
	virtual void OnGUI() 
	{
		CZVDialog dialog1("dialog");
		CZVButton button1("Ask", 40.0f, 40.0f);

		static bool b1 = true;
		if (dialog1.Button(button1))
		{
			if (b1)
				b1 = false;
			else
				b1 = true;
 			CZVimguiManager::SetOverviewDockspace(b1);
		}
		if (dialog1.Button(stage))
		{

		}
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(Layer1);