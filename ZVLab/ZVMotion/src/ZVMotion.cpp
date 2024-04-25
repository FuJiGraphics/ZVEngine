#include "ZVMotion.h"

// include headers
#if (DMotion_Vendor == DMotion_Default) 
	#include "vendor/default/ZVMotion_Default.h"
#elif (DMotion_Vendor == DMotion_ACS)
	#include "vendor/acs/ZVMotion_ACS.h"
#else
	#error ������ ���̺귯���� ã�� �� �����ϴ�.
#endif

namespace ZVLab {

#if (DMotion_Vendor == DMotion_Default) 
	CZVMotion* CZVMotion::Create()
	{
		return (new CZVMotion_Default());
	}
#elif (DMotion_Vendor == DMotion_ACS)
	#include "vendor/acs/ZVMotion_ACS.h"
	CZVMotion* CZVMotion::Create()
	{
		return (new CZVMotion_ACS());
	}
#else
	#error ������ ���̺귯���� ã�� �� �����ϴ�.
#endif

} // namespace ZVLab