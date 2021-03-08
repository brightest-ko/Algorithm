#include<iostream>
using namespace std;

int r, c;
char tmp[10010][510] = { 0 };
int arr[10010][510] = { 0 };
int checked[10010][510] = { 0 };
int cnt = 0;

int dy[3] = { -1,0,1 };
int dx[3] = { 1,1,1 };

int dfs(int y, int x) {
	//cout << y << " " << x << endl;
	if (x == c - 1) {
		return 1;
	}

	for (int i = 0;i < 3;i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue;

		if (arr[next_y][next_x] == 0 && checked[next_y][next_x] == 0) {
			checked[next_y][next_x] = 1;
			if (dfs(next_y, next_x)) return 1;
			//checked[next_y][next_x] = 0;
			//���� �������� ��������, �ٸ��� �Ǽ����� ���� ���̹Ƿ� �ɼ��� �ٸ��� ������ش�.
			//Nope! �ֳ��ϸ� ���⼭ �ٸ��� �Ǽ����� ���Ѵٸ�
			//�Ʒ����� �ö�ͼ� ���⼭���� �Ǽ��Ϸ��ص� �̹� ���Ѵٴ� ���̹Ƿ�!
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &r, &c);
	for (int y = 0;y < r;y++) {
		scanf("%s", &tmp[y]);
		for (int x = 0;x < c;x++) {
			arr[y][x] = (tmp[y][x] == '.') ? 0 : 1;
		}
	}
	for (int y = 0;y < r;y++) {
		checked[y][0] = 1;
		cnt += dfs(y, 0);
		//cout << cnt<<endl;
	}

	printf("%d\n", cnt);
	return 0;
}