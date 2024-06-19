#include <filesystem>
#include "FZLib/Helpers/StringHelper.h"
#include "ZVFont.h"

namespace {

	static void LoadIconsFaSolid(const std::string& label, float pixel_size)
	{
		std::string currPath = FZLib::StringHelper::WStringToString(std::filesystem::current_path().c_str());

		// Icon Fa-solid-900 Fonts
		std::string strPath_solid;
		static ImFontConfig s_Config_solid;
		strPath_solid = currPath + "\\res\\fonts\\Fa-solid-900.ttf";
		std::filesystem::path fs_solid(strPath_solid);
		if (std::filesystem::exists(fs_solid) == true)
		{
			s_Config_solid.MergeMode = true;
			s_Config_solid.GlyphMinAdvanceX = 5.0f; // Use if you want to make the icon monospaced
			static std::vector<ImWchar> vIconRanges_solid = { ICON_MIN_FA, ICON_MAX_FA, 0 };
			ZVLab::CzvFont::GetInstance().Load(label, strPath_solid, pixel_size, vIconRanges_solid, s_Config_solid);
		}
		else
		{
			FZLOG_INFO("Did not found Fa-solid-900 font data!");
		}
	}
}

namespace ZVLab {

	// Statics
	Shared<CzvFont>				CzvFont::s_spInstance = nullptr;
	CzvFont::FontMemoryPool		CzvFont::s_mFontData;
	CzvFont::FontStack			CzvFont::s_mFontStack;
	int							CzvFont::s_iStackCount = 0;
	bool						CzvFont::s_bInitialized = false;

	CzvFont& CzvFont::GetInstance()
	{
		if (s_spInstance == nullptr)
		{
			s_spInstance = CreateShared<CzvFont>();
		}
		s_spInstance->Init();
		return (*s_spInstance);
	}

	void CzvFont::Init()
	{
		if (s_bInitialized)
			return;

		// Default Font
		auto& io = ImGui::GetIO();
		io.Fonts->AddFontDefault();

		//// Icon Fa-regular-400 Fonts
		//std::string strPath_regular;
		//ImFontConfig tConfig_regular;
		//strPath_regular = currPath + "\\res\\fonts\\Fa-regular-400.ttf";
		//std::filesystem::path fs_regular(strPath_regular);
		//if (std::filesystem::exists(fs_regular) == true)
		//{
		//	tConfig_regular.MergeMode = true;
		//	tConfig_regular.GlyphMinAdvanceX = 5.0f; // Use if you want to make the icon monospaced
		//	static std::vector<ImWchar> vIconRanges_regular = { ICON_MIN_FA, ICON_MAX_FA, 0 };
		//	this->Load("ZV_ICONS_REGULAR", strPath_regular, 10.0f, vIconRanges_regular, tConfig_regular);
		//}
		//else
		//{
		//	FZLOG_INFO("Did not found Fa-regular-400 font data!");
		//}

		s_bInitialized = true;
	}

	void CzvFont::Update()
	{
		bool first = true;
		bool bIsDestroyed = false;
		while (!s_mFontStack.empty())
		{
			if (first)
			{
				auto& io = ImGui::GetIO();
				if (ImGui_ImplOpenGL3_DestroyFontsTexture())
				{
					bIsDestroyed = true;
				}
				io.Fonts->AddFontDefault();
				first = false;
			}
			s_mFontStack.top()->Init();
			s_mFontStack.pop();
			if (s_mFontStack.empty() && bIsDestroyed)
			{
				ImGui_ImplOpenGL3_CreateFontsTexture();
			}
		}		
	}

	bool CzvFont::Load(const std::string& label, 
					   const std::string& path,
					   float pixel_size)
	{
		if (DZVLog_Failed((s_mFontData.find(label) == s_mFontData.end()), "Warning: Font file already exists."))
			return (false);

		s_mFontData.insert({ label, { path, pixel_size } });
		return (true);
	}

	bool CzvFont::Load(const std::string& label, 
					   const std::string& path, 
					   float pixel_size,
					   const std::vector<unsigned short>& glyph_ranges)
	{
		if (DZVLog_Failed((s_mFontData.find(label) == s_mFontData.end()), "Warning: Font file already exists."))
			return (false);

		s_mFontData.insert({ label, { path, pixel_size, glyph_ranges } });
		return (true);
	}

	bool CzvFont::Load(const std::string& label, 
					   const std::string& path, 
					   float pixel_size,
					   const std::vector<unsigned short>& glyph_ranges, 
					   ImFontConfig& config)
	{
		if (DZVLog_Failed((s_mFontData.find(label) == s_mFontData.end()), "Warning: Font file already exists."))
			return (false);

		s_mFontData.insert({ label, { path, pixel_size, glyph_ranges, config } });
		return (true);
	}

	CzvFontData& CzvFont::GetIcon(unsigned int pixel_size)
	{
		std::string strPixelSize = std::to_string(pixel_size);
		std::string strFindFaIcon = "ZV_ICONS_FA_" + strPixelSize;
		auto findIcon = s_mFontData.find(strFindFaIcon);
		if (findIcon == s_mFontData.end())
		{
			float fPixelSize = static_cast<float>(pixel_size);
			::LoadIconsFaSolid(strFindFaIcon, fPixelSize);
			s_mFontStack.push(&s_mFontData[strFindFaIcon]);
		}
		return (s_mFontData[strFindFaIcon]);
	}

	CzvFontData& CzvFont::operator[](const std::string& key)
	{
		return (s_mFontData[key]);
	}

	CzvFontData::CzvFontData()
		: m_bIsBindedFont(false)
		, m_pFonts(nullptr)
		, m_strPath()
		, m_fPixelSize(0.0f)
		, m_vGlyphRanges()
		, m_ptConfig(NULL)
	{/*Empty*/}

	CzvFontData::CzvFontData(const std::string& path, float pixel_size)
		: m_bIsBindedFont(false)
		, m_pFonts(nullptr)
		, m_strPath(path)
		, m_fPixelSize(pixel_size)
		, m_vGlyphRanges()
		, m_ptConfig(NULL)
	{/*Empty*/}

	CzvFontData::CzvFontData(const std::string& path, 
							 float pixel_size, 
							 const std::vector<unsigned short>& glyph_ranges)
		: m_bIsBindedFont(false)
		, m_pFonts(nullptr)
		, m_strPath(path)
		, m_fPixelSize(pixel_size)
		, m_vGlyphRanges(glyph_ranges)
		, m_ptConfig(NULL)
	{/*Empty*/}

	CzvFontData::CzvFontData(const std::string& path, 
							 float pixel_size, 
							 const std::vector<unsigned short>& glyph_ranges, 
							 ImFontConfig& config)
		: m_bIsBindedFont(false)
		, m_pFonts(nullptr)
		, m_strPath(path)
		, m_fPixelSize(pixel_size)
		, m_vGlyphRanges(glyph_ranges)
		, m_ptConfig(&config)
	{/*Empty*/}

	bool CzvFontData::Init()
	{
		auto& io = ImGui::GetIO();
		const char* font_path = m_strPath.c_str();
		float font_size = (m_fPixelSize > 0.0f) ? m_fPixelSize : 13.0f;
		const ImFontConfig* font_config = m_ptConfig;
		const ImWchar* font_ranges = m_vGlyphRanges.data();
		m_pFonts = io.Fonts->AddFontFromFileTTF(font_path, font_size, font_config, font_ranges);

		if (m_pFonts == nullptr)
		{
			return (false);
		}
		m_bIsBindedFont = true;
		return (true);
	}

	void CzvFontData::SetFontSize(float size_pixels)
	{
		ImGui::SetWindowFontScale(size_pixels);
	}

	void CzvFontData::Begin(bool bIsMainFont)
	{
		if (!bIsMainFont && m_bIsBindedFont)
			ImGui::PopFont();
		if (m_bIsBindedFont)
			ImGui::PushFont(m_pFonts);
	}

	void CzvFontData::End()
	{
		if (m_bIsBindedFont)
			ImGui::PopFont();
	}

} // namespace ZVLab
