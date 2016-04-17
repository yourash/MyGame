#ifndef  _BLOCK_H_
#define  _BLOCK_H_

#include "cocos2d.h"
//#include "HelloWorldScene.h"

class block
{
public:
	block(cocos2d::Layer* layer);
	~block();
	cocos2d::Sprite* returnBlock();
	void removeblock(cocos2d::Sprite* block_1);

private:

	cocos2d::Layer* layer1;
	cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    cocos2d::Sprite *block1;
	
};

#endif // _BLOCK_H_