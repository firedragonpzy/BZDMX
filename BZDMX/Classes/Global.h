#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include "BZDMX.h"
#include "Singleton.h"

class Game_1_1;
class Hero;
class GameMap;
class ControlLayer;
class FailedLayer;
class Global : public Singleton<Global>
{
public:
	Global(void);
	~Global(void);
	Game_1_1 *game_1_1;
	GameMap *gameMap;
	Hero *hero;
	ControlLayer *controlLayer;
	FailedLayer *faledLayer;
	bool isMusicOn;
	bool isEffectOn;
	int gameStage;
	int IQ;
	
};
#define sGlobal Global::instance()

#endif
