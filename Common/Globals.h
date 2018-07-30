#ifndef _GLOBALS_H_
#define _GLOBALS_H_
<<<<<<< HEAD
#include <memory>
=======
>>>>>>> dev_fbxsdk
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

<<<<<<< HEAD

const float PI = 3.1415926f;
=======
>>>>>>> dev_fbxsdk
#define TRIANGLE_VERTEX_COUNT   3

typedef XMFLOAT4 Vec4;
typedef XMFLOAT3 Vec3;
typedef XMFLOAT2 Vec2;

struct GeneralVertex
{
<<<<<<< HEAD
	Vec3 Position;
	Vec3 Normal;       // As color for now
	Vec2 UV;
=======
	Vec4 Position;
	Vec4 Normal;       // As color for now
>>>>>>> dev_fbxsdk
};

struct BasicTransform
{
	XMMATRIX M;
	XMMATRIX V;
	XMMATRIX P;
};



#endif // _GLOBALS_H_
