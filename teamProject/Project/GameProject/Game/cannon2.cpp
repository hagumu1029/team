#include "cannon2.h"
#include "Field.h"
#include "Animdata.h"
#include"Bullet.h"
#include"Bullet2.h"

cannon2::cannon2(const CVector2D& pos, bool flip,bool flipV) :Base(eType_cannon2)
{
	m_img = COPY_RESOURCE("cannon2", CImage);
	m_flip = flip;
	m_flipV = true;
	m_pos = pos;
	m_img.SetSize(256, 256);
	m_img.SetCenter(128, 128);
	m_rect = CRect(-128, -128, 128, 128);
	m_img.ChangeAnimation(0);
	m_cnt = 160;
}

void cannon2::Update()
{
	m_img.UpdateAnimation();


	m_cnt--;
	if (m_cnt <= 0)
	{
		Base::Add(new Bullet2(m_pos,CVector2D(-3,-3)));
		m_cnt = 160;
	}
}

void cannon2::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.SetFlipV(m_flipV);
	m_img.Draw();
	//DrawRect();
}
