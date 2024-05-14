#ifndef __ZV_ZVTEXTURE_H__
#define __ZV_ZVTEXTURE_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include <string>

namespace ZVLab {

	class ZV_API CzvTexture
	{
	//// Member Functions
	public:
		// Generate Object
		static Shared<CzvTexture> Create(const std::string& label);

		// Getter
		virtual inline GLuint			GetID() const = 0;
		virtual inline unsigned int		GetWidth() const = 0;
		virtual inline unsigned int		GetHeight() const = 0;
		virtual inline bool				Empty() const = 0;

		// others
		virtual void					Load(const std::string& path) = 0;
		virtual void					Load(const cv::Mat& cvImageData) = 0;
		virtual void					Bind() = 0;
		virtual void					UnBind() = 0;
		virtual void					Release() = 0;
	};

} // namespace ZVLab

#endif /*__ZV_ZVTEXTURE_H__*/ 
