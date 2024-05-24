#ifndef __ZV_INPUT_TEXT_H__
#define __ZV_INPUT_TEXT_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"

namespace ZVLab {

#define DzvDef_InputTextMaxSize 500

	class ZV_API CzvInputText
	{
	//// Member Variables
	private:
		std::string									m_strLabel;
		std::array<char, DzvDef_InputTextMaxSize>	m_arrText;
		TzvInputTextInfo							m_tOptions;

		// Static Member Variables
		static unsigned int		s_uniInputTextCount;
	//// Member Functions
	public:
		CzvInputText(const TzvInputTextInfo& info = TzvInputTextInfo());
		CzvInputText(const std::string& label, const TzvInputTextInfo& info = TzvInputTextInfo());
		~CzvInputText();

		bool	Bind(std::string* out);

	private:
		void	Copy(std::array<char, DzvDef_InputTextMaxSize>* dst, const std::string& src);
	};


} // namespace ZVLab

#endif /*__ZV_INPUT_TEXT_H__*/
