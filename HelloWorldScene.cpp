#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include "flyblock.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    PhysicsWorld* world = scene->getPhysicsWorld();
    auto gravity = Vec2(0, -5000);
    world->setGravity(gravity);
    //world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    return scene;
}

bool jump=false;
//auto flycoin1= new Coin(this);

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
   
    //cache animation
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/manrun1.plist");

    // image, which is clicked to quit the program

    // add a "close" icon to exit the progress. it's an autorelease object
     auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	 closeItem->setPosition(Vec2(visibleSize.width - closeItem->getContentSize().width/2 ,closeItem->getContentSize().height/2));

     // create menu, it's an autorelease object
     auto menu = Menu::create(closeItem, NULL);
     menu->setPosition(Vec2::ZERO);
     this->addChild(menu, 2);

    //cache anim
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/manrun.plist");

    Vector<SpriteFrame*> frames;
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("1.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("2.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("3.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("4.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("5.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("6.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("7.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("8.png"));
    
    sprite = Sprite::createWithSpriteFrame(frames.front());
    auto animation = Animation::createWithSpriteFrames(frames, 1.0f/10);
    Vec2 pos = sprite->getContentSize();
    sprite->setPosition(Vec2((visibleSize.width/4), (visibleSize.height/4)));
    sprite->setScale(visibleSize.width/pos.x*MAN_WIDTH,visibleSize.height/pos.y*MAN_HEIGHT);
    this->addChild(sprite, 10);

    sprite->runAction(RepeatForever::create(Animate::create(animation)));

    flyBlock(this);
    coin= new flyBlock(this);



    auto manBody = PhysicsBody::createBox( sprite->getContentSize()*0.8,PhysicsMaterial(0.0f, 0.0f, 0.0f) );
    manBody->setGravityEnable(true);
    manBody->setRotationEnable(false);
    manBody->setDynamic(true);

    manBody->setContactTestBitmask( true );
    manBody->setTag(1);
    sprite->setPhysicsBody( manBody );


    jumpsprite=Sprite::create("jump.png");
    jumpsprite->setScale(visibleSize.width/pos.x*MAN_WIDTH,visibleSize.height/pos.y*MAN_HEIGHT);
    jumpsprite->setVisible(false);
    this->addChild(jumpsprite, 10);
    

    auto line = Node::create();
    auto line_body = PhysicsBody::createEdgeSegment(Vec2(0,visibleSize.height/4-sprite->getBoundingBox().size.height/2.2),
                                                        Vec2(visibleSize.width*3,visibleSize.height/4-sprite->getBoundingBox().size.height/2.2),
                                                        PhysicsMaterial(0.0f, 0.0f, 1.0f));

    line->setPhysicsBody(line_body);
    line_body->setContactTestBitmask(true);
    line_body->setTag(2);
    this->addChild(line);
    
    bkroad1 = Sprite::create("inside.png");
    auto insidesize = bkroad1->getContentSize();
    bkroad1->setAnchorPoint( Vec2(0,0) );
    bkroad1->setPosition( Vec2(0,0) );
    bkroad1->setScale(visibleSize.width/insidesize.width*1.01,visibleSize.height/insidesize.height);

    bkroad2 = Sprite::create("inside.png");

    bkroad2->setAnchorPoint( Vec2(0,0) );
    bkroad2->setPosition(Vec2(bkroad1->getBoundingBox().size.width -1, 0));
    bkroad2->setScale(visibleSize.width/insidesize.width*1.01,visibleSize.height/insidesize.height);

    // add the sprite as a child to this layer
    this->addChild(bkroad1, 1);
    this->addChild(bkroad2, 1); 
    
    
    //[start] keybord event
auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){

        Vec2 loc = event->getCurrentTarget()->getPosition();
        // jump = JumpBy::create(0.5, Vec2(0, 0), 100, 1);
        switch(keyCode){
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                //event->getCurrentTarget()->setPosition(--loc.x,loc.y);
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
            case EventKeyboard::KeyCode::KEY_SPACE:
                //event->getCurrentTarget()->setPosition(++loc.x,loc.y);
                //coordinate*=loc.y;
                //if(loc.y == coordinate*)
                //if(loc.y==(visibleSize.height/5)||loc.y==(visibleSize.height/4))
                {
                    //sprite->runAction(JumpBy::create(1, Vect(0,0),visibleSize.height*0.5,1));
                    //score++;
                    sprite->getPhysicsBody()->applyImpulse(Vec2(0, 200000));
                }

                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:

                
    
                //event->getCurrentTarget()->setPosition(loc.x,loc.y*0.07+loc.y);
            if(loc.y==((visibleSize.height/2 + origin.y)*0.35))
            {
                event->getCurrentTarget()->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.4, (visibleSize.height/2 + origin.y)*0.6));
                //sprite->setScale(visibleSize.width/pos.x*0.18,visibleSize.height/pos.y*0.18);
            }
                
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:

            if(loc.y==((visibleSize.height/2 + origin.y)*0.6))
            {

                event->getCurrentTarget()->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.42, (visibleSize.height/2 + origin.y)*0.35));
                //sprite->setScale(visibleSize.width/pos.x*0.25,visibleSize.height/pos.y*0.25);
            }
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,sprite);
    //[end] keybord event
    
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [=](PhysicsContact &contact)->bool
        {
        PhysicsBody *a = contact.getShapeA()->getBody();
        PhysicsBody *b = contact.getShapeB()->getBody();

        // if ((PLAYER_COLLISION_TAG == a->getCollisionBitmask() && OBSTACLE_COLLISION_TAG == b->getCollisionBitmask()) ||
        // (PLAYER_COLLISION_TAG == b->getCollisionBitmask() && OBSTACLE_COLLISION_TAG == a->getCollisionBitmask()))
        if((a->getTag()==1 && b->getTag()==2)||(b->getTag()==1 && a->getTag()==2))
        {

            jump=false;
                

        }
        //else jump=true;
        return true;
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto touchEvent = EventListenerTouchOneByOne::create();

                touchEvent->onTouchBegan = [=](Touch* touch, Event* event)->bool
                {
                    if(!jump)
                            {
                                jump=true;
                                sprite->getPhysicsBody()->applyImpulse(Vec2(0, 2000));
                            }
                };
                this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);

    
    score = 0;
    //auto coin=new Coin(this);
    __String *tempScore = __String::createWithFormat( "%i", score );
    
    scoreLabel = Label::createWithTTF( tempScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    scoreLabel->setColor( Color3B::WHITE );
    scoreLabel->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y ) );
    
    this->addChild( scoreLabel, 10000 );

    layer1=this;
    trapCreate();
    // this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::scrollBk), 0.01f);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::scrollBk1), 0.01f);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::trapCreate), 1.0f);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::scroll), 0.01f);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::spriteBoost), 0.01f);
    
    //this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::coinCreate), 1.0f);

    this->scheduleUpdate();

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update(float delta){


    Node::update(delta);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    jumpsprite->setPosition(sprite->getPosition());

    if(jump==true)
    {
        sprite->setVisible(false);
        jumpsprite->setVisible(true);
    }
    else
    { 
        sprite->setVisible(true);
        jumpsprite->setVisible(false);
    }

    //VibleSize.width/cocos2d::RandomHelper::random_int(2, 3)+visibleSize.width,(visibleSize.height/2)*0.35));
        score++;
        
        __String *tempScore = __String::createWithFormat( "%i", score );
        
        scoreLabel->setString( tempScore->getCString( ) );

    Layer::update(delta);
}

void HelloWorld::scrollBk1()
{
    bkroad1->setPosition( Vec2(bkroad1->getPosition().x-ROADSPEED, bkroad1->getPosition().y) );
    bkroad2->setPosition( Vec2(bkroad2->getPosition().x-ROADSPEED, bkroad2->getPosition().y) );
    
    if( bkroad1->getPosition().x < -bkroad1->getBoundingBox().size.width-1)
    {
        bkroad1->setPosition( Vec2( bkroad2->getPosition().x + bkroad2->getBoundingBox().size.width, bkroad1->getPosition().y));
    }
    if( bkroad2->getPosition().x < -bkroad2->getBoundingBox().size.width-1)
    {
        bkroad2->setPosition( Vec2( bkroad1->getPosition().x + bkroad1->getBoundingBox().size.width, bkroad2->getPosition().y));
    }

        for(int i=0;i<traps.size();i++)
        {
            traps[i].returnBlock()->setPosition(traps[i].returnBlock()->getPosition().x-ROADSPEED, traps[i].returnBlock()->getPosition().y);
            
            if( traps[i].returnBlock()->getPosition().x < -visibleSize.width/2 )
            {
                traps[i].removeblock(traps[i].returnBlock());
                traps.erase(traps.begin()+i);
            }
            
            if(sprite->getPosition().x<-50)
            {
                auto scene = GameOverScene::createScene();
                Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
            }
        }
}

void HelloWorld::trapCreate()
{
    block trap1(layer1);
    traps.insert(traps.end(), trap1);
}

void HelloWorld::GoToGameOverScene( cocos2d::Ref *sender )
{
    auto scene = GameOverScene::createScene();
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}

void HelloWorld::scroll()
{
    coin->returnflyblock()->setPosition(Vec2(coin->returnflyblock()->getPosition().x-ROADSPEED,coin->returnflyblock()->getPosition().y));
}

bool boost=false;

void HelloWorld::spriteBoost()
{
    Rect rectsprite = sprite->getBoundingBox();
    Rect rectcoin = coin->returnflyblock()->getBoundingBox();
    if (rectcoin.intersectsRect(rectsprite))
        boost=true;
    if(boost)
        sprite->setPosition(Vec2(sprite->getPosition().x+ROADSPEED,sprite->getPosition().y));
    if(sprite->getPosition().x>visibleSize.width/2-1)
        boost=false;
}