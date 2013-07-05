#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "BZDMX.h"
class Game_1_1  : public cocos2d::CCLayer
{
public:
	Game_1_1(void);
	~Game_1_1(void);
 // static	CCSprite *hero;
	typedef enum{
		die=0,
		normal=1,
		left=3,
		kright=4,
	} State;
	static cocos2d::CCScene* scene();
	virtual bool init();  
	CREATE_FUNC(Game_1_1);
	void update(float dt);
	void backItemCallback(CCObject* pSender);
	CCAnimation* createAnimationByState(State direction);
	void  ccTouchesBegan (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void  ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent); 
	bool haveTouchBiqi;
};

