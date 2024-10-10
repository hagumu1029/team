#include "Enemy.h"
#include "AnimData.h"
#include "Field.h"

void Enemy::StateIdle()
{
	const float move_speed = 4;
	bool move_flag = true;
	const float jump_pow = 20;
	if(m_flip == false)
	m_pos.x += -move_speed;
	else
	m_pos.x += move_speed;
	move_flag = true;
	if (move_flag) {
		m_img.ChangeAnimation(eAnimStep);
	}
	else {
		m_img.ChangeAnimation(eAnimIdle);
	}

}



Enemy::Enemy(const CVector2D& p, bool flip)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	m_pos = p;
	m_img.SetCenter(64, 128);
	m_img.SetSize(128, 128);
	m_rect = CRect(-64, -128, 32, 0);
	m_state = eState_Idle;
	m_is_ground = true;
	m_flip = flip;
}

void Enemy::Update()
{
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();
}

void Enemy::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}

void Enemy::Collision(Base* b)
{
	{
		switch (b->m_type) {
		case eType_Field:
			if (Field* f = dynamic_cast<Field*>(b)) {
				if (m_pos.y > f->GetGroundY()) {
					m_pos.y = f->GetGroundY();
					m_vec.y = 0;
					m_is_ground = true;
				}
			}
			break;
		}
	};
}

