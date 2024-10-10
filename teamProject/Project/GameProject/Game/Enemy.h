#pragma once
#pragma once
#include "../Base/Base.h"
#include"Player.h"
class Enemy :public Base {
private:
	enum {
		eState_Idle,
		eState_Run,
		eState_Down,
	};
	void StateIdle();
	int m_state;
	CImage m_img;
	bool m_is_ground;
	bool m_flip;
public:
	Enemy(const CVector2D& p,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};