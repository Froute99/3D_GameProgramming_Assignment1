#pragma once
#include <list>
#include <vector>

class CTrack : public CGameObject {
public:
	CTrack() = default;
	CTrack(int num, float degree);
	void CreateTrack();
	CGameObject* now = nullptr;
	CGameObject* begin;
	int m_nTrack = 60;
	float m_degree = -6.f;
	//std::list<CGameObject*> track;
	std::vector<CGameObject*> track;
private:
public:
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
};

