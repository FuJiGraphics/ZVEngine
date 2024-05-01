#ifndef __ZV_ZVBUTTON_H__
#define __ZV_ZVBUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include <string>

namespace ZVLab {
	
	class CzvButton
	{
	protected: /// using 
		using FuncEventCallback = std::function<void(void)>;

	protected: /// static member variables
		static unsigned int		s_nuiButtonCount;

	protected: /// member variables
		std::string				m_strButtonLabel;
		std::optional<ImVec2>	m_optSize;
		std::optional<ImVec2>	m_optPosition;
		std::function<void()>	m_fpCallbackFn;

	public: // static member functions
		inline static unsigned int	GetButtonCount() { return (s_nuiButtonCount); }

	public: // Constructors, Destructors
		CzvButton(const std::string& label);
		CzvButton(const std::string& label, const ImVec2& size);
		CzvButton(const std::string& label, const ImVec2& size, const ImVec2& position);
		virtual ~CzvButton();

	public: // inline Getter
		inline std::string	GetLabel() const	{ return (m_strButtonLabel); }
		inline float		GetWidth() const	{ return (m_optSize.has_value() ? m_optSize->x : 0); }
		inline float		GetHeight() const	{ return (m_optSize.has_value() ? m_optSize->y : 0); }
		inline float		GetPosX() const		{ return (m_optPosition.has_value() ? m_optPosition->x : -999); }
		inline float		GetPosY() const		{ return (m_optPosition.has_value() ? m_optPosition->y : 0); }
		
	public: // inline Setter
		inline void			SetLabel(const std::string& label)	{ m_strButtonLabel = label; }
		inline void			SetSize(float width, float height)	{ m_optSize = { width, height }; }
		inline void			SetPosition(float x, float y)		{ m_optPosition = { x, y }; }
		inline void			SetCallbackFunc(FuncEventCallback fn) { m_fpCallbackFn = fn; }

	public: // others
		virtual bool Bind();
	};

} // namesapce ZVLab
#endif /*__ZV_ZVBUTTON_H__*/

