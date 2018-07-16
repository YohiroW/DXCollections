#ifndef _MESHES_H_
#define _MESHES_H_
#include "Globals.h"
#include <vector>

class Meshes
{
public:
	Meshes();
	~Meshes();


	bool Initialize(ID3D11Device* device, const char* fbxPath);

protected:
	void GenerateBuffers(ID3D11Device* device);


private:    
	std::vector<Vec4> m_MeshVertices;
	std::vector<Vec3> m_MeshNormals;
	std::vector<Vec4> m_MeshUVs;
	std::vector<int>  m_MeshIndices;

	ID3D11Buffer * m_MeshesVB{ nullptr };
	ID3D11Buffer * m_MeshesIB{ nullptr };
	ID3D11Buffer * m_MeshesCB{ nullptr };
};

#endif