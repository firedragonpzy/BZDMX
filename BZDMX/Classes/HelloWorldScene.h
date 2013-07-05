#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"

#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
   
void	animateFinished(CCNode *sender);
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
     virtual bool init();  
	 CREATE_FUNC(HelloWorld);
   void  skipCallback(CCObject* pSender);

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
 
};

#endif  // __HELLOWORLD_SCENE_H__