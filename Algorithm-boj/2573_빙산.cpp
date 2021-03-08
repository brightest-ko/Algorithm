#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


int n, m;
int arr[310][310][2] = { 0 };
int year = 0, ret = 1;

int now = 0, next_ = 1;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
void melt() {
	next_ = (now + 1) % 2;

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			arr[y][x][next_] = arr[y][x][now];
			if (arr[y][x][now]) {
				for (int i = 0;i < 4;i++) {
					int next_y = y + dy[i];
					int next_x = x + dx[i];
					if (arr[next_y][next_x][now]==0 && arr[y][x][next_]>0) {
						arr[y][x][next_]--;
					}
				}
			}
		}
	}

	now = next_;

	/*
	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			cout << arr[y][x][now] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
}

int checked[310][310] = { 0 };
int cnt = 0;
void bfs(int y, int x) {

	queue<pair<int, int>> qu;
	qu.push(make_pair(y, x));
	checked[y][x] = cnt;

	while (!qu.empty())
	{
		int now_y = qu.front().first;
		int now_x = qu.front().second;
		qu.pop();

		for (int i = 0;i < 4;i++) {
			int next_y = now_y + dy[i];
			int next_x = now_x + dx[i];
			if (checked[next_y][next_x] == 0 && arr[next_y][next_x][now] != 0) {
				qu.push(make_pair(next_y, next_x));
				checked[next_y][next_x] = cnt;
			}
		}
	}
}
int dangi() {
	cnt = 0;
	memset(checked, 0, sizeof(checked));
	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			if (arr[y][x][now] != 0 && checked[y][x] == 0) {
				cnt++;
				//cout << cnt << endl;
				if (cnt > 1) return 2;
				bfs(y,x);
			}
		}
	}

	return cnt;
}
int main() {
	scanf("%d %d", &n, &m);


	for (int y = 0;y < n;y++) {
		for (int x = 0;x < m;x++) {
			scanf("%d", &arr[y][x][now]);
		}
	}

	ret = 1;
	while (ret == 1)
	{
		year++;
		melt();
		ret = dangi();
	}

	if (ret == 0) {
		printf("0\n");
	}else if(ret==2){
		printf("%d\n", year);
	}
	return 0;
}