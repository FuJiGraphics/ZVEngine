#include "ZVImage.h"

namespace ZVLab {

	/// static variable
	unsigned int CzvImage::s_nuiImageCount = 0;

	CzvImage::CzvImage()
		: m_strLabel(DBindLabelNumbering("Image", CzvImage::GetImageCount()))
		, m_strPath("")
		, m_matImageData()
		, m_spTexture(nullptr)
		, m_bInitialized(false)
	{
		m_spTexture = CzvTexture::Create(m_strLabel);
	}

	CzvImage::CzvImage(const std::string& label)
		: m_strLabel(label)
		, m_strPath("")
		, m_matImageData()
		, m_spTexture(nullptr)
		, m_bInitialized(false)
	{
		m_spTexture = CzvTexture::Create(m_strLabel);
	}

	CzvImage::~CzvImage()
	{
		this->Release();
	}

	bool CzvImage::Empty() const
	{
		return (!m_bInitialized);
	}

	bool CzvImage::Load(const std::string& path)
	{
		if (path.size() <= 2)
		{
			return (false);
		}
		if (m_strPath == path)
			return (false);

		this->Release();

		// Load Image from path
		m_matImageData = cv::imread(path);
		m_spTexture->Load(m_matImageData);

		m_strPath = path;
		m_bInitialized = true;
		return (m_bInitialized);
	}

	bool CzvImage::Save(const std::string& path)
	{
		if (path.size() <= 2)
			return (false);

		if (m_bInitialized)
			cv::imwrite(path, m_matImageData);
		else
			return (false);

		return (true);
	}

	void CzvImage::Release()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			m_matImageData.release();
			m_spTexture->Release();
		}
	}

	void CzvImage::Bind(const ImVec2& size) const
	{
		if (this->Empty() == false)
		{
			static ImVec2 s_Size;
			DDrawTextureImage
			(
				m_spTexture->GetID(),
				(size.x > 0) ? size.x : m_spTexture->GetWidth(),
				(size.y > 0) ? size.y : m_spTexture->GetHeight(),
			);
		}
	}

} // namespace ZVLab