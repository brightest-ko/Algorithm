#include<iostream>
#include<queue>
using namespace std;

#define MAX 110
#define INF 987987987

int testCase;
int n;
int arr[MAX][MAX], dp[MAX][MAX];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

struct Info {
	int y;
	int x;
};
queue<Info> qu;

int main() {
	scanf("%d", &testCase);
	for (int tt = 1;tt <= testCase;tt++) {
		scanf("%d", &n);
		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				scanf("%1d", &arr[y][x]);
				dp[y][x] = INF;
				//cout << arr[y][x] << " ";
			}
			//cout << endl;
		}

		Info start;
		start.y = 0;
		start.x = 0;
		dp[start.y][start.x] = arr[start.y][start.x];
		qu.push(start);

		while (!qu.empty()) {
			Info cur = qu.front(); qu.pop();
			
			for(int i=0;i<4;i++){
				Info next;
				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) continue;
				//cout << next.y << " " << next.x <<" "<< dp[next.y][next.x]<<" " << arr[next.y][next.x] + dp[cur.y][cur.x]<< endl;
				if (dp[next.y][next.x] > arr[next.y][next.x] + dp[cur.y][cur.x]) {
					dp[next.y][next.x] = arr[next.y][next.x] + dp[cur.y][cur.x];
					qu.push(next);
				}
			}
		}

		printf("#%d %d\n", tt, dp[n - 1][n - 1]);
	}
}