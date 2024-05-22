#ifndef __ZV_ZVMEMORY_H__
#define __ZV_ZVMEMORY_H__
#pragma once
#include <memory>
#include <optional>

namespace ZVLab {

	template<typename T>
	using Unique = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Unique<T> CreateUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Shared = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Shared<T> CreateShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Optional = std::optional<T>;

	template<typename T>
	using Args = const std::initializer_list<T>;
	
} // namespace ZVLab

#endif /*__ZV_ZVMEMORY_H__*/
