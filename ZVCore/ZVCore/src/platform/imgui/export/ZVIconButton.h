#ifndef __ZV_ICON_BUTTON_H__
#define __ZV_ICON_BUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVButton.h"
#include "ZVTexture.h"
#include <string>

namespace ZVLab {

	// forwards
	class ZV_API CzvDialog;
	class ZV_API CzvHotKey;

	class ZV_API CzvIconButton : public CzvButton
	{
	private: /// Member variables
		std::optional<ImVec2>	m_optPosition;
		std::optional<ImVec2>	m_optRectMin;
		std::optional<ImVec2>	m_optRectMax;
		std::optional<float>	m_optWeight;
		bool					m_bIsClicked;

	public: // Constructors, Destructors
		CzvIconButton(const std::string& icon, float size);
		virtual ~CzvIconButton();

	public: // others
		bool IsHovered(const ImVec2& pos);

	public: // Inlines member functions
		inline void Resizing(float weight) { m_optWeight = weight; }

	public: // overrides
		virtual bool Bind() override;
		virtual bool Bind(const CzvHotKey& keyMap) override;
	};

} // namesapce ZVLab
#endif /*__ZV_ICON_BUTTON_H__*/

