#ifndef __ZV_LAYERBUFFER_H__
#define __ZV_LAYERBUFFER_H__
#pragma once

#include "Core.h"
#include "ZVlayer.h"

#include <vector>

namespace ZVLab {

	class ZV_API CZVlayerBuffer
	{
		using iter = std::vector<CZVlayer*>::iterator;
		using const_iter = std::vector<CZVlayer*>::const_iterator;

	public:
		static Unique<CZVlayerBuffer> Create();

	private:
		std::vector<CZVlayer*>		m_vContainer;
		ZVuint						m_uiInsertIndex;
		ZVbool						m_bInitialized;

	public:
		explicit CZVlayerBuffer();
		virtual ~CZVlayerBuffer();

	private:
		CZVlayerBuffer(CZVlayerBuffer&) = delete;
		void operator= (CZVlayerBuffer&) = delete;

	public:
		void	Shutdown();

		ZVbool	InsertLayer(CZVlayer* pLevel);
		ZVbool	InsertOverlay(CZVlayer* pOverlay);
		ZVbool	RemoveLayer(CZVlayer* pLevel);
		ZVbool	RemoveOverlay(CZVlayer* pOverlay);

	protected:
		iter FindLayer(CZVlayer* pLevel);

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
