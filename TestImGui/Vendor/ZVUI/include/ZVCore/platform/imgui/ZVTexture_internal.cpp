#include "ZVTexture_internal.h"
#include "SOIL2/SOIL2/stb_image.h"
#include "SOIL2/common/common.hpp"
#include "SOIL2/SOIL2/SOIL2.h"

namespace ZVLab {

	CzvTexture_internal::CzvTexture_internal(const std::string& path)
		: m_uiTexID(GL_NONE)
		, m_uiWidth(0)
		, m_uiHeight(0)
		, m_strPath(path)
		, m_bInitialized(true)
	{
		this->Load(path);
	}

	CzvTexture_internal::~CzvTexture_internal()
	{
		this->Release();
	}

	void CzvTexture_internal::Load(const std::string& path)
	{
		m_bInitialized = true;

		m_uiTexID = SOIL_load_OGL_texture
		(
			path.c_str(),
			SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);
		DZVLog_Failed(m_uiTexID, "FAILED: SOIL Load error = \"{0}, {1}\"", SOIL_last_result(), path.c_str());
		SOIL_Load_Texture_Result(&m_uiWidth, &m_uiHeight);
	}

	void CzvTexture_internal::Release()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			glDeleteTextures(1, &m_uiTexID);
		}
	}

	void CzvTexture_internal::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_uiTexID);
	}

	void CzvTexture_internal::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
