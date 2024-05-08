#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../ZVCore.h"
#include "ZVGuiConfig.h"
#include "ZVButton.h"
#include <optional>

namespace ZVLab {

	struct TzvDialogChunk
	{
		std::string				strLabel;
		std::optional<ImVec2>	optSize;
		std::optional<ImVec2>	optPosition;
		bool					bIsUnFolded;
		TzvDialogInfo			tOptions;
	};


//----------------------------------------------------
// Dialog
//----------------------------------------------------
	class ZV_API CzvDialog
	{
	protected: 
		TzvDialogChunk	m_tData;
		
	public:
		CzvDialog(const std::string& label);
		CzvDialog(const std::string& label, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size);
		CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options);
		CzvDialog(const TzvDialogChunk& data);
		virtual ~CzvDialog();

		// get
		inline std::string	GetLabel() const	{ return (m_tData.strLabel); }
		inline bool			IsFolded() const	{ return (!m_tData.bIsUnFolded); }
		inline bool			IsUnFolded() const	{ return (m_tData.bIsUnFolded); }

		// interfaces
		bool Button(const std::string& label);
		bool Button(const std::string& label, const ImVec2& size);
		bool Button(const std::string& label, const ImVec2& size, const ImVec2& position);
		bool Button(CzvButton& button);

	private: // Others
		bool Synchronization();
	};

//----------------------------------------------------
// Dialog Child
//----------------------------------------------------
	class ZV_API CzvDialog_Child : public CzvDialog
	{
	private:
		TzvDialogChunk	m_tData;

	public:
		CzvDialog_Child(const std::string& label);
		CzvDialog_Child(const std::string& label, const TzvDialogInfo& options);
		CzvDialog_Child(const std::string& label, const ImVec2& size);
		CzvDialog_Child(const std::string& label, const ImVec2& size, const TzvDialogInfo& options);
		CzvDialog_Child(const std::string& label, const ImVec2& size, const ImVec2& position);
		CzvDialog_Child(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options);
		virtual ~CzvDialog_Child();

	private:
		bool Synchronization();
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/