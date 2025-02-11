#pragma once
#include "State_Base.h"

#define STATE_IDLE 0
#define STATE_WALK 1
#define STATE_JUMP 2
#define STATE_SWIM 3

#define ANI_IDLE_RIGHT 400
#define ANI_IDLE_LEFT 401
#define ANI_WALK_RIGHT 600
#define ANI_WALK_LEFT 601

class State_Contra_Base : public State_Base
{
	protected:

	public:
		State_Contra_Base(Game_ObjectBase* obj) : State_Base(obj){}

		int StateId() override { return -1; }
		void Render() override {}
		void Update(DWORD dt) override {}

		virtual void KeyHold_Up() {}
		virtual void KeyHold_Down() {}
		virtual void KeyHold_Left() {}
		virtual void KeyHold_Right() {}
		virtual void KeyHold_Shoot() {}

		virtual void KeyPressed_Up() {}
		virtual void KeyPressed_Down() {}
		virtual void KeyPressed_Left() {}
		virtual void KeyPressed_Right() {}
		virtual void KeyPressed_Shoot() {}
		virtual void KeyPressed_Jump() {}

		virtual void KeyReleased_Up() {}
		virtual void KeyReleased_Down() {}
		virtual void KeyReleased_Left() {}
		virtual void KeyReleased_Right() {}
		virtual void KeyReleased_Shoot() {}
		virtual void KeyReleased_Jump() {}
};

