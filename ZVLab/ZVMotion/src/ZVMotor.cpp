#include "ZVMotor.h"

// include headers
#if (DMotion_Vendor == DMotion_Default) 
	#include "vendor/virtual/ZVMotor_Virtual.h"
#elif (DMotion_Vendor == DMotion_ACS)
	#include "vendor/acs/ZVMotor_ACS.h"
#else
	#error ������ ���̺귯���� ã�� �� �����ϴ�.
#endif

namespace ZVLab {

#if (DMotion_Vendor == DMotion_Default) 
	Shared<CzvMotor> CzvMotor::Create(const std::string& label)
	{
		return (CreateShared<CzvMotor_Virtual>(label));
	}
#elif (DMotion_Vendor == DMotion_ACS)
	Shared<CzvMotor> CzvMotor::Create(const std::string& label)
	{
		return (CreateShared<CzvMotor_ACS>(label));
	}
#else
	#error ������ ���̺귯���� ã�� �� �����ϴ�.
#endif

} // namespace ZVLab
