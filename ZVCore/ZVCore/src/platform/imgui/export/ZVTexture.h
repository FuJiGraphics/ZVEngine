#ifndef __ZV_ZVTEXTURE_H__
#define __ZV_ZVTEXTURE_H__
#pragma once

#include "../../../core/Core.h"
#include <string>

namespace ZVLab {

	class ZV_API CZVTexture
	{
	private:
		GLuint				m_uiTexID;
		unsigned int		m_uiWidth;
		unsigned int		m_uiHeight;
		std::string			m_strPath;
		bool				m_bInitialized;
		bool				m_bOwner;

	public:
		CZVTexture();
		CZVTexture(const CZVTexture& tex) = delete;
		~CZVTexture();

	public:
		void Load(const std::string& path);
		void Bind();
		void UnBind();

	public:
		GLuint			GetID() const { return (m_uiTexID); }
		unsigned int	GetWidth() const { return (m_uiWidth); }
		unsigned int	GetHeight() const { return (m_uiHeight); }
		std::string		GetPath() const { return (m_strPath); }
		bool			Empty() const { return (!m_bInitialized); }
		bool			IsOwner() const { return (m_bOwner); }

	public:
		void			SetID(unsigned int id) { m_uiTexID = id; }
		void			SetWidth(unsigned int w) { m_uiWidth = w; }
		void			SetHeight(unsigned int h) { m_uiHeight = h; }
		void			SetPath(const std::string& path) { m_strPath = path; }
		void			SetInit(bool flags) { m_bInitialized = flags; }
		void			SetOwner(bool owner) { m_bOwner = owner; }

	public: // Others
		void			TransferOwner(CZVTexture* texture);
	};

} // namespace ZVLab

#endif /*__ZV_ZVTEXTURE_H__*/ 
