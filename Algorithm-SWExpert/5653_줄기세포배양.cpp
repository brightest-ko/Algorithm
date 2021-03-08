#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

#define MAX 700

int testCase;
int n, m, k;
int checked[MAX][MAX] = { 0 };

struct Info{
	int time; // time <= how_long & time => active_time : active
	int how_long; //큐에 있었던 시간
	int active_time; //활성화 될 시간
	int dead;

	Info(){}
	Info(int _time, int _how_long, int _active_time, int _dead) {
		time = _time;
		how_long = _how_long;
		active_time = _active_time;
		dead = _dead;
	}

};
Info arr[MAX][MAX];
queue<pair<int,int>> qu[2];
int now_ = 0, next_ =1;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &testCase);
	for (int t = 1;t <= testCase;t++) {
		memset(arr, 0, sizeof(arr));
		for (int i = 0;i < MAX;i++) {
			for (int j = 0;j < MAX;j++) {
				Info in(0, 0, 0, 0);
				arr[i][j] = in;
			}
		}
		while (!qu[now_].empty()) {
			qu[now_].pop();
		}
		while (!qu[next_].empty()) {
			qu[next_].pop();
		}

		scanf("%d %d %d", &n, &m, &k);
		for (int y = 350;y < 350+n;y++) {
			for (int x = 350; x < 350 + n; x++) {
				int time;
				scanf("%d", &time);
				if (time != 0) {
					Info in(time, 0, 0, 0);
					arr[y][x] = in;
					qu[now_].push(make_pair(y,x));
					checked[y][x] = 1;
				}
			}
		}

		for (int i = 1;i < k;i++) {
			next_ = (now_ + 1) % 2;

			while (!qu[now_].empty())
			{
				int cur_y = qu[now_].front().first;
				int cur_x = qu[now_].front().second;
				Info* cur = &arr[cur_y][cur_x]; qu[now_].pop();

				cur->how_long++; //qu에 한시간 더 있었어
				//cout << cur_y << " " << cur_x << " " << cur->time << " " << cur->how_long << " " << cur->active_time << " " << cur->dead << " " << endl;
				if (cur->dead == 0 && cur->how_long >= cur->time) {//죽지 않았고, 있던 시간이 time보다 크거나 같다면 활성화중
					cur->active_time ++;
					//cout << "ac:" << cur_y << " " << cur_x << " " << cur->time << " " << cur->how_long << " " << cur->active_time << " " << cur->dead << " " << endl;

					if (cur->active_time == cur->time) cur->dead = 1;
					else qu[next_].push(make_pair(cur_y, cur_x));

					for (int d = 0;d < 4;d++) {
						int next_y = cur_y + dy[d];
						int next_x = cur_x + dx[d];
						if (next_y < 0 || next_y >= MAX || next_x < 0 || next_x >= MAX) continue;
						
						//cout << next_y<<" "<< next_x<<" "<<checked[next_y][next_x] << endl;
						if (checked[next_y][next_x] == 1) continue;
						if (checked[next_y][next_x] == 2 && arr[next_y][next_x].time >= cur->time) {
							continue;
						}
						else if(checked[next_y][next_x] == 2 && arr[next_y][next_x].time < cur->time){
							arr[next_y][next_x].time = cur->time;
							arr[next_y][next_x].how_long = -1;
							arr[next_y][next_x].active_time = 0;
							arr[next_y][next_x].dead = 0;
							continue;
						}
						
						Info in(cur->time, -1, 0, 0);
						arr[next_y][next_x] = in;
						qu[next_].push(make_pair(next_y, next_x));
						checked[next_y][next_x] = 2;

					}

				}else if(cur->dead == 0) {
					qu[next_].push(make_pair(cur_y, cur_x));
					//cout << cur_y <<" "<< cur_x <<" "<< arr[cur_y][cur_x].how_long<<endl;
				}
			}

			for (int y = 0;y < MAX;y++) {
				for (int x = 0;x < MAX;x++) {
					if (checked[y][x] == 2) {
						checked[y][x] = 1;
					}
				}
			}
			now_ = next_;
			printf("#%d %d\n", t, qu[now_].size());
		}

		printf("#%d %d\n", t, qu[now_].size());
	}
}

