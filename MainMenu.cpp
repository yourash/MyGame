#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "definitions.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();// 'scene' is an autorelease object
    
    auto layer = MainMenu::create();// 'layer' is an autorelease object

    scene->addChild(layer);// add layer as a child to scene

    return scene;// return the scene
}

bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "Background.jpg" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
    
    // auto titleSprite = Sprite::create( "Title.png" );
    // titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );
    // titleSprite->setScale(2,2);

    // this->addChild( titleSprite );
    
    auto playItem = MenuItemImage::create( "Title.png", "Titleselected.png", CC_CALLBACK_1( MainMenu::GoToHelloWorldScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    Vec2 sizeof1 = playItem->getContentSize();
    playItem->setScale(visibleSize.width/sizeof1.x/2,visibleSize.height/sizeof1.y/1.5);


    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
    return true;
}

void MainMenu::GoToHelloWorldScene( cocos2d::Ref *sender )
{
    auto scene = HelloWorld::createScene();
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}