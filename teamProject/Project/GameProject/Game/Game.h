#pragma once
#include"../Base/Base.h"

class Game :public Base {
	int m_cnt;
	int m_enemy_cnt;
public:
	Game();
	void Update();
};