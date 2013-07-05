#ifndef __GAME_CONSTANTS_H__
#define __GAME_CONSTANTS_H__

typedef enum {
	hdie =  0,//死亡
	hnormal=1,//正常
	hleftJump=2,//向左跳
	hrightJump=5,
	hright=4,//向右方向
	hleft=3,//
	hjump=6,//向上方向

} HeroDirection;//勇士方向

typedef enum
{
	kNone = 1,//可以通行
	kWall,//墙
	kItem,//物品
	kDoor,//门
	khideblock,
	kbiqi
	
} CollisionType;//碰撞类型

typedef enum
{
	anormal=0,
	aLeftjump,
	arightjump,
	aDie ,//
	aLeft,//向左行走动画
	aRight,//向右行走动画
	aother,
	heroCry,
	victory,
	biqiSmile,
} AnimationKey;//动画模版键值
typedef enum
{
	heronormalkey=0,
	heroleftJumpkey,
	herorightJumpkey,
	controlLeftkey ,//
	controlLeftPressedkey,
	controlRightkey,
	controlRightPressedkey,
	controlJumpkey,
	controlJumpPressedkey,
	whyBlockKey,
	firmBlockKey,
	goldCoinkey,
	failedboxkey,
	cryFramekey,
	onkey,
	offkey,
}CCSpriteFrameKey;//CCSpriteFrame模版键值
enum 
{
	kZMap = 0,//地图的zOrder
	kZNPC,
	kZTeleport,
	kZHero,//勇士精灵的zOrder
	kZTip,//提示信息的zOrder
};//GameLayer中各部分的显示zOrder及tag

enum 
{
	kGameLayer = 0,
	kControlLayer,
	kFadeLayer,
};

enum{
	eSize = 50,
};
#endif