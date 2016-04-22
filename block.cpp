#include "block.h"

USING_NS_CC;

block::block( cocos2d::Layer* layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    block1 = Sprite::create( "block.png" );

    Vec2 sizeblock = block1->getContentSize();
    block1->setScale(visibleSize.width/sizeblock.x*0.10,visibleSize.height/sizeblock.y*0.20);

    //block1->setPosition( Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    block1->setPosition(Vec2(visibleSize.width/(float)((float)6/(float)cocos2d::RandomHelper::random_int(1,6))+visibleSize.width,(visibleSize.height/2)));
    
    auto block_body = PhysicsBody::createBox(block1->getContentSize(), PhysicsMaterial(100.0f, 0.0f, 20.0f) );
    block1->setPhysicsBody(block_body);
    block_body->setRotationEnable(true);
    block_body->setCollisionBitmask( 1);
    block_body->setContactTestBitmask( true );

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