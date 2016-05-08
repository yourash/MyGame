#include "block.h"

USING_NS_CC;

block::block( cocos2d::Layer* layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    block1 = Sprite::create( "labki.png" );

    Vec2 sizeblock = block1->getContentSize();
    block1->setScale(visibleSize.width/sizeblock.x*0.25,visibleSize.height/sizeblock.y*0.25);

    //block1->setPosition( Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    block1->setPosition(Vec2(visibleSize.width/(float)((float)3/(float)cocos2d::RandomHelper::random_int(4,8))+visibleSize.width,(visibleSize.height*1)));
    
    auto block_body = PhysicsBody::createBox(block1->getContentSize(), PhysicsMaterial(0.2f, 0.0f, 0.0f) );
    block1->setPhysicsBody(block_body);
    block_body->setRotationEnable(true);
    block_body->setContactTestBitmask( true );
    block_body->setTag(2);

    layer->addChild( block1, 10 );
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