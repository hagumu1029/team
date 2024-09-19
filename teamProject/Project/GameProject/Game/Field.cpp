#include"Field.h"

Field::Field() :Base(eType_Field) {
	m_sky = COPY_RESOURCE("sky", CImage);
	m_background= COPY_RESOURCE("background", CImage);
	m_foreground= COPY_RESOURCE("foreground", CImage);
	m_ground_y = 540;
}
void Field::Draw()
{
	m_sky.Draw();
	m_background.Draw();
	m_foreground.Draw();
}