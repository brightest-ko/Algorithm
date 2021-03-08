#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> Pair;
//�ð� ����� ��ġ

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
		for (int i = MOD; i < n + MOD; i++) {// 300���ĺ���
			for (int j = MOD; j < m + MOD; j++) {
				scanf("%d", &cells[i][j]); //�� �ð� ����
				if (cells[i][j] > 0) {
					chk[i][j] = 1; // �� ĭ 1
					pq.push({ {cells[i][j], -cells[i][j]}, {i,j} });
					//�� �ð�, -���ð�, ��ġ2

				}
			}
		}
		for (int time = 1; time < k; time++) {
			while (!pq.empty() && pq.top().first.first == time) {
				//������� �ʰ� priority queue�� ���ð��� �ð��� ������ ����
				//����ְų� �ð��� ���� ������ ����
				
				//�켱���� ť�� top �� �׻� �ּ� time ���� �ִ�.

				int r = pq.top().second.first; //��ġ y
				int c = pq.top().second.second; //��ġ x
				int v = -pq.top().first.second; //�ʱ� ���ð� cells[i][j]
				pq.pop();
				if (v == 5000) continue;
				//5000�̸� ���� ���������ϱ� pq�ȳ־��ְ� coninue�� ����

				//���� �������� ���� ���� pop �Ǿ�� �ϱ� ����?

				pq.push({ {time + v - 1, -5000}, {-1,-1} });
				//���������� ����־��ٴ°Ŵϱ�
				//v �� 5000�̶�� ���� ������ �ѹ� pop �� ���� �ִ� �����ε�
				//�������� ������ ���� ���� ��������
				//�����ð� = ���� �ð� + �ʱ� ���ð� -1, ���ð� -5000���� �ٲ�, ��ġ�� -1 -1

				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					//4����
					if (chk[nr][nc] == 0) { //�������� ����ִٸ�
						chk[nr][nc] = 1; //����
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
//[��ó] SWEA] 5653.[���� SW �����׽�Ʈ] �ٱ⼼����� - �켱����ť | �ۼ��� 1ilsang