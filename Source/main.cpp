#include "Application.h"
#include "TestSample.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	TestSample sample(1280, 720, L"Test Case");
	return Application::Run(&sample, hInstance, nCmdShow);
}
