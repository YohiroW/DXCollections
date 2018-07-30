#ifndef _MESHES_H_
#define _MESHES_H_
#include "Globals.h"
#include <vector>

class Meshes
{
public:
	Meshes();
	~Meshes();

    //
	bool Initialize(ID3D11Device* device, const char* fbxPath);
	void AddVertex(Vec4 vertex) { m_MeshVertices.push_back(vertex); }
	void AddNormal(Vec3 normal) { m_MeshNormals.push_back(normal); }
	void AddUV(Vec2 uv) { m_MeshUVs.push_back(uv); }
	void AddIndex(int index) { m_MeshIndices.push_back(index); }

protected:
	void GenerateBuffers(ID3D11Device* device);

private:    
	std::vector<Vec4> m_MeshVertices;
	std::vector<Vec3> m_MeshNormals;
	std::vector<Vec2> m_MeshUVs;
	std::vector<int>  m_MeshIndices;

	ID3D11Buffer * m_MeshesVB{ nullptr };
	ID3D11Buffer * m_MeshesIB{ nullptr };
	ID3D11Buffer * m_MeshesCB{ nullptr };
};

#endif