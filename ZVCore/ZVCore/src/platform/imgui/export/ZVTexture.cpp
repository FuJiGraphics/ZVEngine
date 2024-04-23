#include "ZVTexture.h"
#include "../ZVTexture_impl.h"

namespace ZVLab {

	Shared<CZVTexture> CZVTexture::Create(const std::string& path)
	{
		return (CreateShared<CZVTexture_impl>(path));
	}

}
