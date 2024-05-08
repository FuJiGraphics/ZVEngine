#ifndef __ZV_ZVTEXTURE_IMPL_H__
#define __ZV_ZVTEXTURE_IMPL_H__
#pragma once

#include "ZVCore.h"
#include "export/ZVTexture.h"
#include <string>

namespace ZVLab {

	class ZV_API CzvTexture_internal : public CzvTexture
	{
	private:
		GLuint				m_uiTexID;
		unsigned int		m_uiWidth;
		unsigned int		m_uiHeight;
		std::string			m_strPath;
		bool				m_bInitialized;

	public:
		CzvTexture_internal(const std::string& path);
		CzvTexture_internal(const CzvTexture& tex) = delete;
		~CzvTexture_internal();

	public:
		GLuint			GetID() const { return (m_uiTexID); }
		unsigned int	GetWidth() const { return (m_uiWidth); }
		unsigned int	GetHeight() const { return (m_uiHeight); }
		bool			Empty() const { return (!m_bInitialized); }

	public:
		void Bind();
		void UnBind();

	private:
		void Load(const std::string& path);
		void Release();
	};

} // namespace ZVLab

#endif /*__ZV_ZVTEXTURE_IMPL_H__*/ 