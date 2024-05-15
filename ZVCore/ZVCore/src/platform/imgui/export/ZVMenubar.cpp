#include "ZVMenubar.h"

namespace ZVLab {
	bool ZVLab::CzvMenuBar::Synchronization()
	{
		return false;
	}

	CzvMenuBar::CzvMenuBar(const std::string& label)
		: m_strLabel(label)
	{

	}

	CzvMenuBar::~CzvMenuBar()
	{
	}

} // namespace ZVLab
