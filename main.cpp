#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1A_19_タナカショウ_PG2_13-1";

bool Enemy::isEnemyAlive_[] = { 1 };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	Enemy* enemy = new Enemy;

	player->Initialize();
	enemy->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		enemy->Update(keys, preKeys);
		player->Update(keys, preKeys);

		for (int i = 0; i < 2; i++)
		{
			float disXB = (player->GetBulletPos().x - enemy->GetPos().x[i]) * (player->GetBulletPos().x - enemy->GetPos().x[i]);
			float disYB = (player->GetBulletPos().y - enemy->GetPos().y[i]) * (player->GetBulletPos().y - enemy->GetPos().y[i]);
			float disRB = (player->GetBulletRad() + enemy->GetRadius()) * (player->GetBulletRad() + enemy->GetRadius());

			if (disRB > disXB + disYB)
			{
				enemy->~Enemy();
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemy->Draw();
		player->Draw();

		Novice::ScreenPrintf(0, 0, "respown : PRESS[R] ");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
};
