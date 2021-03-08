#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n = 8;
char tmp[10][10] = { 0 };
int arr[20][10][9] = { 0 };
int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
int dx[] = {-1,0,1,-1,0,1,-1,0,1 };

int checked[10][10][9] = { 0 };

struct Mov
{
	int y, x, mov_cnt;
};

int move() {
	queue<Mov> qu;
	Mov start;
	start.y = 7;
	start.x = 0;
	start.mov_cnt = 0;
	qu.push(start);
	checked[start.y][start.x][start.mov_cnt] = 1;

	while (!qu.empty())
	{
		Mov cur = qu.front();
		qu.pop();
		if (cur.x == 7 && cur.y == 0) return 1;
		for (int i = 0;i < 9;i++) {
			Mov next;
			next.y = cur.y + dy[i];
			next.x = cur.x + dx[i];
			if(cur.mov_cnt<8) next.mov_cnt = cur.mov_cnt+1;
			else next.mov_cnt = 8;
			if (arr[next.y][next.x][next.mov_cnt] == 0 && arr[next.y][next.x][cur.mov_cnt] == 0 && checked[next.y][next.x][next.mov_cnt] == 0) {

				qu.push(next);
				checked[next.y][next.x][next.mov_cnt] = 1;
				checked[next.y][next.x][cur.mov_cnt] = 1;
			}
		}
	}
	return 0;
}

void wall_fall(int cnt) {
	for (int y = n-1;y >=0 ;y--) {
		for (int x = 0;x < n;x++) {
			arr[y + 1][x][cnt+1] = arr[y][x][cnt];
		}
	}
	for (int x = 0;x < n;x++) {
		arr[0][x][cnt + 1] = 0;
	}
}
int main() {

	memset(arr, -1, sizeof(arr));

	for (int y = 0;y < n;y++) {
		scanf("%s", tmp[y]);
		for (int x = 0;x < n;x++) {
			if (tmp[y][x] == '.') arr[y][x][0] = 0;
			else arr[y][x][0] = 1;
		}
	}

	for (int i = 0;i < 8;i++) {
		wall_fall(i);
	}

	cout << move() << endl;
	return 0;
}