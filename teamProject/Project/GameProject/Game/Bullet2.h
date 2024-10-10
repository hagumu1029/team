#pragma once
#include "../Base/Base.h"
class Bullet2 : public Base {
public:
	CImage m_img;
public:
	Bullet2(const CVector2D& pos,CVector2D vec);
	void Update();
	void Draw();
	void Collision(Base* b);
};