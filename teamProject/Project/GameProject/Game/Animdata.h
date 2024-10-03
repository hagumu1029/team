#pragma once

enum {
	eAnimIdle = 0,
	eAnimStep,
	eAnimJump,
	eAnimDamage,
	eAnimDown,
	eAnimDownGround,
	eAnimWakeUp,
	eAnimGuard,
	eAnimGuardEnd,
	eAnimCrash,
	eAnimCrashEnd,
	eAnimExtAttack01,
	eAnimExtAttack01End,
	eAnimExtAttack02,
	eAnimExtAttack02End,
	
};
extern TexAnimData player_anim_data[];
extern TexAnimData enemy_anim_data[];