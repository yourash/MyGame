#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "block.h"
#include "flyblock.h"
#include "definitions.h"

class flyBlock;
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

	//flyBlock(this);
    flyBlock *coin;
    
	std::vector<block> traps;
	cocos2d::Sprite* sprite;

	cocos2d::Sprite* block1;
	cocos2d::Layer* layer1;
	cocos2d::Layer* layer21;
	cocos2d::Sprite* animation;

	bool jump;

	cocos2d::Sprite* bk1;
	cocos2d::Sprite* bk2;
	cocos2d::Sprite* bkroad1;
	cocos2d::Sprite* bkroad2;

	void scroll();
	void scrollBk();
	void scrollBk1();
	void trapCreate();

	cocos2d::Label* scoreLabel;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	int score;
	
	void SetPhysicsWorld( cocos2d::PhysicsWorld *world ) { sceneWorld = world; };
	cocos2d::PhysicsWorld *sceneWorld;
	void GoToGameOverScene( cocos2d::Ref *sender );

};

#endif // __HELLOWORLD_SCENE_H__
