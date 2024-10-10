#pragma once
#include "../Base/Base.h"

class cannon2 : public Base {
private:
	CImage m_img;
	bool m_flip;
	int m_cnt;
	bool m_flipV;
public:
	cannon2(const CVector2D& pos, bool flip,bool flipV);
	void Update();
	void Draw();
};