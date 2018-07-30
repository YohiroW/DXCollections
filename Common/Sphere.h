#ifndef _SPHERE_H_
#define _SPHERE_H_
#include "Globals.h"
#include <vector>

#define SEG_IN_Y 64
#define SEG_IN_X 64

class Shader;

class Sphere
{
public:
	Sphere();
	~Sphere();

	static std::unique_ptr<Sphere> Create(ID3D11Device* device, const Vec3& pos);
	bool Initialize(ID3D11Device* device, const Vec3& pos);
	virtual void Render(ID3D11DeviceContext* ctx, Shader* shader);

protected:
	void GenerateBuffers(ID3D11Device* device);
	void GenerateGeometry();

private:
	ID3D11Buffer * m_SphereIB{ nullptr };
	ID3D11Buffer * m_SphereVB{ nullptr };
	ID3D11Buffer * m_SphereCB{ nullptr };

	// geometries
	std::vector<GeneralVertex> m_Vertices;
	std::vector<unsigned int> m_Indices;
};


#endif