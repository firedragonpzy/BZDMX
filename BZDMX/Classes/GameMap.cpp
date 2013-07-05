#include "GameMap.h"
CCSprite *hideBlock;
CCSprite* goldSprite;
GameMap::GameMap(void)
{
	sGlobal->gameMap=this;
}


GameMap::~GameMap(void)
{
	this->unscheduleAllSelectors();
}
//静态方法，用于生成GameMap实例
GameMap* GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	//new一个对象
	GameMap *pRet = new GameMap();
	//调用init方法
	if (pRet->initWithTMXFile(tmxFile))
	{
		//调用额外的init方法
		pRet->extraInit();
		//将实例放入autorelease池，统一由引擎控制对象的生命周期
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
//TliedMap额外的初始化方法
void GameMap::extraInit()
{
	//开启各个图层的纹理抗锯齿
	enableAnitiAliasForEachLayer();
	//初始化各层对象
	 platformLayer = this->layerNamed("Platform");
	platformDynamicLayer = this->layerNamed("PlatformDynamic");
	hideBlockLayer = this->layerNamed("HideBlock");
	biqiLayer = this->layerNamed("biqi");
	hideBlockLayer->setVisible(false);
	//platformDynamicLayer->setVisible(false);
	//itemLayer = this->layerNamed("item");
	//doorLayer = this->layerNamed("door");

	
}
void GameMap::enableAnitiAliasForEachLayer()
{
	CCArray * pChildrenArray = this->getChildren();
	CCSpriteBatchNode* child = NULL;
	CCObject* pObject = NULL;
	//遍历Tilemap的所有图层
	CCARRAY_FOREACH(pChildrenArray, pObject)
	{
		child = (CCSpriteBatchNode*)pObject;
		if(!child)
			break;
		//给图层的纹理开启抗锯齿
		child->getTexture()->setAntiAliasTexParameters();
	}
}

//从cocos2d-x坐标转换为Tilemap坐标
CCPoint GameMap::tileCoordForPosition(CCPoint position)
{
	int x = position.x / this->getTileSize().width;
	int y = (((this->getMapSize().height) * this->getTileSize().height) - position.y) / this->getTileSize().height;
	return ccp(x, y);
}

//从Tilemap坐标转换为cocos2d-x坐标
CCPoint GameMap::positionForTileCoord(CCPoint tileCoord)
{
	CCPoint pos =  ccp((tileCoord.x * this->getTileSize().width),
		((this->getMapSize().height - tileCoord.y) * this->getTileSize().height));
	return pos;
}
//返回地板层
CCTMXLayer* GameMap::getPlatformLayer()
{
	return platformLayer;
}
CCTMXLayer* GameMap::getPlatformDynamicLayer()
{
	return platformDynamicLayer;
}
CCTMXLayer* GameMap::getHideBlockLayer()
{
	return hideBlockLayer;
}
CCTMXLayer* GameMap::getBiqiLayer()
{
	return biqiLayer;
}
void GameMap::hideBlockAnimate(CCPoint target)
{
	
	target=positionForTileCoord(target);
	target=ccp(target.x,target.y-24);
	hideBlock=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(whyBlockKey));
	hideBlock->setAnchorPoint(ccp(0,0));
	hideBlock->setPosition(target);
	sGlobal->game_1_1->addChild(hideBlock );

	
	CCPointArray* array=CCPointArray::create(2);
	array->addControlPoint(ccp(target.x,target.y+10));
	array->addControlPoint(target);
	CCCardinalSplineTo *cardinal=CCCardinalSplineTo::create(0.4f,array,0);
	//CCFiniteTimeAction* action=cardinal->release();
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(GameMap::blockMoveFinished));
	
	hideBlock->runAction(CCSequence::create(cardinal,actionMoveDone,NULL));
	goldSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(goldCoinkey));
   goldSprite->setAnchorPoint(ccp(0,0));
   goldSprite->setPosition(ccp(target.x+10,target.y+48));
	CCFiniteTimeAction *actionMove=CCMoveBy::create(0.9f,ccp(0,60));

	CCFiniteTimeAction* goldMoveDone=CCCallFuncN::create(this,callfuncN_selector(GameMap::removeGold));
	sGlobal->game_1_1->addChild(goldSprite );
	goldSprite->runAction(CCSequence::create(actionMove,goldMoveDone,NULL));

}
void GameMap::blockMoveFinished(CCNode *sender)
{

	hideBlock->setDisplayFrame(sAnimationMgr->getSpritFrame(firmBlockKey));
}

void GameMap::removeGold(CCNode *sender)
{
	CCFadeOut* fadeout=CCFadeOut::create(0.8f);
	goldSprite->runAction(fadeout);
}