#include "GameOverScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

unsigned int score;

Scene* GameOverScene::createScene( unsigned int tempScore )
{
    score = tempScore;
    
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
    Vec2 backSize=backgroundSprite->getContentSize();
    backgroundSprite->setScale(visibleSize.width/backSize.x,visibleSize.height/backSize.y);

    this->addChild( backgroundSprite );
    
    auto retryItem = MenuItemImage::create( "retry.png", "retry.png", CC_CALLBACK_1( GameOverScene::GoToHelloWorldScene, this ) );
    retryItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 * 3 ) );
    Vec2 retrySize=retryItem->getContentSize();
    retryItem->setScale(visibleSize.width/retrySize.x*0.15,visibleSize.height/retrySize.y*0.2);
    
    auto mainMenuItem = MenuItemImage::create( "menu.png", "menu.png", CC_CALLBACK_1( GameOverScene::GoToMainMenu, this ) );
    mainMenuItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 ) );
    Vec2 menuSize=mainMenuItem->getContentSize();
    mainMenuItem->setScale(visibleSize.width/menuSize.x*0.15,visibleSize.height/menuSize.y*0.2);
    
    auto menu = Menu::create( retryItem, mainMenuItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
    UserDefault *def = UserDefault::getInstance( );
    
    auto highScore = def->getIntegerForKey( "HIGHSCORE MAN", 0 );
    
    if ( score > highScore )
    {
        highScore = score;
        
        def->setIntegerForKey( "HIGHSCORE MAN", highScore );
    }
    
    def->flush( );
    
    __String *tempScore = __String::createWithFormat( "%i", score );
    
    auto currentScore = LabelTTF::create( tempScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    currentScore->setPosition( Point( visibleSize.width * 0.25 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( currentScore );
    
    __String *tempHighScore = __String::createWithFormat( "%i", highScore );
    
    auto highScoreLabel = LabelTTF::create( tempHighScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    
    highScoreLabel->setColor( Color3B::YELLOW );
    highScoreLabel->setPosition( Point( visibleSize.width * 0.75 + origin.x, visibleSize.height / 2 + origin.y ) );

    this->addChild( highScoreLabel );
    
    return true;
}

void GameOverScene::GoToMainMenu( cocos2d::Ref *sender )
{
    auto scene = MainMenu::createScene( );
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}

void GameOverScene::GoToHelloWorldScene( cocos2d::Ref *sender )
{
    auto scene = HelloWorld::createScene( );
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}
