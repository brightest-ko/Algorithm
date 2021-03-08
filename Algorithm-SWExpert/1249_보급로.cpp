#include <stdio.h>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;

int map[101][101];
int opt[101][101];
const int dx[4] = { -1, 0, 1,  0 };
const int dy[4] = { 0, 1, 0, -1 };
int n;
queue< pair<int, int> > q;
int main(void) {
	int T;
	setbuf(stdout, NULL);
	scanf("%d\n", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 101; i++)
		{
			for (int j = 0; j < 101; j++)
				opt[i][j] = 2e9;
		}
		opt[0][0] = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		q.push(make_pair(0, 0));//½ÃÀÛÁ¡ Çª½¬

		while (q.size())
		{
			int x = q.front().first;//´ÙÀ½ Å½»öÇÒ x,yÁÂÇ¥
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextX = x + dx[i];
				int nextY = y + dy[i];
				if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
					continue;
				if (opt[nextX][nextY] > opt[x][y] + map[nextX][nextY])
				{
					opt[nextX][nextY] = opt[x][y] + map[nextX][nextY];
					q.push(make_pair(nextX, nextY));
				}
			}
		}
		printf("#%d %d\n", test_case, opt[n - 1][n - 1]);
	}
	return 0;
}
