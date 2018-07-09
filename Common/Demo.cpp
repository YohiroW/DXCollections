#include "Application.h"
#include "Demo.h"

//
Demo::Demo(UINT width, UINT height, std::wstring name) :
	m_Width(width),
	m_Height(height),
	m_title(name)
{
	m_AspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

Demo::~Demo()
{
}

// Helper function for setting the window's title text.
void Demo::SetCustomWindowText(LPCWSTR text)
{
	std::wstring windowText = m_title + L": " + text;
	SetWindowText(Application::GetHwnd(), windowText.c_str());
}
