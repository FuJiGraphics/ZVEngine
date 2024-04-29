#ifndef __ZV_ZVGUICONFIG_H__
#define __ZV_ZVGUICONFIG_H__
#pragma once
#include "../../../core/Core.h"

// ZVGui Defines
#define DBindLabelNumbering(label, number) (std::string(##label) + std::to_string(##number))

#pragma region Dialog Options
enum EzvDialogOptions
{
	ezvDialogFlags_None							= ImGuiWindowFlags_::ImGuiWindowFlags_None,
	ezvDialogFlags_NoTitleBar					= ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar,
	ezvDialogFlags_NoResize						= ImGuiWindowFlags_::ImGuiWindowFlags_NoResize,
	ezvDialogFlags_NoMove						= ImGuiWindowFlags_::ImGuiWindowFlags_NoMove,
	ezvDialogFlags_NoScrollbar					= ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar,
	ezvDialogFlags_NoScrollWithMouse			= ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollWithMouse,
	ezvDialogFlags_NoCollapse					= ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse,
	ezvDialogFlags_AlwaysAutoResize				= ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize,
	ezvDialogFlags_NoBackground					= ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground,
	ezvDialogFlags_NoSavedSettings				= ImGuiWindowFlags_::ImGuiWindowFlags_NoSavedSettings,
	ezvDialogFlags_NoMouseInputs				= ImGuiWindowFlags_::ImGuiWindowFlags_NoMouseInputs,
	ezvDialogFlags_MenuBar						= ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar,
	ezvDialogFlags_HorizontalScrollbar			= ImGuiWindowFlags_::ImGuiWindowFlags_HorizontalScrollbar,
	ezvDialogFlags_NoFocusOnAppearing			= ImGuiWindowFlags_::ImGuiWindowFlags_NoFocusOnAppearing,
	ezvDialogFlags_NoBringToFrontOnFocus		= ImGuiWindowFlags_::ImGuiWindowFlags_NoBringToFrontOnFocus,
	ezvDialogFlags_AlwaysVerticalScrollbar		= ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysVerticalScrollbar,
	ezvDialogFlags_AlwaysHorizontalScrollbar	= ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysHorizontalScrollbar,
	ezvDialogFlags_NoNavInputs					= ImGuiWindowFlags_::ImGuiWindowFlags_NoNavInputs,
	ezvDialogFlags_NoNavFocus					= ImGuiWindowFlags_::ImGuiWindowFlags_NoNavFocus,
	ezvDialogFlags_UnsavedDocument				= ImGuiWindowFlags_::ImGuiWindowFlags_UnsavedDocument,
	ezvDialogFlags_NoDocking					= ImGuiWindowFlags_::ImGuiWindowFlags_NoDocking,
	ezvDialogFlags_NoNav						= ImGuiWindowFlags_::ImGuiWindowFlags_NoNav,
	ezvDialogFlags_NoDecoration					= ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration,
	ezvDialogFlags_NoInputs						= ImGuiWindowFlags_::ImGuiWindowFlags_NoInputs,

	// [Internal]
	ezvDialogFlags_NavFlattened					= ImGuiWindowFlags_::ImGuiWindowFlags_NavFlattened,
	ezvDialogFlags_ChildWindow					= ImGuiWindowFlags_::ImGuiWindowFlags_ChildWindow,
	ezvDialogFlags_Tooltip						= ImGuiWindowFlags_::ImGuiWindowFlags_Tooltip,
	ezvDialogFlags_Popup						= ImGuiWindowFlags_::ImGuiWindowFlags_Popup,
	ezvDialogFlags_Modal						= ImGuiWindowFlags_::ImGuiWindowFlags_Modal,
	ezvDialogFlags_ChildMenu					= ImGuiWindowFlags_::ImGuiWindowFlags_ChildMenu,
	ezvDialogFlags_DockNodeHost					= ImGuiWindowFlags_::ImGuiWindowFlags_DockNodeHost,
};

struct ZV_API TzvDialogInfo
{
	using DialogOptions = int;

	/// members
private:
	DialogOptions	m_uiDialogOptions = ezvDialogFlags_None;

	/// getter
public:
	inline DialogOptions	GetOptions()	{ return (m_uiDialogOptions); }

	/// setter
public:
	inline void SetOptions(EzvDialogOptions flags)			{ this->AddOptions(flags); }
	inline void SetNoTitleBar(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoTitleBar); }
	inline void SetNoResize(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoResize); }
	inline void SetNoMove(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoMove); }
	inline void SetNoScrollbar(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoScrollbar); }
	inline void SetNoScrollWithMouse(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_NoScrollWithMouse); }
	inline void SetNoCollapse(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoCollapse); }
	inline void SetAlwaysAutoResize(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysAutoResize); }
	inline void SetNoBackground(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoBackground); }
	inline void SetNoSavedSettings(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_NoSavedSettings); }
	inline void SetNoMouseInputs(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoMouseInputs); }
	inline void SetMenuBar(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_MenuBar); }
	inline void SetHorizontalScrollbar(bool enabled)		{ this->FlagOptions(enabled, ezvDialogFlags_HorizontalScrollbar); }
	inline void SetNoFocusOnAppearing(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_NoFocusOnAppearing); }
	inline void SetNoBringToFrontOnFocus(bool enabled)		{ this->FlagOptions(enabled, ezvDialogFlags_NoBringToFrontOnFocus); }
	inline void SetAlwaysVerticalScrollbar(bool enabled)	{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysVerticalScrollbar); }
	inline void SetAlwaysHorizontalScrollbar(bool enabled)	{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysHorizontalScrollbar); }
	inline void SetNoNavInputs(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoNavInputs); }
	inline void SetNoNavFocus(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoNavFocus); }
	inline void SetUnsavedDocument(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_UnsavedDocument); }
	inline void SetNoDocking(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoDocking); }
	inline void SetNoNav(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoNav); }
	inline void SetNoDecoration(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoDecoration); }
	inline void SetNoInputs(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoInputs); }

	// [internal]
	inline void SetNavFlattened(bool enabled)	{  this->FlagOptions(enabled, ezvDialogFlags_NavFlattened); }
	inline void SetChildWindow(bool enabled)	{  this->FlagOptions(enabled, ezvDialogFlags_ChildWindow); }
	inline void SetTooltip(bool enabled)		{  this->FlagOptions(enabled, ezvDialogFlags_Tooltip); }
	inline void SetPopup(bool enabled)			{  this->FlagOptions(enabled, ezvDialogFlags_Popup); }
	inline void SetModal(bool enabled)			{  this->FlagOptions(enabled, ezvDialogFlags_Modal); }
	inline void SetChildMenu(bool enabled)		{  this->FlagOptions(enabled, ezvDialogFlags_ChildMenu); }
	inline void SetDockNodeHost(bool enabled)	{  this->FlagOptions(enabled, ezvDialogFlags_DockNodeHost); }

	/// others
public:
	inline void FlagOptions(bool enabled, const EzvDialogOptions& flag) { (enabled) ? this->AddOptions(flag) : this->DelOptions(flag); }
	inline void AddOptions(const EzvDialogOptions& flag) { m_uiDialogOptions |= flag; }
	inline void DelOptions(const EzvDialogOptions& flag) { m_uiDialogOptions &= ~flag; }
};
#pragma endregion

#endif /*__ZV_ZVGUICONFIG_H__*/
