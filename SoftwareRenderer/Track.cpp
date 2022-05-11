#include "stdafx.h"
#include "Rail.h"
#include "Track.h"

CTrack::CTrack(int num, float degree)
	: m_nTrack(num), m_degree(degree) {
	CreateTrack();
}

void CTrack::CreateTrack() {

	XMFLOAT3 basePos = XMFLOAT3{ 15.f, 0.f, 0.f };
	XMFLOAT4X4 t = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
	CCubeMesh* pCubeMesh = new CCubeMesh(1.0f, 1.0f, basePos.x / 10);
	for (int i = 0; i < m_nTrack; ++i) {
		CGameObject* o = new CGameObject;

		o->SetMesh(pCubeMesh);
		o->SetColor(RGB(255, 0, 0));

		XMFLOAT4X4 r = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, m_degree * i);
		o->m_xmf4x4World = Matrix4x4::Multiply(t, r);
		o->UpdateBoundingBox();

		track.push_back(o);
	}
	//begin = *track.begin();
	begin = track.at(0);
	//now = begin;
}

void CTrack::Render(HDC hDCFrameBuffer, CCamera* pCamera) {
	for (CGameObject* x : track) {
		x->Render(hDCFrameBuffer, pCamera);
	}
}
