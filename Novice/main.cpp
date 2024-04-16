#define _USE_MATH_DEFINES
#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "GC2A_09_ハラサワ_ミツタカ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

struct Vector3 {
	float x;
	float y;
	float z;
};


Vector3 Add(const Vector3& a, const Vector3& b) {
	Vector3 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return result;
}
Vector3 Subtract(const Vector3& a, const Vector3& b) {
	Vector3 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}
Vector3 Multiply(float scalar, const Vector3& a) {
	Vector3 result;
	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	return result;
}
float Dot(const Vector3& a, const Vector3& b) {
	float result;
	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return result;
}
float Length(const Vector3& a) {
	float result;
	result = float(pow(a.x, 2.0f) + pow(a.y, 2.0f) + pow(a.z, 2.0f));
	result = sqrtf(result);
	return result;
}
Vector3 Normalize(const Vector3& a) {
	Vector3 result;
	float length = Length(a);
	result.x = a.x / length;
	result.y = a.y / length;
	result.z = a.z / length;
	return result;
}



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 宣言開始
	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = 4.0f;

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	
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

		

		///
		/// ↑更新処理ここまで
		///
				
		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 0, "%.02f", resultAdd.x);
		Novice::ScreenPrintf(50, 0, "%.02f", resultAdd.y);
		Novice::ScreenPrintf(100, 0, "%.02f", resultAdd.z);
		Novice::ScreenPrintf(170, 0, ":Add");

		Novice::ScreenPrintf(0, 30, "%.02f", resultSubtract.x);
		Novice::ScreenPrintf(50, 30, "%.02f", resultSubtract.y);
		Novice::ScreenPrintf(100, 30, "%.02f", resultSubtract.z);
		Novice::ScreenPrintf(170, 30, ":Subtract");

		Novice::ScreenPrintf(0, 60, "%.02f", resultMultiply.x);
		Novice::ScreenPrintf(50, 60, "%.02f", resultMultiply.y);
		Novice::ScreenPrintf(100, 60, "%.02f", resultMultiply.z);
		Novice::ScreenPrintf(170, 60, ":Multiply");

		Novice::ScreenPrintf(0, 90, "%.02f", resultDot);
		Novice::ScreenPrintf(70, 90, ":Dot");

		Novice::ScreenPrintf(0, 120, "%.02f", resultLength);
		Novice::ScreenPrintf(70, 120, ":Length");

		Novice::ScreenPrintf(0, 150, "%.02f", resultNormalize.x);
		Novice::ScreenPrintf(50, 150, "%.02f", resultNormalize.y);
		Novice::ScreenPrintf(100, 150, "%.02f", resultNormalize.z);
		Novice::ScreenPrintf(170, 150, ":Normalize");


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
}