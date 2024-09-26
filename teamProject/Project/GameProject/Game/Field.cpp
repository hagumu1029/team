#include"Field.h"

Field::Field() :Base(eType_Field) {
	m_sky = COPY_RESOURCE("Sky", CImage);
	m_background= COPY_RESOURCE("BackGround", CImage);
	m_foreground= COPY_RESOURCE("ForeGround", CImage);
	m_sky.SetSize(1920, 1020);
	m_background.SetSize(1920, 1020);
	m_foreground.SetSize(1920, 1020);
	m_ground_y = 1150;
}
void Field::Draw()
{
	float sc;
	m_sky.Draw();
	sc = m_scroll.x/4;
	m_background.SetRect(sc, 0, sc + 512, 256);
	m_background.Draw();

	sc = m_scroll.x;
	m_foreground.SetRect(sc, 0, sc + 512, 256);
	m_foreground.Draw();
}