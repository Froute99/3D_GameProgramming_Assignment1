#include <list>
#include "stdafx.h"
#include "Rail.h"
#include "Track.h"

void CTrack::CreateTrack() {
	//const float xBase = 0.f;
	//const float yBase = 0.f;
	//const float zBase = 0.f;
	//const float offset = 5.f;

	//// how to increase scene object number?
	//for (int i = 0; i < 10; ++i) {
	//	CRail* rail = new CRail({ xBase, yBase, zBase + offset * i });
	//	track.push_back(*rail);
	//}


	XMFLOAT3 basePos = XMFLOAT3{ 15.f, 0.f, 0.f };
	for (int i = 0; i < 60; ++i) {
		CGameObject* o = new CGameObject;
		CCubeMesh* pCubeMesh = new CCubeMesh(1.0f, 1.0f, 3.0f);

		o->SetMesh(pCubeMesh);
		o->SetColor(RGB(255, 0, 0));

		XMFLOAT4X4 t = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
		XMFLOAT4X4 r = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, m_degree * i);
		o->m_xmf4x4World = Matrix4x4::Multiply(t, r);

		track.push_back(*o);

		//m_ppObjects[i] = new CGameObject;
		//m_ppObjects[i]->SetMesh(pCubeMesh);
		//m_ppObjects[i]->SetColor(RGB(255, 0, 0));

		//XMFLOAT4X4 r = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, m_degree * i);
		//m_ppObjects[i]->m_xmf4x4World = Matrix4x4::Multiply(t, r);
	}
}
