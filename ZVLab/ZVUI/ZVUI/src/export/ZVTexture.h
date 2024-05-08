#ifndef __ZV_ZVTEXTURE_H__
#define __ZV_ZVTEXTURE_H__
#pragma once

#include "../ZVCore.h"
#include <string>

namespace ZVLab {

	class ZV_API CzvTexture
	{
	public:
		static Shared<CzvTexture> Create(const std::string& path);

	public:
		virtual inline GLuint			GetID() const = 0;
		virtual inline unsigned int		GetWidth() const = 0;
		virtual inline unsigned int		GetHeight() const = 0;
		virtual inline bool				Empty() const = 0;

	public:
		virtual void Bind() = 0;
		virtual void UnBind() = 0;
	};

} // namespace ZVLab

#endif /*__ZV_ZVTEXTURE_H__*/ 
