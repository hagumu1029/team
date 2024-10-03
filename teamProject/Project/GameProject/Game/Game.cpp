//--平山--------------------------------------
#include"Goal.h"
#include"Map.h"







//--大勝---------------------------------------
#include"Game.h"
#include"Field.h"
#include"../Title/Title.h"

 Game::Game():Base(eType_Scene)
{
	 Base::Add(new Field());
	 Base::Add(new Goal(CVector2D(512, 540)));
	 Base::Add(new Map());
 

}

void Game::Update()
{
	//ゴールが無ければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	}
	//プレイヤー死亡　ボタン1でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
	}
}













