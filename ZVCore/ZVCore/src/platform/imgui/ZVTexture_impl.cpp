#include "ZVTexture_impl.h"
#include "SOIL2/SOIL2/stb_image.h"
#include "SOIL2/common/common.hpp"
#include "SOIL2/SOIL2/SOIL2.h"


namespace ZVLab {

	CZVTexture_impl::CZVTexture_impl(const std::string& path)
		: m_uiTexID(GL_NONE)
		, m_uiWidth(0)
		, m_uiHeight(0)
		, m_strPath(path)
		, m_bInitialized(true)
	{
		this->Load(path);
	}

	CZVTexture_impl::~CZVTexture_impl()
	{
		this->Release();
	}

	void CZVTexture_impl::Load(const std::string& path)
	{
		m_bInitialized = true;

		m_uiTexID = SOIL_load_OGL_texture
		(
			path.c_str(),
			SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);
		ZVLOG_FAILED(m_uiTexID, "FAILED: SOIL loading error = \"{0}, {1}\"", SOIL_last_result(), path.c_str());
		SOIL_Load_Texture_Result(&m_uiWidth, &m_uiHeight);
	}

	void CZVTexture_impl::Release()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			glDeleteTextures(1, &m_uiTexID);
		}
	}

	void CZVTexture_impl::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_uiTexID);
	}

	void CZVTexture_impl::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
