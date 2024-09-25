#include"Field.h"

Field::Field() :Base(eType_Field) {
	m_sky = COPY_RESOURCE("Sky", CImage);
	m_background= COPY_RESOURCE("BackGround", CImage);
	m_foreground= COPY_RESOURCE("ForeGround", CImage);
	m_sky.SetSize(960, 540);
	m_background.SetSize(960, 540);
	m_foreground.SetSize(960, 540);
	m_ground_y = 540;
}
void Field::Draw()
{
	m_sky.Draw();
	m_background.Draw();
	m_foreground.Draw();
}