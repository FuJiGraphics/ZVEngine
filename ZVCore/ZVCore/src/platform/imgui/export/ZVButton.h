#ifndef __ZV_ZVBUTTON_H__
#define __ZV_ZVBUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include <string>

namespace ZVLab {
	
	class CZVButton
	{
	private:
		std::string		m_strButtonLabel;
		float			m_fWidth;
		float			m_fHeight;
		float			m_fPosX;
		float			m_fPosY;
		bool			m_bSetupPos;

	public:
		CZVButton(const std::string& label, float width, float height);
		CZVButton(const std::string& label, float width, float height, float posX, float posY);

	public:
		inline std::string	GetLabel() const	{ return (m_strButtonLabel); }
		inline float		GetWidth() const	{ return (m_fWidth); }
		inline float		GetHeight() const	{ return (m_fHeight); }
		inline float		GetPosX() const		{ return (m_fPosX); }
		inline float		GetPosY() const		{ return (m_fPosY); }
		
	public:
		bool IsClicked() const;
	};


} // namesapce ZVLab
#endif /*__ZV_ZVBUTTON_H__*/

