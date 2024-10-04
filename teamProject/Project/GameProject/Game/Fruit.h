#pragma once
#include "../Base/Base.h"

class Fruit : public Base {
private:
	float m_FallSpeed;
	int m_rand;
public:
	int m_cnt;
	Fruit(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};