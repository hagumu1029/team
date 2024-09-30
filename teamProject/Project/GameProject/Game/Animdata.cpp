#include "Animdata.h"


static TexAnim playerstep[] = {
	{ 24, 10},
	{ 25 ,10},
	{ 26 ,10},
	{ 27 ,10},
	{ 28 ,10},
	{ 29 ,10},
	{ 30 ,10},
	{ 31 ,10},
};
static TexAnim playerJumpUp[] = { { 24, 6},
	{ 40,10},
	{ 41 ,10},
	{ 42 ,10},
	{ 43 ,10},
	{ 44 ,10},
	{ 45 ,10},
	{ 46 ,10},
};
static TexAnim playerJumpDown[] = { { 24, 6},
	{ 25 ,6},
	{ 26 ,6},
	{ 27 ,6},
	{ 28 ,6},
	{ 29 ,6},
	{ 30 ,6},
	{ 31 ,6}, };
static TexAnim playerRun[] = { { 24, 6},
	{ 25 ,6},
	{ 26 ,6},
	{ 27 ,6},
	{ 28 ,6},
	{ 29 ,6},
	{ 30 ,6},
	{ 31 ,6}, };

TexAnimData player_anim_data[] = {
ANIMDATA(playerstep),
ANIMDATA(playerRun),
ANIMDATA(playerJumpUp),
ANIMDATA(playerJumpDown),

};