#pragma once

#include "ZVCore.h"

struct TzvImageData
{
	std::string			Name;
	std::string			Path;
	std::string			Class;
};

class CzvImageManager
{
private:
	std::multimap<std::string, TzvImageData> m_mImagePool;

public:
	CzvImageManager(const std::vector<const std::string>& paths);

	bool AddImage(const std::string& category, const std::string& path);
};
