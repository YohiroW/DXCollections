#ifndef _SAMPLE_H_
#define _SAMPLE_H_
#include <string>
#include "d3d11.h"

class Sample
{
public:
	Sample(UINT width, UINT height, std::wstring name);
	virtual ~Sample();

	// Interfaces
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;

	// Handle input
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	//
	UINT GetWidth() const { return m_Width; }
	UINT GetHeight() const { return m_Height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }

	void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

protected:
	std::wstring GetAssetFullPath(LPCWSTR assetName);
	void SetCustomWindowText(LPCWSTR text);

	// Viewport dimensions.
	UINT m_Width;
	UINT m_Height;
	float m_AspectRatio;

	// Adapter info.
	bool m_UseWarpDevice;

private:
	// Root assets path.
	std::wstring m_assetsPath;

	// Window title.
	std::wstring m_title;
};


#endif // 
