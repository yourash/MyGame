#ifndef  _MAIN_MENU_H_
#define  _MAIN_MENU_H_

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
	MainMenu();
	~MainMenu();
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
    

    //void update(float) override;
private:
	//void GoToGameScene( cocos2d::Ref *sender );
};

#endif // _MAIN_MENU_H_