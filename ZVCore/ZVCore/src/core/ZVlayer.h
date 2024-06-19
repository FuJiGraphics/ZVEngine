#ifndef __ZV_ZVLAYER_H__
#define __ZV_ZVLAYER_H__
#pragma once

#include "Core.h"
#include "../events/ZVevent.h"

namespace ZVLab {

	class ZV_API CzvLayer
	{
	private:
		std::string m_strLabel;

	public:
		CzvLayer(const std::string& label)
			: m_strLabel(label) {}
		virtual ~CzvLayer() = default;

		inline std::string GetLabel() const { return (m_strLabel); }

		virtual void OnAttach()						{};
		virtual void OnDetach()						{};
		virtual void OnEvent(CzvEvent& event)		{};
		virtual void OnUpdate(const float& dt)		{};
		virtual void OnGUI()						{};
		virtual void OnMainMenuBar()				{};
	};

} 

#endif /*__ZV_ZVLAYER_H__*/
