#pragma once

/// ----------------------------------------------------------------
/// ��� ������ ������ �����մϴ�.
/// DMotion_Vendor�� DMotion_Default �Ǵ� DMotion_ACS�� �����մϴ�.
/// ----------------------------------------------------------------
#pragma region Enabled ZVMotion Vendors
	#define DMotion_Virtual		0
	#define DMotion_ACS			1	

	/// Set ZVMotion Library
	#define DMotion_Vendor DMotion_Virtual
#pragma endregion
/// ----------------------------------------------------------------
/// 

/// ----------------------------------------------------------------
///  ZVMotion���� ������ ��� ���
/// ----------------------------------------------------------------
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <optional>
#include "ZVAssert.h"
#include "ZVMemory.h"
/// ----------------------------------------------------------------


#define zvStrNull ""
#define zvStrSuccess "Success"
#define zvStrEnglish "English"
#define zvStrKorean "Korean"
#define zvStrChinese "Chinese"