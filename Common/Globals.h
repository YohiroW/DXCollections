#ifndef _GLOBALS_H_
#define _GLOBALS_H_
#include <memory>
#include "windows.h"
#include "xnamath.h"
#include "d3d11.h"

#define SAFE_DELETE(_ptr_)       \
        if(_ptr_)                \
        {                        \
            delete _ptr_;        \
            _ptr_ = nullptr;     \
		}

#define SAFE_RELEASE(_ptr_)      \
        if(_ptr_)                \
        {                        \
            _ptr_->Release();    \
            _ptr_ = nullptr;     \
		}

const float PI = 3.1415926f;
#define TRIANGLE_VERTEX_COUNT   3

typedef XMFLOAT4 Vec4;
typedef XMFLOAT3 Vec3;
typedef XMFLOAT2 Vec2;

struct GeneralVertex
{
	Vec3 Position;
	Vec3 Normal;       // As color for now
	Vec2 UV;
};

struct BasicTransform
{
	XMMATRIX M;
	XMMATRIX V;
	XMMATRIX P;
};



#endif // _GLOBALS_H_
