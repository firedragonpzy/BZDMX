#pragma once
#include "BZDMX.h"
class VictoryLayer : public cocos2d::CCLayer
{
public:
	VictoryLayer(void);
	~VictoryLayer(void);
	virtual bool init();
	CREATE_FUNC(VictoryLayer);
	void update(float dt);
	void backItemCallback(CCObject* pSender);
};

