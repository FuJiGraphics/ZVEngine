#pragma once

#include "../ZVCore.h"
#include <chrono>

#define DZVTimer_CurrentTime std::chrono::high_resolution_clock::now()
#define DZVTimer_ConvertNanoseconds(hrc) std::chrono::duration_cast<std::chrono::nanoseconds>(hrc)

namespace ZVLab {

	enum class EzvTimerUnit : int
	{
		eTimeUnit_Nanoseconds,
		eTimeUnit_Microseconds,
		eTimeUnit_Milliseconds,
		eTimeUnit_Seconds,
	};

	class ZV_API CzvTimer
	{
	public:
		CzvTimer()
		{
			this->Reset();
		}

		void Reset()
		{
			m_startTime = DZVTimer_CurrentTime;
		}

		float Elapsed(EzvTimerUnit unit = EzvTimerUnit::eTimeUnit_Nanoseconds) const
		{
			auto elapsedTime = DZVTimer_ConvertNanoseconds(DZVTimer_CurrentTime - m_startTime).count();
			return CalcTimeUnit(static_cast<float>(elapsedTime), unit);
		}

	private:
		float CalcTimeUnit(const float& e, const EzvTimerUnit& unit) const
		{
			return	/*micros*/	(unit == EzvTimerUnit::eTimeUnit_Microseconds) ? (e * 0.001f) :
				/*millis*/	(unit == EzvTimerUnit::eTimeUnit_Milliseconds) ? (e * 0.001f * 0.001f) :
				/*seconds*/	(unit == EzvTimerUnit::eTimeUnit_Seconds) ? (e * 0.001f * 0.001f * 0.001f) :
				/*return*/	(e);
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
	};
}