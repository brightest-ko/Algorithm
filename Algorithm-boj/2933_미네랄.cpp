#include<iostream>
#include<queue>
using namespace std;

char tmp[110][110] = { 0 };
int arr[110][110] = { 0 };
int checked[110][110] = { 0 };
int n;
int stick[110] = { 0 };

int r, c;

//�������� ���� ���� ����� �̳׶� ã�� ���ֱ� 
void stick_left_func(int h) {
	for (int i = 0;i < c;i++) {
		if (arr[h][i]) {
			arr[h][i] = 0;
			if (bfs() >= 2) {
				fall();
			}
		}
	}
}
void stick_right_func(int h) {
	for (int i = c-1;i >= 0;i--) {
		if (arr[h][i]) {
			arr[h][i] = 0;
			if (bfs() >= 2) {
				fall();
			}
		}
	}
}
//������ȣ ������ ������ȣ�� 1�̸� pass 2�̻��̸� fall
int bfs() {
	int cnt = 1;
	const int dy[] = { 0,0,1,-1 };
	const int dx[] = { 1,-1,0,0 };
	for (int y = 0;y < r;y++) {
		for (int x = 0;x < c;x++) {
			if (arr[y][x] == 1) {
				checked[y][x] = cnt;
				queue<pair<int, int>> qu;
				qu.push(make_pair(y, x));

				while (!qu.empty())
				{
					int cur_y = qu.front().first;
					int cur_x = qu.front().second;
					qu.pop();

					for (int i = 0;i < 4;i++) {
						int next_y = cur_y + dy[i];
						int next_x = cur_x + dx[i];

						if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue;

						if (arr[y][x] == 1 && checked[y][x] == 0) {
							checked[y][x] = cnt;
							qu.push(make_pair(next_y, next_x));
						}
					}
				}
				cnt++;
			}
			else {
				checked[y][x] = 0;
			}
		}
	}
	return cnt;
}

//���� ª�� �Ÿ� ã�� ����߸���
void fall() {
	for (int x = 0;x < c;x++) {
		int vilage_num=-1,last_h=-1, another_village_h=-1, dist=0;
		for (int y = r - 1;y >= 0;y--) {
			if(checked[y][x]!=0) 
		}
	}
}


int main() {
	for (int y = 0;y < r;y++) {
		scanf("%s", tmp[y]);
		for (int x = 0;x < c;x++) {
			arr[y][x] = (tmp[y][x] == '.') ? 0 : 1;
		}
	}
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &stick[i]);

		int cur = i % 2;
		if (cur==0) {//����
			stick_left_func(stick[i]);
		}
		else {//������
			stick_right_func(stick[i]);
		}
	}
	return 0;
}