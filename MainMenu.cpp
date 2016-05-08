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

    auto backgroundSprite = Sprite::create( "Background.jpg" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
    
    // auto titleSprite = Sprite::create( "Title.png" );
    // titleSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize( ).height ) );
    // titleSprite->setScale(2,2);

    // this->addChild( titleSprite );
    
    auto playItem = MenuItemImage::create( "play.png", "playpressed.png", CC_CALLBACK_1( MainMenu::GoToHelloWorldScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    Vec2 sizeof1 = playItem->getContentSize();
    playItem->setScale(visibleSize.width/sizeof1.x/2/1.3/2,visibleSize.height/sizeof1.y/1.5/2);

    auto playItem1 = MenuItemImage::create( "Title.png", "Titleselected.png", CC_CALLBACK_1( MainMenu::GoToHelloWorldScene, this ) );
    playItem1->setPosition( Point( visibleSize.width/10, visibleSize.height / 20) );
    Vec2 sizeof11 = playItem->getContentSize();
    playItem1->setScale(visibleSize.width/sizeof11.x/8,visibleSize.height/sizeof11.y/8);


    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );

    this->addChild( menu );

    auto menu1 = Menu::create( playItem1, NULL );
    menu1->setPosition( Point::ZERO );
    
    this->addChild( menu1 );
    
    return true;
}

void MainMenu::GoToHelloWorldScene( cocos2d::Ref *sender )
{
    auto scene = HelloWorld::createScene();
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}

// void MainMenu::GoToHiddengame( cocos2d::Ref *sender )
// {
//     auto hiddenscene = GameScene::createScene();
    
//     Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, hiddenscene ) );
// }