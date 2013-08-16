#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCScale9Sprite* sacel9SprY = CCScale9Sprite::create("Icon@2x.png");
    CCEditBox* box = CCEditBox::create(CCSizeMake(200, 80), sacel9SprY);
     //设置编辑框内的文字
//    box->setText("xcc");
    //设置位置
    box->setPosition(ccp(200, 200));
    
    //获取编辑框内的文字
    CCLOG("Text:%s",box->getText());
    
    box->setDelegate(this);
    
     //设置文本的颜色
    box->setFontColor(ccc3(255, 0, 0));
    
    
    //当编辑框中没有任何字符的提示  
    box->setPlaceHolder("请输入账号：");
    
    //最大输入文本长度
    box->setMaxLength(3);
    
    box->setInputMode(kEditBoxInputModeAny);
    
   
     //      kEditBoxInputModeAny:         开启任何文本的输入键盘,包括换行
     //      kEditBoxInputModeEmailAddr:   开启 邮件地址 输入类型键盘
     //      kEditBoxInputModeNumeric:     开启 数字符号 输入类型键盘
     //      kEditBoxInputModePhoneNumber: 开启 电话号码 输入类型键盘
     //      kEditBoxInputModeUrl:         开启 URL 输入类型键盘
     //      kEditBoxInputModeDecimal:     开启 数字 输入类型键盘，允许小数点
     //      kEditBoxInputModeSingleLine:  开启任何文本的输入键盘,不包括换行
     
    
     box->setReturnType(kKeyboardReturnTypeSearch);
    
    
     //      kKeyboardReturnTypeDefault:  默认使用键盘return 类型
     //      kKeyboardReturnTypeDone:     默认使用键盘return类型为“Done”字样
     //      kKeyboardReturnTypeSend:     默认使用键盘return类型为“Send”字样
     //      kKeyboardReturnTypeSearch:   默认使用键盘return类型为“Search”字样
     //      kKeyboardReturnTypeGo:       默认使用键盘return类型为“Go”字样
    
    
    //设置该属性输入密码时为替代符
    box->setInputFlag(kEditBoxInputFlagPassword);
    
   
     this->addChild(box);
    
    
    
   
    
   
    return true;
}

void HelloWorld::onEnter()
{
    CCLog("AAA");
    
}

void HelloWorld::onExit()
{
    CCLog("AAA");
}

void HelloWorld::editBoxEditingDidBegin(cocos2d::extension::CCEditBox *editBox)
{
    CCLOG("start edit");
}

void HelloWorld::editBoxEditingDidEnd(cocos2d::extension::CCEditBox *editBox)
{
     CCLOG("end edit");
}

void HelloWorld::editBoxReturn(cocos2d::extension::CCEditBox *editBox)
{
    CCLOG("editboxreturn");
}

void HelloWorld::editBoxTextChanged(cocos2d::extension::CCEditBox *editBox, const std::string &text)
{
     CCLOG("textchanged");
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    

    
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
