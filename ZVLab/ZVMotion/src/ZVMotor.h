#ifndef __ZV_ZVMOTOR_H__
#define __ZV_ZVMOTOR_H__

#pragma once
#include "ZVCore.h"
#include "ZVMotor_cfg.h"

namespace ZVLab {

	class CzvMotor
	{
	public:
		static Shared<CzvMotor> Create(const std::string& label);

	public:
		virtual void Initialize(const TzvMotorInfo& info) = 0;
		virtual void Shutdown() = 0;

	public:
		inline virtual bool				HasValue() const = 0;
		inline virtual TzvMotorInfo		GetMotorInfo() const = 0;
		inline virtual TzvMotorInfo&	FetchMotorInfo() = 0;
	};

} // namespace ZVLab

#endif /*__ZV_ZVMOTOR_H__*/
