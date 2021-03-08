#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int r, c;
char arr[10010][510] = { 0 };
const int dy[] = { -1,0,1 };
const int dx[] = { 1,1,1 };
int max_ret = 0;

struct Info {
	int y, x;
};

void dfs(int cnt, int start_r, int y, int x) { //cnt:파이프 개수, idx 지금 만드는 파이프 위치
	//cout << cnt << " " << start_r << " " << y << " " << x<<endl;
	if (start_r == (r-1)) { if (max_ret < cnt) max_ret = cnt;}

	if (x == (c-1)) { //나의 파이프까지 왔다면
		if (start_r == (r-1)) { if (max_ret < (cnt + 1)) max_ret = cnt + 1; return; }
		dfs(cnt + 1, start_r+1, start_r + 1, 1);
	}

	for (int i = 0;i < 3;i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue;

		if (arr[next_y][next_x] == '.') {
			arr[next_y][next_x] = 'x';
			dfs(cnt, start_r, next_y, next_x);
			arr[next_y][next_x] = '.';
		}
	}
	return;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int y = 0;y < r;y++) {
		scanf("%s", &arr[y]); //마지막은 널값들어감. 배열크기 +1
	}

	for (int y = 0;y < r;y++) {
		for (int i = 0;i < 3;i++) {
			int next_y = y + dy[i];
			int next_x = 1 + dx[i];
			if (next_y<0 || next_y>=r || next_x<0 || next_x>=c) continue;
			//cout << "? " << y << " " << next_y << " " << next_x << " " << arr[next_y][next_x] << endl;
			if (arr[next_y][next_x] == '.') {
				arr[next_y][next_x] = 'x';
				dfs(0, y, next_y, next_x);
				arr[next_y][next_x] = '.';
			}
		}
	}

	printf("%d\n", max_ret);
	return 0;
}