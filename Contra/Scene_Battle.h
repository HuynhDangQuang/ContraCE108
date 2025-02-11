#pragma once

#include "Scene_Base.h"
#include "ScreenManager.h"
#include <string>
#include "debug.h"
#include "Game_Player.h"
#include "Game_Layer.h"
#include "Game_Blocker.h"
#include "Game_Terrain.h"
#include "Game_Collision.h"
#include "Game_Water.h"
// DEMO
#include "Demo_Layer.h"

using namespace std;


class Scene_Battle : public Scene_Base
{
	private: 
		Game_Player* _p1 = NULL;
		Game_Player* _p2 = NULL;
		vector<Game_Layer*> _layers;
		vector<Game_ObjectBase*> _objects;
		int _mapWidth = 1;
		int _mapHeight = 1;
		void checkObjectNeedRender(Game_ObjectBase* obj);
		// DEMO
		void Demo_Camera_Action();
	public:
		~Scene_Battle();
		vector<Game_ObjectBase*>* objects() { return &_objects; }
		Game_Player* p1() { return _p1; }
		Game_Player* p2() { return _p2; }
		int MapWidth() { return _mapWidth; }
		int MapHeight() { return _mapHeight; }
		void SetMapSize(int width, int height) { _mapWidth = width; _mapHeight = height; }

		void Render() override;
		void Update(DWORD dt) override;

		void Create_Stage_Demo();
};

