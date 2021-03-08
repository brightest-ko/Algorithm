#include <iostream>
using namespace std;

#define MAX 15
int w[MAX];
int cnt;

int test_case;
int n;

void perm(int step, int l, int r) {
	//cout << l << " " << r << endl;

	if (step == n) {
		// System.out.println(Arrays.toString(w));
		/*
		for (int i = 0;i < n;i++) {
			cout << w[i] << " ";
		}
		cout << endl;
		*/
		cnt++;
	}
	else {
		for (int i = step; i < n; i++) {
			int temp = w[step];
			w[step] = w[i];
			w[i] = temp;

			// 다음 단계 재귀호출
			perm(step + 1, l + w[step], r); // 저울의 왼쪽에 w[step]추를 올려 놓고 재귀호출
			if (l >= r + w[step]) {
				perm(step + 1, l, r + w[step]); // 저울의 오른쪽에 w[step]추를 올려 놓고 재귀호출
			}
			temp = w[step];
			w[step] = w[i];
			w[i] = temp;

		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int T = 1;T <= test_case;T++) {
		scanf("%d", &n);
		for (int i = 0;i < n;i++) {
			scanf("%d", &w[i]);
		}

		cnt = 0;
		perm(0, 0, 0);
		printf("#%d %d\n", T, cnt);
	}
	return 0;
}