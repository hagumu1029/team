//--���R--------------------------------------









//--�叟---------------------------------------
#include"Game.h"
#include"Field.h"
#include"../Title/Title.h"

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













