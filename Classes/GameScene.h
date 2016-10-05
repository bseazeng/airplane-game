#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "HeroPlaneLayer.h"
#include "BulletLayer.h"

using namespace cocos2d;

class GameScene : public cocos2d::Scene {
public:
	CREATE_FUNC(GameScene);
private:
	virtual bool init() override;

	GameBackgroundLayer *game_background_layer;
	HeroPlaneLayer *hero_plane_layer;
	BulletLayer *bullet_layer;
};
#endif