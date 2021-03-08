#include<iostream>
#include<queue>
using namespace std;

#define MAX 10

int testcase;
int n, k;
int arr[MAX][MAX];
int max_num = -1;

struct INFO {
	int depth;
	int y, x;
};
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int bfs() {
	int ans = -1;


	queue<INFO> qu;
	int checked[MAX*MAX][MAX][MAX] = { 0 };

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < n;x++) {
			if (max_num == arr[y][x]) qu.push({ 1, y,x });
			checked[1][y][x] = 1;
		}
	}

	while (!qu.empty())
	{
		INFO cur = qu.front(); qu.pop();
		//ÃÖ´ñ°ª °»½Å
		if (ans < cur.depth) ans = cur.depth;

		for (int i = 0;i < 4;i++) {
			int next_y = cur.y + dy[i];
			int next_x = cur.x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
			if (checked[cur.depth + 1][next_y][next_x]) continue;

			if (arr[cur.y][cur.x] > arr[next_y][next_x]) {
				qu.push({ cur.depth + 1,next_y,next_x });
				checked[cur.depth + 1][next_y][next_x] = 1;
			}
		}
	}

	return ans;
}
int main() {
	cin >> testcase;

	for (int tt = 1;tt <= testcase;tt++) {
		cin >> n >> k;
		int ans = 0;
		max_num = -1;

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				cin >> arr[y][x];
				if (max_num < arr[y][x]) max_num = arr[y][x];
			}
		}

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				for (int i = 1;i <= k;i++) {
					arr[y][x] -= i;
					int tmp = bfs();
					if (tmp > ans)ans = tmp;
					arr[y][x] += i;
				}
			}
		}
		cout << "#" << tt << " " << ans << endl;
	}
	return 0;
}