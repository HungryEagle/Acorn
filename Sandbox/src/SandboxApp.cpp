#include <Acorn.h>

class Sandbox : public Acorn::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Acorn::Application* Acorn::CreateApplication() {
	return new Sandbox();
}