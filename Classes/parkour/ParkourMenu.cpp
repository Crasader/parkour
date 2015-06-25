/*
 * ParkourMenu.cpp
 *
 *  Created on: 2015/01/29
 *      Author: chu
 */

#include "parkour\ParkourMenu.h"


USING_NS_CC;

using namespace cocos2d;
using namespace std;

Scene* ParkourMenu::createScene()
{

    auto scene = Scene::create();
    auto layer = ParkourMenu::create();
    scene->addChild(layer);

    return scene;
}

bool ParkourMenu::init()
{
	//1. �ŏ��ɐe�N���X�̏��������s���B
    if ( !Layer::init() )
    {
        return false;
    }

    // 2. ��ʃT�C�Y���擾����B
    Size visibleSize = Director::getInstance()->getVisibleSize();
   
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 3. ���S���v�Z����B
    auto centerPosition = visibleSize / 2;

    // 4. �w�i�摜���쐬���A�ʒu�ƒ��S��ݒ肷��B

    Sprite* spriteBg = Sprite::create("parkour_img/helloBG.png");
    spriteBg->setPosition(centerPosition);
	this->addChild(spriteBg);

	MenuItemFont::setFontSize(60);

	auto menuItemPlay = MenuItemImage::create(
		"parkour_img/start_n.png" ,
		"parkour_img/start_s.png" ,
		CC_CALLBACK_1(ParkourMenu::onPlay , this)
		);

	Menu* menu = Menu::create(menuItemPlay , NULL);
	menu->setPosition(centerPosition);
	this->addChild(menu);


	auto menuBackButton = MenuItemImage::create(
		"parkour_img/back_btn.png" ,
		"parkour_img/back_btn1.png" ,
		CC_CALLBACK_1(ParkourMenu::backCallback , this)
		);

	menuBackButton->setScale(0.25f);

	Menu* menuBack = Menu::create(menuBackButton , NULL);
	menuBack->setAnchorPoint(Vec2::ZERO);
	menuBack->setPosition(Vec2(30 , 30));

	this->addChild(menuBack);

    return true;
}

void ParkourMenu::onPlay(Ref* pSender){
	cocos2d::log("onPlay Clicked");
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}


void ParkourMenu::backCallback(Ref* pSender){
	auto listView = ListViewGameScene::createScene();
	Director::getInstance()->replaceScene(listView);
}


