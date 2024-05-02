#include "ZVTexture.h"
#include "../ZVTexture_internal.h"

namespace ZVLab {

	Shared<CzvTexture> CzvTexture::Create(const std::string& path)
	{
		return (CreateShared<CzvTexture_internal>(path));
	}

}
