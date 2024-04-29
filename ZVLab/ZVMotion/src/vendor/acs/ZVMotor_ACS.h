#pragma once
#include "../../ZVMotor.h"

namespace ZVLab {

	class CzvMotor_ACS : public CzvMotor
	{
	private:
		std::string		m_strLabel;
		TzvMotorInfo	m_tInfo;
		int				m_iState;
		bool			m_bInitialized;
		 
	public:
		CzvMotor_ACS(const std::string& label);
		virtual ~CzvMotor_ACS();

	public:
		virtual void Initialize(const TzvMotorInfo& info) override;
		virtual void Shutdown() override;

	public:
		inline virtual bool				HasValue() const override { return (m_bInitialized); };
		inline virtual TzvMotorInfo		GetMotorInfo() const override { return (m_tInfo); }
		inline virtual TzvMotorInfo&	FetchMotorInfo() override { return (m_tInfo); }

	}; 

} // namespace ZVLab
