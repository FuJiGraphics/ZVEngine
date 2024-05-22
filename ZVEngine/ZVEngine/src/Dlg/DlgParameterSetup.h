#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

struct TzvParametersChunk
{
	std::string		strLoadingPath;
	std::string		strSavingPath;
	EzvImageFormat	eImageFormal;
	bool			bEditROI;
};

class CDlgParameterSetup final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	std::string			m_strLabel;
	TzvDialogInfo		m_tDialogInfo;
	TzvParametersChunk	m_tParamChunk;

//// Member Functions
public:
	// Layer Virtual Features
	virtual void OnAttach() override;
	virtual void OnGUI() override;

	// Others
	std::vector<std::string> LoadImages(const std::string& path);
};
