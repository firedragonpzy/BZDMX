#include "HelloWorldScene.h"
#include "GameMenu.h"
using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
		 CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_startup_cg.mp3",true);
        CCSprite *sprite1=CCSprite::create("StageCG_bkg1_zh.png");
		sprite1->setAnchorPoint(ccp(0,0));
		sprite1->setPosition(ccp(0,0));
		
		addChild(sprite1);
		
		CCFadeIn* fadein=CCFadeIn::create(1.0f);
		CCFadeIn* fadein2=CCFadeIn::create(0.1f);
		//sprite1->runAction(fadein);

		 CCSpriteFrame * frame0=CCSpriteFrame::create("StageCG_bkg1_zh.png",CCRectMake(0,0,800,480)); 
	     CCSpriteFrame * frame1=CCSpriteFrame::create("StageCG_bkg2_zh.png",CCRectMake(0,0,800,480));
	     CCSpriteFrame * frame2=CCSpriteFrame::create("StageCG_bkg3_zh.png",CCRectMake(0,0,800,480)); 
		 CCSpriteFrame * frame3=CCSpriteFrame::create("StageCG_bkg4_zh.png",CCRectMake(0,0,800,480));
      CCArray* array=CCArray::createWithCapacity(4);
	  array->addObject(frame0);
	  array->addObject(frame1);
	  array->addObject(frame2);
	  array->addObject(frame3);
	  CCAnimation* animation=CCAnimation::createWithSpriteFrames(array,2.0f);
	  
	  CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(HelloWorld::animateFinished));
	  sprite1->runAction(CCSequence::create(CCSpawn::createWithTwoActions(fadein,CCAnimate::create(animation)),actionMoveDone,NULL));
		//addChild(sprite2);

        CC_BREAK_IF(! CCLayer::init());
		CCMenuItemImage *skipItem = CCMenuItemImage::create(
			"StageCG_skip_normal_zh.png",
			"StageCG_skip_pressed_zh.png",
			this,
			menu_selector(HelloWorld::skipCallback));
		CC_BREAK_IF(! skipItem);

		// Place the menu item bottom-right conner.
		skipItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 110, CCDirector::sharedDirector()->getWinSize().height-50));
		//this->addChild(skipItem);
		CCMenu* pMenu = CCMenu::create(skipItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);
        bRet = true;
    } while (0);

    return bRet;
}
 void  HelloWorld::skipCallback(CCObject* pSender)
 {
	 CCScene *gameMenu=GameMenu::scene();
	 CCDirector::sharedDirector()->replaceScene( CCTransitionJumpZoom::create(1.0f,gameMenu));
 }
void HelloWorld::animateFinished(CCNode *sender)
{

	CCScene *gameMenu=GameMenu::scene();
	CCDirector::sharedDirector()->replaceScene( CCTransitionJumpZoom::create(1.0f,gameMenu));
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

