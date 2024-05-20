#include "ZVLayerBuffer.h"

namespace ZVLab {
	// static
	Unique<CzvLayerBuffer> CzvLayerBuffer::Create()
	{
		return (CreateUnique<CzvLayerBuffer>());
	}

	CzvLayerBuffer::CzvLayerBuffer()
		: m_vContainer()
		, m_uiInsertIndex(0)
		, m_bInitialized(false)
	{/*Empty*/
	}

	CzvLayerBuffer::~CzvLayerBuffer()
	{
		this->Shutdown();
	}

	void CzvLayerBuffer::Shutdown()
	{
		if (m_bInitialized)
		{
			m_bInitialized = false;
			if (m_vContainer.size())
			{
				for (auto Layer : m_vContainer)
				{
					DZVLog_Failed(Layer, "FAILED: Failed to deallocate memory.");
					Layer->OnDetach();
					delete Layer;
				}
			}
		}
	}

	bool CzvLayerBuffer::InsertLayer(CzvLayer* pLayer)
	{
		DZVLog_Failed(pLayer, "FAILED: Failed to called a emplace_back");

		auto findLayer = FindLayer(pLayer);
		if (findLayer == m_vContainer.end())
		{
			pLayer->OnAttach();
			m_vContainer.emplace_back(pLayer);
			m_bInitialized = true;
			return (true);
		}
		return (false);
	}

	bool CzvLayerBuffer::InsertOverlay(CzvLayer* pOverlay)
	{
		DZVLog_Failed(pOverlay, "FAILED: Failed to called a emplace");

		auto findOverlay = FindLayer(pOverlay);
		if (findOverlay == m_vContainer.end())
		{
			pOverlay->OnAttach();
			m_vContainer.emplace(m_vContainer.begin() + m_uiInsertIndex, pOverlay);
			++m_uiInsertIndex;
			m_bInitialized = true;
			return (true);
		}
		return (false);
	}

	bool CzvLayerBuffer::RemoveLayer(CzvLayer* pLayer)
	{
		DZVLog_Failed(pLayer, "FAILED: Failed to called a PopOverlay");

		auto findLayer = FindLayer(pLayer);
		if (findLayer != m_vContainer.end())
		{
			pLayer->OnDetach();
			m_vContainer.erase(findLayer);
			if (m_uiInsertIndex <= 0)
				m_bInitialized = false;
			return (true);
		}
		return (false);
	}


	bool CzvLayerBuffer::RemoveOverlay(CzvLayer* pOverlay)
	{
		DZVLog_Failed(pOverlay, "FAILED: Failed to called a PopLevel");

		auto findOverlay = FindLayer(pOverlay);
		if (findOverlay != m_vContainer.end())
		{
			pOverlay->OnDetach();
			m_vContainer.erase(findOverlay);
			--m_uiInsertIndex;
			if (m_uiInsertIndex <= 0)
				m_bInitialized = false;
			return (true);
		}
		return (false);
	}

	CzvLayerBuffer::iter CzvLayerBuffer::FindLayer(CzvLayer* pLayer)
	{
		return std::find_if(m_vContainer.begin(), m_vContainer.end(),
							[pLayer](CzvLayer* pTarget)
		{
			return (pLayer == pTarget);
		});
	} // auto CzvLayerBuffer::FindLayer( Layer* pLevel )

} // namespace ZVLab