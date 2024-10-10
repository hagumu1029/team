#pragma once
#include "../Base/Base.h"
class Bullet2 : public Base {
public:
	CImage m_img;
public:
	Bullet2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};