#ifndef __ZV_ZVTOGGLEBUTTON_H__
#define __ZV_ZVTOGGLEBUTTON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVButton.h"

namespace ZVLab {

	class ZV_API CzvToggleButton final : public CzvButton
	{
	//// Member Functions
	public: 
		// Constructor, Destructors
		CzvToggleButton(const std::string& label);
		CzvToggleButton(const std::string& label, const ImVec2& size);
		CzvToggleButton(const std::string& label, const ImVec2& size, const ImVec2& position);
		virtual ~CzvToggleButton() = default;

		// Getter
		bool				GetStatus() const;

		// Setter
		void				Release();

		// Others
		virtual bool		Bind() override;

		// Inline Functions
		inline void			SetPosX(float posX)					{ this->SetPosition(posX , m_optPosition->y); }
		inline void			SetPosY(float posY)					{ this->SetPosition(m_optPosition->x, posY); }
		inline void			Resizing(const ImVec2& weight)		{ m_optSize = weight; }
		inline void			ResizingW(float weightX)			{ this->Resizing({ weightX, 1.0f }); }
		inline void			ResizingH(float weightY)			{ this->Resizing({ 1.0f, weightY }); }
	};

} // namespace ZVLab


#endif /**/
