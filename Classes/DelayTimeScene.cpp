//
//  DelayTimeScene.cpp
//  DelayTime
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#include "DelayTimeScene.h"
// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

DelayTimeScene::DelayTimeScene()
{
    
}

DelayTimeScene::~DelayTimeScene()
{
    
}

Scene* DelayTimeScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = DelayTimeScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool DelayTimeScene::init()
{
    if ( !Layer::init() )
    {
        
        return false;
    }
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー（ホワイト）
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    this->addChild(background);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    //スプライトの作成
    auto Sprite = Sprite::create("Icon-152.png");
    Sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(Sprite);
    
    //拡大のアクション 0.5秒 3倍拡大
    auto scaleAction = ScaleBy::create(.5, 3);
    
    //3秒のお休み
    auto delay = DelayTime::create(3);
    
    //フェードアウトのアクション 0.5秒
    auto fadeOutAction = FadeOut::create(0.5);
    
    //拡大->3秒お休み->フェードアウトの順番にアクションを並べる
    auto sequence = Sequence::create(scaleAction, delay, fadeOutAction, NULL);
    
    //開始！
    Sprite->runAction(sequence);
    
    return true;
}
