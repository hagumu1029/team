//--���R--------------------------------------
#include"Goal.h"
#include"Map.h"







//--�叟---------------------------------------
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
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
	}
	//�v���C���[���S�@�{�^��1�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
	}
}













