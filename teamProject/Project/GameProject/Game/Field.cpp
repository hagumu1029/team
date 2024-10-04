#include"Field.h"

Field::Field() :Base(eType_Field) {
	m_sky = COPY_RESOURCE("Sky", CImage);
	m_tree = COPY_RESOURCE("Tree", CImage);
	m_background= COPY_RESOURCE("Ground", CImage);
	m_foreground= COPY_RESOURCE("ForeGround", CImage);
	m_sky.SetSize(1920,1020);
	m_tree.SetSize(1920, 1020);
	m_background.SetSize(1920, 1020);
	m_foreground.SetSize(1920,1020);
	m_ground_y = 980;
}

void Field::Draw()
{
	float sc;
	m_sky.Draw();
	sc = m_scroll.x/4 * (320.0 / 1920);
	m_background.SetRect(sc, 0, sc + 320, 180);
	m_background.Draw();
	
	sc = m_scroll.x/3 * (320.0 / 1920);
	m_tree.SetRect(sc, 0, sc + 320, 180);
	m_tree.Draw();

	sc = m_scroll.x * 1 * (320.0 / 1920); 
	m_foreground.SetRect(sc, 0, sc + 320, 180);
	m_foreground.Draw();
}