#ifndef __ZV_ZV_IMAGE_BUTTON_H__
#define __ZV_ZV_IMAGE_BUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVButton.h"
#include "ZVTexture.h"
#include <string>

namespace ZVLab {

	// forwards
	class ZV_API CzvDialog;
	class ZV_API CzvHotKey;

	class ZV_API CzvImageButton : public CzvButton
	{
	private: /// Member variables
		Shared<CzvTexture>		m_spTexIdle;
		Shared<CzvTexture>		m_spTexClick;
		std::optional<ImVec2>	m_optPosition;
		std::optional<ImVec2>	m_optWeight;
		std::optional<ImVec2>	m_optRectMin;
		std::optional<ImVec2>	m_optRectMax;
		bool					m_bIsClicked;

	public: // Constructors, Destructors
		CzvImageButton();
		CzvImageButton(const std::string& label);
		CzvImageButton(const std::string& label, const ImVec2& position);
		CzvImageButton(const ImVec2& position);
		virtual ~CzvImageButton();

	public: // Setter
		void SetTexture(const Shared<CzvTexture>& idle, const Shared<CzvTexture>& click = nullptr);
		void SetTexture(const std::string& idle_path, const std::string& click_path = std::string());

	public: // others
		bool IsHovered(const ImVec2& pos);

	public: // Inlines member functions
		inline void Resizing(const ImVec2& weight)	{ m_optWeight = weight; }
		inline void ResizingW(float weightX)		{ this->Resizing({ weightX, 1.0f }); }
		inline void ResizingH(float weightY)		{ this->Resizing({ 1.0f, weightY }); }

	public: // overrides
		virtual bool Bind() override;
		virtual bool Bind(const CzvHotKey& keyMap, CzvDialog& targetFocusDialog) override;
	};

} // namesapce ZVLab
#endif /*__ZV_ZV_IMAGE_BUTTON_H__*/

