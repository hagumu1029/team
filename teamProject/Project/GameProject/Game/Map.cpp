#include "Map.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
      //{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        { 1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        { 1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        { 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        { 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        


};


Map::Map() : Base(eType_Map)
{

    //画像複製
    m_img = COPY_RESOURCE("MapTip", CImage);
    memcpy(m_stage_data, stage1data, sizeof(stage1data));
}

void Map::Draw()
{
    //マップチップによる表示の繰り返し
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (stage1data[i][j] == 0)continue;
            int t = stage1data[i][j];

            //画像切り抜き
            m_img.SetRect(32, 0, 32 + 32, 32);
            //表示サイズ設定
            m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
            //表示位置設定
            m_img.SetPos(MAP_TIP_SIZE * j-m_scroll.x, MAP_TIP_SIZE * i-m_scroll.y);
            //描画
            m_img.Draw();
        }
    }
    DrawRect();
}

int Map::GetTip(const CVector2D& pos)
{
    //列を計算
    int col = pos.x / MAP_TIP_SIZE;
    //列の制限(0〜MAP_WIDTH-1)
    if (col < 0) col = 0;
    if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
    //行を計算
    int row = pos.y / MAP_TIP_SIZE;
    //行の制限(0〜MAP_HEIGHT-1)
    if (row < 0) row = 0;
    if (row > MAP_HEIGHT - 1) row = MAP_HEIGHT - 1;
    //チップデータを返却
    return GetTip(col, row);
    
}

int Map::GetTip(int col, int row)
{
    return stage1data[row][col];
}

int Map::CollisionPoint(const CVector2D& pos)
{
    //1点のみ検証
    int t = GetTip(pos);
    if (t != 0) return t;
    return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
    CRect r = CRect(
        pos.x + rect.m_left,
        pos.y + rect.m_top,
        pos.x + rect.m_right,
        pos.y + rect.m_bottom);
    int t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_top));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
    if (t != 0) return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
    if (t != 0) return t;
    return 0;
}
