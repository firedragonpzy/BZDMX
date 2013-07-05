#include "GameMenu.h"


GameMenu::GameMenu(void)
{
}


GameMenu::~GameMenu(void)
{
}
CCScene* GameMenu::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		GameMenu *layer = GameMenu::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

 bool GameMenu::init()
 {
	 bool bRet = false;
	 do 
	 {
		  
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
		  CCSprite* title =CCSprite::create("Startup_lbl_title_zh.png");
		  title->setPosition(ccp(size.width/2,size.height-135));
		  addChild(title);
		  CCSprite* photo_border=CCSprite::create("Startup_photo_border.png");
		  photo_border->setPosition(ccp(230,200));

		  addChild(photo_border);
		  CCSprite* saveher=CCSprite::create("Startup_lbl_saveher.png");
		  saveher->setPosition(ccp(230,240));

		  addChild(saveher);
		  CCSprite* herface=CCSprite::create("Startup_herface1.png");
		  herface->setPosition(ccp(230,180));
		  
		  addChild(herface,2);
		  herface->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(biqiSmile))));
		  CCMenuItemImage *startItem = CCMenuItemImage::create(
			  "Startup_lbl_start_zh.png",
			  "Startup_lbl_start_pressed_zh.png",
			  this,
			  menu_selector(GameMenu::startButtonCallback));
		  CC_BREAK_IF(! startItem);

		  // Place the menu item bottom-right conner.
		  startItem->setPosition(ccp(435,250));
		  //this->addChild(skipItem);
		  CCMenu* pMenu = CCMenu::create(startItem, NULL);
		  pMenu->setPosition(CCPointZero);
		  addChild(pMenu);
		   //,,,,,,,,,,,,,,,,,,,,,,
		  CCMenuItemImage *aboutItem = CCMenuItemImage::create(
			  "Startup_lbl_about_zh.png",
			  "Startup_lbl_about_pressed_zh.png",
			  this,
			  menu_selector(GameMenu::aboutItemCallback));
		  CC_BREAK_IF(! aboutItem);

		  // Place the menu item bottom-right conner.
		  aboutItem->setPosition(ccp(360,150));
		  //this->addChild(skipItem);
		  CCMenu* aboutItemMenu = CCMenu::create(aboutItem, NULL);
		  aboutItemMenu->setPosition(CCPointZero);
		  addChild(aboutItemMenu);
		  //,,,,,,,,,,,,,,,,,,,,,,
		  CCMenuItemImage *optionItem = CCMenuItemImage::create(
			  "Startup_lbl_option_zh.png",
			  "Startup_lbl_option_pressed_zh.png",
			  this,
			  menu_selector(GameMenu::optionItemCallback));
		  CC_BREAK_IF(! optionItem );

		  // Place the menu item bottom-right conner.
		  optionItem ->setPosition(ccp(500,150));
		  //this->addChild(skipItem);
		  CCMenu* optionItemMenu = CCMenu::create(optionItem , NULL);
		  optionItemMenu->setPosition(CCPointZero);
		  addChild(optionItemMenu);
		  CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_home.mp3",true);
		  bRet = true;
	 }while(0);
	 return bRet;

 }
 void GameMenu::startButtonCallback(CCObject* pSender)
 {
	 CCScene *stageSelect=StageSelect::scene();
	 //CCDirector::sharedDirector()->replaceScene( CCTransitionJumpZoom::create(1.0f,stageSelect));
	 CCDirector::sharedDirector()->pushScene( (CCTransitionSlideInR::create(1, stageSelect)));
 }
 void 	GameMenu::aboutItemCallback(CCObject* pSender)
 {
	 CCScene *setting=AboutScene::scene();
	 CCDirector::sharedDirector()->pushScene(setting);
 }
 void 	GameMenu::optionItemCallback(CCObject* pSender)
 {
	   CCScene *setting=SettingScene::scene();
	  CCDirector::sharedDirector()->pushScene(setting);
 }