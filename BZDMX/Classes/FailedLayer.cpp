#include "FailedLayer.h"

CCSprite* crySprite;
CCSprite* boxSprite;
CCSprite* loseSprite;
CCLabelTTF* pLabel2;
CCLabelTTF* pLabel3;
CCMenuItemImage *replayItem;
FailedLayer::FailedLayer(void)
{
	sGlobal->faledLayer=this;
}


FailedLayer::~FailedLayer(void)
{
}
bool FailedLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	 boxSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(failedboxkey));
	CCSize size=CCDirector::sharedDirector()->getWinSize();

	boxSprite->setPosition(ccp(size.width/2-sGlobal->game_1_1->getPositionX(),size.height+200));
	this->addChild(boxSprite);
	crySprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(cryFramekey));
	crySprite->setPosition(ccp(boxSprite->getPositionX()-113,boxSprite->getPositionY()-50));
	crySprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(heroCry))));
	this->addChild(crySprite);
	this->scheduleUpdate();
		CCFiniteTimeAction *actionMove=CCMoveBy::create(0.9f,ccp(0,-(size.height/2+200)));
    
		boxSprite->runAction(actionMove);
		loseSprite=CCSprite::create("lose.png",CCRectMake(0,0,163,57));
		loseSprite->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()+60));
		addChild(loseSprite);
		
		pLabel2 = CCLabelTTF::create("IQ:", "Arial",24);
		pLabel2->setColor(ccc3(0,0,0));
		pLabel2->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()+10));

		addChild(pLabel2,2);
		sGlobal->IQ=sGlobal->IQ-50;
		int iq=sGlobal->IQ;
		char temp[20];

		sprintf(temp, "%d", iq);
		//CCStringMake(sGlobal->IQ);
		pLabel3 = CCLabelTTF::create(temp, "Arial",24);
		pLabel3->setColor(ccc3(0,0,0));
		pLabel3->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()-10));

		addChild(pLabel3,2);

		//Ë¢ÐÂ°´Å¥
		replayItem = CCMenuItemImage::create(
			"Btn_replay.png",
			"Btn_replay_pressed.png",
			this,
			menu_selector(FailedLayer::backItemCallback));
	

		// Place the menu item bottom-right conner.
		replayItem ->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()-80));
		//this->addChild(skipItem);
		CCMenu* backItemMenu = CCMenu::create(replayItem , NULL);
		backItemMenu->setPosition(CCPointZero);
		addChild(backItemMenu,2);

	return true;
}
void FailedLayer::update(float dt)
{
	crySprite->setPosition(ccp(boxSprite->getPositionX()-113,boxSprite->getPositionY()-50));
	loseSprite->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()+60));
		replayItem ->setPosition(ccp(boxSprite->getPositionX()+75,boxSprite->getPositionY()-60));
		pLabel2->setPosition(ccp(boxSprite->getPositionX()-30+75,boxSprite->getPositionY()));
		pLabel3->setPosition(ccp(boxSprite->getPositionX()+30+75,boxSprite->getPositionY()));
}
void FailedLayer::backItemCallback(CCObject* pSender)
{
	
	CCDirector::sharedDirector()->popScene();
	CCScene* game_1_1=Game_1_1::scene();
	CCDirector::sharedDirector()->pushScene(game_1_1);
}