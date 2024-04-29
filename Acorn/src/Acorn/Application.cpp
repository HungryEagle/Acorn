#include "acpch.h"
#include "Application.h"

#include "Acorn/Events/ApplicationEvent.h"
#include "Acorn/Log.h"

namespace Acorn {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}