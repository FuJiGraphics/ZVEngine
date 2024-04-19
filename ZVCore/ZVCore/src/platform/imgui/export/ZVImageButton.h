#ifndef __ZV_ZV_IMAGE_BUTTON_H__
#define __ZV_ZV_IMAGE_BUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVButton.h"
#include "ZVTexture.h"
#include <string>

namespace ZVLab {

	class ZV_API CZVImageButton : public CZVButton
	{
	private:
		CZVTexture	m_cTexture;

	public:
		CZVImageButton(const std::string& label = std::string());
		CZVImageButton(float posX, float posY, const std::string& label = std::string());

	public:
		void SetTexture(CZVTexture* tex);
		void SetTexture(const std::string& path);

	public: // others
		bool IsClicked();
	};

} // namesapce ZVLab
#endif /*__ZV_ZV_IMAGE_BUTTON_H__*/

