#pragma once
#include <list>

class CTrack {
public:
	CTrack() = default;
	CTrack(int m_trackNum, float degree)
		: m_track(m_trackNum), m_degree(degree) {}
	void CreateTrack();
	int m_track;
	float m_degree;
	std::list<CGameObject> track;
private:
};

