#ifndef __ZV_HOTKEY_H__
#define __ZV_HOTKEY_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVDialog.h"
#include "ZVKeyMap.h"

namespace ZVLab {

	class ZV_API CzvHotKey
	{
	//// Member Variables
	private:
		CzvKeyMap					m_KeyMap;

	//// Member Functions
	public:
		// Constructor, Destructor
		CzvHotKey();
		CzvHotKey(const CzvKeyMap& keymap);
		CzvHotKey(const CzvHotKey& src);
		~CzvHotKey() = default;

		// Getter
		CzvKeyMap	GetKeyMap() const;
		std::string	GetKeyString() const;

		// Others
		bool IsPressed(bool IsRepeatPressedMode = false) const;

		// Operators
		std::ostream& operator<< (std::ostream& os);

		
	};

} // namespace ZVLab
#endif