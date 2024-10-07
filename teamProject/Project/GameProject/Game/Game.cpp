//--平山--------------------------------------
#include"Goal.h"
#include"Map.h"







//--大勝---------------------------------------
#include"Game.h"
#include"Field.h"
#include"../Title/Title.h"
#include"Player.h"
#include"Enemy.h"
#include"cannon.h"

 Game::Game():Base(eType_Scene)
{
	 Base::Add(new Field());
	 Base::Add(new Map());
	 Base::Add(new Goal(CVector2D(1000, 900)));
	 Base::Add(new Player(CVector2D(100, 1050)));
	 Base::Add(new Enemy(CVector2D(1000, 1050)));
	 //Base::Add(new cannon(CVector2D(500, 1050), false));


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













