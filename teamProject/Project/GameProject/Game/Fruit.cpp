#include "Fruit.h"
#include "Map.h"

Fruit::Fruit(const CVector2D& pos) : Base(eType_Fruit)
{
	int r = rand() % 3;
	switch (r) {
	case 0:
		m_img = COPY_RESOURCE("banana", CImage);
		m_img.SetSize(50, 50);
		m_img.SetCenter(10, 16);
		m_rect = CRect(-8, -14, 8, 14);
		break;

	case 1:
		m_img = COPY_RESOURCE("Apple", CImage);
		m_img.SetSize(50, 50);
		m_img.SetCenter(10, 16);
		m_rect = CRect(-8, -14, 8, 14);
		break;

	case 2:
		m_img = COPY_RESOURCE("berry", CImage);
		m_img.SetSize(50, 50);
		m_img.SetCenter(10, 16);
		m_rect = CRect(-8, -14, 8, 14);
		break;
	}
	m_pos = pos;
	m_FallSpeed = 3.5;
	m_rand = 0;
	m_cnt = 0;
}

void Fruit::Update()
{
	m_pos_old = m_pos;
	m_pos.y += m_FallSpeed;
	if (m_pos.y >= 1280)
	{
		m_kill = true;
	}
}

void Fruit::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void Fruit::Collision(Base* b)
{
}

