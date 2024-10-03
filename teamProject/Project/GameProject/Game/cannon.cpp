#include "cannon.h"
#include "Field.h"
#include "Animdata.h"

cannon::cannon(const CVector2D& pos, bool flip):Base(eType_cannon)
{
	m_img = COPY_RESOURCE("cannon", CImage);
	m_flip = flip;
	m_pos = pos;
	m_img.SetCenter(64, 64);
	m_rect = CRect(-64, -64, 64, 64);
	m_img.ChangeAnimation(0, false);
}

void cannon::Update()
{
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void cannon::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
