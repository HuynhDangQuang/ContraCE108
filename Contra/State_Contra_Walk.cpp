#include "State_Contra_Walk.h"
#include "Game_Player.h"
#include "Animations.h"

void State_Contra_Walk::Render()
{
	Game_Player* obj = (Game_Player*)_srcObj;
	CAnimations* animations = CAnimations::GetInstance();
	float x, y;
	obj->GetCenterPoint(x, y);
	if (obj->IsFaceLeft())
	{
		animations->Get(ANI_WALK_LEFT)->Render(x, y);
	}
	else
	{
		animations->Get(ANI_WALK_RIGHT)->Render(x, y);
	}
}

void State_Contra_Walk::Update(DWORD dt)
{
	if (left_release && right_release)
	{
		if (_nextState == -1)
		{
			_nextState = STATE_IDLE;
		}
	}
}

void State_Contra_Walk::KeyHold_Left()
{
	Game_Player* obj = (Game_Player*)_srcObj;
	obj->moveLeft();
	left_release = false;
}

void State_Contra_Walk::KeyHold_Right()
{
	Game_Player* obj = (Game_Player*)_srcObj;
	obj->moveRight();
	right_release = false;
}

void State_Contra_Walk::KeyReleased_Left()
{
	left_release = true;
}

void State_Contra_Walk::KeyReleased_Right()
{
	right_release = true;
}