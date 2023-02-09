#pragma once
#include "Struct.h"
class Enemy
{

public:
	TransformE enemy_{
		enemy_.x[1] = 640,
		enemy_.y[1] = 300
	};
	int EnemyRad;
	int speed_[2];

	static bool isEnemyAlive_[2];

public:

	Enemy();
	~Enemy();
	void Initialize();//‰Šú‰»


	TransformE GetPos() { return enemy_; };

	int GetRadius() { return EnemyRad; };


	void Update(char* keys, char* prekeys);    //XVˆ—

	void OnCollision(int i);
	void OnCollisionB(int i);

	void Draw();

};
