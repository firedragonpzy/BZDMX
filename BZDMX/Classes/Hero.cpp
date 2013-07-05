#include "Hero.h"
CCSprite* shi;
CCSprite* daodan;
int shicount;
int daodancount;
int xianjingcount;
Hero::Hero(void)
{
	sGlobal->hero=this;
}


Hero::~Hero(void)
{
}

//静态方法，用于生成Hero实例
Hero* Hero::heroWithinLayer()
{
	//new一个对象
	Hero *pRet = new Hero();
	//调用init方法
	if (pRet && pRet->heroInit())
	{
		//将实例放入autorelease池，统一由引擎控制对象的生命周期
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool Hero::heroInit()
{
	xianjingcount=0;
	daodancount=0;
	shicount=0;
	isWin=false;
	isanimate=false;
	hspeed=0;
	isDead=false;
	heroSprite = CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(heronormalkey));
	//设置锚点
	heroSprite->setAnchorPoint(ccp(0,0));
	//heroSprite->setAnchorPoint(ccp(46*3,46*2+2));
	//将用于显示的heroSprite加到自己的节点下
	this->addChild(heroSprite);
	this->setAnchorPoint(ccp(0,0));
	//一开始不处于move状态。
	isHeroMoving = false;
	isJumpDone=false;
	vspeed=0;
	return true;
}
void Hero::move(int i)
{
	   if (isDead)
	   {return;
	   }
	   float targetX=this->getPositionX()+i+46;
	   for (float j=this->getPositionY();j<=(46+this->getPositionY());j++)
	   {
		   if (checkCollisionOnly(ccp(targetX,j))==kWall)
		   {
			   i=0;
		   }
	   }
	   float targetX2=this->getPositionX()+i;
	   for (float j=this->getPositionY();j<=(46+this->getPositionY());j++)
	   {
		   if (checkCollisionOnly(ccp(targetX2,j))==kWall)
		   {
			   i=0;
		   }
	   }
		this->setPosition(this->getPositionX()+1*i,this->getPositionY());
		setViewpointCenter(this->getPosition());
		hspeed=i;
		if (!isanimate&&i!=0&&isJumpDone)
		{
			AnimationKey key;
			
			if (i<0)
			{
				key=aLeft;
			}else 
			{
				key=aRight;
			}
				
			CCAnimation *animation=sAnimationMgr->getAnimation(key);
			CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(Hero::animateDone));
			heroSprite->runAction(CCSequence::create(CCAnimate::create(animation),actionMoveDone,NULL));
			isanimate=true;
		}
	
}
void Hero::jump()
{
	if (isWin)
	{
		return;
	}
	if (isDead&&this->getPositionY()<5)
	{
		this->setPosition(this->getPositionX(),this->getPositionY()-6);
	
	}
	if (isDead)
		{
			heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
			return;
		}
	
	if (this->getPositionX()+50>=15*48&&daodancount==0&&isDead==false)
	{
		daodan=CCSprite::create("Missileop.png",CCRectMake(0,0,48,72));
		daodancount++;
		daodan->setAnchorPoint(ccp(0,0));
		daodan->setPosition(ccp(15*48,5*48));
		sGlobal->game_1_1->addChild(daodan);
	}

	if (daodancount==1)
	{
		daodan->setPosition(ccp(15*48,daodan->getPositionY()+2));
		if (daodan->getPositionY()>480)
		{
			daodan->setPosition(ccp(15*48,5*48));
		}
		CCRect herRect=CCRectMake(this->getPositionX(),this->getPositionY(),50,50);
		if (herRect.intersectsRect(CCRectMake(daodan->getPositionX(),daodan->getPositionY(),47,72)))
		{
			this->isDead=true;
			
		}
	}
	if (this->getPositionX()+50>=22*48&&shicount==0&&isDead==false)
	{
		shi=CCSprite::create("shi.png",CCRectMake(0,0,47,57));
		shicount++;
		shi->setAnchorPoint(ccp(0,0));
		shi->setPosition(ccp(22*48,480));
		sGlobal->game_1_1->addChild(shi);
	}
	if (shicount==1)
	{
		shi->setPosition(ccp(22*48,shi->getPositionY()-6));
		if (shi->getPositionY()<-50)
		{
			shi->setPosition(ccp(22*48,480));
		}
		CCRect herRect=CCRectMake(this->getPositionX(),this->getPositionY(),50,50);
		if (herRect.intersectsRect(CCRectMake(shi->getPositionX(),shi->getPositionY(),47,57)))
		{
			this->isDead=true;
			shicount=0;
		}
	}

	
	if (vspeed!=-0.4f)
	{
		CCSpriteFrameKey framekey;
		if (hspeed<0)
		{
			framekey=heroleftJumpkey;
		}
		else{
			framekey=herorightJumpkey;
		}
		heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(framekey));
	}else if(hspeed==0)
	{
		if (this->isDead)
		{heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
		}else{
		
		heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(heronormalkey));
		}
	}
	float x=this->getPositionX();
	float y=this->getPositionY();
	float targetY=this->getPositionY()+vspeed;
	for (int i=this->getPositionX();i<=(this->getPositionX()+46);i++)
	{
		if (checkCollisionOnly(ccp(i,targetY))==kWall)
		{
			
			vspeed=-0.4;
			isJumpDone=true;
			return;
		}
	}
	float targetY2=this->getPositionY()+vspeed+46;
	for (int i=this->getPositionX();i<=(this->getPositionX()+46);i++)
	{

		if (checkCollisionOnly(ccp(i,targetY2))==kWall)
		{
			vspeed=-0.4;
			
			return;
		}
		if (vspeed>0)
		{
			if(checHeadkCollision(ccp(i,targetY2))==khideblock)
			{
				vspeed=-0.4;
				if (sGlobal->isEffectOn)
				{
				
             CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_gold.mp3",false);
			 }
				return;
			}
		}
	}
	
	
	
	this->setPosition(this->getPositionX(),this->getPositionY()+vspeed);
	vspeed=vspeed-0.4f;

	
}
CollisionType Hero::checkCollisionOnly(CCPoint heroPosition)
{
	//cocos2d-x坐标转换为Tilemap坐标
	if (heroPosition.y<=4)
	{
		this->isDead=true;
		//heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
		
	}
	CCPoint targetTileCoord = sGlobal->gameMap->tileCoordForPosition(heroPosition);

	//如果勇士坐标超过地图边界，返回kWall类型，阻止其移动
	if (heroPosition.x < 0 || targetTileCoord.x > sGlobal->gameMap->getMapSize().width - 1 ||  targetTileCoord.y > sGlobal->gameMap->getMapSize().height - 1)
		return kWall;
	//获取墙壁层对应坐标的图块ID
	int tagetid=sGlobal->gameMap->getPlatformDynamicLayer()->tileGIDAt(targetTileCoord);
	if (tagetid)
	{
		
		if (this->getPositionX()<240)
		{
			setLayerEmpty(ccp(0,16),14,4);
		}
		if (this->getPositionX()>576&&this->getPositionX()<15*48)
		{
			setLayerEmpty(ccp(24,16),6,4);
		}
		if (this->getPositionX()>1152&&this->getPositionX()<1248)
		{
			setLayerEmpty(ccp(48,16),4,4);
		}
		if (this->getPositionX()>28*48&&this->getPositionX()<31*48)
		{
			setLayerEmpty(ccp(56,16),6,4);
		}
		
		return kWall;
	}
	int targetTileGID = sGlobal->gameMap->getPlatformLayer()->tileGIDAt(targetTileCoord);
	//如果图块ID不为0，表示有墙
	if (targetTileGID) 
	{
		return kWall;
	}
	if (sGlobal->gameStage==1)
	{
	
	int winID=sGlobal->gameMap->getBiqiLayer()->tileGIDAt(targetTileCoord);
	if (winID&&xianjingcount==0) 
	{
		xianjingcount++;
		//this->isWin=true;
		sGlobal->gameMap->getBiqiLayer()->setVisible(false);
		CCSprite* xianjing=CCSprite::create("Stage1_2_hello_zh.png");
		
		xianjing->setPosition(ccp(-sGlobal->game_1_1->getPositionX()+500,240));
		sGlobal->game_1_1->addChild(xianjing,1);
		sGlobal->game_1_1->haveTouchBiqi=true;
		return kbiqi;
	}
	}
	//可以通行
	return kNone;
}
CollisionType Hero::checHeadkCollision(CCPoint heroPosition)
{
	CCPoint targetTileCoord = sGlobal->gameMap->tileCoordForPosition(heroPosition);
	int hideblockId=sGlobal->gameMap->getHideBlockLayer()->tileGIDAt(targetTileCoord);
	//sGlobal->gameMap->getHideBlockLayer()->
	if (hideblockId)
	{
	 
	  CCPoint  startposition;
	  if (sGlobal->gameMap->getHideBlockLayer()->tileGIDAt(ccp(targetTileCoord.x-1,targetTileCoord.y)))
	  {
		  startposition=ccp(targetTileCoord.x-1,targetTileCoord.y);
	  }else
	  {
	         startposition=targetTileCoord;
	  }
	//   startposition=targetTileCoord;
	 int id=  sGlobal->gameMap->getPlatformLayer()->tileGIDAt(ccp(0,0));
	  sGlobal->gameMap->getPlatformLayer()->setTileGID(id,startposition);
	  sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x+1,startposition.y));
	   sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x+1,startposition.y-1));
	   sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x,startposition.y-1));
	   sGlobal->gameMap->hideBlockAnimate(startposition);
	   return khideblock;
	}
	return kNone;
}
void Hero::setViewpointCenter(CCPoint p)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	float x=MAX(p.x,size.width/2);
	float y=MAX(p.y,size.height/2);
	
	x=MIN(x,(sGlobal->gameMap->getMapSize().width*sGlobal->gameMap->getTileSize().width)-size.width/2);
	y=MIN(y,(sGlobal->gameMap->getMapSize().height*sGlobal->gameMap->getTileSize().height)-size.height/2);
	CCPoint actualPosition=ccp(x,y);
	CCPoint centerOfView=ccp(size.width/2,size.height/2);
	CCPoint viewPoint=ccpSub(centerOfView,actualPosition);
	int x1=viewPoint.x;
	int y1=viewPoint.y;
	int herox=p.x;
	int heroy=p.y;
	int thisx=this->getPositionX();
	int htisy=this->getPositionY();
	int mapSize=sGlobal->gameMap->getMapSize().width;
	int TileSize=sGlobal->gameMap->getTileSize().width;
	
	sGlobal->game_1_1->setPosition(viewPoint);
	int x2=0-viewPoint.x;
	int y2=0-viewPoint.y;
	//sGlobal->controlLayer->setPosition(ccp((float)x2,(float)y2));
	//controlSprite->setPosition(ccp((float)x2,(float)y2));
}
void Hero::animateDone(CCNode *sender)
{
	isanimate=false;
	heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(heronormalkey));
}
void Hero::setLayerEmpty(CCPoint start,int width,int height)
{
	for (int i=start.y;i<height+start.y;i++)
	{
		for (int j=start.x;j<width+start.x;j++)
		{
			sGlobal->gameMap->getPlatformDynamicLayer()->removeTileAt(ccp(j,i));
		}
	}
	
}