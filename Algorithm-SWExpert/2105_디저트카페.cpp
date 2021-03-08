#include<iostream>

using namespace std;

#define MAX 30

int dy[4] = {-1,1,1,-1};
int dx[4] = { 1,1,-1,-1 };


int testcase;
int n, arr[MAX][MAX];

int ans = 0;
int checked[4] = { 0 };
int desert_num[110] = { 0 };
int iy, ix, iidx;

void dfs(int y, int x,int idx, int depth) {

	if (y == iy && x == ix && desert_num[arr[y][x]]) {
		if (ans < depth) ans = depth;
		return;
	}

	if (desert_num[arr[y][x]]) return; //한번 마주한 갯수라면

	desert_num[arr[y][x]] =1;
	for (int i = 0;i < 4;i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;


		if (i != idx){ //직진이 아니라면
			if (checked[i]) continue; // 이미 지나간 방향
			if (idx!=-1 && (i + 2) % 4 == idx) continue;//온길과 꺼꾸로 방향
		}

		checked[i] = 1;
		dfs(next_y, next_x, i, depth+1);
		checked[i] = 0;
	}
	desert_num[arr[y][x]] =0;
	return;
}

int main() {
	cin >> testcase;
	for (int tt = 1;tt <= testcase;tt ++ ) {
		ans = 0;
		cin >> n;

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				cin >> arr[y][x];
			}
		}


		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				iy = y, ix = x;
				dfs(y, x, 0, 0);
			}
		}
		if (ans <= 1) ans = -1;
		cout << "#" << tt << " " << ans << endl;
	}
}