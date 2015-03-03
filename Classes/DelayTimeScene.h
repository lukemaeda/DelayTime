//
//  DelayTimeScene.h
//  DelayTime
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#ifndef __DelayTime__DelayTimeScene__
#define __DelayTime__DelayTimeScene__

#include "cocos2d.h"

class DelayTimeScene : public cocos2d::Layer
{
protected:
    DelayTimeScene();
    virtual ~DelayTimeScene();
    //初期化のメソッド
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(DelayTimeScene);
    
};

#endif /* defined(__DelayTime__DelayTimeScene__) */
