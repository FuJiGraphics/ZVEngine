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
	ezvDialogExtensionFlags_None							= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_None,
	ezvDialogExtensionFlags_KeepAliveOnly					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_KeepAliveOnly,
	ezvDialogExtensionFlags_NoDockingOverCentralNode		= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingOverCentralNode,
	ezvDialogExtensionFlags_PassthruCentralNode				= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_PassthruCentralNode,
	ezvDialogExtensionFlags_NoDockingSplit					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingSplit,
	ezvDialogExtensionFlags_NoResize						= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoResize,
	ezvDialogExtensionFlags_AutoHideTabBar					= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_AutoHideTabBar,
	ezvDialogExtensionFlags_NoUndocking						= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoUndocking,
	ezvDialogExtensionFlags_NoSplit							= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoSplit,
	ezvDialogExtensionFlags_NoDockingInCentralNode			= ImGuiDockNodeFlags_::ImGuiDockNodeFlags_NoDockingInCentralNode,
	ezvDialogExtensionFlags_DockSpace						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockSpace,
	ezvDialogExtensionFlags_CentralNode						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_CentralNode,
	ezvDialogExtensionFlags_NoTabBar						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoTabBar,
	ezvDialogExtensionFlags_HiddenTabBar					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_HiddenTabBar,
	ezvDialogExtensionFlags_NoWindowMenuButton				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoWindowMenuButton,
	ezvDialogExtensionFlags_NoCloseButton					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoCloseButton,
	ezvDialogExtensionFlags_NoResizeX						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeX,
	ezvDialogExtensionFlags_NoResizeY						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeY,
	ezvDialogExtensionFlags_DockedWindowsInFocusRoute		= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_DockedWindowsInFocusRoute,
	ezvDialogExtensionFlags_NoDockingSplitOther				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingSplitOther,
	ezvDialogExtensionFlags_NoDockingOverMe					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverMe,
	ezvDialogExtensionFlags_NoDockingOverOther				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverOther,
	ezvDialogExtensionFlags_NoDockingOverEmpty				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDockingOverEmpty,
	ezvDialogExtensionFlags_NoDocking						= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoDocking,
	ezvDialogExtensionFlags_SharedFlagsInheritMask_			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SharedFlagsInheritMask_,
	ezvDialogExtensionFlags_NoResizeFlagsMask_				= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_NoResizeFlagsMask_,
	ezvDialogExtensionFlags_LocalFlagsTransferMask_			= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_LocalFlagsTransferMask_,
	ezvDialogExtensionFlags_SavedFlagsMask_					= ImGuiDockNodeFlagsPrivate_::ImGuiDockNodeFlags_SavedFlagsMask_,
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
	DialogOptions				m_iDialogExtensionOptions	= ezvDialogExtensionFlags_None;

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
	inline void SetDocsKeepAliveOnly(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_KeepAliveOnly); }
	inline void SetDocsNoDockingOverCentralNode(bool enabled)	{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingOverCentralNode); }
	inline void SetDocsPassthruCentralNode(bool enabled)		{ this->FlagOptions(enabled,ezvDialogExtensionFlags_PassthruCentralNode); }
	inline void SetDocsNoDockingSplit(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingSplit); }
	inline void SetDocsNoResize(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoResize); }
	inline void SetDocsAutoHideTabBar(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_AutoHideTabBar); }
	inline void SetDocsNoUndocking(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoUndocking); }
	inline void SetDocsNoSplit(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoSplit); }
	inline void SetDocsNoDockingInCentralNode(bool enabled)		{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingInCentralNode); }
	inline void SetDocsDockSpace(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_DockSpace); }
	inline void SetDocsCentralNode(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_CentralNode); }
	inline void SetDocsNoTabBar(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoTabBar); }
	inline void SetDocsHiddenTabBar(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_HiddenTabBar); }
	inline void SetDocsNoWindowMenuButton(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoWindowMenuButton); }
	inline void SetDocsNoCloseButton(bool enabled)				{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoCloseButton); }
	inline void SetDocsNoResizeX(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoResizeX); }
	inline void SetDocsNoResizeY(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoResizeY); }
	inline void SetDocsDockedWindowsInFocusRoute(bool enabled)	{ this->FlagOptions(enabled,ezvDialogExtensionFlags_DockedWindowsInFocusRoute); }
	inline void SetDocsNoDockingSplitOther(bool enabled)		{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingSplitOther); }
	inline void SetDocsNoDockingOverMe(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingOverMe); }
	inline void SetDocsNoDockingOverOther(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingOverOther); }
	inline void SetDocsNoDockingOverEmpty(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDockingOverEmpty); }
	inline void SetDocsNoDocking(bool enabled)					{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoDocking); }
	inline void SetDocsSharedFlagsInheritMask_(bool enabled)	{ this->FlagOptions(enabled,ezvDialogExtensionFlags_SharedFlagsInheritMask_); }
	inline void SetDocsNoResizeFlagsMask_(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_NoResizeFlagsMask_); }
	inline void SetDocsLocalFlagsTransferMask_(bool enabled)	{ this->FlagOptions(enabled,ezvDialogExtensionFlags_LocalFlagsTransferMask_); }
	inline void SetDocsSavedFlagsMask_(bool enabled)			{ this->FlagOptions(enabled,ezvDialogExtensionFlags_SavedFlagsMask_); }

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
	ezvTabBarFlags_None								= ImGuiTabBarFlags_::ImGuiTabBarFlags_None,
	ezvTabBarFlags_Reorderable						= ImGuiTabBarFlags_::ImGuiTabBarFlags_Reorderable,
	ezvTabBarFlags_AutoSelectNewTabs				= ImGuiTabBarFlags_::ImGuiTabBarFlags_AutoSelectNewTabs,
	ezvTabBarFlags_TabListPopupButton				= ImGuiTabBarFlags_::ImGuiTabBarFlags_TabListPopupButton,
	ezvTabBarFlags_NoCloseWithMiddleMouseButton		= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoCloseWithMiddleMouseButton,
	ezvTabBarFlags_NoTabListScrollingButtons		= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoTabListScrollingButtons,
	ezvTabBarFlags_NoTooltip						= ImGuiTabBarFlags_::ImGuiTabBarFlags_NoTooltip,
	ezvTabBarFlags_FittingPolicyResizeDown			= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyResizeDown,
	ezvTabBarFlags_FittingPolicyScroll				= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyScroll,
	ezvTabBarFlags_FittingPolicyMask_				= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyMask_,
	ezvTabBarFlags_FittingPolicyDefault_			= ImGuiTabBarFlags_::ImGuiTabBarFlags_FittingPolicyDefault_,
};

//----------------------------------------------------
// struct Tab Bar Info
//----------------------------------------------------
struct ZV_API TzvTabBarInfo
{
	using TabBarOptions = int;

//// Member Variables
private:
	TabBarOptions	m_iTabBarOptions = ezvTabBarFlags_None;

//// Member Functions
public:
	// Getter
	inline TabBarOptions	GetOptions()	{ return (m_iTabBarOptions); }

	// Setter
	inline void SetOptions(EzvTabBarOptions flags)				{ this->AddOptions(flags); }
	inline void SetReorderable(bool enabled)					{ this->FlagOptions(enabled, ezvTabBarFlags_Reorderable);  }
	inline void SetAutoSelectNewTabs(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarFlags_AutoSelectNewTabs); }
	inline void SetTabListPopupButton(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarFlags_TabListPopupButton); }
	inline void SetNoCloseWithMiddleMouseButton(bool enabled)	{ this->FlagOptions(enabled, ezvTabBarFlags_NoCloseWithMiddleMouseButton); }
	inline void SetNoTabListScrollingButtons(bool enabled)		{ this->FlagOptions(enabled, ezvTabBarFlags_NoTabListScrollingButtons); }
	inline void SetNoTooltip(bool enabled)						{ this->FlagOptions(enabled, ezvTabBarFlags_NoTooltip); }
	inline void SetFittingPolicyResizeDown(bool enabled)		{ this->FlagOptions(enabled, ezvTabBarFlags_FittingPolicyResizeDown); }
	inline void SetFittingPolicyScroll(bool enabled)			{ this->FlagOptions(enabled, ezvTabBarFlags_FittingPolicyScroll); }
	inline void SetFittingPolicyMask_(bool enabled)				{ this->FlagOptions(enabled, ezvTabBarFlags_FittingPolicyMask_); }
	inline void SetFittingPolicyDefault_(bool enabled)			{ this->FlagOptions(enabled, ezvTabBarFlags_FittingPolicyDefault_); }

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
	ezvTabItemFlags_None								= ImGuiTabItemFlags_::ImGuiTabItemFlags_None,
	ezvTabItemFlags_UnsavedDocument						= ImGuiTabItemFlags_::ImGuiTabItemFlags_UnsavedDocument,
	ezvTabItemFlags_SetSelected							= ImGuiTabItemFlags_::ImGuiTabItemFlags_SetSelected,
	ezvTabItemFlags_NoCloseWithMiddleMouseButton		= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoCloseWithMiddleMouseButton,
	ezvTabItemFlags_NoPushId							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoPushId,
	ezvTabItemFlags_NoTooltip							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoTooltip,
	ezvTabItemFlags_NoReorder							= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoReorder,
	ezvTabItemFlags_Leading								= ImGuiTabItemFlags_::ImGuiTabItemFlags_Leading,
	ezvTabItemFlags_Trailing							= ImGuiTabItemFlags_::ImGuiTabItemFlags_Trailing,
	ezvTabItemFlags_NoAssumedClosure					= ImGuiTabItemFlags_::ImGuiTabItemFlags_NoAssumedClosure,
};

//----------------------------------------------------
// struct Tab Item Info
//----------------------------------------------------
struct ZV_API TzvTabItemInfo
{
	using TabItemOptions = int;

//// Member Variables
private:
	TabItemOptions	m_iTabItemOptions = ezvTabItemFlags_None;

//// Member Functions
public:
	// Getter
	inline TabItemOptions	GetOptions() { return (m_iTabItemOptions); }

	// Setter
	inline void SetOptions(EzvTabItemOptions flags)				{ this->AddOptions(flags); }
	inline void SetUnsavedDocument(bool enabled)				{ this->FlagOptions(enabled, ezvTabItemFlags_UnsavedDocument);  }
	inline void SetSetSelected(bool enabled)					{ this->FlagOptions(enabled, ezvTabItemFlags_SetSelected); }
	inline void SetNoCloseWithMiddleMouseButton(bool enabled)	{ this->FlagOptions(enabled, ezvTabItemFlags_NoCloseWithMiddleMouseButton); }
	inline void SetNoPushId(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemFlags_NoPushId); }
	inline void SetNoTooltip(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemFlags_NoTooltip); }
	inline void SetNoReorder(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemFlags_NoReorder); }
	inline void SetLeading(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemFlags_Leading); }
	inline void SetTrailing(bool enabled)						{ this->FlagOptions(enabled, ezvTabItemFlags_Trailing); }
	inline void SetNoAssumedClosure(bool enabled)				{ this->FlagOptions(enabled, ezvTabItemFlags_NoAssumedClosure); }
	
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
	ezvInputTextFlags_None						= ImGuiInputTextFlags_::ImGuiInputTextFlags_None,
	ezvInputTextFlags_CharsDecimal       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsDecimal,		 // Allow 0123456789.+-*/
	ezvInputTextFlags_CharsHexadecimal   		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsHexadecimal,	 // Allow 0123456789ABCDEFabcdef
	ezvInputTextFlags_CharsUppercase     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsUppercase,		 // Turn a..z into A..Z
	ezvInputTextFlags_CharsNoBlank       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsNoBlank,		 // Filter out spaces, tabs
	ezvInputTextFlags_AutoSelectAll      		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AutoSelectAll,		 // Select entire text when first taking mouse focus
	ezvInputTextFlags_EnterReturnsTrue   		= ImGuiInputTextFlags_::ImGuiInputTextFlags_EnterReturnsTrue,	 // Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
	ezvInputTextFlags_CallbackCompletion 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCompletion,  // Callback on pressing TAB (for completion handling)
	ezvInputTextFlags_CallbackHistory    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackHistory,	 // Callback on pressing Up/Down arrows (for history handling)
	ezvInputTextFlags_CallbackAlways     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackAlways,		 // Callback on each iteration. User code may query cursor position, modify text buffer.
	ezvInputTextFlags_CallbackCharFilter 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackCharFilter,  // Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
	ezvInputTextFlags_AllowTabInput      		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AllowTabInput,		 // Pressing TAB input a '\t' character into the text field
	ezvInputTextFlags_CtrlEnterForNewLine		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CtrlEnterForNewLine, // In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter).
	ezvInputTextFlags_NoHorizontalScroll 		= ImGuiInputTextFlags_::ImGuiInputTextFlags_NoHorizontalScroll,  // Disable following the cursor horizontally
	ezvInputTextFlags_AlwaysOverwrite    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_AlwaysOverwrite,	 // Overwrite mode
	ezvInputTextFlags_ReadOnly           		= ImGuiInputTextFlags_::ImGuiInputTextFlags_ReadOnly,			 // Read-only mode
	ezvInputTextFlags_Password           		= ImGuiInputTextFlags_::ImGuiInputTextFlags_Password,			 // Password mode, display all characters as '*'
	ezvInputTextFlags_NoUndoRedo         		= ImGuiInputTextFlags_::ImGuiInputTextFlags_NoUndoRedo,			 // Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
	ezvInputTextFlags_CharsScientific    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CharsScientific,	 // Allow 0123456789.+-*/eE (Scientific notation input)
	ezvInputTextFlags_CallbackResize     		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackResize,		 // Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
	ezvInputTextFlags_CallbackEdit       		= ImGuiInputTextFlags_::ImGuiInputTextFlags_CallbackEdit,		 // Callback on any edit (note that InputText() already returns true on edit, the callback is useful mainly to manipulate the underlying buffer while focus is active)
	ezvInputTextFlags_EscapeClearsAll    		= ImGuiInputTextFlags_::ImGuiInputTextFlags_EscapeClearsAll,	 // Escape key clears content if not empty, and deactivate otherwise (contrast to default behavior of Escape to revert)
};

//----------------------------------------------------
// struct InputText Info
//----------------------------------------------------
struct ZV_API TzvInputTextInfo
{
	using InputTextOptions = int;

	//// Member Variables
private:
	InputTextOptions	m_iInputTextOptions = ezvInputTextFlags_None;

	//// Member Functions
public:
	// Getter
	inline InputTextOptions	GetOptions() { return (m_iInputTextOptions); }
	inline InputTextOptions	GetOptions() const { return (m_iInputTextOptions); }

	// Setter
	inline void SetNone(bool enabled)					{ m_iInputTextOptions = ezvInputTextFlags_None; }
	inline void	SetCharsDecimal(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CharsDecimal);}
	inline void	SetCharsHexadecimal(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_CharsHexadecimal);}
	inline void	SetCharsUppercase(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CharsUppercase);}
	inline void	SetCharsNoBlank(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CharsNoBlank);}
	inline void	SetAutoSelectAll(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_AutoSelectAll);}
	inline void	SetEnterReturnsTrue(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_EnterReturnsTrue);}
	inline void	SetCallbackCompletion(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackCompletion);}
	inline void	SetCallbackHistory(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackHistory);}
	inline void	SetCallbackAlways(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackAlways);}
	inline void	SetCallbackCharFilter(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackCharFilter);}
	inline void	SetAllowTabInput(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_AllowTabInput);}
	inline void	SetCtrlEnterForNewLine(bool enabled)	{ this->FlagOptions(enabled, ezvInputTextFlags_CtrlEnterForNewLine);}
	inline void	SetNoHorizontalScroll(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_NoHorizontalScroll);}
	inline void	SetAlwaysOverwrite(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_AlwaysOverwrite);}
	inline void	SetReadOnly(bool enabled)				{ this->FlagOptions(enabled, ezvInputTextFlags_ReadOnly);}
	inline void	SetPassword(bool enabled)				{ this->FlagOptions(enabled, ezvInputTextFlags_Password);}
	inline void	SetNoUndoRedo(bool enabled)				{ this->FlagOptions(enabled, ezvInputTextFlags_NoUndoRedo);}
	inline void	SetCharsScientific(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_CharsScientific);}
	inline void	SetCallbackResize(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackResize);}
	inline void	SetCallbackEdit(bool enabled)			{ this->FlagOptions(enabled, ezvInputTextFlags_CallbackEdit);}
	inline void	SetEscapeClearsAll(bool enabled)		{ this->FlagOptions(enabled, ezvInputTextFlags_EscapeClearsAll);}

	// Others
	inline bool IsActivated(const EzvInputTextOptions& flags) { return (m_iInputTextOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvInputTextOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvInputTextOptions& flags) { m_iInputTextOptions |= flags; }
	inline void DelOptions(const EzvInputTextOptions& flags) { m_iInputTextOptions &= ~flags; }
};

#pragma endregion
#pragma region Table Options
//----------------------------------------------------
// enum Table Options
//----------------------------------------------------
enum EzvTableOptions
{
	// Features
	ezvTableFlags_None                      	 = ImGuiTableFlags_::ImGuiTableFlags_None,
	ezvTableFlags_Resizable                 	 = ImGuiTableFlags_::ImGuiTableFlags_Resizable,
	ezvTableFlags_Reorderable               	 = ImGuiTableFlags_::ImGuiTableFlags_Reorderable,
	ezvTableFlags_Hideable                  	 = ImGuiTableFlags_::ImGuiTableFlags_Hideable,
	ezvTableFlags_Sortable                  	 = ImGuiTableFlags_::ImGuiTableFlags_Sortable,
	ezvTableFlags_NoSavedSettings           	 = ImGuiTableFlags_::ImGuiTableFlags_NoSavedSettings,
	ezvTableFlags_ContextMenuInBody         	 = ImGuiTableFlags_::ImGuiTableFlags_ContextMenuInBody,
	// Decorations
	ezvTableFlags_RowBg                     	 = ImGuiTableFlags_::ImGuiTableFlags_RowBg,
	ezvTableFlags_BordersInnerH             	 = ImGuiTableFlags_::ImGuiTableFlags_BordersInnerH,
	ezvTableFlags_BordersOuterH             	 = ImGuiTableFlags_::ImGuiTableFlags_BordersOuterH,
	ezvTableFlags_BordersInnerV             	 = ImGuiTableFlags_::ImGuiTableFlags_BordersInnerV,
	ezvTableFlags_BordersOuterV             	 = ImGuiTableFlags_::ImGuiTableFlags_BordersOuterV,
	ezvTableFlags_BordersH                  	 = ImGuiTableFlags_::ImGuiTableFlags_BordersH,
	ezvTableFlags_BordersV                  	 = ImGuiTableFlags_::ImGuiTableFlags_BordersV,
	ezvTableFlags_BordersInner              	 = ImGuiTableFlags_::ImGuiTableFlags_BordersInner,
	ezvTableFlags_BordersOuter              	 = ImGuiTableFlags_::ImGuiTableFlags_BordersOuter,
	ezvTableFlags_Borders                   	 = ImGuiTableFlags_::ImGuiTableFlags_Borders,
	ezvTableFlags_NoBordersInBody           	 = ImGuiTableFlags_::ImGuiTableFlags_NoBordersInBody,
	ezvTableFlags_NoBordersInBodyUntilResize	 = ImGuiTableFlags_::ImGuiTableFlags_NoBordersInBodyUntilResize,
	// Sizing Policy (read above for defaults)
	ezvTableFlags_SizingFixedFit            	 = ImGuiTableFlags_::ImGuiTableFlags_SizingFixedFit,
	ezvTableFlags_SizingFixedSame           	 = ImGuiTableFlags_::ImGuiTableFlags_SizingFixedSame,
	ezvTableFlags_SizingStretchProp         	 = ImGuiTableFlags_::ImGuiTableFlags_SizingStretchProp,
	ezvTableFlags_SizingStretchSame         	 = ImGuiTableFlags_::ImGuiTableFlags_SizingStretchSame,
	// Sizing Extra Options
	ezvTableFlags_NoHostExtendX             	 = ImGuiTableFlags_::ImGuiTableFlags_NoHostExtendX,
	ezvTableFlags_NoHostExtendY             	 = ImGuiTableFlags_::ImGuiTableFlags_NoHostExtendY,
	ezvTableFlags_NoKeepColumnsVisible      	 = ImGuiTableFlags_::ImGuiTableFlags_NoKeepColumnsVisible,
	ezvTableFlags_PreciseWidths             	 = ImGuiTableFlags_::ImGuiTableFlags_PreciseWidths,
	// Clipping
	ezvTableFlags_NoClip                    	 = ImGuiTableFlags_::ImGuiTableFlags_NoClip,
	// Padding
	ezvTableFlags_PadOuterX                 	 = ImGuiTableFlags_::ImGuiTableFlags_PadOuterX,
	ezvTableFlags_NoPadOuterX               	 = ImGuiTableFlags_::ImGuiTableFlags_NoPadOuterX,
	ezvTableFlags_NoPadInnerX               	 = ImGuiTableFlags_::ImGuiTableFlags_NoPadInnerX,
	// Scrolling
	ezvTableFlags_ScrollX                   	 = ImGuiTableFlags_::ImGuiTableFlags_ScrollX,
	ezvTableFlags_ScrollY                   	 = ImGuiTableFlags_::ImGuiTableFlags_ScrollY,
	// Sorting
	ezvTableFlags_SortMulti                 	 = ImGuiTableFlags_::ImGuiTableFlags_SortMulti,
	ezvTableFlags_SortTristate              	 = ImGuiTableFlags_::ImGuiTableFlags_SortTristate,
	// Miscellaneous
	ezvTableFlags_HighlightHoveredColumn    	 = ImGuiTableFlags_::ImGuiTableFlags_HighlightHoveredColumn,
	// [Internal] Combinations and masks
	ezvTableFlags_SizingMask_               	 = ImGuiTableFlags_::ImGuiTableFlags_SizingMask_,
	ezvTableFlags_ArrangeIndexed				 = 1 << 29,
};


//----------------------------------------------------
// struct Table Info
//----------------------------------------------------
struct ZV_API TzvTableInfo
{
	using TableOptions = int;

	//// Member Variables
private:
	TableOptions	m_iTableOptions = ezvTableFlags_None;

	//// Member Functions
public:
	// Getter
	inline TableOptions	GetOptions() { return (m_iTableOptions); }
	inline TableOptions	GetOptions() const { return (m_iTableOptions); }

	// Setter
	inline void SetNone(bool enabled)							{ m_iTableOptions = ezvTableFlags_None; }
	inline void SetResizable(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_Resizable); }
	inline void SetReorderable(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_Reorderable); }
	inline void SetHideable(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_Hideable); }
	inline void SetSortable(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_Sortable); }
	inline void SetNoSavedSettings(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_NoSavedSettings); }
	inline void SetContextMenuInBody(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_ContextMenuInBody); }
	inline void SetRowBg(bool enabled)							{ this->FlagOptions(enabled, ezvTableFlags_RowBg); }
	inline void SetBordersInnerH(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersInnerH); }
	inline void SetBordersOuterH(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersOuterH); }
	inline void SetBordersInnerV(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersInnerV); }
	inline void SetBordersOuterV(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersOuterV); }
	inline void SetBordersH(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_BordersH); }
	inline void SetBordersV(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_BordersV); }
	inline void SetBordersInner(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersInner); }
	inline void SetBordersOuter(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_BordersOuter); }
	inline void SetBorders(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_Borders); }
	inline void SetNoBordersInBody(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_NoBordersInBody); }
	inline void SetNoBordersInBodyUntilResize(bool enabled)		{ this->FlagOptions(enabled, ezvTableFlags_NoBordersInBodyUntilResize); }
	inline void SetSizingFixedFit(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_SizingFixedFit); }
	inline void SetSizingFixedSame(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_SizingFixedSame); }
	inline void SetSizingStretchProp(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_SizingStretchProp); }
	inline void SetSizingStretchSame(bool enabled)				{ this->FlagOptions(enabled, ezvTableFlags_SizingStretchSame); }
	inline void SetNoHostExtendX(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_NoHostExtendX); }
	inline void SetNoHostExtendY(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_NoHostExtendY); }
	inline void SetNoKeepColumnsVisible(bool enabled)			{ this->FlagOptions(enabled, ezvTableFlags_NoKeepColumnsVisible); }
	inline void SetPreciseWidths(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_PreciseWidths); }
	inline void SetNoClip(bool enabled)							{ this->FlagOptions(enabled, ezvTableFlags_NoClip); }
	inline void SetPadOuterX(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_PadOuterX); }
	inline void SetNoPadOuterX(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_NoPadOuterX); }
	inline void SetNoPadInnerX(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_NoPadInnerX); }
	inline void SetScrollX(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_ScrollX); }
	inline void SetScrollY(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_ScrollY); }
	inline void SetSortMulti(bool enabled)						{ this->FlagOptions(enabled, ezvTableFlags_SortMulti); }
	inline void SetSortTristate(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_SortTristate); }
	inline void SetHighlightHoveredColumn(bool enabled)			{ this->FlagOptions(enabled, ezvTableFlags_HighlightHoveredColumn); }
	inline void SetSizingMask_(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_SizingMask_); }
	inline void SetArrangeIndexed(bool enabled)					{ this->FlagOptions(enabled, ezvTableFlags_ArrangeIndexed); }

	// Others
	inline bool IsActivated(const EzvTableOptions& flags) { return (m_iTableOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvTableOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvTableOptions& flags) { m_iTableOptions |= flags; }
	inline void DelOptions(const EzvTableOptions& flags) { m_iTableOptions &= ~flags; }
};
#pragma endregion
#pragma region Table Header Options
//----------------------------------------------------
// enum TableHeader Options
//----------------------------------------------------
enum EzvTableHeaderOptions
{
	ezvTableHeaderFlags_None					= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_None,
	ezvTableHeaderFlags_Disabled				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_Disabled,
	ezvTableHeaderFlags_DefaultHide				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_DefaultHide,
	ezvTableHeaderFlags_DefaultSort				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_DefaultSort,
	ezvTableHeaderFlags_WidthStretch			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_WidthStretch,
	ezvTableHeaderFlags_WidthFixed				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_WidthFixed,
	ezvTableHeaderFlags_NoResize				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoResize,
	ezvTableHeaderFlags_NoReorder				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoReorder,
	ezvTableHeaderFlags_NoHide					= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoHide,
	ezvTableHeaderFlags_NoClip					= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoClip,
	ezvTableHeaderFlags_NoSort					= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoSort,
	ezvTableHeaderFlags_NoSortAscending			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoSortAscending,
	ezvTableHeaderFlags_NoSortDescending		= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoSortDescending,
	ezvTableHeaderFlags_NoHeaderLabel			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoHeaderLabel,
	ezvTableHeaderFlags_NoHeaderWidth			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoHeaderWidth,
	ezvTableHeaderFlags_PreferSortAscending		= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_PreferSortAscending,
	ezvTableHeaderFlags_PreferSortDescending	= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_PreferSortDescending,
	ezvTableHeaderFlags_IndentEnable			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IndentEnable,
	ezvTableHeaderFlags_IndentDisable			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IndentDisable,
	ezvTableHeaderFlags_AngledHeader			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_AngledHeader,
	ezvTableHeaderFlags_IsEnabled				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IsEnabled,
	ezvTableHeaderFlags_IsVisible				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IsVisible,
	ezvTableHeaderFlags_IsSorted				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IsSorted,
	ezvTableHeaderFlags_IsHovered				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IsHovered,
	ezvTableHeaderFlags_WidthMask_				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_WidthMask_,
	ezvTableHeaderFlags_IndentMask_				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_IndentMask_,
	ezvTableHeaderFlags_StatusMask_				= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_StatusMask_,
	ezvTableHeaderFlags_NoDirectResize_			= ImGuiTableColumnFlags_::ImGuiTableColumnFlags_NoDirectResize_,
};
//----------------------------------------------------
// struct TableHeader Info
//----------------------------------------------------
struct ZV_API TzvTableHeaderInfo
{
	using TableHeaderOptions = int;

	//// Member Variables
private:
	TableHeaderOptions	m_iTableHeaderOptions = ezvTableHeaderFlags_None;

	//// Member Functions
public:
	// Getter
	inline TableHeaderOptions	GetOptions() { return (m_iTableHeaderOptions); }
	inline TableHeaderOptions	GetOptions() const { return (m_iTableHeaderOptions); }

	// Setter
	inline void SetNone(bool enabled)					{ m_iTableHeaderOptions =  ezvTableHeaderFlags_None; }
	inline void SetDisabled(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_Disabled); }
	inline void SetDefaultHide(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_DefaultHide); }
	inline void SetDefaultSort(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_DefaultSort); }
	inline void SetWidthStretch(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_WidthStretch); }
	inline void SetWidthFixed(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_WidthFixed); }
	inline void SetNoResize(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoResize); }
	inline void SetNoReorder(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoReorder); }
	inline void SetNoHide(bool enabled)					{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoHide); }
	inline void SetNoClip(bool enabled)					{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoClip); }
	inline void SetNoSort(bool enabled)					{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoSort); }
	inline void SetNoSortAscending(bool enabled)		{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoSortAscending); }
	inline void SetNoSortDescending(bool enabled)		{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoSortDescending); }
	inline void SetNoHeaderLabel(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoHeaderLabel); }
	inline void SetNoHeaderWidth(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoHeaderWidth); }
	inline void SetPreferSortAscending(bool enabled)	{ this->FlagOptions(enabled, ezvTableHeaderFlags_PreferSortAscending); }
	inline void SetPreferSortDescending(bool enabled)	{ this->FlagOptions(enabled, ezvTableHeaderFlags_PreferSortDescending); }
	inline void SetIndentEnable(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_IndentEnable); }
	inline void SetIndentDisable(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_IndentDisable); }
	inline void SetAngledHeader(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_AngledHeader); }
	inline void SetIsEnabled(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_IsEnabled); }
	inline void SetIsVisible(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_IsVisible); }
	inline void SetIsSorted(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_IsSorted); }
	inline void SetIsHovered(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_IsHovered); }
	inline void SetWidthMask_(bool enabled)				{ this->FlagOptions(enabled, ezvTableHeaderFlags_WidthMask_); }
	inline void SetIndentMask_(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_IndentMask_); }
	inline void SetStatusMask_(bool enabled)			{ this->FlagOptions(enabled, ezvTableHeaderFlags_StatusMask_); }
	inline void SetNoDirectResize_(bool enabled)		{ this->FlagOptions(enabled, ezvTableHeaderFlags_NoDirectResize_); }

	// Others
	inline bool IsActivated(const EzvTableHeaderOptions& flags) { return (m_iTableHeaderOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvTableHeaderOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvTableHeaderOptions& flags) { m_iTableHeaderOptions |= flags; }
	inline void DelOptions(const EzvTableHeaderOptions& flags) { m_iTableHeaderOptions &= ~flags; }
};
#pragma endregion
#pragma region Selectable Options
//----------------------------------------------------
// enum Selectable Options
//----------------------------------------------------
enum ZV_API EzvSelectableOptions
{
	ezvSelectableFlags_None				= ImGuiSelectableFlags_::ImGuiSelectableFlags_None,
	ezvSelectableFlags_DontClosePopups 	= ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups,
	ezvSelectableFlags_SpanAllColumns  	= ImGuiSelectableFlags_::ImGuiSelectableFlags_SpanAllColumns,
	ezvSelectableFlags_AllowDoubleClick	= ImGuiSelectableFlags_::ImGuiSelectableFlags_AllowDoubleClick,
	ezvSelectableFlags_Disabled        	= ImGuiSelectableFlags_::ImGuiSelectableFlags_Disabled,
	ezvSelectableFlags_AllowOverlap    	= ImGuiSelectableFlags_::ImGuiSelectableFlags_AllowOverlap     ,

#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS,
	ezvSelectableFlags_AllowItemOverlap = ImGuiSelectableFlags_::ImGuiSelectableFlags_AllowItemOverlap ,
#endif

};
//----------------------------------------------------
// struct Selectable Info
//----------------------------------------------------
struct ZV_API TzvSelectableInfo
{
	using SelectableOptions = int;

	//// Member Variables
private:
	SelectableOptions	m_iSelectableOptions = ezvSelectableFlags_None;

	//// Member Functions
public:
	// Getter
	inline SelectableOptions	GetOptions() { return (m_iSelectableOptions); }
	inline SelectableOptions	GetOptions() const { return (m_iSelectableOptions); }

	// Setter
	inline void SetNone(bool enabled)				{ m_iSelectableOptions = ezvTableHeaderFlags_None; }
	inline void	SetDontClosePopups(bool enabled)	{ this->FlagOptions(enabled, ezvSelectableFlags_DontClosePopups); }
	inline void	SetSpanAllColumns(bool enabled)		{ this->FlagOptions(enabled, ezvSelectableFlags_SpanAllColumns); }
	inline void	SetAllowDoubleClick(bool enabled)	{ this->FlagOptions(enabled, ezvSelectableFlags_AllowDoubleClick); }
	inline void	SetDisabled(bool enabled)			{ this->FlagOptions(enabled, ezvSelectableFlags_Disabled); }
	inline void	SetAllowOverlap(bool enabled)		{ this->FlagOptions(enabled, ezvSelectableFlags_AllowOverlap); }
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS,
	inline void	SetAllowItemOverlap(bool enabled)	{ this->FlagOptions(enabled, ezvSelectableFlags_AllowItemOverlap); }
#endif

	// Others
	inline bool IsEmpty() const { return (m_iSelectableOptions == ezvSelectableFlags_None); }
	inline bool IsActivated(const EzvSelectableOptions& flags) { return (m_iSelectableOptions & flags); }
	inline void FlagOptions(bool enabled, const EzvSelectableOptions& flags) { (enabled) ? this->AddOptions(flags) : this->DelOptions(flags); }
	inline void AddOptions(const EzvSelectableOptions& flags) { m_iSelectableOptions |= flags; }
	inline void DelOptions(const EzvSelectableOptions& flags) { m_iSelectableOptions &= ~flags; }
};
#pragma endregion


} // namespace ZVLab
#endif /*__ZV_ZVGUICONFIG_H__*/

