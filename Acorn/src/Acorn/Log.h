#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Acorn {
	class ACORN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define AC_CORE_TRACE(...)   ::Acorn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AC_CORE_INFO(...)    ::Acorn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AC_CORE_WARN(...)    ::Acorn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AC_CORE_ERROR(...)   ::Acorn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AC_CORE_FATAL(...)   ::Acorn::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define AC_TRACE(...)   ::Acorn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AC_INFO(...)    ::Acorn::Log::GetClientLogger()->info(__VA_ARGS__)
#define AC_WARN(...)    ::Acorn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AC_ERROR(...)   ::Acorn::Log::GetClientLogger()->error(__VA_ARGS__)
#define AC_FATAL(...)   ::Acorn::Log::GetClientLogger()->fatal(__VA_ARGS__)