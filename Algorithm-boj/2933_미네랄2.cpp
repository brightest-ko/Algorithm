#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int r, c;
char mineral[111][111];
bool cluster[111][111];
int dx[4] = { -1, 1 , 0 , 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mineral[i][j];
		}
	}

	int n;
	cin >> n;
	
	bool left = true;
	while (n--) {
		int height;
		cin >> height;
		height = r - height + 1; //height를 거꾸로 받으니까.
	
		// del
		if (left == true) {
			for (int i = 1; i <= c; i++) {
				if (mineral[height][i] == 'x') { //처음 만나는 곳에서 삭제
					mineral[height][i] = '.';
					break;
				}
			}
		}
		else {
			for (int i = c; i >= 1; i--) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		left = !left;//왔다갔다함.

		// check
		memset(cluster, false, sizeof(cluster));
		for (int j = 1; j <= c; j++) {
			if (mineral[r][j] == 'x') { //높이가 1인 줄에 x가 있으면
				queue<pair<int, int> > q;
				q.push(make_pair(r, j));
				cluster[r][j] = true; //클러스터가 true
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
							if (!cluster[nx][ny] && mineral[nx][ny] == 'x') { //클러스트 지정이 안되있고 x이면
								cluster[nx][ny] = true; //클러스터 지정해주고
								q.push(make_pair(nx, ny)); //넣어줘라
							}
						}
					}
				}
			}
		}

		// down
		int down = r; //맨 아랫줄
		for (int j = 1; j <= c; j++) { //칸
			for (int i = r; i >= 1; i--) { //높이 맨 아랫줄부터 위로 올라옴 //줄
				if (mineral[i][j] == 'x' && cluster[i][j] == false) { //미네랄은 있는데 클러스터에 지정이 안됐다면 위에 떨어진 아이
					int col_down = r - i; // 맨아래에서 i뺀값 = 지금까지 올라온 높이 수 - 1
					for (int k = i + 1; k <= r; k++) { //미네랄은 있느데 클러스터가 다른 아이의 아래높이부터 바닥까지 확인
						if (cluster[k][j] == true) { // 클러스터가 바닥과 같은 아이가 나타나면
							col_down = k - i - 1; //그 클러스터의 높이 - 다른 클러스터의 높이 -1 == 둘 사이 차이
							break;
						}
					}
					if (down > col_down) {
						down = col_down; //둘 사이 차이가 가장 작은 아이를 찾아서
					}
				}
			}
		}
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				//지금 높이 + 차이 가 r을 벗어나지 않고
				//차이는 0이 아니어야하고
				//미네랄은 있지만 같은 클러스터가 아닌 아이들을
				if (i + down <= r && down != 0 && mineral[i][j] == 'x' && cluster[i][j] == false) {
					mineral[i + down][j] = mineral[i][j];
					mineral[i][j] = '.';
				}
				//내린다
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << mineral[i][j];
		}
		cout << '\n';
	}
	return 0;
}