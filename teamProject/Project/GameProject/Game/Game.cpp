//--���R--------------------------------------
#include"Goal.h"
#include"Map.h"







//--�叟---------------------------------------
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













