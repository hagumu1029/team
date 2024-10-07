#include "Player.h"
#include "Field.h"
#include "Animdata.h"

void Player::StateIdle()
{
	const float move_speed = 3;
	bool move_flag = false;
	const float jump_pow = 15;
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
	if (!m_is_ground) {
		if (m_vec.y < 0)
			m_img.ChangeAnimation(eAnimJump);
		
	}
	else {
		if (move_flag) {
			m_img.ChangeAnimation(eAnimStep);
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}


	Player::Player(const CVector2D&p)
	:Base(eType_Player){
	m_img=COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	m_img.SetCenter(128, 224);
	m_img.SetSize(150, 150);
	m_state = eState_Idle;
	m_is_ground = true;
	m_damage_no = -1;
	m_hp = 150;
	m_invicible = 0;
}

	void Player::StateDamage()
	{
		m_img.ChangeAnimation(eAnimDamage, false);
		if (m_img.CheckAnimationEnd()) {
			m_state = eState_Idle;
			m_is_ground = true;
		}
	}
void Player::StateDown()
{
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}

}

void Player::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	case eState_Damage:
		StateDamage();
		break;
	case eState_Down:
		StateDown();
		break;
	}
	if (m_invicible >= 1) {
		m_invicible -= 1;
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();
	m_scroll.x = m_pos.x - 1280 / 2;
}


void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
void Player::Collision(Base* b)
{
	switch (b->m_type) 
	case eType_Enemy:
	{
		if (Base::CollisionRect(this,b )) {
			if (m_invicible <= 0) {
				m_invicible = 120;
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
			}
		}
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
