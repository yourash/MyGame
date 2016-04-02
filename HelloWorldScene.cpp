#include "HelloWorldScene.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
     auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	 closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));

     // create menu, it's an autorelease object
     auto menu = Menu::create(closeItem, NULL);
     menu->setPosition(Vec2::ZERO);
     this->addChild(menu, 2);

 //    /////////////////////////////
 //    // 3. add your codes below...

 //    // add a label shows "Hello World"
 //    // create and initialize a label
    
 //    auto label = Label::createWithTTF("Хєлоу!", "fonts/Marker Felt.ttf", 24);
    
 //    // position the label on the center of the screen
 //    label->setPosition(Vec2(origin.x + visibleSize.width/2,
 //                            origin.y + visibleSize.height - label->getContentSize().height));

 //    // add the label as a child to this layer
 //    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("man.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.4, (visibleSize.height/2 + origin.y)*0.6));
    Vec2 pos = sprite->getContentSize();
    sprite->setScale(visibleSize.width/pos.x*0.25,visibleSize.height/pos.y*0.25);
    //CCLOG(visibleSize.width);
    // add the sprite as a child to this layer
    this->addChild(sprite, 2);

    background = Sprite::create("road1.png");

    Vec2 pos2 = background->getContentSize();
    background->setPosition(Vec2(visibleSize.width/2 + origin.x,visibleSize.height/6 + origin.y));
    background->setScale(visibleSize.width/pos2.x,1);
    this->addChild(background, 1);


    background2 = Sprite::create("road1.png");

    background2 ->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width,visibleSize.height/6 + origin.y));
    background2->setScale(visibleSize.width/pos2.x,1);
    this->addChild(background2, 1);

    background3 = Sprite::create("texture.jpg");

    Vec2 pos3 = background3->getContentSize();
    background3->setPosition(Vec2(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y));
    background3->setScale(visibleSize.width/pos3.x,visibleSize.height/pos3.y);
    this->addChild(background3, 0);

    background4 = Sprite::create("texture.jpg");

    Vec2 pos4 = background4->getContentSize();
    background4->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width,visibleSize.height/2 + origin.y));
    background4->setScale(visibleSize.width/pos4.x,visibleSize.height/pos4.y);
    this->addChild(background4, 0);
    
        
    
    
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
                //event->getCurrentTarget()->setPosition(++loc.x,loc.y);

                if(loc.y == event->getCurrentTarget()->getPosition().y)
                    event->getCurrentTarget()->runAction(JumpBy::create(1, Vect(0,0),loc.y*1.5,1));

                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:

                
    
                //event->getCurrentTarget()->setPosition(loc.x,loc.y*0.07+loc.y);
                event->getCurrentTarget()->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.4, (visibleSize.height/2 + origin.y)*0.6));

                


                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:

                event->getCurrentTarget()->setPosition(Vec2((visibleSize.width/2 + origin.x)*0.45, (visibleSize.height/2 + origin.y)*0.35));

                break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,sprite);

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
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Vec2 pos3 = background3->getPosition();
    Vec2 pos4 = background4->getPosition(); 

    background3->setPosition(pos3.x-1, pos3.y);
    background4->setPosition(pos4.x-1, pos4.y);

    if(pos3.x==(-0.5)*visibleSize.width)
    {
        background3->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width-1,visibleSize.height/2 + origin.y));
    }
    else if(pos4.x==(-0.5)*visibleSize.width)
    {
        background4->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width-1,visibleSize.height/2 + origin.y));
    }

    Vec2 pos = background->getPosition();
    Vec2 pos2 = background2->getPosition(); 

    background->setPosition(pos.x-2, pos.y);
    background2->setPosition(pos2.x-2, pos2.y);

    if(pos.x==(-0.5)*visibleSize.width)
    {
        background->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width-2,visibleSize.height/6 + origin.y));
    }
    else if(pos2.x==(-0.5)*visibleSize.width)
    {
        background2->setPosition(Vec2(visibleSize.width/2 + origin.x+visibleSize.width-2,visibleSize.height/6 + origin.y));
    }
} 