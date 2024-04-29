#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Acorn {
	class ACORN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in the client
	Application* CreateApplication();
}

