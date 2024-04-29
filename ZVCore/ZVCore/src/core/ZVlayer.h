#ifndef __ZV_ZVLAYER_H__
#define __ZV_ZVLAYER_H__
#pragma once

#include "Core.h"
#include "../events/ZVevent.h"

namespace ZVLab {

	class ZV_API CzvLayer
	{
	public:
		CzvLayer() = default;
		virtual ~CzvLayer() = default;

	public:
		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent(CzvEvent& event) {};
		virtual void OnUpdate(const float& dt) {};
		virtual void OnGUI() {};
		virtual void OnMainMenuBar() {};
	};

} 

#endif /*__ZV_ZVLAYER_H__*/
