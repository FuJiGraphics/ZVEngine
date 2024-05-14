#include "ZVTexture_internal.h"
#include "SOIL2/SOIL2/stb_image.h"
#include "SOIL2/common/common.hpp"
#include "SOIL2/SOIL2/SOIL2.h"

//// static functions
namespace {
	GLuint sConvert_CVMat_To_GLTexture(
		const cv::Mat& cvImageData, 
		unsigned int* out_width = nullptr, 
		unsigned int* out_height = nullptr,
		unsigned int* out_channels = nullptr)
	{
		cv::Mat convertMat;
		cv::cvtColor(cvImageData, convertMat, cv::COLOR_BGR2RGBA);

		GLuint texture = GL_NONE;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, convertMat.cols, convertMat.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, convertMat.data);
		(out_width != nullptr) ? (*out_width) = convertMat.cols : 0;
		(out_height != nullptr) ? (*out_height) = convertMat.rows : 0;
		(out_channels != nullptr) ? (*out_channels) = convertMat.channels() : 0;
		return (texture);
	}
}

namespace ZVLab {

	CzvTexture_internal::CzvTexture_internal(const std::string& label)
		: m_strLabel(label)
		, m_strPath("")
		, m_uiTexID(GL_NONE)
		, m_uiWidth(0)
		, m_uiHeight(0)
		, m_uiChannels(0)
		, m_bInitialized(false)
	{/*Empty*/}

	CzvTexture_internal::~CzvTexture_internal()
	{
		this->Release();
	}

	void CzvTexture_internal::Load(const std::string& path)
	{
		if (this->Empty() == false)
		{
			FZLOG_WARN("WARN: Already loaded texture data. = {0}", m_strLabel);
			FZLOG_WARN("-> The requested data is used to overwrite the texture.");
		}
		this->Release();

		m_uiTexID = SOIL_load_OGL_texture
		(
			path.c_str(),
			SOIL_LOAD_RGBA,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS
		);
		if (m_uiTexID == 0)
			FZLOG_WARN("WARN: Failed to loaded texture! = {0}", m_strLabel);

		SOIL_Load_Texture_Result(&m_uiWidth, &m_uiHeight, &m_uiChannels);
		m_strPath = path;
		m_bInitialized = true;
	}

	void CzvTexture_internal::Load(const cv::Mat& cvImageData)
	{
		if (this->Empty() == false)
		{
			FZLOG_WARN("WARN: Already loaded texture data. = {0}", m_strLabel);
			FZLOG_WARN("-> The requested data is used to overwrite the texture.");
		}
		this->Release();

		m_uiTexID = sConvert_CVMat_To_GLTexture
		(
			cvImageData, 
			&m_uiWidth, 
			&m_uiHeight, 
			&m_uiChannels
		);
		if (m_uiTexID == 0)
			FZLOG_WARN("WARN: Failed to loaded texture! = {0}", m_strLabel);

		m_bInitialized = true;
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
		if(this->Empty())
			FZLOG_WARN("WARN: Did not fount Texture = {0}", m_strLabel);
		glBindTexture(GL_TEXTURE_2D, m_uiTexID);
	}

	void CzvTexture_internal::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
