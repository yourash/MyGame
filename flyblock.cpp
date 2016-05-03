 #include "flyblock.h"

USING_NS_CC;

flyBlock::flyBlock( cocos2d::Layer* layer )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
        
    flyblock = Sprite::create("coin.png");

    Vec2 sizeblock = flyblock->getContentSize();
    flyblock->setScale(visibleSize.width/sizeblock.x*0.05,visibleSize.height/sizeblock.y*0.1);

    flyblock->setPosition((visibleSize.width*(float)cocos2d::RandomHelper::random_int(1,3))+visibleSize.width,(visibleSize.height*0.7));
    
    layer->addChild( flyblock, 10 );

    layer1=layer;
   
}
//flyblock::~flyblock(){}



cocos2d::Sprite* flyBlock::returnflyblock()
{
    return flyblock;
} 

void flyBlock::removeflyblock(cocos2d::Sprite* flyblock)
{
    layer1->removeChild(flyblock,true);
}