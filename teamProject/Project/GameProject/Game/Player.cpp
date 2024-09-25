#include "Player.h"



Player::Player(const CVector2D& p)
	:Base(eType_Player)
{
	m_img.Load("Image/pureiya(kari).png");
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
