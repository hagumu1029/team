#pragma once
#include "../Base/Base.h"

class cannon : public Base {
private:
	CImage m_img;
	bool m_flip;
public:
	cannon(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
};