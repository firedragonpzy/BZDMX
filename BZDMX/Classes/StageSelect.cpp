#include "StageSelect.h"


StageSelect::StageSelect(void)
{

}


StageSelect::~StageSelect(void)
{

}
CCScene* StageSelect::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		StageSelect *layer = StageSelect::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}
bool StageSelect::init()
{
	bool bRet = false;
	do 
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite* bgSprite=CCSprite::create("StageSelector_bkg_gray.jpg");
		bgSprite->setPosition(ccp(size.width / 2, size.height/2));
		this->addChild(bgSprite);
		CCSprite* StageSelect_frame=CCSprite::create("StageSelect_frame.png");
		//bgSprite->setAnchorPoint(ccp(0,0));
		
		StageSelect_frame->setPosition(ccp(size.width / 2, size.height/2));
		this->addChild(StageSelect_frame);
		//........................
		CCMenuItemImage *backItem = CCMenuItemImage::create(
			"Thumb_back.png",
			"Thumb_back_pressed.png",
			this,
			menu_selector(StageSelect::backItemCallback));
		CC_BREAK_IF(! backItem );

		// Place the menu item bottom-right conner.
		backItem ->setPosition(ccp(36,size.height-36));
		//this->addChild(skipItem);
		CCMenu* backItemMenu = CCMenu::create(backItem , NULL);
		backItemMenu->setPosition(CCPointZero);
		addChild(backItemMenu);
		//.......................
		CCMenuItemImage *stageOneItem = CCMenuItemImage::create(
			"StageSelect_key_pressed.PNG",
			"StageSelect_tinyblock_pressed.png",
			this,
			menu_selector(StageSelect::stageOneItemCallback));
		CC_BREAK_IF(! stageOneItem );

		// Place the menu item bottom-right conner.
		stageOneItem ->setPosition(ccp(250+30,300));
		//this->addChild(skipItem);
		CCMenu* stageOneItemMenu = CCMenu::create(stageOneItem , NULL);
		stageOneItemMenu->setPosition(CCPointZero);
		addChild(stageOneItemMenu);

		CCLabelTTF* stageOneLabel = CCLabelTTF::create("1", "Arial", 50);
		stageOneLabel->setColor(ccc3(0,0,0));
		CC_BREAK_IF(! stageOneLabel);

		// Get window size and place the label upper. 
		
		 stageOneLabel->setPosition(ccp(250+30,300));
		addChild(stageOneLabel);
		 CCSprite* lockSprite=CCSprite::create("stagelock.png");
		 lockSprite->setPosition(ccp(size.width /2-30-10, size.height/2-10));
		 this->addChild(lockSprite);
		
		 bRet = true;
		
	}while(0);
	return bRet;
}
void StageSelect::backItemCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}
void StageSelect::stageOneItemCallback(CCObject* pSender)
{
	CCScene* game_1_1=Game_1_1::scene();
	 CCDirector::sharedDirector()->pushScene( (CCTransitionSlideInR::create(0.3, game_1_1)));

}