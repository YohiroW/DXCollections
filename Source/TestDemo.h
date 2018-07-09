#ifndef _TESTSAMPLE_H_
#define _TESTSAMPLE_H_
#include "Demo.h"

class TestDemo : public Demo
{
public:
	TestDemo(UINT width, UINT height, std::wstring name)
		:Demo(width, height, name)
	{
	}
	~TestDemo() {}

	virtual void OnInit() {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
	virtual void OnDestroy() {}
};

#endif