#include "ZVTexture.h"

#include "SOIL2/SOIL2/stb_image.h"
#include "SOIL2/common/common.hpp"
#include "SOIL2/SOIL2/SOIL2.h"


namespace ZVLab {

	CZVTexture::CZVTexture()
		: m_uiTexID(GL_NONE)
		, m_uiWidth(0)
		, m_uiHeight(0)
		, m_strPath()
		, m_bInitialized(false)
	{/*Empty*/}

	CZVTexture::~CZVTexture()
	{
		if (m_bOwner)
			glDeleteTextures(1, &m_uiTexID);
	}

	void CZVTexture::Load(const std::string& path)
	{
		if (m_bInitialized)
		{
			glDeleteTextures(1, &m_uiTexID);
		}
		m_bInitialized = true;

		m_uiTexID = SOIL_load_OGL_texture
		(
			path.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);
		ZVLOG_FAILED(m_uiTexID, "FAILED: SOIL loading error = \"{0}, {1}\"",SOIL_last_result(), path.c_str());
		SOIL_Load_Texture_Result(&m_uiWidth, &m_uiHeight);
	}

	void CZVTexture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_uiTexID);
	}

	void CZVTexture::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void CZVTexture::TransferOwner(CZVTexture* texture)
	{
		texture->SetID(m_uiTexID);
		texture->SetWidth(m_uiWidth);
		texture->SetHeight(m_uiHeight);
		texture->SetOwner(true);
		texture->SetInit(true);
		texture->SetPath(m_strPath.c_str());
		m_strPath.clear();
		m_bInitialized = false;
		m_bOwner = false;
		m_uiHeight = 0;
		m_uiWidth = 0;
		m_uiTexID = 0;
	}

}
