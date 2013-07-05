#include "AboutScene.h"


AboutScene::AboutScene(void)
{
}


AboutScene::~AboutScene(void)
{
}
CCScene* AboutScene::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		AboutScene *layer = AboutScene::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
bool AboutScene::init()
{
	bool bRet = false;
	do 
	{CCSprite* bgSprite=CCSprite::create("Startup_bkg_gray.jpg");
	bgSprite->setAnchorPoint(ccp(0,0));
	bgSprite->setPosition(ccp(0,0));

	addChild(bgSprite);

	CCSprite* bgSprite2=CCSprite::create("about.png");
	//bgSprite->setAnchorPoint(ccp(0,0));
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	bgSprite2->setPosition(ccp(size.width / 2, size.height/2));
	
	//  float a=(float)480/800;
	// float b=(float)320/480;
	//  bgSprite2->setScaleX((float)480/800);
	//  bgSprite2->setScaleY((float)320/480);
	//bgSprite2->setScaleX(0.9f);
	//  bgSprite2->setScaleY(0.9f);
	addChild(bgSprite2);
	
	
	
	
	


	CCMenuItemImage *musicItem = CCMenuItemImage::create(
		"Option_btn_back_zh.png",
		"Option_btn_back_pressed_zh.png",
		this,
		menu_selector(AboutScene::musicItemCallback));
	musicItem->setPosition(ccp(size.width/2,120));
	CCMenu* pMenu = CCMenu::create(musicItem, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);
	bRet=true;

	}while(0);
	return bRet;

}
void AboutScene::musicItemCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}