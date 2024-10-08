#pragma once


#include "../Base/Base.h"
//マップの横のチップ数
#define MAP_WIDTH    	70
//マップの縦のチップ数
#define MAP_HEIGHT	10
//マップチップの大きさ
#define MAP_TIP_SIZE	128

class Map : public Base {
private:
    CImage m_img;
    int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
    Map();
    void Draw();
    //指定座標のチップ番号を取得
    int GetTip(const CVector2D& pos);
    //指定列、指定行のマップチップを取得
    int GetTip(int col, int row);
    //マップとの当たり判定
    int CollisionPoint(const CVector2D& pos);
    int CollisionRect(const CVector2D& pos, const CRect& rect);

};



