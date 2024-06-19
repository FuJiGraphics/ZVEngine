#include "ImageManager.h"

CzvImageManager::CzvImageManager(const std::vector<const std::string>& paths)
{
}

bool CzvImageManager::AddImage(const std::string& category, const std::string& path)
{
	auto iter = m_mImagePool.insert({ category, {path, {}} });

	return (true);
}
