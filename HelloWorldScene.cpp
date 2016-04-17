#include "HelloWorldScene.h"

#include "definitions.h"

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();// 'scene' is an autorelease object
    
    auto layer = HelloWorld::create();// 'layer' is an autorelease object

    scene->addChild(layer);// add layer as a child to scene

    return scene;// return the scene
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //traps.reserve(10);

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    //cache animation
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/manrun.plist");

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
     auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	 closeItem->setPosition(Vec2(visibleSize.width - closeItem->getContentSize().width/2 ,
                                 closeItem->getContentSize().height/2));

     // create menu, it's an autorelease object
     auto menu = Menu::create(closeItem, NULL);
     menu->setPosition(Vec2::ZERO);
     this->addChild(menu, 2);

 //    /////////////////////////////
 //    // 3. add your codes below...

 //    // add a label shows "Hello World"
 //    // create and initialize a label
    
    // auto label = Label::createWithTTF(score, "fonts/Marker Felt.ttf", 24);
    
    // // position the label on the center of the screen
    // label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                         origin.y + visibleSize.height - label->getContentSize().height));

    // // add the label as a child to this layer
    // this->addChild(label, 1);
   

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/manrun.plist");

    Vector<SpriteFrame*> frames;
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man001.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man002.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man003.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man004.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man005.png"));
    frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("man006.png"));

    sprite = Sprite::createWithSpriteFrame(frames.front());
    auto animation = Animation::createWithSpriteFrames(frames, 1.0f/10);
    Vec2 pos = sprite->getContentSize();
    sprite->setPosition(Vec2((visibleSize.width/5), (visibleSize.height/4)));
    sprite->setScale(visibleSize.width/pos.x*0.07,visibleSize.height/pos.y*0.18);
    this->addChild(sprite, 4);

    sprite->runAction(RepeatForever::create(Animate::create(animation)));

    bk1 = Sprite::create("fon.png");
    bk1->setAnchorPoint( Vec2(0,0) );
    bk1->setPosition( Vec2(0,0) );
    bk1->setScale(visibleSize.width/getContentSize().width*1.01,visibleSize.height/getContentSize().height);


    bk2 = Sprite::create("fon.png");
    bk2->setAnchorPoint( Vec2(0,0) );
    bk2->setPosition(Vec2(bk1->getBoundingBox().size.width -5, 0));
    bk2->setScale(visibleSize.width/getContentSize().width*1.01,visibleSize.height/getContentSize().height);

    this->addChild(bk1, 0);
    this->addChild(bk2, 0); 

    bkroad1 = Sprite::create("road1.png");
    bkroad1->setAnchorPoint( Vec2(0,0) );
    bkroad1->setPosition( Vec2(0,0) );
    bkroad1->setScale(visibleSize.width/getContentSize().width*1.01,visibleSize.height/getContentSize().height/5);


    bkroad2 = Sprite::create("road1.png");
    bkroad2->setAnchorPoint( Vec2(0,0) );
    bkroad2->setPosition(Vec2(bkroad1->getBoundingBox().size.width -1, 0));
    bkroad2->setScale(visibleSize.width/getContentSize().width*1.01,visibleSize.height/getContentSize().height/5);

    // add the sprite as a child to this layer
    this->addChild(bkroad1, 1);
    this->addChild(bkroad2, 1); 

    // add "HelloWorld" splash screen"
    //Vector frames = getAnimation("res/manrun.png", 4);

    // sprite = Sprite::create("man.png");

    // // position the sprite on the center of the screen
    // sprite->setPosition(Vec2((visibleSize.width/2)*0.42+origin.x, (visibleSize.height/2 + origin.y)*0.35));
     
    // sprite->setScale(visibleSize.width/pos.x*0.25,visibleSize.height/pos.y*0.25);
    // //CCLOG(visibleSize.width);
    // // add the sprite as a child to this layer
    // this->addChild(sprite, 2);

    // bird = Sprite::create("bird.png");
    // bird->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.4, (visibleSize.height/2 + origin.y)*1.4));
    // Vec2 birdpos = bird->getContentSize();
    // bird->setScale(visibleSize.width/pos.x*0.25,visibleSize.height/pos.y*0.25);
    // this->addChild(bird, 2);

    // background = Sprite::create("road");

    // Vec2 pos2 = background->getContentSize();
    // background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/10));
    // background->setScale(visibleSize.width/pos2.x,visibleSize.height/pos2.y/5);
    // this->addChild(background, 1);


    // background2 = Sprite::create("road");

    // Vec2 pos21 = background->getContentSize();
    // background2 ->setPosition(Vec2(visibleSize.width/2 +visibleSize.width,visibleSize.height/10));
    // background2->setScale(visibleSize.width/pos21.x,visibleSize.height/pos21.y/5);
    // this->addChild(background2, 1);

    // background3 = Sprite::create("fon.png");

    // Vec2 pos3 = background3->getContentSize();
    // background3->setPosition(Vec2(visibleSize.width,visibleSize.height/2));
    // background3->setScale(visibleSize.width/pos3.x*2.01,visibleSize.height/pos3.y);
    // this->addChild(background3, 0);

    // background4 = Sprite::create("fon.png");

    // Vec2 pos4 = background4->getContentSize();
    // background4->setPosition(Vec2(visibleSize.width*3,visibleSize.height/2));
    // background4->setScale(visibleSize.width/pos4.x*2.01,visibleSize.height/pos4.y);
    // this->addChild(background4, 0);
  
    

    // block1 = Sprite::create("block.png");

    // Vec2 sizeblock = block1->getContentSize();
    // //block1->setPosition(Vec2(visibleSize.width/cocos2d::RandomHelper::random_int(2, 3),visibleSize.height/2));
    // block1->setScale(visibleSize.width/sizeblock.x*0.25,visibleSize.height/sizeblock.y*0.25);
    // this->addChild(block1, 2);
    
        
    
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
                if(loc.y==(visibleSize.height/5)||loc.y==(visibleSize.height/4))
                {
                    sprite->runAction(JumpBy::create(1, Vect(0,0),visibleSize.height*0.5,1));
                    //score++;
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

     auto touchEvent = EventListenerTouchOneByOne::create(); 

    touchEvent->onTouchBegan = [=](Touch* touch, Event* event)->bool
    {
        Vec2 loc = sprite->getPosition();
        if(loc.y==(visibleSize.height/5)||loc.y==(visibleSize.height/4))
                {
                    sprite->runAction(JumpBy::create(1, Vect(0,0),visibleSize.height*0.5,1));
                    //score++;
                }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);

    // Vector<SpriteFrame*> animFrames(2);
    // char str[100] = {0};
    // for(int i = 1; i < 2; i++)
    // {
    //     sprintf(str, ".png",i);
    //     auto frame = SpriteFrame::create(str,Rect(0,0,40,40)); //we assume that the sprites' dimentions are 40*40 rectangles.
    //     animFrames.pushBack(frame);
    // }

    // auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
    // auto animate = Animate::create(animation);
    // sprite->runAction(animate);


    score = 0;
    
    __String *tempScore = __String::createWithFormat( "%i", score );
    
    scoreLabel = Label::createWithTTF( tempScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    scoreLabel->setColor( Color3B::WHITE );
    scoreLabel->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y ) );
    
    this->addChild( scoreLabel, 10000 );

    layer1=this;
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::scrollBk), 0.01f);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::scrollBk1), 0.01f);
    //some = new block(this);
    this->schedule(cocos2d::SEL_SCHEDULE(&HelloWorld::trapCreate), 1.0f);
    this->scheduleUpdate();

    return true;
}

// void HelloWorldScene::update(float delta) {
//     // Register an update function that checks to see if the CTRL key is pressed
//     // and if it is displays how long, otherwise tell the user to press it
//     Node::update(delta);
// }
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

    // Vec2 pos3 = background3->getPosition();
    // Vec2 pos4 = background4->getPosition(); 
     //Vec2 posB = block1->getPosition(); 
    // Vec2 posM = sprite->getPosition();

    // background4->setPosition(pos4.x-0.5, pos4.y);
    // background3->setPosition(pos3.x-0.5, pos3.y);
    
    //block1->setPosition(posB.x-4,posB.y);

    // if(pos3.x==(-1)*visibleSize.width /*|| pos3.x==(-0.5)*visibleSize.width+0.5*/)
    // {
    //     background3->setPosition(Vec2(visibleSize.width*3-4,visibleSize.height/2));
    // }
    // else if(pos4.x==(-1)*visibleSize.width /*|| pos4.x==(-0.5)*visibleSize.width+0.5*/)
    // {
    //     background4->setPosition(Vec2(visibleSize.width*3-4,visibleSize.height/2));
    // }

    // Vec2 pos = background->getPosition();
    // Vec2 pos2 = background2->getPosition(); 


    // background2->setPosition(pos2.x-4, pos2.y);
    // background->setPosition(pos.x-4, pos.y);
    

    // if(pos.x==(-0.5)*visibleSize.width)
    // {
    //     background->setPosition(Vec2(visibleSize.width/2+visibleSize.width-2,visibleSize.height/10));
    // }
    // else if(pos2.x==(-0.5)*visibleSize.width)
    // {
    //     background2->setPosition(Vec2(visibleSize.width/2+visibleSize.width-2,visibleSize.height/10));
    // }

    // if(score%800==0)
    // block1->setPosition(Vec2(visibleSize.width/cocos2d::RandomHelper::random_int(2, 3)+visibleSize.width,(visibleSize.height/2)*0.35));

        score++;
        
        __String *tempScore = __String::createWithFormat( "%i", score );
        
        scoreLabel->setString( tempScore->getCString( ) );

    // if((posB.x<=posM.x+visibleSize.width/5) && (posB.y==posM.y+visibleSize.height/5))
    // {
    //     score=score-10000;
        
    //     __String *tempScore = __String::createWithFormat( "%i", score );
        
    //     scoreLabel->setString( tempScore->getCString() );
    // }

       // some->returnBlock()->setPosition(0,0);

    Layer::update(delta);
}

// Vector HelloWorld::getAnimation(const char *format,int count)
// {
//     auto spritecache=SpriteFrameCache::getInstance();
//     Vector animFrames;
//     char str[100];
//     for(int i=1;i<=count;i++)
//     {
//         sprintf(str, format, i);
//         animFrames.pushBack(spritecache->getSpriteFrameByName(str));
//     }
//     return animFrames;
// }

void HelloWorld::scrollBk()
{
    bk1->setPosition( Vec2(bk1->getPosition().x-BACKGROUNDSPEED, bk1->getPosition().y) );
    bk2->setPosition( Vec2(bk2->getPosition().x-BACKGROUNDSPEED, bk2->getPosition().y) );

    if( bk1->getPosition().x < -bk1->getBoundingBox().size.width){
        bk1->setPosition( Vec2( bk2->getPosition().x + bk2->getBoundingBox().size.width-5, bk1->getPosition().y));
    }
    if( bk2->getPosition().x < -bk2->getBoundingBox().size.width){
        bk2->setPosition( Vec2( bk1->getPosition().x + bk1->getBoundingBox().size.width-5, bk2->getPosition().y));
   }
}

void HelloWorld::scrollBk1()
{
    bkroad1->setPosition( Vec2(bkroad1->getPosition().x-ROADSPEED, bkroad1->getPosition().y) );
    bkroad2->setPosition( Vec2(bkroad2->getPosition().x-ROADSPEED, bkroad2->getPosition().y) );

    if( bkroad1->getPosition().x < -bkroad1->getBoundingBox().size.width-1){
        bkroad1->setPosition( Vec2( bkroad2->getPosition().x + bkroad2->getBoundingBox().size.width, bkroad1->getPosition().y));
   }
    if( bkroad2->getPosition().x < -bkroad2->getBoundingBox().size.width-1){
        bkroad2->setPosition( Vec2( bkroad1->getPosition().x + bkroad1->getBoundingBox().size.width, bkroad2->getPosition().y));
   }

        for(int i=0;i<traps.size();i++)
        {
            traps[i].returnBlock()->setPosition(traps[i].returnBlock()->getPosition().x-ROADSPEED, traps[i].returnBlock()->getPosition().y);
            if( traps[i].returnBlock()->getPosition().x < 50)
            {
                traps[i].removeblock(traps[i].returnBlock());
                traps.erase(traps.begin()+i);
            }
        }

}

void HelloWorld::trapCreate()
{
    block trap1(layer1);
    traps.insert(traps.end(), trap1);
}