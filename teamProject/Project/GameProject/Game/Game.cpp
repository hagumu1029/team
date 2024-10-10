//--平山--------------------------------------
#include"Goal.h"
#include"Map.h"
#include"Fruit.h"
#include"cannon2.h"







//--大勝---------------------------------------
#include"Game.h"
#include"Field.h"
#include"../Title/Title.h"
#include"Player.h"
#include"Enemy.h"
#include"cannon.h"
#include"Bullet.h"
#include"UI.h"

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Map());
	Base::Add(new Goal(CVector2D(8000, 680)));
	Base::Add(new Player(CVector2D(6150, 680)));
	//Base::Add(new Enemy(CVector2D(1000, 1050)));
	Base::Add(new cannon(CVector2D(1300, 800), false));
	Base::Add(new cannon(CVector2D(6700, 680), false));
	Base::Add(new cannon2(CVector2D(6500, 680), true, true));
	Base::Add(new UI());

	//Base::Add(new Bullet(CVector2D(1000,800)));
	m_cnt = 60 * 1;
	m_enemy_cnt = 60 * 5;
}

void Game::Update()
{


	//プレイヤー死亡　ボタン1でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton5)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());
		Base::Add(new Field());
		Base::Add(new Player(CVector2D(100, 450)));
	}
	m_cnt--;
	if (m_cnt <= 0) {
		m_cnt = 20;
		Base::Add(new Fruit(CVector2D(Utility::Rand(0, 1920)+m_scroll.x, 0)));
	}
	m_enemy_cnt--;
	if (m_enemy_cnt <= 0) {
		m_enemy_cnt = 60*5;

		Base::Add(new Enemy(CVector2D(1920 + m_scroll.x, 800), false));
		Base::Add(new Enemy(CVector2D(0 + m_scroll.x, 800), true));
	}
}













