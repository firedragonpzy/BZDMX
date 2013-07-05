#pragma once
#include "BZDMX.h"
class AnimationManager : public Singleton<AnimationManager>
{
public:
	AnimationManager(void);
	~AnimationManager(void);
	//初始化动画模版缓存表
	bool initAnimationMap();
	//根据名字得到一个动画模板
	CCAnimation* getAnimation(int key);
	//创建一个动画实例
	CCAnimate* createAnimate(int key);
	//创建一个动画实例
	CCAnimate* createAnimate(const char* key);
	CCSpriteFrame * getSpritFrame(int key);
	
protected:
	//加载勇士行走动画模版
	CCAnimation* createHeroMovingAnimationByDirection(HeroDirection direction);
	CCAnimation* createCryAnimation();
	CCAnimation* createVictoryAnimation();
	CCAnimation* createBiqiSmile();
};

//定义动画管理器实例的别名
#define sAnimationMgr AnimationManager::instance()
