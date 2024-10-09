#include "cannon.h"
#include "Field.h"
#include "Animdata.h"
#include"Bullet.h"

cannon::cannon(const CVector2D& pos, bool flip):Base(eType_cannon)
{
	m_img = COPY_RESOURCE("cannon", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetSize(256,256);
	m_img.SetCenter(128,128);
	m_rect = CRect(-128, -128, 128, 128);
	m_img.ChangeAnimation(0);
	m_cnt = 110;
}

void cannon::Update()
{
	m_img.UpdateAnimation();


	m_cnt--;
	if (m_cnt <= 0)
	{
		Base::Add(new Bullet(m_pos));
		m_cnt = 110;
	}
}

void cannon::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();
}
