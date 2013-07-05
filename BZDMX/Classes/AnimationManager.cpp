#include "AnimationManager.h"

DECLARE_SINGLETON_MEMBER(AnimationManager);
AnimationManager::AnimationManager(void)
{
}


AnimationManager::~AnimationManager(void)
{
}
bool AnimationManager::initAnimationMap()
{
	char temp[20];
	
	sprintf(temp, "%d", aRight);
	//加载勇士向右走的动画
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hright), temp);
	sprintf(temp, "%d", aLeft);
	//加载勇士向左走的动画
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hleft), temp);
	sprintf(temp, "%d", aDie);
	//加载勇士死亡的动画
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hdie), temp);
	 
	sprintf(temp, "%d", heroCry);
	
	CCAnimationCache::sharedAnimationCache()->addAnimation(createCryAnimation(), temp);

	sprintf(temp, "%d", victory);

	CCAnimationCache::sharedAnimationCache()->addAnimation(createVictoryAnimation(), temp);
	
	sprintf(temp, "%d", biqiSmile);

	CCAnimationCache::sharedAnimationCache()->addAnimation(createBiqiSmile(), temp);
	CCSpriteFrame *heronormal, *heroleftJump, *herorightJump;

	//第二个参数表示显示区域的x, y, width, height，根据direction来确定显示的y坐标

	CCTexture2D *heroTexture = CCTextureCache::sharedTextureCache()->addImage("Hero_image.png");
	heronormal = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*0, eSize*1, eSize, eSize));
	heroleftJump = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*0, eSize*2, eSize, eSize));
	herorightJump = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*1, eSize*2, eSize, eSize));
	CCSpriteFrame *controlLeft=CCSpriteFrame::create("Thumb_dpad_left.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlLeftPressed=CCSpriteFrame::create("Thumb_dpad_left_pressed.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlRight=CCSpriteFrame::create("Thumb_dpad_right.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlRightPressed=CCSpriteFrame::create("Thumb_dpad_right_pressed.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlJump=CCSpriteFrame::create("Thumb_dpad_jump.png",CCRectMake(0,0,135,90));
	CCSpriteFrame *controlJumpPressed=CCSpriteFrame::create("Thumb_dpad_jump_pressed.png",CCRectMake(0,0,135,90));
	sprintf(temp, "%d", heronormalkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(heronormal,temp);
	sprintf(temp, "%d", heroleftJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(heroleftJump,temp);
	sprintf(temp, "%d", herorightJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(herorightJump,temp);
	sprintf(temp, "%d", controlLeftkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlLeft,temp);
	sprintf(temp, "%d", controlLeftPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlLeftPressed,temp);
	sprintf(temp, "%d", controlRightkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlRight,temp);
	sprintf(temp, "%d", controlRightPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlRightPressed,temp);
	sprintf(temp, "%d", controlJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlJump,temp);
	sprintf(temp, "%d", controlJumpPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlJumpPressed,temp);
	CCTexture2D *tileTexture = CCTextureCache::sharedTextureCache()->addImage("Tile_source.png");
	CCSpriteFrame *whyBlock=CCSpriteFrame::createWithTexture(tileTexture, cocos2d::CCRectMake(0, 96, 48, 48));
	sprintf(temp, "%d", whyBlockKey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(whyBlock,temp);
	CCSpriteFrame *firmBlock=CCSpriteFrame::createWithTexture(tileTexture, cocos2d::CCRectMake(240, 0, 48, 48));
	sprintf(temp, "%d", firmBlockKey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(firmBlock,temp);
	CCSpriteFrame *gold=CCSpriteFrame::create("gold.png",CCRectMake(0,0,48,48));
	sprintf(temp, "%d", goldCoinkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(gold,temp);
	CCSpriteFrame *box=CCSpriteFrame::create("Navigator_tv.png",CCRectMake(0,0,527,418));
	sprintf(temp, "%d", failedboxkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(box,temp);

	CCSpriteFrame *cryFrame=CCSpriteFrame::create("Navigator_lose_image_1.png",CCRectMake(0,0,179,176));
	sprintf(temp, "%d", cryFramekey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(cryFrame,temp);

	CCSpriteFrame *onFrame=CCSpriteFrame::create("Switch_on.png",CCRectMake(0,0,130,58));
	sprintf(temp, "%d", onkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(onFrame,temp);
	
	CCSpriteFrame *offFrame=CCSpriteFrame::create("Switch_off.png",CCRectMake(0,0,130,58));
	sprintf(temp, "%d", offkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(offFrame,temp);
	return true;
}
CCSpriteFrame * AnimationManager::getSpritFrame(int key)
{
	char temp[20];
	sprintf(temp, "%d", key);
	return CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(temp);
}
CCAnimation* AnimationManager::createHeroMovingAnimationByDirection(HeroDirection direction)
{
	CCTexture2D *heroTexture = CCTextureCache::sharedTextureCache()->addImage("Hero_image.png");
	CCSpriteFrame *frame0, *frame1, *frame2;
	CCArray* animFrames ;
	//第二个参数表示显示区域的x, y, width, height，根据direction来确定显示的y坐标
	
	
	frame0 = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*0, eSize*direction, eSize, eSize));
	frame1 = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*1, eSize*direction, eSize, eSize));

	
	 animFrames = new CCArray(2);
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	
	

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.09f);

	animFrames->release();
	
	return animation;
}
//获取哭泣动画
CCAnimation* AnimationManager::createCryAnimation()
{
	CCSpriteFrame *frame0, *frame1, *frame2,*frame3;
	CCArray* animFrames =CCArray::createWithCapacity(4);
	frame0=CCSpriteFrame::create("Navigator_lose_image_1.png",CCRectMake(0,0,179,176));
	frame1=CCSpriteFrame::create("Navigator_lose_image_2.png",CCRectMake(0,0,179,176));
	frame2=CCSpriteFrame::create("Navigator_lose_image_3.png",CCRectMake(0,0,179,176));
	frame3=CCSpriteFrame::create("Navigator_lose_image.png",CCRectMake(0,0,179,176));
	
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	animFrames->addObject(frame3);
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
	animFrames->release();
	
	return animation;
}
CCAnimation* AnimationManager::createVictoryAnimation()
{

	CCSpriteFrame *frame0, *frame1;
	CCArray* animFrames =CCArray::createWithCapacity(2);
	frame0=CCSpriteFrame::create("Navigator_win_image_2.png",CCRectMake(0,0,179,176));
	frame1=CCSpriteFrame::create("Navigator_win_image_1.png",CCRectMake(0,0,179,176));


	animFrames->addObject(frame0);
	animFrames->addObject(frame1);

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
	animFrames->release();

	return animation;
}
//获取指定动画模版
CCAnimation* AnimationManager::getAnimation(int key)
{
	char temp[20];
	sprintf(temp, "%d", key);
	return CCAnimationCache::sharedAnimationCache()->animationByName(temp);
}

//获取一个指定动画模版的实例
CCAnimate* AnimationManager::createAnimate(int key)
{
	//获取指定动画模版
	CCAnimation* anim = getAnimation(key);
	if(anim)
	{
		//根据动画模版生成一个动画实例
		return CCAnimate::create(anim);
	}
	return NULL;
}

//获取一个指定动画模版的实例
CCAnimate* AnimationManager::createAnimate(const char* key)
{
	//获取指定动画模版
	CCAnimation* anim = CCAnimationCache::sharedAnimationCache()->animationByName(key);
	if(anim)
	{
		//根据动画模版生成一个动画实例
		return CCAnimate::create(anim);
	}
	return NULL;
}
CCAnimation* AnimationManager::createBiqiSmile()
{

	CCSpriteFrame *frame0, *frame1,*frame2;
	CCArray* animFrames =CCArray::createWithCapacity(3);
	frame0=CCSpriteFrame::create("Startup_herface1.png",CCRectMake(0,0,97,92));
	frame1=CCSpriteFrame::create("Startup_herface2.png",CCRectMake(0,0,97,92));
    frame2=CCSpriteFrame::create("Startup_herface3.png",CCRectMake(0,0,97,92));

	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.6f);
	animFrames->release();

	return animation;
}