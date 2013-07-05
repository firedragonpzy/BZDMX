#include "SettingScene.h"

CCSprite* musicSwitch;
CCSprite* effectSwitch;
SettingScene::SettingScene(void)
{
}


SettingScene::~SettingScene(void)
{
}
CCScene* SettingScene::scene()
{
	CCScene * scene = NULL;
	do 
	{

		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SettingScene *layer = SettingScene::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
bool SettingScene::init()
{
	bool bRet = false;
	do 
	{
		this->setTouchEnabled(true);
		isMusicSwitchOn=sGlobal->isMusicOn;
		isEffectSwitchOn=sGlobal->isEffectOn;
		
		CCSprite* bgSprite=CCSprite::create("Startup_bkg_gray.jpg");
		bgSprite->setAnchorPoint(ccp(0,0));
		bgSprite->setPosition(ccp(0,0));

		addChild(bgSprite);

		CCSprite* bgSprite2=CCSprite::create("Startup_frame.png");
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
		CCSprite* photo_border=CCSprite::create("Startup_photo_border.png");
		photo_border->setPosition(ccp(190,190));

		addChild(photo_border);
		CCSprite* herface=CCSprite::create("Option_gear.png");
		herface->setPosition(ccp(190,190));

		addChild(herface,2);
		CCSprite* option=CCSprite::create("Startup_lbl_option_zh.png");
		option->setPosition(ccp(size.width/2,240+120));

		addChild(option,2);

		CCSprite*  music=CCSprite::create("Option_lbl_music_zh.png");
		music->setPosition(ccp(size.width/2-30,240));

		addChild(music,2);

		CCSprite*  effect=CCSprite::create("Option_lbl_sound_zh.png");
		effect->setPosition(ccp(size.width/2-30,180));

		addChild(effect,2);
		musicSwitch=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(onkey));
		 effectSwitch=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(onkey));
		musicSwitch->setPosition(ccp(size.width/2+100,240));
		effectSwitch->setPosition(ccp(size.width/2+100,180));
		addChild(musicSwitch);
		addChild(effectSwitch);
		//......
		CCMenuItemImage *musicItem = CCMenuItemImage::create(
			"Option_btn_back_zh.png",
			"Option_btn_back_pressed_zh.png",
			this,
			menu_selector(SettingScene::musicItemCallback));
		musicItem->setPosition(ccp(size.width/2,120));
		CCMenu* pMenu = CCMenu::create(musicItem, NULL);
		pMenu->setPosition(CCPointZero);
		addChild(pMenu);
		//..............
		if (isMusicSwitchOn)
		{
			musicSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(onkey));

		}else
		{
			musicSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(offkey));

		}
		if (isEffectSwitchOn)
		{
			effectSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(onkey));

		}else
		{
			effectSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(offkey));

		}

		bRet=true;
	}while(0);
	return bRet;

}
void SettingScene::musicItemCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}
void  SettingScene::ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
	CCPoint	location=touch->getLocationInView();
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);
	if (location.x>size.width/2+100-65&&location.x<size.width/2+100+65&&location.y>210&&location.y<270)
	{
		if (isMusicSwitchOn)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
			musicSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(offkey));
			isMusicSwitchOn=false;
			sGlobal->isMusicOn=false;
			
		}else
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_home.mp3",true);
			musicSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(onkey));
			isMusicSwitchOn=true;
			sGlobal->isMusicOn=true;
		}
	}
	if (location.x>size.width/2+100-65&&location.x<size.width/2+100+65&&location.y>150&&location.y<210)
	{
		if (isEffectSwitchOn)
		{
			effectSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(offkey));
			isEffectSwitchOn=false;
			sGlobal->isEffectOn=false;
		}else
		{
			effectSwitch->setDisplayFrame(sAnimationMgr->getSpritFrame(onkey));
			isEffectSwitchOn=true;
			sGlobal->isEffectOn=true;
		}
	}
}