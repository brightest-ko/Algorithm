#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int r, c;

char tmp[30][30] = { 0 };
int arr[30][30] = { 0 };
//pip = arr[next_y][next_x]

struct Info {
	int dir, y, x;
};
//dir : 다음 dir
Info mo, za;

//next_dir[pip][dir]
const int next_dir[8][4] = {
	{-1,-1,-1,-1},
	{-1,2,-1,0},
	{-1,3,0,-1},
	{3,-1,1,-1},
	{2,-1,-1,1},
	{-1,-1,2,3},
	{0,1,-1,-1},
	{0,1,2,3}
};
//모양
//if (tmp[y][x] == '1') arr[y][x] = 1;
//if (tmp[y][x] == '2') arr[y][x] = 2;
//if (tmp[y][x] == '3') arr[y][x] = 3;
//if (tmp[y][x] == '4') arr[y][x] = 4;
//if (tmp[y][x] == '|') arr[y][x] = 5;
//if (tmp[y][x] == '-') arr[y][x] = 6;
//if (tmp[y][x] == '+') arr[y][x] = 7;

//주석 Ctrl K + C
//주석 해제 Ctrl K + U

const int dy[] = { 0,0,1,-1 };// dir: 0동 1서 2남 3북
const int dx[] = { 1,-1,0,0 };



bool bfs() {
	int checked[30][30] = { 0 };
	queue<Info> qu;
	checked[mo.y][mo.x] = 1;

	for (int i = 0;i < 4;i++) {
		int dir = i; //mo.dir 다음방향이 i이면
		int next_y = mo.y + dy[dir];
		int next_x = mo.x + dx[dir];
		int pip = arr[next_y][next_x];
		if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue;

		if (pip != 0) {
			Info next;
			next.y = next_y;
			next.x = next_x;
			next.dir = next_dir[pip][dir]; //mo에서 next_y , next_x로 갈때의 방향
			qu.push(next);
			//checked[next_y][next_x] = 1;
		}
	}

	while (!qu.empty())
	{
		Info cur = qu.front(); qu.pop();

		//cout << cur.y << " " << cur.x << " " << za.y << " " << za.x << endl;
		if (cur.y == za.y && cur.x == za.x) return true;

		int dir = cur.dir; //cur.dir 다음방향이 i이면
		int next_y = cur.y + dy[dir];
		int next_x = cur.x + dx[dir];
		int pip = arr[next_y][next_x];
		if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue;

		//		if (next_dir[pip][dir] != -1 && checked[next_y][next_x] == 0) {

		if (pip != 0) {
			Info next;
			next.y = next_y;
			next.x = next_x;
			next.dir = next_dir[pip][dir]; //mo에서 next_y , next_x로 갈때의 방향
			qu.push(next);
			checked[next_y][next_x] = 1;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int y = 0;y < r;y++) {
		scanf("%s", tmp[y]);
	}


	for (int y = 0;y < r;y++) {
		for (int x = 0;x < c;x++) {
			if (tmp[y][x] == '1') arr[y][x] = 1;
			if (tmp[y][x] == '2') arr[y][x] = 2;
			if (tmp[y][x] == '3') arr[y][x] = 3;
			if (tmp[y][x] == '4') arr[y][x] = 4;
			if (tmp[y][x] == '|') arr[y][x] = 5;
			if (tmp[y][x] == '-') arr[y][x] = 6;
			if (tmp[y][x] == '+') arr[y][x] = 7;
			if (tmp[y][x] == 'M') {
				mo.y = y;
				mo.x = x;
				mo.dir = -1;
				arr[y][x] = 10;
			}if (tmp[y][x] == 'Z') {
				za.y = y;
				za.x = x;
				za.dir = -1;
				arr[y][x] = 20;
			}
		}
	}


	for (int y = 0;y < r;y++) {
		for (int x = 0;x < c;x++) {
			if (arr[y][x] == 0) {
				for (int i = 1;i <= 7;i++) {

					arr[y][x] = i;
					//printf("nn %d %d %d %d\n", y, x, i, arr[y][x]);
					if (bfs()) {
						y++;
						x++;
						if (i == 1) printf("%d %d %c\n", y, x, '1');
						if (i == 2) printf("%d %d %c\n", y, x, '2');
						if (i == 3) printf("%d %d %c\n", y, x, '3');
						if (i == 4) printf("%d %d %c\n", y, x, '4');
						if (i == 5) printf("%d %d %c\n", y, x, '|');
						if (i == 6) printf("%d %d %c\n", y, x, '-');
						if (i == 7) printf("%d %d %c\n", y, x, '+');
						return 0;
					}
					arr[y][x] = 0;
				}
			}
		}
	}
	return 0;
}