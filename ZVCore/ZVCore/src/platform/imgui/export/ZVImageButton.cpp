#include "ZVImageButton.h"
#include "../ZVimguiInterface.h"

namespace ZVLab {
	CZVImageButton::CZVImageButton(const std::string& label)
		: CZVButton(label, 0, 0)
		, m_cTexture()
	{/*Empty*/}

	CZVImageButton::CZVImageButton(float posX, float posY, const std::string& label)
		: CZVButton(label, 0, 0, posX, posY)
		, m_cTexture()
	{/*Empty*/}

	void CZVImageButton::SetTexture(CZVTexture* tex)
	{
		ZVLOG_FAILED(tex, "FAILED: texture is null!!");
		tex->TransferOwner(&m_cTexture);
	}

	void CZVImageButton::SetTexture(const std::string& path)
	{
		m_cTexture.Load(path);
	}

	bool CZVImageButton::IsClicked()
	{
		if (m_cTexture.Empty())
		{
			ZVLOG_FAILED(false, "FAILED: ImageButton is empty!!");
			return (false);
		}

		bool result = false;

		if (this->IsSetupPos())
		{
			result = ImGui::ImageButton((void*)(intptr_t)m_cTexture.GetID(),
										{ (float)m_cTexture.GetWidth(), (float)m_cTexture.GetHeight() },
										{ this->GetPosX(), this->GetPosY() });
		}
		else
		{
			result = ImGui::ImageButton((void*)(intptr_t)m_cTexture.GetID(),
										{ (float)m_cTexture.GetWidth(), (float)m_cTexture.GetHeight() });
		}
		return (result);
	}

} // namespace ZVLab
