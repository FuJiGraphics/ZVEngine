#include "ZVlayerBuffer.h"

namespace ZVLab {
	// static
	Unique<CZVlayerBuffer> CZVlayerBuffer::Create()
	{
		return (CreateUnique<CZVlayerBuffer>());
	}

	CZVlayerBuffer::CZVlayerBuffer()
		: m_vContainer()
		, m_uiInsertIndex(0)
		, m_bInitialized(false)
	{/*Empty*/}

	CZVlayerBuffer::~CZVlayerBuffer()
	{
		this->Shutdown();
	}

	void CZVlayerBuffer::Shutdown()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			if (m_vContainer.size())
			{
				for (const auto& Layer : m_vContainer)
				{
					ZVLOG_FAILED(Layer, "FAILED: Failed to deallocate memory.");
					delete Layer;
				}
			}
		}
	}

	bool CZVlayerBuffer::InsertLayer(CZVlayer* pLayer)
	{
		ZVLOG_FAILED(pLayer, "FAILED: Failed to called a emplace");

		auto findLayer = FindLayer(pLayer);
		if (findLayer == m_vContainer.end())
		{
			pLayer->OnAttach();
			m_vContainer.emplace(m_vContainer.begin() + m_uiInsertIndex, pLayer);
			++m_uiInsertIndex;
			m_bInitialized = true;
			return (true);
		}
		return (false);
	}

	bool CZVlayerBuffer::InsertOverlay(CZVlayer* pOverlay)
	{
		ZVLOG_FAILED(pOverlay, "FAILED: Failed to called a emplace_back");

		auto findOverlay = FindLayer(pOverlay);
		if (findOverlay == m_vContainer.end())
		{
			pOverlay->OnAttach();
			m_vContainer.emplace_back(pOverlay);
			m_bInitialized = true;
			return (true);
		}
		return (false);
	}

	bool CZVlayerBuffer::RemoveLayer(CZVlayer* pLayer)
	{
		ZVLOG_FAILED(pLayer, "FAILED: Failed to called a PopLevel");

		auto findLayer = FindLayer(pLayer);
		if (findLayer != m_vContainer.end())
		{
			pLayer->OnDetach();
			m_vContainer.erase(findLayer);
			--m_uiInsertIndex;
			if (m_uiInsertIndex <= 0)
				m_bInitialized = false;
			return (true);
		}
		return (false);
	}

	bool CZVlayerBuffer::RemoveOverlay(CZVlayer* pOverlay)
	{
		ZVLOG_FAILED(pOverlay, "FAILED: Failed to called a PopOverlay");

		auto findOverlay = FindLayer(pOverlay);
		if (findOverlay != m_vContainer.end())
		{
			pOverlay->OnDetach();
			m_vContainer.erase(findOverlay);
			if (m_uiInsertIndex <= 0)
				m_bInitialized = false;
			return (true);
		}
		return (false);
	}

	CZVlayerBuffer::iter CZVlayerBuffer::FindLayer(CZVlayer* pLayer)
	{
		return std::find_if(m_vContainer.begin(), m_vContainer.end(),
							[pLayer](CZVlayer* pTarget)
		{
			return (pLayer == pTarget);
		});
	} // auto CZVlayerBuffer::FindLayer( Layer* pLevel )

} // namespace ZVLab
