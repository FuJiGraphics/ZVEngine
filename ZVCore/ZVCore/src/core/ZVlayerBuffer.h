#ifndef __ZV_LAYERBUFFER_H__
#define __ZV_LAYERBUFFER_H__
#pragma once

#include "Core.h"
#include "ZVLayer.h"

#include <vector>

namespace ZVLab {

	class ZV_API CzvLayerBuffer
	{
		using iter = std::vector<CzvLayer*>::iterator;
		using const_iter = std::vector<CzvLayer*>::const_iterator;

	public:
		static Unique<CzvLayerBuffer> Create();

	private:
		std::vector<CzvLayer*>		m_vContainer;
		ZVuint						m_uiInsertIndex;
		ZVbool						m_bInitialized;

	public:
		explicit CzvLayerBuffer();
		virtual ~CzvLayerBuffer();

	private:
		CzvLayerBuffer(CzvLayerBuffer&) = delete;
		void operator= (CzvLayerBuffer&) = delete;

	public:
		void		Shutdown();

		ZVbool		InsertLayer(CzvLayer* pLevel);
		ZVbool		InsertOverlay(CzvLayer* pOverlay);
		ZVbool		RemoveLayer(CzvLayer* pLevel);
		ZVbool		RemoveOverlay(CzvLayer* pOverlay);

		CzvLayer*	FindLayer(const std::string& label);

	protected:
		iter FindLayer(CzvLayer* pLevel);

	public:
		inline ZVbool		empty() { return m_vContainer.empty(); }
		inline iter			begin() { return m_vContainer.begin(); }
		inline iter			end()	{ return m_vContainer.end(); }
		inline ZVbool		empty() const { return m_vContainer.empty(); }
		inline const_iter	begin() const { return m_vContainer.begin(); }
		inline const_iter	end()	const { return m_vContainer.end(); }
	};

} // namespace ZVLab

#endif /*__ZV_LAYERBUFFER_H__*/