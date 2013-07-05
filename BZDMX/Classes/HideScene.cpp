#include "HideScene.h"


HideScene::HideScene(void)
{
}


HideScene::~HideScene(void)
{
}
CCScene* HideScene::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		HideScene *layer = HideScene::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
bool HideScene::init()
{
	bool bRet = false;
	do 
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		GameMap *gameMap2=GameMap::gameMapWithTMXFile("TMX_2_1.tmx");
	this->addChild(gameMap2);
		bRet=true;
	}while(0);
	return bRet;
}