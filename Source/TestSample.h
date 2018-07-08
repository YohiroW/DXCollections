#ifndef _TESTSAMPLE_H_
#define _TESTSAMPLE_H_
#include "Sample.h"

class TestSample : public Sample
{
public:
	TestSample(UINT width, UINT height, std::wstring name)
		:Sample(width, height, name)
	{
	}
	~TestSample() {}

	virtual void OnInit() {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
	virtual void OnDestroy() {}
};

#endif