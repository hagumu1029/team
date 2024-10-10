#pragma once
#include"../Base/Base.h"

class Game :public Base {
	int m_cnt;
	int m_enemy_cnt;
	CImage m_img;
public:
	Game();
	void Update();
};