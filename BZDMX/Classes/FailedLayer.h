#pragma once
#include "BZDMX.h"
class FailedLayer : public cocos2d::CCLayer
{
public:
	FailedLayer(void);
	~FailedLayer(void);
	virtual bool init();
	CREATE_FUNC(FailedLayer);
	void update(float dt);
	void backItemCallback(CCObject* pSender);
};

