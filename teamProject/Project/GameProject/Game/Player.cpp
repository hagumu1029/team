#include "Player.h"
#include "Field.h"

void Player::StateIdle()
{
	const float move_speed = 6;
	bool move_flag = false;
	const float jump_pow = 12;
	if (HOLD(CInput::eLeft)) {
		m_pos.x += -move_speed;
		m_flip = true;
		move_flag = true;
	}
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

}


	Player::Player(const CVector2D&p)
	:Base(eType_Player){
	m_img.Load("Image/pureiya(kari).png");
	m_pos_old = m_pos = p;
	m_img.SetCenter(128, 224);
	m_state = eState_Idle;
	m_is_ground = true;
	m_damage_no = -1;
	m_hp = 100;
}

void Player::StateDamage()
{
	m_hp = 0;
}

void Player::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	    m_vec.y += GRAVITY;
	    m_pos += m_vec;

}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
void Player::Collision(Base* b)
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

}
;
