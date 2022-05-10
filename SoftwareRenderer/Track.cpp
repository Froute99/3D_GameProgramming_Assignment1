#include "stdafx.h"
#include "Rail.h"
#include "Track.h"

void CTrack::CreateTrack() {

	XMFLOAT3 basePos = XMFLOAT3{ 15.f, 0.f, 0.f };
	for (int i = 0; i < m_track; ++i) {
		CGameObject* o = new CGameObject;
		CCubeMesh* pCubeMesh = new CCubeMesh(1.0f, 1.0f, basePos.x / 10);

		o->SetMesh(pCubeMesh);
		o->SetColor(RGB(255, 0, 0));

		XMFLOAT4X4 t = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
		XMFLOAT4X4 r = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, m_degree * i);
		o->m_xmf4x4World = Matrix4x4::Multiply(t, r);

		track.push_back(o);
	}
	now = *track.begin();
}

void CTrack::Render(HDC hDCFrameBuffer, CCamera* pCamera) {
	for (CGameObject* x : track) {
		//x->Render(hDCFrameBuffer, pCamera);
		//if (pCamera->IsInFrustum(m_xmOOBB))
			CGameObject::Render(hDCFrameBuffer, &x->m_xmf4x4World, x->m_pMesh);
	}
}
