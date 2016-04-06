#include "MainMenu.h"
#include "HelloWorldScene.h"

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

    auto backgroundSprite = Sprite::create( "Background.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
    
    auto titleSprite = Sprite::create( "Title.png" );
    titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );
    
    this->addChild( titleSprite );
    
    // auto playItem = MenuItemImage::create( "Play Button.png", "Play Button Clicked.png", CC_CALLBACK_1( MainMenu::menuCloseCallback, this ) );
    // playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    // auto menu = Menu::create( playItem, NULL );
    // menu->setPosition( Point::ZERO );
    
    // this->addChild( menu );
    
    return true;
}

// void MainMenu::GoToGameScene( cocos2d::Ref *sender )
// {
//     auto scene = GameScene::createScene();
    
//     Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
// }