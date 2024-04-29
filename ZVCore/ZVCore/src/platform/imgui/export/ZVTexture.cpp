#include "ZVTexture.h"
#include "../ZVTexture_impl.h"

namespace ZVLab {

	Shared<CzvTexture> CzvTexture::Create(const std::string& path)
	{
		return (CreateShared<CZVTexture_impl>(path));
	}

}
