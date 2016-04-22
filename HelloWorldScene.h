#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "block.h"
#include "definitions.h"


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
	std::vector<block> traps;
	cocos2d::Sprite* sprite;
	cocos2d::Sprite* manrun;

	cocos2d::Sprite* background;
	cocos2d::Sprite* background2;
	cocos2d::Sprite* background3;
	cocos2d::Sprite* background4;
	cocos2d::Sprite* block1;
	cocos2d::Layer* layer1;

	

	cocos2d::Sprite* bk1;
	cocos2d::Sprite* bk2;
	cocos2d::Sprite* bkroad1;
	cocos2d::Sprite* bkroad2;
	void scrollBk();
	void scrollBk1();
	void trapCreate();

	cocos2d::Label* scoreLabel;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	//float *coordinate;
	int score;
	
	void SetPhysicsWorld( cocos2d::PhysicsWorld *world ) { sceneWorld = world; };
	cocos2d::PhysicsWorld *sceneWorld;
	//static int runspeed=1;
	void GoToGameOverScene( cocos2d::Ref *sender );

};

#endif // __HELLOWORLD_SCENE_H__
