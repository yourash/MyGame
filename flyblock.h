#ifndef  _FLYBLOCK_H_
#define  _FLYBLOCK_H_

#include "cocos2d.h"
#include "definitions.h"
#include "HelloWorldScene.h"

class flyBlock
{
public:
	flyBlock(cocos2d::Layer *layer);
	//~flyblock();
	cocos2d::Sprite* returnflyblock();
	void removeflyblock(cocos2d::Sprite* flyblock);
	
	cocos2d::Sprite *flyblock;
	cocos2d::Layer *layer1;
	
private:

	cocos2d::Size visibleSize; 
	
};

#endif // _FLYBLOCK_H_