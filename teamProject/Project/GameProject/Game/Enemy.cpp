#include "Enemy.h"
#include "AnimData.h"
#include "Field.h"

void Enemy::StateIdle()
{
	const float move_speed = 2;
	bool move_flag = false;
	const float jump_pow = 20;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		if (player->m_pos.x < m_pos.x - 64) {
			m_pos.x += -move_speed;
			m_flip = true;
			move_flag = true;
		}
		if (player->m_pos.x > m_pos.x + 64) {
			m_pos.x += move_speed;
			m_flip = false;
			move_flag = true;
		}
	}

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
	m_img.SetCenter(128, 224);
	m_img.SetSize(150, 150);
	m_rect = CRect(-32, -128, 32, 0);
	m_flip = flip;
	m_state = eState_Run;
	m_is_ground = true;
}

void Enemy::Update()
{
	switch (m_state) {
	case eState_Run:
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

