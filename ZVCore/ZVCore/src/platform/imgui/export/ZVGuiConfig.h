#ifndef __ZV_ZVGUICONFIG_H__
#define __ZV_ZVGUICONFIG_H__
#pragma once
#include "../../../core/Core.h"

namespace ZVLab { 

// ZVGui Defines
#define DBindLabelNumbering(label, number) (std::string(##label) + std::to_string(##number))
#define DGLuint2ImTextureID(ptr) (reinterpret_cast<void*>(static_cast<intptr_t>(ptr)))
#define DDrawTextureImage(texture, width, height) ImGui::Image(DGLuint2ImTextureID(texture), {static_cast<float>(width), static_cast<float>(height)});

#pragma region Window Focus Options
//----------------------------------------------------
// enum Window Focus Options
//----------------------------------------------------
enum EzvWindowFoucsOptions
{
	ezvWindowFocusFlags_None				= ImGuiFocusedFlags_::ImGuiFocusedFlags_None,
	ezvWindowFocusFlags_ChildWindows		= ImGuiFocusedFlags_::ImGuiFocusedFlags_ChildWindows,
	ezvWindowFocusFlags_RootWindow			= ImGuiFocusedFlags_::ImGuiFocusedFlags_RootWindow,
	ezvWindowFocusFlags_AnyWindow			= ImGuiFocusedFlags_::ImGuiFocusedFlags_AnyWindow,
	ezvWindowFocusFlags_NoPopupHierarchy	= ImGuiFocusedFlags_::ImGuiFocusedFlags_NoPopupHierarchy,
	ezvWindowFocusFlags_DockHierarchy		= ImGuiFocusedFlags_::ImGuiFocusedFlags_DockHierarchy,
	ezvWindowFocusFlags_RootAndChildWindows	= ImGuiFocusedFlags_::ImGuiFocusedFlags_RootAndChildWindows,
};
struct ZV_API TzvWindowFocusedInfo
{
	using WindowFocusedOptions = int;

//// Member Variables
private:
	WindowFocusedOptions	m_iWindowFocusedOptions = ezvWindowFocusFlags_None;

//// Member Functions
public:
	// getter
	inline WindowFocusedOptions	GetOptions() const	{ return (m_iWindowFocusedOptions); }
	inline WindowFocusedOptions	GetOptions()		{ return (m_iWindowFocusedOptions); }

	// setter
	inline void SetOptions(EzvWindowFoucsOptions flags)		{ this->AddOptions(flags); }
	inline void SetNoTitleBar(bool enabled)					{ this->FlagOptions(enabled, ezvWindowFocusFlags_None); }
	inline void SetNoResize(bool enabled)					{ this->FlagOptions(enabled, ezvWindowFocusFlags_ChildWindows);}		
	inline void SetNoMove(bool enabled)						{ this->FlagOptions(enabled, ezvWindowFocusFlags_RootWindow);}	
	inline void SetNoScrollbar(bool enabled)				{ this->FlagOptions(enabled, ezvWindowFocusFlags_AnyWindow);}		
	inline void SetNoScrollWithMouse(bool enabled)			{ this->FlagOptions(enabled, ezvWindowFocusFlags_NoPopupHierarchy);}
	inline void SetNoCollapse(bool enabled)					{ this->FlagOptions(enabled, ezvWindowFocusFlags_DockHierarchy);}
	inline void SetAlwaysAutoResize(bool enabled)			{ this->FlagOptions(enabled, ezvWindowFocusFlags_RootAndChildWindows);}

	// others
	inline bool IsActivated(const EzvWindowFoucsOptions& flags) const { return (m_iWindowFocusedOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvWindowFoucsOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvWindowFoucsOptions& flags) { m_iWindowFocusedOptions |= flags; }
	inline void DelOptions(const EzvWindowFoucsOptions& flags) { m_iWindowFocusedOptions &= ~flags; }
};

#pragma endregion
#pragma region Dialog Options
//----------------------------------------------------
// enum Dialog Options
//----------------------------------------------------
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

enum EzvDialogExtensionOptions
{
	EzvDialogExtensionOptions_None							= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_None,
	EzvDialogExtensionOptions_KeepAliveOnly					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_KeepAliveOnly,
	EzvDialogExtensionOptions_NoDockingOverCentralNode		= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingOverCentralNode,
	EzvDialogExtensionOptions_PassthruCentralNode			= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_PassthruCentralNode,
	EzvDialogExtensionOptions_NoDockingSplit				= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingSplit,
	EzvDialogExtensionOptions_NoResize						= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoResize,
	EzvDialogExtensionOptions_AutoHideTabBar				= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_AutoHideTabBar,
	EzvDialogExtensionOptions_NoUndocking					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoUndocking,
	EzvDialogExtensionOptions_NoSplit						= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoSplit,
	EzvDialogExtensionOptions_NoDockingInCentralNode		= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingInCentralNode,
	EzvDialogExtensionOptions_DockSpace						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockSpace,
	EzvDialogExtensionOptions_CentralNode					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_CentralNode,
	EzvDialogExtensionOptions_NoTabBar						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoTabBar,
	EzvDialogExtensionOptions_HiddenTabBar					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_HiddenTabBar,
	EzvDialogExtensionOptions_NoWindowMenuButton			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoWindowMenuButton,
	EzvDialogExtensionOptions_NoCloseButton					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoCloseButton,
	EzvDialogExtensionOptions_NoResizeX						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeX,
	EzvDialogExtensionOptions_NoResizeY						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeY,
	EzvDialogExtensionOptions_DockedWindowsInFocusRoute		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockedWindowsInFocusRoute,
	EzvDialogExtensionOptions_NoDockingSplitOther			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingSplitOther,
	EzvDialogExtensionOptions_NoDockingOverMe				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverMe,
	EzvDialogExtensionOptions_NoDockingOverOther			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverOther,
	EzvDialogExtensionOptions_NoDockingOverEmpty			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverEmpty,
	EzvDialogExtensionOptions_NoDocking						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDocking,
	EzvDialogExtensionOptions_SharedFlagsInheritMask_		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SharedFlagsInheritMask_,
	EzvDialogExtensionOptions_NoResizeFlagsMask_			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeFlagsMask_,
	EzvDialogExtensionOptions_LocalFlagsTransferMask_		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_LocalFlagsTransferMask_,
	EzvDialogExtensionOptions_SavedFlagsMask_				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SavedFlagsMask_,
};

//----------------------------------------------------
// struct Dialog Info
//----------------------------------------------------
struct ZV_API TzvDialogInfo
{
	using DialogOptions = int;

//// Member Variables
private:
	DialogOptions				m_iDialogOptions			= ezvDialogFlags_None;
	DialogOptions				m_iDialogExtensionOptions	= EzvDialogExtensionOptions_None;

//// Member Functions
public:
	// Getter
	inline DialogOptions	GetOptions()				{ return (m_iDialogOptions); }
	inline DialogOptions	GetOptions() const			{ return (m_iDialogOptions); }
	inline DialogOptions	GetExtensionOptions()		{ return (m_iDialogExtensionOptions); }
	inline DialogOptions	GetExtensionOptions() const	{ return (m_iDialogExtensionOptions); }

	// Setter
	inline void SetOptions(EzvDialogOptions flags)				{ this->AddOptions(flags); }
	inline void SetNoTitleBar(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoTitleBar); }
	inline void SetNoResize(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoResize); }
	inline void SetNoMove(bool enabled)							{ this->FlagOptions(enabled, ezvDialogFlags_NoMove); }
	inline void SetNoScrollbar(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoScrollbar); }
	inline void SetNoScrollWithMouse(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoScrollWithMouse); }
	inline void SetNoCollapse(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoCollapse); }
	inline void SetAlwaysAutoResize(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysAutoResize); }
	inline void SetNoBackground(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoBackground); }
	inline void SetNoSavedSettings(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoSavedSettings); }
	inline void SetNoMouseInputs(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoMouseInputs); }
	inline void SetMenuBar(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_MenuBar); }
	inline void SetHorizontalScrollbar(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_HorizontalScrollbar); }
	inline void SetNoFocusOnAppearing(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_NoFocusOnAppearing); }
	inline void SetNoBringToFrontOnFocus(bool enabled)			{ this->FlagOptions(enabled, ezvDialogFlags_NoBringToFrontOnFocus); }
	inline void SetAlwaysVerticalScrollbar(bool enabled)		{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysVerticalScrollbar); }
	inline void SetAlwaysHorizontalScrollbar(bool enabled)		{ this->FlagOptions(enabled, ezvDialogFlags_AlwaysHorizontalScrollbar); }
	inline void SetNoNavInputs(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoNavInputs); }
	inline void SetNoNavFocus(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoNavFocus); }
	inline void SetUnsavedDocument(bool enabled)				{ this->FlagOptions(enabled, ezvDialogFlags_UnsavedDocument); }
	inline void SetNoDocking(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoDocking); }
	inline void SetNoNav(bool enabled)							{ this->FlagOptions(enabled, ezvDialogFlags_NoNav); }
	inline void SetNoDecoration(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NoDecoration); }
	inline void SetNoInputs(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_NoInputs); }

	// [internal]
	inline void SetNavFlattened(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_NavFlattened); }
	inline void SetChildWindow(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_ChildWindow); }
	inline void SetTooltip(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_Tooltip); }
	inline void SetPopup(bool enabled)							{ this->FlagOptions(enabled, ezvDialogFlags_Popup); }
	inline void SetModal(bool enabled)							{ this->FlagOptions(enabled, ezvDialogFlags_Modal); }
	inline void SetChildMenu(bool enabled)						{ this->FlagOptions(enabled, ezvDialogFlags_ChildMenu); }
	inline void SetDockNodeHost(bool enabled)					{ this->FlagOptions(enabled, ezvDialogFlags_DockNodeHost); }

	// [Dockspace Options]
	inline void SetDocsKeepAliveOnly(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_KeepAliveOnly); }
	inline void SetDocsNoDockingOverCentralNode(bool enabled)	{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingOverCentralNode); }
	inline void SetDocsPassthruCentralNode(bool enabled)		{ this->FlagOptions(enabled,EzvDialogExtensionOptions_PassthruCentralNode); }
	inline void SetDocsNoDockingSplit(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingSplit); }
	inline void SetDocsNoResize(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoResize); }
	inline void SetDocsAutoHideTabBar(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_AutoHideTabBar); }
	inline void SetDocsNoUndocking(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoUndocking); }
	inline void SetDocsNoSplit(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoSplit); }
	inline void SetDocsNoDockingInCentralNode(bool enabled)		{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingInCentralNode); }
	inline void SetDocsDockSpace(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_DockSpace); }
	inline void SetDocsCentralNode(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_CentralNode); }
	inline void SetDocsNoTabBar(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoTabBar); }
	inline void SetDocsHiddenTabBar(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_HiddenTabBar); }
	inline void SetDocsNoWindowMenuButton(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoWindowMenuButton); }
	inline void SetDocsNoCloseButton(bool enabled)				{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoCloseButton); }
	inline void SetDocsNoResizeX(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoResizeX); }
	inline void SetDocsNoResizeY(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoResizeY); }
	inline void SetDocsDockedWindowsInFocusRoute(bool enabled)	{ this->FlagOptions(enabled,EzvDialogExtensionOptions_DockedWindowsInFocusRoute); }
	inline void SetDocsNoDockingSplitOther(bool enabled)		{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingSplitOther); }
	inline void SetDocsNoDockingOverMe(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingOverMe); }
	inline void SetDocsNoDockingOverOther(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingOverOther); }
	inline void SetDocsNoDockingOverEmpty(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDockingOverEmpty); }
	inline void SetDocsNoDocking(bool enabled)					{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoDocking); }
	inline void SetDocsSharedFlagsInheritMask_(bool enabled)	{ this->FlagOptions(enabled,EzvDialogExtensionOptions_SharedFlagsInheritMask_); }
	inline void SetDocsNoResizeFlagsMask_(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_NoResizeFlagsMask_); }
	inline void SetDocsLocalFlagsTransferMask_(bool enabled)	{ this->FlagOptions(enabled,EzvDialogExtensionOptions_LocalFlagsTransferMask_); }
	inline void SetDocsSavedFlagsMask_(bool enabled)			{ this->FlagOptions(enabled,EzvDialogExtensionOptions_SavedFlagsMask_); }

	// others
	inline bool IsActivated(const EzvDialogOptions& flags) const					{ return (m_iDialogOptions & flags); }
	inline bool IsActivated(const EzvDialogExtensionOptions& flags) const			{ return (m_iDialogExtensionOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvDialogOptions& flags)			{ (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void FlagOptions(bool enabled, const EzvDialogExtensionOptions& flags)	{ (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvDialogOptions& flags)							{ m_iDialogOptions |= flags; }
	inline void DelOptions(const EzvDialogOptions& flags)							{ m_iDialogOptions &= ~flags; }
	inline void AddOptions(const EzvDialogExtensionOptions& flags)					{ m_iDialogExtensionOptions |= flags; }
	inline void DelOptions(const EzvDialogExtensionOptions& flags)					{ m_iDialogExtensionOptions &= ~flags; }
};
#pragma endregion
#pragma region Dockspace Options
//----------------------------------------------------
// enum Dockspace Options
//----------------------------------------------------
enum EzvDockspaceOptions
{
	ezvDockspaceFlags_None						= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_None,
	ezvDockspaceFlags_KeepAliveOnly				= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_KeepAliveOnly,
	//ImGuiDockNodeFla      gs_NoCentralNode              
	ezvDockspaceFlags_NoDockingOverCentralNode	= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingOverCentralNode,
	ezvDockspaceFlags_PassthruCentralNode		= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_PassthruCentralNode,
	ezvDockspaceFlags_NoDockingSplit			= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingSplit,
	ezvDockspaceFlags_NoResize					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoResize,
	ezvDockspaceFlags_AutoHideTabBar			= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_AutoHideTabBar,
	ezvDockspaceFlags_NoUndocking				= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoUndocking,
	ezvDockspaceFlags_NoSplit					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoSplit,
	ezvDockspaceFlags_NoDockingInCentralNode	= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingInCentralNode,
	// [Internal]
	ezvDockspaceFlags_DockSpace					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockSpace,
	ezvDockspaceFlags_CentralNode				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_CentralNode,
	ezvDockspaceFlags_NoTabBar					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoTabBar,
	ezvDockspaceFlags_HiddenTabBar				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_HiddenTabBar,
	ezvDockspaceFlags_NoWindowMenuButton		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoWindowMenuButton,
	ezvDockspaceFlags_NoCloseButton				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoCloseButton,
	ezvDockspaceFlags_NoResizeX					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeX,
	ezvDockspaceFlags_NoResizeY					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeY,
	ezvDockspaceFlags_DockedWindowsInFocusRoute	= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockedWindowsInFocusRoute,
	ezvDockspaceFlags_NoDockingSplitOther		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingSplitOther,
	ezvDockspaceFlags_NoDockingOverMe			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverMe,
	ezvDockspaceFlags_NoDockingOverOther		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverOther,
	ezvDockspaceFlags_NoDockingOverEmpty		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverEmpty,
	ezvDockspaceFlags_NoDocking					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDocking,
	ezvDockspaceFlags_SharedFlagsInheritMask_	= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SharedFlagsInheritMask_,
	ezvDockspaceFlags_NoResizeFlagsMask_		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeFlagsMask_,
	ezvDockspaceFlags_LocalFlagsTransferMask_	= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_LocalFlagsTransferMask_,
	ezvDockspaceFlags_SavedFlagsMask_			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SavedFlagsMask_,
};

//----------------------------------------------------
// struct Dockspace Info
//----------------------------------------------------
struct ZV_API TzvDockspaceInfo
{
	using DockspaceOptions = int;

	//// Member Variables
private:
	DockspaceOptions	m_iDockspaceOptions = ezvDockspaceFlags_None;

	//// Member Functions
public:
	// Getter
	inline DockspaceOptions	GetOptions()		{ return (m_iDockspaceOptions); }
	inline DockspaceOptions	GetOptions() const	{ return (m_iDockspaceOptions); }

	// Setter
	inline void SetKeepAliveOnly(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_KeepAliveOnly); }
	inline void SetNoDockingOverCentralNode(bool enabled)	{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingOverCentralNode); }
	inline void SetPassthruCentralNode(bool enabled)		{ this->FlagOptions(enabled, ezvDockspaceFlags_PassthruCentralNode); }
	inline void SetNoDockingSplit(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingSplit); }
	inline void SetNoResize(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoResize); }
	inline void SetAutoHideTabBar(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_AutoHideTabBar); }
	inline void SetNoUndocking(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_NoUndocking); }
	inline void SetNoSplit(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoSplit); }
	inline void SetNoDockingInCentralNode(bool enabled)		{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingInCentralNode); }

	// [internal]
	inline void SetDockSpace(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_DockSpace); }
	inline void SetCentralNode(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_CentralNode); }
	inline void SetNoTabBar(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoTabBar); }
	inline void SetHiddenTabBar(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_HiddenTabBar); }
	inline void SetNoWindowMenuButton(bool enabled)			{ this->FlagOptions(enabled, ezvDockspaceFlags_NoWindowMenuButton); }
	inline void SetNoCloseButton(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_NoCloseButton); }
	inline void SetNoResizeX(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoResizeX); }
	inline void SetNoResizeY(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoResizeY); }
	inline void SetDockedWindowsInFocusRoute(bool enabled)	{ this->FlagOptions(enabled, ezvDockspaceFlags_DockedWindowsInFocusRoute); }
	inline void SetNoDockingSplitOther(bool enabled)		{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingSplitOther); }
	inline void SetNoDockingOverMe(bool enabled)			{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingOverMe); }
	inline void SetNoDockingOverOther(bool enabled)			{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingOverOther); }
	inline void SetNoDockingOverEmpty(bool enabled)			{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDockingOverEmpty); }
	inline void SetNoDocking(bool enabled)					{ this->FlagOptions(enabled, ezvDockspaceFlags_NoDocking); }
	inline void SetSharedFlagsInheritMask(bool enabled)		{ this->FlagOptions(enabled, ezvDockspaceFlags_SharedFlagsInheritMask_); }
	inline void SetNoResizeFlagsMask(bool enabled)			{ this->FlagOptions(enabled, ezvDockspaceFlags_NoResizeFlagsMask_); }
	inline void SetLocalFlagsTransferMask(bool enabled)		{ this->FlagOptions(enabled, ezvDockspaceFlags_LocalFlagsTransferMask_); }
	inline void SetSavedFlagsMask(bool enabled)				{ this->FlagOptions(enabled, ezvDockspaceFlags_SavedFlagsMask_); }

	// others
	inline bool IsActivated(const EzvDockspaceOptions& flags) const { return (m_iDockspaceOptions & flags); }
	inline bool	IsNone() const { return (m_iDockspaceOptions == ezvDockspaceFlags_None); }
	inline void FlagOptions(bool enabled, const EzvDockspaceOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvDockspaceOptions& flags) { m_iDockspaceOptions |= flags; }
	inline void DelOptions(const EzvDockspaceOptions& flags) { m_iDockspaceOptions &= ~flags; }
};
#pragma endregion
#pragma region TabBar Options
//----------------------------------------------------
// enum Tab Bar Options
//----------------------------------------------------
enum EzvTabBarOptions
{
	ezvTabBarOptions_None							= ImGuiTabBarFlags_::ImGuiTabBarFlags_None,
	ezvTabBarOptions_Reorderable					= ImGuiTabBarFlags_::ImGuiTabBarFlags_Reorderable,
	ezvTabBarOptions_AutoSelectNewTabs				= ImGuiTabBarFlags_::ImGuiTabBarFlags_AutoSelectNewTabs,
	ezvTabBarOptions_TabListPopupButton				= ImGuiTabBarFlags_::ImGuiTabBarFlags_TabListPopupButton,
	ezvTabBarOptions_NoCloseWithMiddleMouseButton	= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoCloseWithMiddleMouseButton,
	ezvTabBarOptions_NoTabListScrollingButtons		= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoTabListScrollingButtons,
	ezvTabBarOptions_NoTooltip						= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoTooltip,
	ezvTabBarOptions_FittingPolicyResizeDown		= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyResizeDown,
	ezvTabBarOptions_FittingPolicyScroll			= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyScroll,
	ezvTabBarOptions_FittingPolicyMask_				= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyMask_,
	ezvTabBarOptions_FittingPolicyDefault_			= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyDefault_,
};

//----------------------------------------------------
// struct Tab Bar Info
//----------------------------------------------------
struct ZV_API TzvTabBarInfo
{
	using TabBarOptions = int;

//// Member Variables
private:
	TabBarOptions	m_iTabBarOptions = ezvTabBarOptions_None;

//// Member Functions
public:
	// Getter
	inline TabBarOptions	GetOptions()	{ return (m_iTabBarOptions); }

	// Setter
	inline void SetOptions(EzvTabBarOptions flags)				{ this->AddOptions(flags); }
	inline void SetReorderable(bool enabled)					{ this->FlagOptions(enabled, ezvTabBarOptions_Reorderable);  }
	inline void SetAutoSelectNewTabs(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarOptions_AutoSelectNewTabs); }
	inline void SetTabListPopupButton(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarOptions_TabListPopupButton); }
	inline void SetNoCloseWithMiddleMouseButton(bool enabled)	{ this->FlagOptions(enabled, ezvTabBarOptions_NoCloseWithMiddleMouseButton); }
	inline void SetNoTabListScrollingButtons(bool enabled)		{ this->FlagOptions(enabled, ezvTabBarOptions_NoTabListScrollingButtons); }
	inline void SetNoTooltip(bool enabled)						{ this->FlagOptions(enabled, ezvTabBarOptions_NoTooltip); }
	inline void SetFittingPolicyResizeDown(bool enabled)		{ this->FlagOptions(enabled, ezvTabBarOptions_FittingPolicyResizeDown); }
	inline void SetFittingPolicyScroll(bool enabled)			{ this->FlagOptions(enabled, ezvTabBarOptions_FittingPolicyScroll); }
	inline void SetFittingPolicyMask_(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarOptions_FittingPolicyMask_); }
	inline void SetFittingPolicyDefault_(bool enabled)			{ this->FlagOptions(enabled, ezvTabBarOptions_FittingPolicyDefault_); }

	// Others
	inline bool IsActivated(const EzvTabBarOptions& flags)					{ return (m_iTabBarOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvTabBarOptions& flags)	{ (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvTabBarOptions& flags)					{ m_iTabBarOptions |= flags; }
	inline void DelOptions(const EzvTabBarOptions& flags)					{ m_iTabBarOptions &= ~flags; }
};
#pragma endregion
#pragma region TabItem Options
//----------------------------------------------------
// enum Tab Item Options
//----------------------------------------------------
enum EzvTabItemOptions
{
	ezvTabItemOptions_None								= ImGuiTabItemFlags_::ImGuiTabItemFlags_None,
	ezvTabItemOptions_UnsavedDocument					= ImGuiTabItemFlags_::ImGuiTabItemFlags_UnsavedDocument,
	ezvTabItemOptions_SetSelected						= ImGuiTabItemFlags_::ImGuiTabItemFlags_SetSelected,
	ezvTabItemOptions_NoCloseWithMiddleMouseButton		= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoCloseWithMiddleMouseButton,
	ezvTabItemOptions_NoPushId							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoPushId,
	ezvTabItemOptions_NoTooltip							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoTooltip,
	ezvTabItemOptions_NoReorder							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoReorder,
	ezvTabItemOptions_Leading							= ImGuiTabItemFlags_::ImGuiTabItemFlags_Leading,
	ezvTabItemOptions_Trailing							= ImGuiTabItemFlags_::ImGuiTabItemFlags_Trailing,
	ezvTabItemOptions_NoAssumedClosure					= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoAssumedClosure,
};

//----------------------------------------------------
// struct Tab Item Info
//----------------------------------------------------
struct ZV_API TzvTabItemInfo
{
	using TabItemOptions = int;

//// Member Variables
private:
	TabItemOptions	m_iTabItemOptions = ezvTabItemOptions_None;

//// Member Functions
public:
	// Getter
	inline TabItemOptions	GetOptions() { return (m_iTabItemOptions); }

	// Setter
	inline void SetOptions(EzvTabItemOptions flags)				{ this->AddOptions(flags); }
	inline void SetUnsavedDocument(bool enabled)				{ this->FlagOptions(enabled, ezvTabItemOptions_UnsavedDocument);  }
	inline void SetSetSelected(bool enabled)					{ this->FlagOptions(enabled, ezvTabItemOptions_SetSelected); }
	inline void SetNoCloseWithMiddleMouseButton(bool enabled)	{ this->FlagOptions(enabled, ezvTabItemOptions_NoCloseWithMiddleMouseButton); }
	inline void SetNoPushId(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemOptions_NoPushId); }
	inline void SetNoTooltip(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemOptions_NoTooltip); }
	inline void SetNoReorder(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemOptions_NoReorder); }
	inline void SetLeading(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemOptions_Leading); }
	inline void SetTrailing(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemOptions_Trailing); }
	inline void SetNoAssumedClosure(bool enabled)				{ this->FlagOptions(enabled, ezvTabItemOptions_NoAssumedClosure); }
	
	// Others
	inline bool IsActivated(const EzvTabItemOptions& flags)					{ return (m_iTabItemOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvTabItemOptions& flags)	{ (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvTabItemOptions& flags)					{ m_iTabItemOptions |= flags; }
	inline void DelOptions(const EzvTabItemOptions& flags)					{ m_iTabItemOptions &= ~flags; }
};
#pragma endregion
#pragma region ComboBox Options
//----------------------------------------------------
// enum ComboBox Options
//----------------------------------------------------
enum EzvComboBoxOptions
{
	ezvComboBoxFlags_None                   = ImGuiComboFlags_::ImGuiComboFlags_None,
	ezvComboBoxFlags_PopupAlignLeft         = ImGuiComboFlags_::ImGuiComboFlags_PopupAlignLeft,
	ezvComboBoxFlags_HeightSmall            = ImGuiComboFlags_::ImGuiComboFlags_HeightSmall,
	ezvComboBoxFlags_HeightRegular          = ImGuiComboFlags_::ImGuiComboFlags_HeightRegular,
	ezvComboBoxFlags_HeightLarge            = ImGuiComboFlags_::ImGuiComboFlags_HeightLarge,
	ezvComboBoxFlags_HeightLargest          = ImGuiComboFlags_::ImGuiComboFlags_HeightLargest,
	ezvComboBoxFlags_NoArrowButton          = ImGuiComboFlags_::ImGuiComboFlags_NoArrowButton,
	ezvComboBoxFlags_NoPreview              = ImGuiComboFlags_::ImGuiComboFlags_NoPreview,
	ezvComboBoxFlags_WidthFitPreview        = ImGuiComboFlags_::ImGuiComboFlags_WidthFitPreview,
	ezvComboBoxFlags_HeightMask_            = ImGuiComboFlags_::ImGuiComboFlags_HeightMask_,
};

//----------------------------------------------------
// struct ComboBox Info
//----------------------------------------------------
struct ZV_API TzvComboBoxInfo
{
	using ComboBoxOptions = int;

	//// Member Variables
private:
	ComboBoxOptions	m_iComboBoxOptions = ezvComboBoxFlags_None;

	//// Member Functions
public:
	// Getter
	inline ComboBoxOptions	GetOptions() { return (m_iComboBoxOptions); }

	// Setter
	inline void SetPopupAlignLeft(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_PopupAlignLeft  ); }
	inline void SetHeightSmall(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_HeightSmall     ); }
	inline void SetHeightRegular(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_HeightRegular   ); }
	inline void SetHeightLarge(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_HeightLarge     ); }
	inline void SetHeightLargest(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_HeightLargest   ); }
	inline void SetNoArrowButton(bool enabled)			{ this->FlagOptions(enabled, ezvComboBoxFlags_NoArrowButton   ); }
	inline void SetNoPreview(bool enabled)				{ this->FlagOptions(enabled, ezvComboBoxFlags_NoPreview       ); }
	inline void SetWidthFitPreview(bool enabled)		{ this->FlagOptions(enabled, ezvComboBoxFlags_WidthFitPreview ); }
	inline void SetHeightMask(bool enabled)				{ this->FlagOptions(enabled, ezvComboBoxFlags_HeightMask_     ); }

	// Others
	inline bool IsActivated(const EzvComboBoxOptions& flags) { return (m_iComboBoxOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvComboBoxOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvComboBoxOptions& flags) { m_iComboBoxOptions |= flags; }
	inline void DelOptions(const EzvComboBoxOptions& flags) { m_iComboBoxOptions &= ~flags; }
};


#pragma endregion
#pragma region Input Text
//----------------------------------------------------
// enum InputText Options
//----------------------------------------------------
enum EzvInputTextOptions 
{
	EzvInputTextOptions_None					= ImGuiInputTextFlags_::ImGuiInputTextFlags_None,
	EzvInputTextOptions_CharsDecimal       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsDecimal,		 // Allow 0123456789.+-*/
	EzvInputTextOptions_CharsHexadecimal   		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsHexadecimal,	 // Allow 0123456789ABCDEFabcdef
	EzvInputTextOptions_CharsUppercase     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsUppercase,		 // Turn a..z into A..Z
	EzvInputTextOptions_CharsNoBlank       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsNoBlank,		 // Filter out spaces, tabs
	EzvInputTextOptions_AutoSelectAll      		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AutoSelectAll,		 // Select entire text when first taking mouse focus
	EzvInputTextOptions_EnterReturnsTrue   		= ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue,	 // Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
	EzvInputTextOptions_CallbackCompletion 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCompletion,  // Callback on pressing TAB (for completion handling)
	EzvInputTextOptions_CallbackHistory    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackHistory,	 // Callback on pressing Up/Down arrows (for history handling)
	EzvInputTextOptions_CallbackAlways     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackAlways,		 // Callback on each iteration. User code may query cursor position, modify text buffer.
	EzvInputTextOptions_CallbackCharFilter 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCharFilter,  // Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
	EzvInputTextOptions_AllowTabInput      		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AllowTabInput,		 // Pressing TAB input a '\t' character into the text field
	EzvInputTextOptions_CtrlEnterForNewLine		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CtrlEnterForNewLine, // In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter).
	EzvInputTextOptions_NoHorizontalScroll 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_NoHorizontalScroll,  // Disable following the cursor horizontally
	EzvInputTextOptions_AlwaysOverwrite    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AlwaysOverwrite,	 // Overwrite mode
	EzvInputTextOptions_ReadOnly           		= ImGuiInputTextFlags_::ImGuiInputTextFlags_ReadOnly,			 // Read-only mode
	EzvInputTextOptions_Password           		= ImGuiInputTextFlags_::ImGuiInputTextFlags_Password,			 // Password mode, display all characters as '*'
	EzvInputTextOptions_NoUndoRedo         		= ImGuiInputTextFlags_::ImGuiInputTextFlags_NoUndoRedo,			 // Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
	EzvInputTextOptions_CharsScientific    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsScientific,	 // Allow 0123456789.+-*/eE (Scientific notation input)
	EzvInputTextOptions_CallbackResize     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackResize,		 // Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
	EzvInputTextOptions_CallbackEdit       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackEdit,		 // Callback on any edit (note that InputText() already returns true on edit, the callback is useful mainly to manipulate the underlying buffer while focus is active)
	EzvInputTextOptions_EscapeClearsAll    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_EscapeClearsAll,	 // Escape key clears content if not empty, and deactivate otherwise (contrast to default behavior of Escape to revert)
};

//----------------------------------------------------
// struct InputText Info
//----------------------------------------------------
struct ZV_API TzvInputTextInfo
{
	using InputTextOptions = int;

	//// Member Variables
private:
	InputTextOptions	m_iInputTextOptions = EzvInputTextOptions_None;

	//// Member Functions
public:
	// Getter
	inline InputTextOptions	GetOptions() { return (m_iInputTextOptions); }
	inline InputTextOptions	GetOptions() const { return (m_iInputTextOptions); }

	// Setter
	inline void	SetCharsDecimal(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CharsDecimal);}
	inline void	SetCharsHexadecimal(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_CharsHexadecimal);}
	inline void	SetCharsUppercase(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CharsUppercase);}
	inline void	SetCharsNoBlank(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CharsNoBlank);}
	inline void	SetAutoSelectAll(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_AutoSelectAll);}
	inline void	SetEnterReturnsTrue(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_EnterReturnsTrue);}
	inline void	SetCallbackCompletion(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackCompletion);}
	inline void	SetCallbackHistory(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackHistory);}
	inline void	SetCallbackAlways(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackAlways);}
	inline void	SetCallbackCharFilter(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackCharFilter);}
	inline void	SetAllowTabInput(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_AllowTabInput);}
	inline void	SetCtrlEnterForNewLine(bool enabled)	{ this->FlagOptions(enabled, EzvInputTextOptions_CtrlEnterForNewLine);}
	inline void	SetNoHorizontalScroll(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_NoHorizontalScroll);}
	inline void	SetAlwaysOverwrite(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_AlwaysOverwrite);}
	inline void	SetReadOnly(bool enabled)				{ this->FlagOptions(enabled, EzvInputTextOptions_ReadOnly);}
	inline void	SetPassword(bool enabled)				{ this->FlagOptions(enabled, EzvInputTextOptions_Password);}
	inline void	SetNoUndoRedo(bool enabled)				{ this->FlagOptions(enabled, EzvInputTextOptions_NoUndoRedo);}
	inline void	SetCharsScientific(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_CharsScientific);}
	inline void	SetCallbackResize(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackResize);}
	inline void	SetCallbackEdit(bool enabled)			{ this->FlagOptions(enabled, EzvInputTextOptions_CallbackEdit);}
	inline void	SetEscapeClearsAll(bool enabled)		{ this->FlagOptions(enabled, EzvInputTextOptions_EscapeClearsAll);}

	// Others
	inline bool IsActivated(const EzvInputTextOptions& flags) { return (m_iInputTextOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvInputTextOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvInputTextOptions& flags) { m_iInputTextOptions |= flags; }
	inline void DelOptions(const EzvInputTextOptions& flags) { m_iInputTextOptions &= ~flags; }
};

#pragma endregion

} // namespace ZVLab
#endif /*__ZV_ZVGUICONFIG_H__*/

