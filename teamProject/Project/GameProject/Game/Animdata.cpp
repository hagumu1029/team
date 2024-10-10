#include "Animdata.h"



static TexAnim playerIdle[] = {
	{ 0 ,10},
	{ 1 ,10},
	{ 8 ,10},
	{ 9 ,10},

};
static TexAnim playerStep[] = {
	{ 24, 5},
	{ 25 ,5},
	{ 26 ,5},
	{ 27 ,5},
	{ 28 ,5},
	{ 29 ,5},
	{ 30 ,5},
	{ 31 ,5},
};
static TexAnim playerJump[] = {
	{ 40,10},
	{ 41 ,10},
	{ 42 ,10},
	{ 43 ,10},
	{ 44 ,10},
	{ 45 ,10},
	{ 46 ,10},
};

static TexAnim playerDamage[] = {
	{ 49 ,6},
	{ 50 ,6},
	{ 51 ,6},
	{ 50 ,6},
	{ 51 ,6},
};

static TexAnim playerDown[] = {
	{ 57 ,6},
	{ 58 ,6},
	{ 59 ,6},
	{ 60 ,6},
	{ 61 ,6},
	{ 62 ,6},
	{ 63 ,6},
	{ 64 ,6},
};

TexAnimData player_anim_data[] = {
ANIMDATA(playerIdle),
ANIMDATA(playerStep),
ANIMDATA(playerJump),
ANIMDATA(playerDamage),
ANIMDATA(playerDown),
};

static TexAnim enemyIdle[] = {
	{ 0 ,10},
	{ 1 ,10},

};
static TexAnim enemyStep[] = {
	{ 0 ,10},
	{ 1 ,10},

};

static TexAnim enemyDown[] = {
	{ 5 ,10},
	{ 6 ,10},
	{ 7 ,10},
	{ 8 ,10},
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyIdle),
	ANIMDATA(enemyStep),
	ANIMDATA(enemyDown),
};

static TexAnim cannonIdle[] = {
	{ 6 ,10},
	{ 7 ,10},
	{ 8 ,10},
	{ 9 ,10},
	{ 10 ,120},
};

TexAnimData cannon_anim_data[] = {
ANIMDATA(cannonIdle),
};