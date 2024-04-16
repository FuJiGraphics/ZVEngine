#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

///  UI ���� �� ZVLab::CZVlayer�� ��ӹ޽��ϴ�.
///  ���� GUI_Liberator�� �ش� ��ư�� ���� ����� �߰��մϴ�.
///  �׸��� ���� ZVapp Ŭ������ AttachLayer�� �ؼ� ���� �ھ� �ý��ۿ� ��ư�� �߰����ݴϴ�.
///  �޸� ������ ���� ������ �ھ� �ý��ۿ� �ֽ��ϴ�.
class Dialog1 : public ZVLab::CZVlayer
{
public:
	/// ���α׷��� �����ϰ� ��ư�� ������ �� ȣ��Ǵ� �Լ��Դϴ�.
	virtual void OnAttach() override
	{

	}

	/// ���α׷��� ����� �� �Ǵ� ��ư�� Detach �� �� ȣ��Ǵ� �Լ��Դϴ�.
	virtual void OnDetach()
	{

	}

	/// �����쿡 ���� ��� �̺�Ʈ�� �߻��ϸ� ȣ��Ǵ� �Լ��Դϴ�.
	/// CZVevent ��ü�� �̺�Ʈ���� ���� Ÿ���� ��ǥ�մϴ�.
	/// Dispatch ��ü�� ���ؼ� event�� �����ϰ� �ش� �̺�Ʈ�� ������ �Ǻ��ؼ� �ݹ� �Լ��� ����� �� �ֽ��ϴ�.
	virtual void OnEvent(CZVevent& event)
	{
		// ����ó�� ���� ����ϰ��� �ϴ� �̺�Ʈ ������ ����մϴ�.
		CZVeventDispatcher ds(event);
		// ���޵� �̺�Ʈ�� EventType�� Ÿ������ �Ǻ��Ͽ� �ݹ��Լ��� ����մϴ�.
		if (event.GetEventType() == EventType::KeyPressed)
		{
			ds.Dispatch<CZVkeyPressedEvent>(BIND_EVENT_FUNC(Dialog1::keyPressed));
		}
	}

	/// �̱��� �Լ�
	virtual void OnUpdate(const float& dt) {};

	/// ImGui�� ����� �����ϴ� �Լ��Դϴ�.
	/// �� �Լ��� �� �����Ӵ� ȣ��˴ϴ�.
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
			return (true); // �̺�Ʈ�� ó������ ��� true�� ��ȯ�ؾ��մϴ�.
			break;
		case ZV_KEY_SPACE:
			FZLOG_INFO("Pressed Key = {0}", event.ToString());
			return (true); // �̺�Ʈ�� ó������ ��� true�� ��ȯ�ؾ��մϴ�.
			break;
		}
		return (false); // �̺�Ʈ�� ���� ���̾�� ó������ ������ �� false�� ��ȯ�Ͽ� ���� ���̾ event�� �����մϴ�.
	}
	
};

