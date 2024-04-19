#ifndef __ZV_ZVLAYER_H__
#define __ZV_ZVLAYER_H__
#pragma once

#include "Core.h"
#include "../events/ZVevent.h"

namespace ZVLab {

	class ZV_API CZVlayer
	{
	public:
		CZVlayer() = default;
		virtual ~CZVlayer() = default;

	public:
		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent(CZVevent& event) {};
		virtual void OnUpdate(const float& dt) {};
		virtual void OnGUI() {};
		virtual void OnMainMenuBar() {};
	};

} 

#endif /*__ZV_ZVLAYER_H__*/
