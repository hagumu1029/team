#pragma once


#include "../Base/Base.h"
//マップの横のチップ数
#define MAP_WIDTH    	40
//マップの縦のチップ数
#define MAP_HEIGHT	22
//マップチップの大きさ
#define MAP_TIP_SIZE	128

class Map : public Base {
private:
    CImage m_img;
public:
    Map();
    void Draw();
};



