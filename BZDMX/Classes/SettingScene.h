#pragma once
#include "BZDMX.h"
class SettingScene : public cocos2d::CCLayer
{
public:
	SettingScene(void);
	~SettingScene(void);
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(SettingScene);
	bool isMusicSwitchOn;
	bool isEffectSwitchOn;
	void 	musicItemCallback(CCObject* pSender);
	void 	effectItemCallback(CCObject* pSender);
	void  ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

