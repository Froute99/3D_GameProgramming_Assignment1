#pragma once
#include <list>

class CTrack : public CGameObject {
public:
	CTrack() = default;
	CTrack(int num, float degree)
		: m_track(num), m_degree(degree) {
		CreateTrack();
	}
	void CreateTrack();
	CGameObject* now = nullptr;
private:
	int m_track = 60;
	float m_degree = -6.f;
	std::list<CGameObject*> track;

public:
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
};

