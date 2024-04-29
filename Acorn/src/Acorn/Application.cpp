#include "acpch.h"
#include "Application.h"

#include "Acorn/Events/ApplicationEvent.h"
#include "Acorn/Log.h"

namespace Acorn {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowsResizeEvent e(1280, 720);
		AC_TRACE(e.ToString());

		while (true);
	}
}