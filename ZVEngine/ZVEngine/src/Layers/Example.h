#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

///  UI 생성 시 ZVLab::CZVlayer를 상속받습니다.
///  이후 GUI_Liberator에 해당 버튼에 대한 헤더를 추가합니다.
///  그리고 메인 ZVapp 클래스에 AttachLayer를 해서 실제 코어 시스템에 버튼을 추가해줍니다.
///  메모리 관리에 대한 권한은 코어 시스템에 있습니다.
class Dialog1 : public ZVLab::CZVlayer
{
public:
	/// 프로그램이 시작하고 버튼이 생성될 때 호출되는 함수입니다.
	virtual void OnAttach() override
	{

	}

	/// 프로그램이 종료될 때 또는 버튼이 Detach 될 때 호출되는 함수입니다.
	virtual void OnDetach()
	{

	}

	/// 윈도우에 대한 어떠한 이벤트가 발생하면 호출되는 함수입니다.
	/// CZVevent 객체는 이벤트들의 여러 타입을 대표합니다.
	/// Dispatch 객체를 통해서 event를 전달하고 해당 이벤트의 종류를 판별해서 콜백 함수를 등록할 수 있습니다.
	virtual void OnEvent(CZVevent& event)
	{
		// 디스패처를 통해 사용하고자 하는 이벤트 종류를 등록합니다.
		CZVeventDispatcher ds(event);
		// 전달된 이벤트를 EventType의 타입으로 판별하여 콜백함수로 등록합니다.
		if (event.GetEventType() == EventType::KeyPressed)
		{
			ds.Dispatch<CZVkeyPressedEvent>(BIND_EVENT_FUNC(Dialog1::keyPressed));
		}
	}

	/// 미구현 함수
	virtual void OnUpdate(const float& dt) {};

	/// ImGui의 기능을 구현하는 함수입니다.
	/// 이 함수는 매 프레임당 호출됩니다.
	virtual void OnGuiRender()
	{
		ImGui::Begin("Dialog1");
		auto coolbar_button = [](const char* label) -> bool {
			float w = ImGui::GetCoolBarItemWidth();
			auto font_ptr = ImGui::GetIO().Fonts->Fonts[0];
			font_ptr->Scale = ImGui::GetCoolBarItemScale();
			ImGui::PushFont(font_ptr);
			bool res = ImGui::Button(label, ImVec2(w, w));
			ImGui::PopFont();
			return res;
		};
		if (ImGui::BeginCoolBar("##CoolBarMain", ImCoolBarFlags_Vertical, ImVec2(0.5f, 1.0f))) {
			if (ImGui::CoolBarItem()) {
				if (coolbar_button("A")) {

				}
			}
			if (ImGui::CoolBarItem()) {
				if (coolbar_button("B")) {

				}
			}
			ImGui::EndCoolBar();
		}
		ImGui::End();
	}

public:
	bool keyPressed(ZVLab::CZVkeyPressedEvent& event)
	{
		
		switch (event.GetKeyCode())
		{
		case ZV_KEY_A:
			FZLOG_INFO("Pressed Key = {0}", event.ToString());
			return (true); // 이벤트를 처리했을 경우 true를 반환해야합니다.
			break;
		case ZV_KEY_SPACE:
			FZLOG_INFO("Pressed Key = {0}", event.ToString());
			return (true); // 이벤트를 처리했을 경우 true를 반환해야합니다.
			break;
		}
		return (false); // 이벤트가 현재 레이어에서 처리되지 못했을 때 false를 반환하여 다음 레이어에 event를 전달합니다.
	}
	
};

