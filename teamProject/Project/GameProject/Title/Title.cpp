#include"Title.h"
#include"Game/Game.h"
#include"../Base/Base.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(1000, 300);
	m_push = COPY_RESOURCE("Play", CImage);
	m_push.SetSize(400, 100);
}
void Title::Update()
{
	//���N���b�N�Ń^�C�g���j��
	if (m_cnt++ > 60 && PUSH(CInput::eButton5)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[����
		Base::Add(new Game());
	}
}

void Title::Draw()
{
	m_img.SetPos(470,150);
	m_img.Draw();
	m_push.SetPos(700, 670);
	m_push.Draw();

	//�����\��
	//m_title_text.Draw(930, 150, 100, 100, 100, "Title");
}