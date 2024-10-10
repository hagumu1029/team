#pragma once
#include"../Base/Base.h"

class Title :public Base {
	//画像オブジェクト
	CImage m_img;
	CImage m_push;
	//文字表示オブジェクト
	CFont m_title_text;
	//待ち時間
	int m_cnt;
	int m_fruit_cnt;
public:
	Title();
	void Update();
	void Draw();
};