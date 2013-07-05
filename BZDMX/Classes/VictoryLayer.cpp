#include "VictoryLayer.h"
CCSprite* victorySprite;
CCSprite* boxSprite2;
CCSprite* winSprite;
CCMenuItemImage *replayItem2;

VictoryLayer::VictoryLayer(void)
{
	sGlobal->IQ=300;
}


VictoryLayer::~VictoryLayer(void)
{
}
bool VictoryLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	boxSprite2=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(failedboxkey));
	CCSize size=CCDirector::sharedDirector()->getWinSize();

	boxSprite2->setPosition(ccp(size.width/2-sGlobal->game_1_1->getPositionX(),size.height+200));
	this->addChild(boxSprite2);
	
	victorySprite=CCSprite::create("Navigator_win_image_2.png",CCRectMake(0,0,181,146));
	victorySprite->setPosition(ccp(boxSprite2->getPositionX()-113,boxSprite2->getPositionY()-50));
	victorySprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(victory))));
	this->addChild(victorySprite);
	this->scheduleUpdate();
	CCFiniteTimeAction *actionMove=CCMoveBy::create(0.9f,ccp(0,-(size.height/2+200)));

	boxSprite2->runAction(actionMove);
	winSprite=CCSprite::create("Navigator_win_text.png",CCRectMake(0,0,163,57));
	winSprite->setPosition(ccp(boxSprite2->getPositionX()+75,boxSprite2->getPositionY()+60));
	addChild(winSprite);
	//Ë¢ÐÂ°´Å¥
	replayItem2 = CCMenuItemImage::create(
		"Btn_replay.png",
		"Btn_replay_pressed.png",
		this,
		menu_selector(VictoryLayer::backItemCallback));


	// Place the menu item bottom-right conner.
	replayItem2 ->setPosition(ccp(boxSprite2->getPositionX()+75,boxSprite2->getPositionY()-60));
	//this->addChild(skipItem);
	CCMenu* backItemMenu = CCMenu::create(replayItem2, NULL);
	backItemMenu->setPosition(CCPointZero);
	addChild(backItemMenu,2);

	return true;
}
void VictoryLayer::update(float dt)
{
	victorySprite->setPosition(ccp(boxSprite2->getPositionX()-113,boxSprite2->getPositionY()-50));
	winSprite->setPosition(ccp(boxSprite2->getPositionX()+75,boxSprite2->getPositionY()+60));
	replayItem2 ->setPosition(ccp(boxSprite2->getPositionX()+75,boxSprite2->getPositionY()-60));
}
void VictoryLayer::backItemCallback(CCObject* pSender)
{

	CCDirector::sharedDirector()->popScene();
	CCScene* game_1_1=Game_1_1::scene();
	CCDirector::sharedDirector()->pushScene(game_1_1);
}