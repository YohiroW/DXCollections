#ifndef _GLOBALS_H_
#define _GLOBALS_H_
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

typedef XMFLOAT4 Vec4;
typedef XMFLOAT3 Vec3;
typedef XMFLOAT2 Vec2;

struct GeneralVertex
{
	Vec4 Position;
	Vec4 Normal;       // As color for now
};

struct BasicTransform
{
	XMMATRIX M;
	XMMATRIX V;
	XMMATRIX P;
};



#endif // _GLOBALS_H_
