#ifndef __ZV_ZVTEXTURE_IMPL_H__
#define __ZV_ZVTEXTURE_IMPL_H__
#pragma once

#include "../../core/Core.h"
#include "export/ZVTexture.h"
#include <string>

namespace ZVLab {

	class ZV_API CzvTexture_internal final : public CzvTexture
	{
	//// Member Variables
	private:
		std::string			m_strLabel;
		std::string			m_strPath;
		GLuint				m_uiTexID;
		unsigned int		m_uiWidth;
		unsigned int		m_uiHeight;
		unsigned int		m_uiChannels;
		bool				m_bInitialized;
		

	public:
		// Constructor, Destructor
		CzvTexture_internal(const std::string& path);
		CzvTexture_internal(const CzvTexture& tex) = delete;
		virtual ~CzvTexture_internal();

		// Getter
		virtual inline	GLuint			GetID() const override		{ return (m_uiTexID); }
		virtual inline	unsigned int	GetWidth() const override	{ return (m_uiWidth); }
		virtual inline	unsigned int	GetHeight() const override	{ return (m_uiHeight); }
		virtual inline	bool			Empty() const override		{ return (!m_bInitialized); }
		
		// Others
		virtual void					Load(const std::string& path) override;
		virtual void					Load(const cv::Mat& cvImageData) override;
		virtual void					Bind() override; 
		virtual void					UnBind() override;
		void							Release() override;
	};

} // namespace ZVLab

#endif /*__ZV_ZVTEXTURE_IMPL_H__*/ 
