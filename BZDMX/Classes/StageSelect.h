#pragma once
#include "cocos2d.h"
#include "Game_1_1.h"
USING_NS_CC;
class StageSelect : public cocos2d::CCLayer
{
public:
	StageSelect(void);
	~StageSelect(void);
	static cocos2d::CCScene* scene();
	virtual bool init();  
	CREATE_FUNC(StageSelect);
	void backItemCallback(CCObject* pSender);
	void stageOneItemCallback(CCObject* pSender);
};

