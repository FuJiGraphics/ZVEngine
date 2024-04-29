#pragma once

/// ----------------------------------------------------------------
/// 모션 제조사 종류를 설정합니다.
/// DMotion_Vendor에 DMotion_Default 또는 DMotion_ACS를 설정합니다.
/// ----------------------------------------------------------------
#pragma region Enabled ZVMotion Vendors
	#define DMotion_Virtual		0
	#define DMotion_ACS			1	

	/// Set ZVMotion Library
	#define DMotion_Vendor DMotion_Virtual
#pragma endregion
/// ----------------------------------------------------------------


/// ----------------------------------------------------------------
///  ZVMotion에서 참조할 헤더 목록
/// ----------------------------------------------------------------
#include <vector>
#include <string>
#include <optional>
#include "ZVAssert.h"
#include "ZVMemory.h"
/// ----------------------------------------------------------------
