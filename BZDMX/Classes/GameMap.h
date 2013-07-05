#pragma once
#include "BZDMX.h"
class GameMap : public cocos2d::CCTMXTiledMap
{
public:
	GameMap(void);
	~GameMap(void);
	CC_PROPERTY_READONLY(CCTMXLayer*, platformLayer, PlatformLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, hideBlockLayer, HideBlockLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, platformDynamicLayer,PlatformDynamicLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, biqiLayer,BiqiLayer);
	//静态方法，用于生成GameMap实例
	static GameMap* gameMapWithTMXFile(const char *tmxFile);
	//TiledMap和cocos2d-x坐标系相互转换的方法
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
	void hideBlockAnimate(CCPoint target);
	void blockMoveFinished(CCNode *sender);
	void removeGold(CCNode *sender);
protected:
	//TiledMap额外的初始化方法
	void extraInit();
	//开启各图层的纹理抗锯齿
	void enableAnitiAliasForEachLayer();
};

