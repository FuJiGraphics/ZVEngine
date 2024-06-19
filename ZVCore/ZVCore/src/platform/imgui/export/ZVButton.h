#ifndef __ZV_ZVBUTTON_H__
#define __ZV_ZVBUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "../ZVImguiManager.h"
#include "ZVGuiConfig.h"
#include <string>

namespace ZVLab {

	// forwards
	class ZV_API CzvDialog;
	class ZV_API CzvHotKey;

	class CzvButton
	{
		using FuncEventCallback = std::function<void(void)>;

	//// Member Variables
	protected:
		static unsigned int		s_nuiButtonCount;
		std::string				m_strButtonLabel;
		std::optional<ImVec2>	m_optSize;
		std::optional<ImVec2>	m_optPosition;
		std::function<void()>	m_fpCallbackFn;

	//// Member Functions
	public: 
		inline static unsigned int	GetButtonCount() { return (s_nuiButtonCount); }

	// Constructors, Destructors
		CzvButton(const std::string& label);
		CzvButton(const std::string& label, const ImVec2& size);
		CzvButton(const std::string& label, const ImVec2& size, const ImVec2& position);
		CzvButton(const CzvButton& src);
		virtual ~CzvButton();

	// inline Getter
		inline std::string				GetLabel() const		{ return (m_strButtonLabel); }
		inline float					GetWidth() const		{ return (m_optSize.has_value() ? m_optSize->x : 0); }
		inline float					GetHeight() const		{ return (m_optSize.has_value() ? m_optSize->y : 0); }
		inline float					GetPosX() const			{ return (m_optPosition.has_value() ? m_optPosition->x : -999); }
		inline float					GetPosY() const			{ return (m_optPosition.has_value() ? m_optPosition->y : 0); }
		inline FuncEventCallback 		GetCallback() const		{ return (m_fpCallbackFn); }

	// inline Setter
		inline void						SetLabel(const std::string& label)	{ m_strButtonLabel = label; }
		inline void						SetSize(float width, float height)	{ m_optSize = { width, height }; }
		inline void						SetPosition(float x, float y)		{ m_optPosition = { x, y }; }
		inline void						SetCallbackFunc(FuncEventCallback fn) { m_fpCallbackFn = fn; }

	// others
		virtual bool Bind();
		virtual bool Bind(const CzvHotKey& keyMap);
	};

} // namesapce ZVLab
#endif /*__ZV_ZVBUTTON_H__*/

