#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    

    //auto jump;
    void update(float) override;
    //auto background;
private:
	//auto cocos2d::JumpBy* jump;
	// cocos2d::Vector getAnimation(const char *format, int count);
	//cocos2d::Sprite* bird; 
	//cocos2d::Vector getAnimation(const char *format,int count);
	cocos2d::Sprite* sprite;
	cocos2d::Sprite* manrun;

	cocos2d::Sprite* background;
	cocos2d::Sprite* background2;
	cocos2d::Sprite* background3;
	cocos2d::Sprite* background4;
	cocos2d::Sprite* block1;

	cocos2d::Sprite* bk1;
	cocos2d::Sprite* bk2;
	void scrollBk();

	cocos2d::Label* scoreLabel;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	//float *coordinate;
	int score;
	//static int runspeed=1;

};

#endif // __HELLOWORLD_SCENE_H__
