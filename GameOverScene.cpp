#include "GameOverScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
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

    __String *tempHighScore = __String::createWithFormat( "Game OVER!!!!!" /*highScore*/ );
    
    auto highScoreLabel = LabelTTF::create( tempHighScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * 0.2 );
    
    highScoreLabel->setColor( Color3B::YELLOW );
    highScoreLabel->setPosition( Point( visibleSize.width/2 + origin.x, visibleSize.height / 2 + origin.y ) );

    this->addChild( highScoreLabel );

    auto playItem = MenuItemImage::create( "Title.png", "Titleselected.png", CC_CALLBACK_1( GameOverScene::GoToHelloWorldScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y ) );
    Vec2 sizeof1 = playItem->getContentSize();
    playItem->setScale(visibleSize.width/sizeof1.x/2,visibleSize.height/sizeof1.y/1.5);

    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );

    this->addChild( menu );

    
    return true;
}

void GameOverScene::GoToHelloWorldScene( cocos2d::Ref *sender )
{
    auto scene = HelloWorld::createScene();
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}