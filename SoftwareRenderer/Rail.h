#pragma once
#include "GameObject.h"

class CRail : public CGameObject {
public:
	CRail(XMFLOAT3 position);
	virtual ~CRail();

	void Render(HDC hDCFrameBuffer, CCamera* pCamera);
private:
	CGameObject* parts[4];
};
