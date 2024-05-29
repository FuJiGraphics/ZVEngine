#ifndef __ZV_ZV_IMAGE_H__
#define __ZV_ZV_IMAGE_H__
#pragma once

#include "../../../core/Core.h"
#include <string>
#include "ZVTexture.h"

namespace ZVLab {

	enum class EzvImageFormat
	{
		ePNG, eBMP, eJPEG
	};

	class CzvImage
	{
	//// Member Variables
	private:
		std::string				m_strLabel;
		std::string				m_strPath;
		cv::Mat					m_matImageData;
		Shared<CzvTexture>		m_spTexture;
		bool					m_bInitialized;
		static unsigned int		s_nuiImageCount;

	protected:
		inline static unsigned int	GetImageCount() { return (s_nuiImageCount); }

	//// Member Functions
	public:
		CzvImage();
		CzvImage(const std::string& label);
		virtual ~CzvImage();

		bool	Empty() const;
		bool	Load(const std::string& path);
		bool	Save(const std::string& path);
		void	Release();
		void	Bind(const ImVec2& size = { 0.0f, 0.0f }) const;
	};

} // namespace ZVLab
#endif /*__ZV_ZV_IMAGE_H__*/
