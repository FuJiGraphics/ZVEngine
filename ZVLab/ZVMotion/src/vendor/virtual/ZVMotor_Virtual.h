#pragma once
#include "../../ZVMotor.h"

namespace ZVLab {

	class CzvMotor_Virtual : public CzvMotor
	{

	public: // 持失切, 社瑚切
		CzvMotor_Virtual(const std::string& label);
		virtual ~CzvMotor_Virtual();

	public:
		virtual void Initialize(const TzvMotorInfo& info) override;
		virtual void Shutdown() override;

	public:
		inline virtual bool				HasValue() const override;
		inline virtual TzvMotorInfo		GetMotorInfo() const override;
		inline virtual TzvMotorInfo&	FetchMotorInfo() override;
	};



} // namespace ZVLab