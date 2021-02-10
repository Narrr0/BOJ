#include <iostream>
#include <vector>
#include <cmath>
#define INF 2147483647
using namespace std;

/*
팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다. 
마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.
목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 
하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업을 해야 한다.

lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 
우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다. 
우리는 다음과 같은 두 종류의 작업을 할 수 있다.

1. 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
2. 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.

1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 
밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다. 
‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 
또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다. 
땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, B; cin >> N >> M >> B; // 집터의 세로, 가로, 가지고 있는 블럭 수
	vector<vector<int>> field(N, vector<int>(M));
	int min_h = 256; int max_h = 0; // 땅의 최소, 최대 높이
	int time = INF, height = 0;
	
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> field[x][y];
			min_h = min(min_h, field[x][y]);
			max_h = max(max_h, field[x][y]);
		}
	}
	for (int h = min_h; h <= max_h; h++) {
		int remove = 0; // 제거해야할 블럭 수
		int stack = 0;  // 쌓아야할 블럭 수
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (field[x][y] < h) stack += h - field[x][y];
				else remove += field[x][y] - h;
			}
		}
		if (stack <= B + remove) {  // 가지고 있는 블럭 수보다 쌓을 블럭 수가 작거나 같을 경우
			if (time >= stack + remove * 2) {
				time = stack + remove * 2;
				height = h;
			}
		}
	}
	cout << time << " " << height;
}