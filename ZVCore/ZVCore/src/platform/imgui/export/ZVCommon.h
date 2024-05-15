#ifndef __ZV_ZV_COMMON_H__
#define __ZV_ZV_COMMON_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"

#define DzvUI_Bullet				(ImGui::Bullet());
#define DzvUI_Separator				(ImGui::Separator());
#define DzvUI_Text(...)				(ImGui::Text(__VA_ARGS__));
#define DzvUI_Bullet_Text(...)		((DzvUI_Bullet)DzvUI_Text(__VA_ARGS__))
#define DzvUI_Separator_Text(...)	(ImGui::SeparatorText(__VA_ARGS__));

#endif /*__ZV_ZV_COMMON_H__*/
