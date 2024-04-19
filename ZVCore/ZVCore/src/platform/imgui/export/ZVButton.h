#ifndef __ZV_ZVBUTTON_H__
#define __ZV_ZVBUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include <string>

namespace ZVLab {
	
	class CZVButton
	{
		using EventCallbackFn = std::function<void(void)>;
	private:
		std::string				m_strButtonLabel;
		float					m_fWidth;
		float					m_fHeight;
		float					m_fPosX;
		float					m_fPosY;
		bool					m_bSetupPos;
		std::function<void()>	m_fpCallbackFn;

	public:
		CZVButton(const std::string& label, float width, float height);
		CZVButton(const std::string& label, float width, float height, float posX, float posY);

	public: // inline Getter
		inline std::string	GetLabel() const	{ return (m_strButtonLabel); }
		inline float		GetWidth() const	{ return (m_fWidth); }
		inline float		GetHeight() const	{ return (m_fHeight); }
		inline float		GetPosX() const		{ return (m_fPosX); }
		inline float		GetPosY() const		{ return (m_fPosY); }
		inline bool			IsSetupPos() const	{ return (m_bSetupPos); }

	public: // inline Setter
		inline void		SetLabel(const std::string& label)	{ m_strButtonLabel = label; }
		inline void		SetWidth(float width)				{ m_fWidth = width; }
		inline void		SetHeight(float height)				{ m_fHeight = height; }
		inline void		SetPosX(float x)					{ m_fPosX = x; }
		inline void		SetPosY(float y)					{ m_fPosY = y; }
		inline void		SetCallbackFunc(EventCallbackFn fn) { m_fpCallbackFn = fn; }

	public: // others
		bool IsClicked() const;
	};

} // namesapce ZVLab
#endif /*__ZV_ZVBUTTON_H__*/

