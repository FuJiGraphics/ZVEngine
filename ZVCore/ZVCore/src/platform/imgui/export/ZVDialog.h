#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVMenubar.h"
#include <optional>

namespace ZVLab {

#pragma region Forwards
	class ZV_API	CzvImage;
	class ZV_API	CzvButton;
	class ZV_API	CzvImageButton;
	class ZV_API	CzvToggleButton;
	class ZV_API	CzvComboBox;
	class ZV_API	CzvInputText;
	class ZV_API	CzvTable;
#pragma endregion

//----------------------------------------------------
// Dialog
//----------------------------------------------------
	class ZV_API CzvDialog
	{
	//// Member Variables
	protected: 
		std::string				m_strLabel;
		std::optional<ImVec2>	m_optSize;
		std::optional<ImVec2>	m_optPosition;
		bool					m_bIsUnFolded;
		CzvMenuBar				m_MenuBar;
		TzvDialogInfo			m_tOptions;
		TzvDockspaceInfo		m_tDockspaceOptions;
		
	//// Member Functions
	public:
		CzvDialog(const std::string& label);
		CzvDialog(const std::string& label, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size);
		CzvDialog(const std::string& label, const ImVec2& size, const TzvDialogInfo& options);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position);
		CzvDialog(const std::string& label, const ImVec2& size, const ImVec2& position, const TzvDialogInfo& options);
		virtual ~CzvDialog();

		//----------------------------------------------------
		// Getter
		//----------------------------------------------------
		/**
		 * @brief		윈도우 포커스 확인
		 * @details		현재 윈도우가 활성화 되어 있는지 여부를 반환합니다.
		 * @return		bool:	윈도우 활성화 여부(true/false)
		 */
		bool				IsWindowFocused();
		/**
		 * @brief		윈도우 포커스 확인
		 * @details		현재 윈도우가 활성화 되어 있는지 여부를 반환합니다.
		 * @param[in]	options:	윈도우 활성화시 설정들
		 * @return		bool:		윈도우 활성화 여부(true/false)
		 */
		bool				IsWindowFocused(const TzvWindowFocusedInfo& options);
		/**
		 * @brief		Dialog의 Label을 반환
		 * @details		현재 Dialog의 Label을 반환합니다.
		 * @return		std::string:	라벨명
		 */
		inline std::string	GetLabel() const	{ return (m_strLabel); }
		/**
		 * @brief		Dialog가 접힌 상태인지 여부
		 * @details		Dialog가 접혀있는지 상태 여부를 반환합니다. 
		 * @return		bool:	Dialog가 접혀있는지 여부 (true/false) 
		 */
		inline bool			IsFolded() const	{ return (!m_bIsUnFolded); }
		/**
		 * @brief		Dialog가 펼쳐진 상태인지 여부
		 * @details		Dialog가 펼쳐져있는지 상태 여부를 반환합니다. 
		 * @return		bool:	Dialog가 펼쳐져있는지 여부 (true/false) 
		 */
		inline bool			IsUnFolded() const	{ return (m_bIsUnFolded); }

		//----------------------------------------------------
		// interfaces
		//----------------------------------------------------
		/**
		 * @brief		텍스트 출력
		 * @details		현재 Dialog에 텍스트를 출력합니다.
		 * @param[in]	str: 출력할 텍스트 내용
		 */
		void	Text(const char* fmt, ...);
		/**
		 * @brief		텍스트를 입력받음
		 * @details		현재 Dialog에 텍스트를 입력받습니다.
		 * @param[out]	dst:
		 * @param[in]	info:
		 */
		void	InputText(std::string* dst, const TzvInputTextInfo& info = TzvInputTextInfo());
		/**
		 * @brief		텍스트를 입력받음
		 * @details		현재 Dialog에 텍스트를 입력받습니다.
		 * @param[in]	label:
		 * @param[out]	dst:
		 * @param[in]	info:
		 */
		void	InputText(const std::string& label, std::string* dst, const TzvInputTextInfo& info = TzvInputTextInfo());
		/**
		 * @brief		버튼 생성
		 * @details		현재 Dialog에 버튼을 생성합니다.
		 * @param[in]	label:	버튼의 라벨
		 * @return		bool:	클릭 여부 (true/false) 
		 */
		bool	Button(const std::string& label);
		/**
		 * @brief		버튼 생성
		 * @details		현재 Dialog에 버튼을 생성합니다.
		 * @param[in]	label:	버튼 라벨
		 * @param[in]	size:	버튼 크기
		 * @return		bool:	클릭 여부 (true/false)
		 */
		bool	Button(const std::string& label, const ImVec2& size);
		/**
		 * @brief		버튼 생성
		 * @details		현재 Dialog에 버튼을 생성합니다.
		 * @param[in]	label:		버튼 라벨
		 * @param[in]	size:		버튼 크기
		 * @param[in]	position:	버튼 위치
		 * @return		bool:		클릭 여부 (true/false)
		 */
		bool	Button(const std::string& label, const ImVec2& size, const ImVec2& position);
		/**
		 * @brief		버튼 출력
		 * @details		현재 Dialog에 버튼을 출력합니다.
		 * @param[in]	button:	버튼 객체
		 * @return		bool:	클릭 여부 (true/false)
		 */
		bool	Button(CzvButton& button);
		/**
		 * @brief		토글 버튼 생성
		 * @details		현재 Dialog에 토글 버튼을 생성합니다.
		 * @param[in]	label:	토글 버튼의 라벨
		 * @return		bool:	활성화 여부 (true/false)
		 */
		bool	ToggleButton(const std::string& label);
		/**
		 * @brief		토글 버튼 생성
		 * @details		현재 Dialog에 토글 버튼을 생성합니다.
		 * @param[in]	label:	토글 버튼 라벨
		 * @param[in]	size:	토글 버튼 크기
		 * @return		bool:	활성화 여부 (true/false)
		 */
		bool	ToggleButton(const std::string& label, const ImVec2& size);
		/**
		 * @brief		토글 버튼 생성
		 * @details		현재 Dialog에 토글 버튼을 생성합니다.
		 * @param[in]	label:		토글 버튼 라벨
		 * @param[in]	size:		토글 버튼 크기
		 * @param[in]	position:	토글 버튼 위치
		 * @return		bool:		활성화 여부 (true/false)
		 */
		bool	ToggleButton(const std::string& label, const ImVec2& size, const ImVec2& position);
		/**
		 * @brief		토글 버튼 출력
		 * @details		현재 Dialog에 토글 버튼을 출력합니다.
		 * @param[in]	button:	토글 버튼 객체
		 * @return		bool:	활성화 여부 (true/false)
		 */
		bool	ToggleButton(CzvToggleButton& button);
		/**
		 * @brief		이미지 버튼 출력
		 * @details		현재 Dialog에 Image Button을 출력합니다.
		 * @param[in]	button:	이미지 버튼 객체
		 * @return		bool:	클릭 여부 (true/false)
		 */
		bool	ImageButton(CzvImageButton& button);
		/**	
		 * @brief		이미지 출력
		 * @details		현재 Dialog에 이미지를 출력합니다.
		 * @param[in]	image:	이미지 객체
		 * @param[in]	size:	이미지 출력 크기 (초기값: 기본 크기)
		 */
		void	Image(const CzvImage& image, const ImVec2& size = { 0.0f, 0.0f });
		/**
		 * @brief		메뉴 아이템 생성
		 * @details		현재 Dialog에 MenuItem을 생성합니다.
		 *  - TzvDialogInfo의 SetMenubar 설정에 영향을 받습니다.
		 * @param[in]	label:	메뉴 아이템 라벨
		 * @return		bool:	메뉴 아이템 활성화 여부 (true/false)
		 */
		bool	MenuItem(const std::string& label);
		/**
		 * @brief		테이블을 생성한다
		 * @details		현재 Dialog에 Table을 생성합니다.
		 * @param		table:	테이블 객체
		 */
		void	Table(CzvTable& table);
		/**
		 * @brief		콤보 박스 생성
		 * @details		현재 Dialog에 ComboBox를 생성합니다.
		 * @param[in]	label:			콤보 박스의 라벨
		 * @param[in]	item_list:		콤보 박스의 아이템들 (Init ex. {"AAA", "BBB"})	
		 * @param[in]	options:		콤보 박스의 설정
		 * @return		std::string:	현재 선택중인 아이템 라벨
		 */
		std::string	ComboBox(const std::string& label, 
							 const Args<const char *>& item_list, 
							 const TzvComboBoxInfo& options = TzvComboBoxInfo());

		// Others
		void	SetNextPos(const ImVec2& pos);
	private: 
		bool	Synchronization();
		bool	Binding(CzvButton* target);
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
