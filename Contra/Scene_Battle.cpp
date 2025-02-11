#include "Scene_Battle.h"
#include "ScreenManager.h"
#include "Game_KeyInput.h"

Scene_Battle::~Scene_Battle()
{
    delete _p1;
    delete _p2;

    for (int i = 0; i < _layers.size(); i++)
    {
        delete  _layers.at(i);
    }
    _layers.clear();

    for (int i = 0; i < _objects.size(); i++)
    {
        delete  _objects.at(i);
    }
    _objects.clear();
}

void Scene_Battle::Render()
{
    vector<Game_ObjectBase*> RenderQueue;
    // layers
    for (int i = 0; i < _layers.size(); i++)
    {
        Game_ObjectBase* obj = _layers[i];
        if (obj->NeedRender() == false) {
            continue;
        }
        if (RenderQueue.size() == 0)
        {
            RenderQueue.push_back(obj);
            continue;
        }
        int j = RenderQueue.size();
        while (j > 0 && obj->z() < RenderQueue[j-1]->z())
        {
            j--;
        }
        std::vector<Game_ObjectBase*>::iterator it = RenderQueue.begin();
        RenderQueue.insert(it + j, obj);
    }
    // other game objects
    for (int i = 0; i < _objects.size(); i++)
    {
        Game_ObjectBase* obj = _objects[i];
        if (obj->NeedRender() == false) {
            continue;
        }
        if (RenderQueue.size() == 0)
        {
            RenderQueue.push_back(obj);
            continue;
        }
        int j = RenderQueue.size();
        while (j > 0 && obj->z() < RenderQueue[j-1]->z())
        {
            j--;
        }
        std::vector<Game_ObjectBase*>::iterator it = RenderQueue.begin();
        RenderQueue.insert(it + j, obj);
    }
    // Render ingame objects
    for (int i = 0; i < RenderQueue.size(); i++)
    {
        RenderQueue[i]->Render();
    }
    // images

    // Render Images
}

void Scene_Battle::Update(DWORD dt)
{
    for (int i = 0; i < _objects.size(); i++)
    {
        Game_ObjectBase* obj = _objects.at(i);
        obj->Update(dt);
        obj->Update(dt, objects());
        checkObjectNeedRender(obj);
    }

    // Test
    Demo_Camera_Action();
}

void Scene_Battle::checkObjectNeedRender(Game_ObjectBase* obj)
{
    for (int i = 0; i < _objects.size(); i++)
    {
        Game_ObjectBase* obj = _objects[i];
        Game_Screen* screen = ScreenManager::GetInstance()->Screen();
        if (obj->x() + obj->width() < screen->x()
            || obj->x() > screen->x() + screen->width()
            || obj->y() + obj->height() < screen->y()
            || obj->y() > screen->y() + screen->height())
        {
            obj->SetNeedRender(false);
        } else {
            obj->SetNeedRender(true);
        }
    }
}

//=====================================================================================================================
// DEMO
void Scene_Battle::Create_Stage_Demo()
{
    _mapWidth = GAMESCREEN_WIDTH * 2;
    _mapHeight = GAMESCREEN_HEIGHT;
    _p1 = new Game_Player(40,40,2);
    Game_Blocker* block1 = new Game_Blocker(0,32,1,20,GAMESCREEN_HEIGHT - 52);
    Game_Water* water1 = new Game_Water(0, GAMESCREEN_HEIGHT - 20, 1, 300, 20);
    Game_Blocker* block2 = new Game_Blocker(300, GAMESCREEN_HEIGHT - 30, 1, GAMESCREEN_WIDTH * 2 - 300, 30);
    Game_Blocker* block3 = new Game_Blocker(GAMESCREEN_WIDTH * 2 - 20, 1, 0, 20, GAMESCREEN_HEIGHT - 20);
    Demo_Layer* demo = new Demo_Layer(0, 0, 0, 3328, 239);
    _objects.push_back(_p1);
    _objects.push_back(water1);
    _objects.push_back(block1);
    _objects.push_back(block2);
    _objects.push_back(block3);
    _objects.push_back(demo);
    ScreenManager::GetInstance()->Screen()->focusToPoint(GAMESCREEN_WIDTH/2,GAMESCREEN_HEIGHT/2, _mapWidth, _mapHeight);
    Game_KeyInput::GetInstance()->AddObjectControl(_p1);
}

int moveRange = 0;
bool switchLeft = false;
float camPosX = 0;
float camPosY = 0;

void Scene_Battle::Demo_Camera_Action()
{
    Game_Screen* cam = ScreenManager::GetInstance()->Screen();
    p1()->GetCenterPoint(camPosX, camPosY);
    cam->focusToPoint(camPosX, camPosY, _mapWidth, _mapHeight);  

    //cam->GetCenterPoint(camPosX, camPosY);
    //if (moveRange > 0)
    //{
    //    moveRange--;
    //    if (switchLeft) {
    //        camPosX--;
    //    }
    //    else {
    //        camPosX++;
    //    }

    //    cam->focusToPoint(camPosX, camPosY, _mapWidth, _mapHeight);
    //}
    //else
    //{
    //    moveRange = _mapWidth / 2;
    //    switchLeft = !switchLeft;
    //}


}