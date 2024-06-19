#pragma once
#ifndef __FZ_LIBRARY_STRING_HELPER__
#define __FZ_LIBRARY_STRING_HELPER__

#ifdef FZLIB_USAGE_DLL
	#ifdef FZLIB_EXPORTS
		#define FZLIB_API __declspec(dllexport)
	#else
		#define FZLIB_API __declspec(dllimport)
	#endif
#else
	#define FZLIB_API
#endif

// Standard include headers
#include <string>

extern "C" {
	namespace FZLib {

		class FZLIB_API StringHelper
		{
		public:
			/**
			 * @brief	std::string을 LPCWSTR로 변환
			 * @param[in]	str:			변환할 std::string 문자열
			 * @return		std::wstring:	변환된 LPCWSTR 타입의 문자열
			 */
			static std::wstring StringToWString(const std::string& str);

			/**
			 * @brief		LPCWSTR을 std::string으로 변환
			 * @param[in]	wstr:			변환할 wstring 문자열
			 * @return		std::string:	변환된 std::string타입의 문자열	
			 */
			static std::string WStringToString(const std::wstring& wstr);
		};

	} // namespace FZLib
}
#endif