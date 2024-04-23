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
		Shared<CZVTexture>	m_TexIdle;
		Shared<CZVTexture>	m_TexClick;
		ImVec2				m_Weight;
		ImVec2				m_RectMin;
		ImVec2				m_RectMax;
		bool				m_IsSetRect;
		bool				m_IsClicked;

	public:
		CZVImageButton(const std::string& label = std::string());
		CZVImageButton(float posX, float posY, const std::string& label = std::string());

	public:
		void SetTexture(const Shared<CZVTexture>& idle, const Shared<CZVTexture>& click = nullptr);
		void SetTexture(const std::string& idle_path, const std::string& click_path = std::string());

	public: // others
		bool IsHovered(const ImVec2& pos);

	public: // inlines
		inline void ResizingX(float weightX) { m_Weight.x = weightX; }
		inline void ResizingY(float weightY) { m_Weight.y = weightY; }
		inline void Resizing(const ImVec2& weight) { m_Weight = weight; }

	public: // overrides
		virtual bool Bind() override;
	};

} // namesapce ZVLab
#endif /*__ZV_ZV_IMAGE_BUTTON_H__*/

