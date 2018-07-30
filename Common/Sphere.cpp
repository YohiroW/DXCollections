#include "Sphere.h"
#include "Shader.h"
Sphere::Sphere()
{
}

Sphere::~Sphere()
{
	SAFE_RELEASE(m_SphereIB);
	SAFE_RELEASE(m_SphereVB);
	SAFE_RELEASE(m_SphereCB);
}

std::unique_ptr<Sphere> Sphere::Create(ID3D11Device * device, const Vec3 & pos)
{
	std::unique_ptr<Sphere> sphere = std::make_unique<Sphere>();
	if (sphere && sphere->Initialize(device, pos))
	{
		return sphere;
	}
	return nullptr;
}

bool Sphere::Initialize(ID3D11Device * device, const Vec3 & pos)
{
	GenerateGeometry();
	GenerateBuffers(device);

	return true;
}

void Sphere::Render(ID3D11DeviceContext * ctx, Shader * shader)
{
	//
	BasicTransform uniform;
	uniform.M = XMMatrixIdentity();
	uniform.V = XMMatrixIdentity();
	uniform.P = XMMatrixIdentity();
	ctx->UpdateSubresource(m_SphereCB, 0, NULL, &uniform, 0, 0);

	//
	ctx->VSSetShader(shader->GetVertexShader(), NULL, 0);
	ctx->VSSetConstantBuffers(0, 1, &m_SphereCB);
	ctx->PSSetShader(shader->GetPixelShader(), NULL, 0);
	ctx->PSSetConstantBuffers(0, 1, &m_SphereCB);
	ctx->DrawIndexed((UINT)m_Indices.size(), 0, 0);
}

void Sphere::GenerateBuffers(ID3D11Device * device)
{
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(GeneralVertex) * m_Vertices.size();
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = &m_Vertices[0];
	device->CreateBuffer(&bd, &InitData, &m_SphereVB);

	// Create index buffer
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(unsigned int) * m_Indices.size();
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	InitData.pSysMem = &m_Indices[0];
	device->CreateBuffer(&bd, &InitData, &m_SphereIB);

	// Create the constant buffers
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(BasicTransform);
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;
	device->CreateBuffer(&bd, NULL, &m_SphereCB);

}

void Sphere::GenerateGeometry()
{
	// vertices
	for (unsigned int y = 0; y<= SEG_IN_Y; ++y)
	{
		for (unsigned int x = 0; x <= SEG_IN_X; ++x)
		{
			float dx = (float)x / (float)SEG_IN_X;
			float dy = (float)y / (float)SEG_IN_Y;
			float posX = std::cos(SEG_IN_X * 2.0f * PI) * std::sin(SEG_IN_Y * PI);
			float posY = std::cos(SEG_IN_Y * PI);
			float posZ = std::sin(SEG_IN_X * 2.0f * PI) * std::sin(SEG_IN_Y * PI);

			GeneralVertex vertex;
			vertex.Position = Vec3(posX, posY, posZ);
			vertex.Normal = vertex.Position;
			vertex.UV = Vec2(dx, dy);

		}
	}

	// indices
	bool isOdd = false;
	for (unsigned int y = 0; y <= SEG_IN_Y; ++y)
	{
		if (!isOdd)
		{
			for (unsigned int x = 0; x <= SEG_IN_X; ++x)
			{
				m_Indices.push_back(y*      (SEG_IN_X+ 1)+ x);
				m_Indices.push_back((y+ 1)* (SEG_IN_X+ 1)+ x);
			}
		}
		else
		{
			for (unsigned int x = SEG_IN_X; x >= 0; --x)
			{
				m_Indices.push_back((y + 1)* (SEG_IN_X + 1) + x);
				m_Indices.push_back(y*      (SEG_IN_X + 1) + x);
			}
		}
		isOdd = !isOdd;
	}
}
