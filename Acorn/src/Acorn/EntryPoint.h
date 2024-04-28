#pragma once

#ifdef AC_PLATFORM_WINDOWS	

extern Acorn::Application* Acorn::CreateApplication();

int main(int argc, char** argv) {

	Acorn::Log::Init();
	AC_CORE_WARN("Initialized Log");
	AC_INFO("Initialized Log Client");
	auto app = Acorn::CreateApplication(); 
	app->Run();
	delete app;
}

#endif