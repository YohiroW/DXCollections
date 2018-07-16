#include "Meshes.h"
#include "Globals.h"

Meshes::Meshes()
{
}

Meshes::~Meshes()
{
}

bool Meshes::Initialize(ID3D11Device* device, const char * fbxPath)
{



	return false;
}

void Meshes::GenerateBuffers(ID3D11Device* device)
{
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(GeneralVertex) * 24;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = &m_MeshVertices[0];
	device->CreateBuffer(&bd, &InitData, &m_MeshesVB);

	// Create index buffer
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(WORD) * 36;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	InitData.pSysMem = &m_MeshIndices[0];
	device->CreateBuffer(&bd, &InitData, &m_MeshesIB);

	// Create the constant buffers
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(BasicTransform);
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;
	device->CreateBuffer(&bd, NULL, &m_MeshesCB);
}
