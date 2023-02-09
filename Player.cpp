#include "Player.h"
#include <Novice.h>

Player::Player() {

	Initialize();

}

void Player::Initialize()
{
	//メンバ変数の初期化
	PlayerPos_.x = 640;
	PlayerPos_.y = 500;
	playerRad_ = 36;
	speed_ = 5;
	BulletPos_.x = PlayerPos_.x;
	BulletPos_.y = PlayerPos_.y;
	isBulletShot_ = 0;
}



void Player::Update(char* keys, char* preKeys) {

	//上下左右移動
	if (keys[DIK_UP])
	{
		PlayerPos_.y -= speed_;
	}
	if (keys[DIK_DOWN])
	{
		PlayerPos_.y += speed_;
	}
	if (keys[DIK_RIGHT])
	{
		PlayerPos_.x += speed_;
	}
	if (keys[DIK_LEFT])
	{
		PlayerPos_.x -= speed_;
	}

	//spaceキーで弾発射
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isBulletShot_ == 0)
	{
		isBulletShot_ = 1;
		BulletPos_.x = PlayerPos_.x;
		BulletPos_.y = PlayerPos_.y;

	}
	if (isBulletShot_ == 1)
	{
		BulletPos_.y = BulletPos_.y - bulletSpeed_;
	}

	if (BulletPos_.y <= 0)
	{
		isBulletShot_ = 0;
	}
}



void Player::Draw() {
	//弾の描画
	if (isBulletShot_ == 1)
	{
		Novice::DrawEllipse(BulletPos_.x, BulletPos_.y, bulletRad_, bulletRad_, 0.0f, BLUE, kFillModeSolid);
	}

	//プレイヤーの描画
	Novice::DrawEllipse(PlayerPos_.x, PlayerPos_.y, playerRad_, playerRad_, 0, GREEN, kFillModeSolid);
}
