#include "Application.h"
#include "Sample.h"

//
Sample::Sample(UINT width, UINT height, std::wstring name) :
	m_Width(width),
	m_Height(height),
	m_title(name),
	m_UseWarpDevice(false)
{
	WCHAR assetsPath[512];
	//GetAssetsPath(assetsPath, _countof(assetsPath));
	m_assetsPath = assetsPath;

	m_AspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

Sample::~Sample()
{
}

// Helper function for resolving the full path of assets.
std::wstring Sample::GetAssetFullPath(LPCWSTR assetName)
{
	return m_assetsPath + assetName;
}

// Helper function for setting the window's title text.
void Sample::SetCustomWindowText(LPCWSTR text)
{
	std::wstring windowText = m_title + L": " + text;
	SetWindowText(Application::GetHwnd(), windowText.c_str());
}

// Helper function for parsing any supplied command line args.
_Use_decl_annotations_
void Sample::ParseCommandLineArgs(WCHAR* argv[], int argc)
{
	for (int i = 1; i < argc; ++i)
	{
		if (_wcsnicmp(argv[i], L"-warp", wcslen(argv[i])) == 0 ||
			_wcsnicmp(argv[i], L"/warp", wcslen(argv[i])) == 0)
		{
			m_UseWarpDevice = true;
			m_title = m_title + L" (WARP)";
		}
	}
}