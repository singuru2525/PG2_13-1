#pragma once
#include "Struct.h"
class Player
{
private:


	Transform PlayerPos_{
		PlayerPos_.x = 640,
		PlayerPos_.y = 360
	};;

	Transform BulletPos_{
		BulletPos_.x = PlayerPos_.x,
		BulletPos_.y = PlayerPos_.y
	};

	int playerRad_ = 36;
	int bulletRad_ = 15;

	int isBulletShot_ = 0;

	int speed_ = 6;
	int bulletSpeed_ = 10;

public:
	Player();

	//èâä˙âª
	void Initialize();


	void Update(char* keys, char* preKeys);

	Transform GetPlayerPos() { return PlayerPos_; }

	int GetRadius() { return playerRad_; }


	Transform GetBulletPos() { return BulletPos_; }


	int GetPlayerRad() { return playerRad_; }
	int GetBulletRad() { return bulletRad_; }


	void Draw();

};



