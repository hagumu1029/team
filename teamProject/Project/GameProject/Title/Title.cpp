#include"Title.h"
#include"../Game/Game.h"
#include"../Base/Base.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(1920, 1080);
	m_push = COPY_RESOURCE("Play", CImage);
	m_push.SetSize(168, 88);
}
void Title::Update()
{
	//ボタン1でタイトル破棄
	if (m_cnt++ > 60 && PUSH(CInput::eMouseL)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーンへ
		Base::Add(new Game());
	}
}

void Title::Draw()
{
	m_img.Draw();
	m_push.SetPos(960, 600);
	m_push.Draw();

	//文字表示
	m_title_text.Draw(960, 150, 100, 100, 100, "Title");
}