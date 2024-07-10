#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

struct TzvParametersChunk
{
	std::string		strLoadingPath	= "";
	std::string		strSavingPath	= "";
	EzvImageFormat	eImageFormal	= EzvImageFormat::eBMP;
	bool			bEditROI		= false;
	bool			bIsChanged		= false;
};

class CDlgParameterSetup final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	TzvDialogInfo				m_tDialogInfo;
	TzvParametersChunk			m_tParamChunk;
	CzvFileDialog				m_LoadFileDialog;
	CzvFileDialog				m_SaveFileDialog;
	std::vector<std::string>	m_vLoadPaths;

//// Member Functions
public:
	CDlgParameterSetup();

	// Layer Virtual Features
	virtual void OnAttach() override;
	virtual void OnGUI() override;

	// Others
	std::vector<std::string>&	GetImagePaths();
	TzvParametersChunk&			GetParamChunk();

private:
	std::vector<std::string> LoadImages(const std::string& path);
};
