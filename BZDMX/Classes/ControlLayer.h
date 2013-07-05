#pragma once
#include "BZDMX.h"
class ControlLayer : public cocos2d::CCLayer
{
public:
	ControlLayer(void);
	~ControlLayer(void);
		virtual bool init();

		CREATE_FUNC(ControlLayer);
		void  ccTouchesBegan (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
		void  ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent); 
		void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
		void update(float delta);
		int failedLayerInitTimes;
	   int 	winLayerInitTimes;
};

