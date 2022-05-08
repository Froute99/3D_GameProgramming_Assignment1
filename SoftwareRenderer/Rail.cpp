#include "stdafx.h"
#include "Rail.h"

CRail::CRail(XMFLOAT3 position) {
	CCubeMesh* cubeMesh = new CCubeMesh(0.5f, 0.5f, 5.f);


	const float railWidth = 3.5f;
	const float halfRailWidth = railWidth * 0.5f;
	const float halfRailDepth = 1.2f;
	

	parts[0] = new CGameObject();
	parts[0]->SetMesh(cubeMesh);
	parts[0]->SetColor(RGB(255, 0, 0));
	parts[0]->SetPosition(position.x + halfRailWidth, position.y, position.z);

	parts[1] = new CGameObject();
	parts[1]->SetMesh(cubeMesh);
	parts[1]->SetColor(RGB(255, 0, 0));
	parts[1]->SetPosition(position.x - halfRailWidth, position.y, position.z);

	parts[2] = new CGameObject();
	parts[2]->SetMesh(cubeMesh);
	parts[2]->SetColor(RGB(255, 0, 0));
	parts[2]->SetPosition(position.x, position.y, position.z + halfRailDepth);
	parts[2]->Rotate(0.f, 90.f, 0.f);

	parts[3] = new CGameObject();
	parts[3]->SetMesh(cubeMesh);
	parts[3]->SetColor(RGB(255, 0, 0));
	parts[3]->SetPosition(position.x, position.y, position.z - halfRailDepth);
	parts[3]->Rotate(0.f, 90.f, 0.f);

	SetMesh(cubeMesh);
	SetPosition(position);
}

CRail::~CRail() {

}

void CRail::Render(HDC hDCFrameBuffer, CCamera* pCamera) {
	for (CGameObject* part : parts) {
		if (pCamera->IsInFrustum(m_xmOOBB))
			CGameObject::Render(hDCFrameBuffer, &part->m_xmf4x4World, part->m_pMesh);
	}
}

