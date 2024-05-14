#include "ZVTexture.h"
#include "../ZVTexture_internal.h"

namespace ZVLab {

	Shared<CzvTexture> CzvTexture::Create(const std::string& label)
	{
		return (CreateShared<CzvTexture_internal>(label));
	}

}
