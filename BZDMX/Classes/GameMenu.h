#pragma once
#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "StageSelect.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
class GameMenu : public cocos2d::CCLayer
{
public:
	GameMenu(void);
	~GameMenu(void);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
	void startButtonCallback(CCObject* pSender);
    void 	aboutItemCallback(CCObject* pSender);
    void 	optionItemCallback(CCObject* pSender);
	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(GameMenu);
};

