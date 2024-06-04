#include "ZVInputText.h"

namespace {
	static std::map<std::string, bool>	s_mInputTextMap;
	static bool sRegistInputTextStatus(const std::string& key)
	{
		bool result = false;
		auto& f = s_mInputTextMap.find(key);
		if (f == s_mInputTextMap.end())
		{
			s_mInputTextMap.insert({ key, false });
			result = true;
		}
		return (result);
	}
	static bool& sGetInputTextStatus(const std::string& key)
	{
		auto& f = s_mInputTextMap.find(key);
		if (f == s_mInputTextMap.end())
			::sRegistInputTextStatus(key);
		return (s_mInputTextMap[key]);
	}
	static bool sReleaseInputTextStatus(const std::string& key)
	{
		bool result = false;
		auto& f = s_mInputTextMap.find(key);
		if (f != s_mInputTextMap.end())
		{
			s_mInputTextMap.erase(key);
			result = true;
		}
		return (result);
	}
}

namespace ZVLab {

	unsigned int CzvInputText::s_uniInputTextCount = 0;

	CzvInputText::CzvInputText(const TzvInputTextInfo& info)
		: m_strLabel(" ")
		, m_arrText()
		, m_tOptions(info)
	{
		s_uniInputTextCount++;
		DZVLog_Failed((s_uniInputTextCount > 0),
					  "FAILED: Unexpected Error! InputText Count is not greater than 0 \"s_uniInputTextCount = {0}\"",
					  s_uniInputTextCount);
	}

	CzvInputText::CzvInputText(const std::string& label, const TzvInputTextInfo& info)
		: m_strLabel(label)
		, m_arrText()
		, m_tOptions(info)
	{
		// TODO: Key System으로 변경
		s_uniInputTextCount++;
		DZVLog_Failed((s_uniInputTextCount > 0),
					  "FAILED: Unexpected Error! InputText Count is not greater than 0 \"s_uniInputTextCount = {0}\"",
					  s_uniInputTextCount);
	}

	CzvInputText::~CzvInputText()
	{
		DZVLog_Failed((s_uniInputTextCount >= 0),
					  "FAILED: Unexpected Error! InputText Count is less than 0 \"s_uniInputTextCount = {0}\"",
					  s_uniInputTextCount);
	}

	bool CzvInputText::Bind(std::string* out)
	{
		DZVLog_Failed(out, "FAILED: std::string* out is Null!");
		this->Copy(&m_arrText, *out);
		bool result = false;
		result = ImGui::InputText
		(
			m_strLabel.c_str(),
			m_arrText.data(),
			m_arrText.size(),
			m_tOptions.GetOptions()
		);
		(*out) = m_arrText.data();
		sRegistInputTextStatus(m_strLabel);
		return (result);
	}

	bool CzvInputText::Bind(std::string* out, const ImVec2& size)
	{
		DZVLog_Failed(out, "FAILED: std::string* out is Null!");
		this->Copy(&m_arrText, *out);
		bool result = false;
		result = ImGui::InputTextEx
		(
			m_strLabel.c_str(),
			NULL,
			m_arrText.data(),
			m_arrText.size(),
			size,
			m_tOptions.GetOptions()
		);
		(*out) = m_arrText.data();
		sRegistInputTextStatus(m_strLabel);
		return (result);
	}

	void CzvInputText::Copy(std::array<char, DzvDef_InputTextMaxSize>* dst, const std::string& src)
	{
		DZVLog_Failed(dst, "FAILED: std::string* out is Null!");
		if (dst == nullptr)
			return;

		auto& bIter = src.begin();
		if (bIter != src.end())
		{
			for (auto& e : *dst)
			{
				e = *bIter;
				bIter++;
				if (bIter == src.end())
					break;
			}
		}
	}

} // namespace ZVLab
