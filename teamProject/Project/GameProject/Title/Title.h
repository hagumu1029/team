#pragma once
#include"../Base/Base.h"

class Title :public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	CImage m_push;
	//�����\���I�u�W�F�N�g
	CFont m_title_text;
	//�҂�����
	int m_cnt;
	int m_fruit_cnt;
public:
	Title();
	void Update();
	void Draw();
};