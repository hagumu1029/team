#pragma once


#include "../Base/Base.h"
//�}�b�v�̉��̃`�b�v��
#define MAP_WIDTH    	40
//�}�b�v�̏c�̃`�b�v��
#define MAP_HEIGHT	22
//�}�b�v�`�b�v�̑傫��
#define MAP_TIP_SIZE	128

class Map : public Base {
private:
    CImage m_img;
public:
    Map();
    void Draw();
};



