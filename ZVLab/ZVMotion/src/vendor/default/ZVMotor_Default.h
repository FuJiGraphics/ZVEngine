#pragma once
#include "../../ZVMotor.h"

namespace ZVLab {

	class CzvMotor_Default : public CzvMotor
	{

	public: // 持失切, 社瑚切
		CzvMotor_Default(const std::string& label);
		virtual ~CzvMotor_Default();

	public:
		virtual void Initialize(const TzvMotorInfo& info) override;
		virtual void Shutdown() override;

	public:
		inline virtual bool				HasValue() const override;
		inline virtual TzvMotorInfo		GetMotorInfo() const override;
		inline virtual TzvMotorInfo&	FetchMotorInfo() override;
	};



} // namespace ZVLab