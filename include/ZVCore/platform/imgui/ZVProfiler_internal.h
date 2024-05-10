#ifndef __ZV_PROFILER_INTERNAL_H__
#define __ZV_PROFILER_INTERNAL_H__
#pragma once

#include "../../core/Core.h"
// imgui
#include "export/ZVProfiler.h"

namespace ZVLab {

	class ZV_API CzvProfiler_internal : public CzvProfiler
	{
		using ProfileChunk			= std::pair<std::string, float>;
		using ProfileMemoryPool		= std::map<std::string, ProfileChunk>;
		using ProfileList			= std::vector<ProfileChunk*>;

	private:
		std::string			m_strLabel;
		ProfileMemoryPool	m_mData;
		ProfileList			m_vDataList;
		bool				m_bOpen;

	public:
		CzvProfiler_internal(const std::string& label);
		virtual ~CzvProfiler_internal();

		virtual void Submit(const TzvTimeStep& data) override;
		virtual void PlotRender() override;
		virtual void TableRender() override;
	};

} // namespace ZVLab

#endif /*__ZV_PROFILER_INTERNAL_H__*/
