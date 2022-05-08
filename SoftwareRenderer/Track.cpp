
#include <list>
#include "stdafx.h"
#include "Rail.h"
#include "Track.h"

void CTrack::CreateTrack() {
	const float xBase = 0.f;
	const float yBase = 0.f;
	const float zBase = 0.f;
	const float offset = 5.f;

	// how to increase scene object number?
	for (int i = 0; i < 10; ++i) {
		CRail* rail = new CRail({ xBase, yBase, zBase + offset * i });
		track.push_back(*rail);
	}
}
