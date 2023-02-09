#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy()
{
	Initialize();
}

Enemy::~Enemy()
{
	for (int i = 0; i < 2; i++)
	{
		isEnemyAlive_[i] = false;
	}
}

//‰Šú‰»
void Enemy::Initialize() {
	for (int i = 0; i < 2; i++)
	{
		enemy_.x[i] = 640 + (100 * i);
		enemy_.y[i] = 300 - (40 * i);
		isEnemyAlive_[i] = true;
		speed_[i] = 5;
	}
	EnemyRad = 16;
};

//XV
void Enemy::Update(char* keys, char* prekeys) {


	for (int i = 0; i < 2; i++)
	{
		enemy_.x[i] += speed_[i];

		if (enemy_.x[i] - EnemyRad <= 0 || enemy_.x[i] + EnemyRad >= 1280)
		{
			speed_[i] = -speed_[i];
		}
		if (!isEnemyAlive_[i])
		{
			if (keys[DIK_R] && prekeys[DIK_R] == 0)
			{
				isEnemyAlive_[i] = true;
			}
		}
	}
};

void Enemy::OnCollision(int i)
{
	speed_[i] = -speed_[i];
};

void Enemy::OnCollisionB(int i) {

	isEnemyAlive_[i] = false;
};

//•`‰æˆ—
void Enemy::Draw()
{

	for (int i = 0; i < 2; i++)
	{
		if (isEnemyAlive_[i])
		{
			Novice::DrawEllipse(enemy_.x[i], enemy_.y[i], EnemyRad, EnemyRad, 0.0f, RED, kFillModeSolid);
		}
	}
};