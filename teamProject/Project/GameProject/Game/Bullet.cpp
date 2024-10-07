#include "Bullet.h"
Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet)
{
	m_img=COPY_RESOURCE("Bullet",CImage);
	m_pos = pos;
	m_rad = 16;
	m_rad = 12;
	m_img.SetSize(64,64);
	m_img.SetCenter(32,32);
}

void Bullet::Update()
{
	const int move_speed = 4;
	m_pos.x -= move_speed;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	Utility::DrawCircle(m_pos, m_rad, CVector4D(1, 0, 0, 0.5));
}

void Bullet::Collision(Base* b)
{
	{
		switch (b->m_type) {
		case eType_Player:
			if (Base::CollisionCircle(this, b))
			{
				b->SetKill();
				SetKill();
			}
			break;
		}
	}
}
