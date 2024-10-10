#include "Bullet.h"
Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet)
{
	m_img=COPY_RESOURCE("Bullet",CImage);
	m_pos = pos;
	m_rad = 16;
	m_rad = 32;
	m_img.SetSize(256,256);
	m_img.SetCenter(128,128);
}

void Bullet::Update()
{
	const int move_speed = 4;
	m_pos.x -= move_speed;
}

void Bullet::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	Utility::DrawCircle(GetScreenPos(m_pos), m_rad, CVector4D(1,0,0,0.5));
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
