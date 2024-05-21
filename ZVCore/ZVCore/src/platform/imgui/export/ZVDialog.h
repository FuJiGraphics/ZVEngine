#ifndef __ZV_ZVDIALOG_H__
#define __ZV_ZVDIALOG_H__
#pragma once

#include "../../../core/Core.h"
#include "ZVGuiConfig.h"
#include "ZVMenubar.h"
#include <optional>

namespace ZVLab {

	// Forwards
	class ZV_API	CzvImage;
	class ZV_API	CzvButton;
	class ZV_API	CzvImageButton;
	class ZV_API	CzvToggleButton;


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
		 * @brief		������ ��Ŀ�� Ȯ��
		 * @details		���� �����찡 Ȱ��ȭ �Ǿ� �ִ��� ���θ� ��ȯ�մϴ�.
		 * @return		bool:	������ Ȱ��ȭ ����(true/false)
		 */
		bool				IsWindowFocused();
		/**
		 * @brief		������ ��Ŀ�� Ȯ��
		 * @details		���� �����찡 Ȱ��ȭ �Ǿ� �ִ��� ���θ� ��ȯ�մϴ�.
		 * @param[in]	options:	������ Ȱ��ȭ�� ������
		 * @return		bool:		������ Ȱ��ȭ ����(true/false)
		 */
		bool				IsWindowFocused(const TzvWindowFocusedInfo& options);
		/**
		 * @brief		Dialog�� Label�� ��ȯ
		 * @details		���� Dialog�� Label�� ��ȯ�մϴ�.
		 * @return		std::string:	�󺧸�
		 */
		inline std::string	GetLabel() const	{ return (m_strLabel); }
		/**
		 * @brief		Dialog�� ���� �������� ����
		 * @details		Dialog�� �����ִ��� ���� ���θ� ��ȯ�մϴ�. 
		 * @return		bool:	Dialog�� �����ִ��� ���� (true/false) 
		 */
		inline bool			IsFolded() const	{ return (!m_bIsUnFolded); }
		/**
		 * @brief		Dialog�� ������ �������� ����
		 * @details		Dialog�� �������ִ��� ���� ���θ� ��ȯ�մϴ�. 
		 * @return		bool:	Dialog�� �������ִ��� ���� (true/false) 
		 */
		inline bool			IsUnFolded() const	{ return (m_bIsUnFolded); }

		//----------------------------------------------------
		// interfaces
		//----------------------------------------------------
		/**
		 * @brief		��ư ����
		 * @details		���� Dialog�� ��ư�� �����մϴ�.
		 * @param[in]	label:	��ư�� ��
		 * @return		bool:	Ŭ�� ���� (true/false) 
		 */
		bool	Button(const std::string& label);
		/**
		 * @brief		��ư ����
		 * @details		���� Dialog�� ��ư�� �����մϴ�.
		 * @param[in]	label:	��ư ��
		 * @param[in]	size:	��ư ũ��
		 * @return		bool:	Ŭ�� ���� (true/false)
		 */
		bool	Button(const std::string& label, const ImVec2& size);
		/**
		 * @brief		��ư ����
		 * @details		���� Dialog�� ��ư�� �����մϴ�.
		 * @param[in]	label:		��ư ��
		 * @param[in]	size:		��ư ũ��
		 * @param[in]	position:	��ư ��ġ
		 * @return		bool:		Ŭ�� ���� (true/false)
		 */
		bool	Button(const std::string& label, const ImVec2& size, const ImVec2& position);
		/**
		 * @brief		��ư ���
		 * @details		���� Dialog�� ��ư�� ����մϴ�.
		 * @param[in]	button:	��ư ��ü
		 * @return		bool:	Ŭ�� ���� (true/false)
		 */
		bool	Button(CzvButton& button);
		/**
		 * @brief		��� ��ư ����
		 * @details		���� Dialog�� ��� ��ư�� �����մϴ�.
		 * - ��� ��ư ���� ��ü������ ���� ������ ���� �ĺ� �ο��˴ϴ�.
		 * - �ݺ� ȣ�� ��, ����� ��ü�� ���������� �����մϴ�.
		 * - �ĺ��Ǵ� �󺧸��� �ܺο��� Ȯ���� �� �����ϴ�.
		 * @return		bool:	Ȱ��ȭ ���� (true/false)
		 */
		bool	ToggleButton();
		/**
		 * @brief		��� ��ư ����
		 * @details		���� Dialog�� ��� ��ư�� �����մϴ�.
		 * @param[in]	label:	��� ��ư�� ��
		 * @return		bool:	Ȱ��ȭ ���� (true/false)
		 */
		bool	ToggleButton(const std::string& label);
		/**
		 * @brief		��� ��ư ����
		 * @details		���� Dialog�� ��� ��ư�� �����մϴ�.
		 * @param[in]	label:	��� ��ư ��
		 * @param[in]	size:	��� ��ư ũ��
		 * @return		bool:	Ȱ��ȭ ���� (true/false)
		 */
		bool	ToggleButton(const std::string& label, const ImVec2& size);
		/**
		 * @brief		��� ��ư ����
		 * @details		���� Dialog�� ��� ��ư�� �����մϴ�.
		 * @param[in]	label:		��� ��ư ��
		 * @param[in]	size:		��� ��ư ũ��
		 * @param[in]	position:	��� ��ư ��ġ
		 * @return		bool:		Ȱ��ȭ ���� (true/false)
		 */
		bool	ToggleButton(const std::string& label, const ImVec2& size, const ImVec2& position);
		/**
		 * @brief		��� ��ư ���
		 * @details		���� Dialog�� ��� ��ư�� ����մϴ�.
		 * @param[in]	button:	��� ��ư ��ü
		 * @return		bool:	Ȱ��ȭ ���� (true/false)
		 */
		bool	ToggleButton(CzvToggleButton& button);
		/**
		 * @brief		�̹��� ��ư ���
		 * @details		���� Dialog�� Image Button�� ����մϴ�.
		 * @param[in]	button:	�̹��� ��ư ��ü
		 * @return		bool:	Ŭ�� ���� (true/false)
		 */
		bool	ImageButton(CzvImageButton& button);
		/**	
		 * @brief		�̹��� ���
		 * @details		���� Dialog�� �̹����� ����մϴ�.
		 * @param[in]	image:	�̹��� ��ü
		 * @param[in]	size:	�̹��� ��� ũ�� (�ʱⰪ: �⺻ ũ��)
		 */
		void	Image(const CzvImage& image, const ImVec2& size = { 0.0f, 0.0f });

		/**
		 * @brief �޴� ������ ����
		 * @details
		 *	- ���� Dialog�� MenuItem�� �����մϴ�.
		 *  - TzvDialogInfo�� SetMenubar ������ ������ �޽��ϴ�.
		 * @param[in]	label:	�޴� ������ ��
		 * @return		bool:	�޴� ������ Ȱ��ȭ ���� (true/false)
		 */
		bool	MenuItem(const std::string& label);

	private: // Others
		bool	Synchronization();
		void	SettingOptions();
		bool	Binding(CzvButton* target);
	};

} // namespace ZVLab

#endif /*__ZV_ZVDIALOG_H__*/
