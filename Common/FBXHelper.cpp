#include "FBXHelper.h"

FBXHelper::~FBXHelper()
{
}

FBXHelper * FBXHelper::GetInstance()
{
	return nullptr;
}

bool FBXHelper::Initialize()
{
	// Fbx manager
	m_FbxMgr = FbxManager::Create();
	if (!m_FbxMgr)
	{
		return false;
	}

	// Fbx scene 
	m_SceneRoot = FbxScene::Create(m_FbxMgr, "");
 	if (!m_SceneRoot)
	{
		return false;
	}

	// Fbx importer
	m_Importer = FbxImporter::Create(m_SceneRoot, "");
	{
		return false;
	}
	m_SceneRoot->Clear();

	m_Importer->Import(m_SceneRoot);

	m_Importer->Destroy();

	ProcessNode(m_SceneRoot->GetRootNode());

	return true;
}

void FBXHelper::LoadFBX(const char * fbxFileName, Meshes & meshes)
{

}

void FBXHelper::ProcessNode(FbxNode* node)
{
	FbxNodeAttribute::EType type;

	if(node->GetNodeAttribute())
	{
		switch (node->GetNodeAttribute()->GetAttributeType())
		{
		case FbxNodeAttribute::eMesh:
			ProcessMesh(node->GetMesh());
			break;
		default:
			break;
		}
	}

	for (int i = 0; i< node->GetChildCount(); ++i)
	{
		ProcessNode(node->GetChild(i));
	}
}

void FBXHelper::ProcessMesh(FbxMesh* mesh)
{
	//assert(mesh);

	FbxVector4* pointArray = mesh->GetControlPoints();
	int meshCount = mesh->GetPolygonCount();
	int vertexIndex = 0;

	//
	Vec3 vertex[3];
	Vec3 normal[3];
	Vec2 uv[3][2];

	for (int i = 0; i< meshCount; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int ctrlPointIndex = mesh->GetPolygonVertex(i, j);
			// Read the vertex 
			ReadVertex(mesh, ctrlPointIndex, &vertex[j]);

			for (int k = 0; k < 2; ++k)
			{
				ReadUV(mesh, ctrlPointIndex, mesh->GetTextureUVIndex(i, j), k, &(uv[j][k]));
			}

			// Read the normal of each vertex 
			ReadNormal(mesh, ctrlPointIndex, vertexIndex, &normal[j]);

			vertexIndex++;
 		}
	}


}

void FBXHelper::ReadVertex(FbxMesh* mesh, int ctrlPointIndex, Vec3* vertex)
{
	FbxVector4* ctrlPoint = mesh->GetControlPoints();

	vertex->x = ctrlPoint[ctrlPointIndex][0];
	vertex->y = ctrlPoint[ctrlPointIndex][1];
	vertex->z = ctrlPoint[ctrlPointIndex][2];
}

void FBXHelper::ReadNormal(FbxMesh* mesh, int ctrlPointIndex, int vertexCounter, Vec3* normal)
{
	if (mesh->GetElementNormalCount() < 1)
	{
		return;
	}

	FbxGeometryElementNormal* leNormal = mesh->GetElementNormal(0);
	switch (leNormal->GetMappingMode())
	{
	case FbxGeometryElement::eByControlPoint:
	{
		switch (leNormal->GetReferenceMode())
		{
		case FbxGeometryElement::eDirect:
		{
			normal->x = leNormal->GetDirectArray().GetAt(ctrlPointIndex)[0];
			normal->y = leNormal->GetDirectArray().GetAt(ctrlPointIndex)[1];
			normal->z = leNormal->GetDirectArray().GetAt(ctrlPointIndex)[2];
		}
		break;

		case FbxGeometryElement::eIndexToDirect:
		{
			int id = leNormal->GetIndexArray().GetAt(ctrlPointIndex);
			normal->x = leNormal->GetDirectArray().GetAt(id)[0];
			normal->y = leNormal->GetDirectArray().GetAt(id)[1];
			normal->z = leNormal->GetDirectArray().GetAt(id)[2];
		}
		break;

		default:
			break;
		}
	}
	break;

	case FbxGeometryElement::eByPolygonVertex:
	{
		switch (leNormal->GetReferenceMode())
		{
		case FbxGeometryElement::eDirect:
		{
			normal->x = leNormal->GetDirectArray().GetAt(vertexCounter)[0];
			normal->y = leNormal->GetDirectArray().GetAt(vertexCounter)[1];
			normal->z = leNormal->GetDirectArray().GetAt(vertexCounter)[2];
		}
		break;

		case FbxGeometryElement::eIndexToDirect:
		{
			int id = leNormal->GetIndexArray().GetAt(vertexCounter);
			normal->x = leNormal->GetDirectArray().GetAt(id)[0];
			normal->y = leNormal->GetDirectArray().GetAt(id)[1];
			normal->z = leNormal->GetDirectArray().GetAt(id)[2];
		}
		break;

		default:
			break;
		}
	}
	break;
	}
}

void FBXHelper::ReadUV(FbxMesh* mesh, int ctrlPointIndex, int textureUVIndex, int uvLayer, Vec2* UV)
{
	if (uvLayer >= 2 || mesh->GetElementUVCount() <= uvLayer)
	{
		return;
	}

	FbxGeometryElementUV* vertexUV = mesh->GetElementUV(uvLayer);

	switch (vertexUV->GetMappingMode())
	{
	case FbxGeometryElement::eByControlPoint:
	{
		switch (vertexUV->GetReferenceMode())
		{
		case FbxGeometryElement::eDirect:
		{
			UV->x = vertexUV->GetDirectArray().GetAt(ctrlPointIndex)[0];
			UV->y = vertexUV->GetDirectArray().GetAt(ctrlPointIndex)[1];
		}
		break;

		case FbxGeometryElement::eIndexToDirect:
		{
			int id = vertexUV->GetIndexArray().GetAt(ctrlPointIndex);
			UV->x = vertexUV->GetDirectArray().GetAt(id)[0];
			UV->y = vertexUV->GetDirectArray().GetAt(id)[1];
		}
		break;

		default:
			break;
		}
	}
	break;

	case FbxGeometryElement::eByPolygonVertex:
	{
		switch (vertexUV->GetReferenceMode())
		{
		case FbxGeometryElement::eDirect:
		case FbxGeometryElement::eIndexToDirect:
		{
			UV->x = vertexUV->GetDirectArray().GetAt(textureUVIndex)[0];
			UV->y = vertexUV->GetDirectArray().GetAt(textureUVIndex)[1];
		}
		break;

		default:
			break;
		}
	}
	break;
	}
}
