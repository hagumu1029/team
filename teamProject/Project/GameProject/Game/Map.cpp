#include "Map.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
      { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      


};


Map::Map() : Base(eType_Map)
{

    //�摜����
    m_img = COPY_RESOURCE("MapTip", CImage);
    memcpy(m_stage_data, stage1data, sizeof(stage1data));
}

void Map::Draw()
{
    //�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (stage1data[i][j] == 0)continue;
            int t = stage1data[i][j];

            //�摜�؂蔲��
            m_img.SetRect(32, 0, 32 + 32, 32);
            //�\���T�C�Y�ݒ�
            m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
            //�\���ʒu�ݒ�
            m_img.SetPos(MAP_TIP_SIZE * j-m_scroll.x, MAP_TIP_SIZE * i-m_scroll.y);
            //�`��
            m_img.Draw();
        }
    }
    DrawRect();
}

int Map::GetTip(const CVector2D& pos)
{
    //����v�Z
    int col = pos.x / MAP_TIP_SIZE;
    //��̐���(0�`MAP_WIDTH-1)
    if (col < 0) col = 0;
    if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
    //�s���v�Z
    int row = pos.y / MAP_TIP_SIZE;
    //�s�̐���(0�`MAP_HEIGHT-1)
    if (row < 0) row = 0;
    if (row > MAP_HEIGHT - 1) row = MAP_HEIGHT - 1;
    //�`�b�v�f�[�^��ԋp
    return GetTip(col, row);
    
}

int Map::GetTip(int col, int row)
{
    return stage1data[row][col];
}

int Map::CollisionPoint(const CVector2D& pos)
{
    //1�_�̂݌���
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
