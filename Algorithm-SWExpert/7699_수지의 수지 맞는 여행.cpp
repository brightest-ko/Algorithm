#include<iostream>
#include<cstring>
using namespace std;

#define MAX 30

char arr[MAX][MAX];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int test_case;
int r, c;

struct Info {
	int y, x;
};

int checked[MAX][MAX] = { 0 };
int check_alpha[26] = { 0 }; //a~z :26°³
int ret = 0;

bool range(int y, int x) {
	if (y<1 || y>r || x<1 || x>c) return false;
	return true;
}

void dfs(Info cur, int cnt) {
	//cout << cur.y << " " << cur.x << " " <<  arr[cur.y][cur.x] << endl;
	//checked[cur.y][cur.x] = 1;
	check_alpha[arr[cur.y][cur.x] - 'A'] = 1;

	if (cnt > ret ) {
		ret = cnt;
	}

	for (int i = 0;i < 4;i++) {
		int next_y = cur.y + dy[i];
		int next_x = cur.x + dx[i];

		//cout << next_y << " " << next_x << " "; 
		Info next = { next_y ,next_x };

		if (!range(next_y, next_x)) continue;
		//cout<< checked[next_y][next_x] << " " << arr[next_y][next_x] << endl;
		if (check_alpha[arr[next_y][next_x] - 'A']) continue;
		dfs(next, cnt+1);
	}

	//checked[cur.y][cur.x] = 0;
	check_alpha[arr[cur.y][cur.x] - 'A'] = 0;
}

int main() {

	scanf("%d", &test_case);

	for (int T = 1;T <= test_case;T++) {
		ret = 0;
		memset(checked, 0, sizeof(checked));
		memset(check_alpha, 0, sizeof(check_alpha));

		scanf("%d %d", &r, &c);
		for (int y = 1;y <= r;y++) {
			for (int x = 1;x <= c;x++) {
				scanf(" %c", &arr[y][x]);
			}
		}

		Info start = { 1,1 };
		dfs(start, 1);

		printf("#%d %d\n", T,ret);
	}
	return 0;
}