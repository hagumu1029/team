#include "Bullet.h"
#include"Map.h"
Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet)
{
	m_img=COPY_RESOURCE("Bullet",CImage);
	m_pos = pos;
	m_rad = 16;
	m_rad = 32;
	m_img.SetSize(256,256);
	m_img.SetCenter(128,128);
	m_rect = CRect(-32, -32, 32, 32);
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
	//DrawRect();
}

void Bullet::Collision(Base* b)
{
	{
		switch (b->m_type) {
		case eType_Player:
			if (Base::CollisionRect(this, b))
			{
				SetKill();
			}
			break;
		case eType_Map:
			if (Map* m = dynamic_cast<Map*>(b)) {
				int t;
				t = m->CollisionRect(CVector2D(m_pos.x, m_pos.y), m_rect);
				if (t != 0) {
					m_pos.x = m_pos_old.x;
					SetKill();
				}
				
			}

			break;
		}
	}
}
