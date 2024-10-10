#include"UI.h"
UI::UI() :Base(eType_UI) {
	m_img = COPY_RESOURCE("clear", CImage);
}

void UI::Draw()
{
	if (!Base::FindObject(eType_Goal)) {
		m_img.SetSize(1920, 1020);
		m_img.Draw();
	}
}