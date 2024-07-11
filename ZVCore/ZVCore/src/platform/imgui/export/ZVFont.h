#ifndef __ZV_FONT_H__
#define __ZV_FONT_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVIcon.h"

namespace ZVLab {

	class ZV_API CzvFontData
	{
	//// Member Variables
	private:
		bool								m_bIsBindedFont;
		ImFont*								m_pFonts;
		std::string							m_strPath;
		float								m_fPixelSize;
		const std::vector<unsigned short>	m_vGlyphRanges;
		ImFontConfig*						m_ptConfig;
	
	//// Member Functions
	public:
		// Constructor, Destructor
		CzvFontData();
		CzvFontData(const std::string& path, float pixel_size);
		CzvFontData(const std::string& path, float pixel_size, const std::vector<unsigned short>& glyph_ranges);
		CzvFontData(const std::string& path, float pixel_size, const std::vector<unsigned short>& glyph_ranges, ImFontConfig& config);

		// Others
		bool	Init();
		void	SetFontSize(float size_pixels);
		void	Begin(bool bIsMainFont = false);
		void	End();
	};

	class ZV_API CzvFont
	{
		using FontMemoryPool = std::unordered_map<std::string, ZVLab::CzvFontData>;
		using FontStack = std::stack<ZVLab::CzvFontData*>;
	//// Member Variables
	private:
		static Shared<CzvFont>		s_spInstance;
		static FontMemoryPool		s_mFontData;
		static FontStack			s_mFontStack;
		static int					s_iStackCount;
		static bool					s_bInitialized;

	//// Member Functions
	public:
		CzvFont() = default;
		~CzvFont() = default;
		
		static CzvFont&				GetInstance();

		void						Init();
		void						Update();
		static bool					Load(const std::string& label, const std::string& path, float pixel_size);
		static bool					Load(const std::string& label, const std::string& path, float pixel_size, const std::vector<unsigned short>& glyph_ranges);
		static bool					Load(const std::string& label, const std::string& path, float pixel_size, const std::vector<unsigned short>& glyph_ranges, ImFontConfig& config);
		CzvFontData&				GetIcon(unsigned int pixel_size);

		CzvFontData&				operator[] (const std::string& key);
	};

} // namespace ZVLab

#endif /*__ZV_FONT_H__*/
