#pragma once
#include <vector>

class CTrack : public CGameObject {
public:
	CTrack() = default;
	CTrack(int num);
	void CreateTrack();
	CGameObject* now = nullptr;
	int m_nTrack = 60;
	float m_degree = -6.f;
	std::vector<CGameObject*> track;
private:
public:
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
};

