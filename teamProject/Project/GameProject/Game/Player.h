#pragma once
#include "../Base/Base.h"
class Player :public Base {
private:
	enum {
		eState_Idle,
	};
	int m_state;
	CImage m_img;
	bool m_flip;
	bool m_is_ground;
	int m_damage_no;
	int m_hp;
	
	void StateIdle();
	void StateDamage();
	void StateDown();
public:
	Player(const CVector2D& p);
	void Update();
    void Draw();
	void Collision(Base* b);
};
