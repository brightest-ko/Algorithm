#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Pair;
//시간 생명력 위치

int tcase, n, m, k;
int cells[700][700];
int chk[700][700];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
const int MOD = 300;

int main(void) {
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = MOD; i < n + MOD; i++) {// 300이후부터
			for (int j = MOD; j < m + MOD; j++) {
				scanf("%d", &cells[i][j]); //셀 시간 받음
				if (cells[i][j] > 0) {
					chk[i][j] = 1; // 이 칸 1
					pq.push({ {cells[i][j], -cells[i][j]}, {i,j} });
					//셀 시간, -셀시간, 위치2

				}
			}
		}
		for (int time = 1; time < k; time++) {
			while (!pq.empty() && pq.top().first.first == time) {
				//비어있지 않고 priority queue의 셀시간이 시간과 같을때 까지
				//비어있거나 시간이 같지 않을때 멈춤
				
				//우선순위 큐의 top 은 항상 최소 time 값이 있다.

				int r = pq.top().second.first; //위치 y
				int c = pq.top().second.second; //위치 x
				int v = -pq.top().first.second; //초기 셀시간 cells[i][j]
				pq.pop();
				if (v == 5000) continue;
				//5000이면 이제 죽을세포니까 pq안넣어주고 coninue로 죽임

				//죽은 세포들이 가장 먼저 pop 되어야 하기 때문?

				pq.push({ {time + v - 1, -5000}, {-1,-1} });
				//그전까지는 살아있었다는거니까
				//v 가 5000이라는 것은 이전에 한번 pop 이 된적 있는 세포인데
				//다음번에 나오면 죽을 세포 죽은세포
				//죽을시간 = 지금 시간 + 초기 셀시간 -1, 셀시간 -5000으로 바꿈, 위치도 -1 -1

				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					//4방향
					if (chk[nr][nc] == 0) { //간적없이 비어있다면
						chk[nr][nc] = 1; //가고
						pq.push({ {time + v + 1, -v}, {nr, nc} });
					}
				}
			}
		}
		printf("#%d %d\n", t, pq.size());
		memset(chk, 0, sizeof(chk));
		memset(cells, 0, sizeof(cells));
	}
	return 0;
}
//[출처] SWEA] 5653.[모의 SW 역량테스트] 줄기세포배양 - 우선순위큐 | 작성자 1ilsang