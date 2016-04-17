#include "block.h"

USING_NS_CC;

block::block( cocos2d::Layer* layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    block1 = Sprite::create( "block.png" );

    Vec2 sizeblock = block1->getContentSize();
    block1->setScale(visibleSize.width/sizeblock.x*0.25,visibleSize.height/sizeblock.y*0.25);

    //block1->setPosition( Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    block1->setPosition(Vec2(visibleSize.width/cocos2d::RandomHelper::random_int(1, 4)+visibleSize.width,(visibleSize.height/2)*0.35));
    
    layer->addChild( block1, 3 );
    layer1=layer;
}
block::~block(){}
cocos2d::Sprite* block::returnBlock()
{
	return block1;
} 

void block::removeblock(cocos2d::Sprite* block_1)
{
	layer1->removeChild(block_1,true);
}